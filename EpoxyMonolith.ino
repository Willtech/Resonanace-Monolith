#include <WiFi.h>
#include <EEPROM.h>
#include <WebSocketsServer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include "config.h"
#include "index.h"

CRGB leds[NUM_LEDS];
AsyncWebServer server(80);
WebSocketsServer ws(81);

// State
String currentMode = "static";
uint8_t brightness = BRIGHTNESS;
CRGB currentColor = CRGB::Blue;

void loadSettings() {
  EEPROM.begin(64);
  brightness = EEPROM.read(ADDR_BRIGHT);
  currentColor = CRGB(EEPROM.read(ADDR_COLOR), EEPROM.read(ADDR_COLOR+1), EEPROM.read(ADDR_COLOR+2));
  // Restore mode from string (not compacted here)
  EEPROM.end();
}

void saveSettings() {
  EEPROM.begin(64);
  EEPROM.write(ADDR_BRIGHT, brightness);
  EEPROM.write(ADDR_COLOR, currentColor.r);
  EEPROM.write(ADDR_COLOR+1, currentColor.g);
  EEPROM.write(ADDR_COLOR+2, currentColor.b);
  EEPROM.commit();
  EEPROM.end();
}

void handleLEDs() {
  if (currentMode == "static") {
    fill_solid(leds, NUM_LEDS, currentColor);
  } else if (currentMode == "pulse") {
    uint8_t val = beatsin8(6, 20, brightness);
    fill_solid(leds, NUM_LEDS, currentColor.nscale8(val));
  } else if (currentMode == "rainbow") {
    static uint8_t hue = 0;
    fill_rainbow(leds, NUM_LEDS, hue++, 7);
  }
  FastLED.setBrightness(brightness);
  FastLED.show();
}

void handleWebSocket(uint8_t client, WStype_t type, uint8_t *payload, size_t len) {
  if (type == WStype_TEXT) {
    DynamicJsonDocument doc(256);
    deserializeJson(doc, payload);

    if (doc.containsKey("mode"))   currentMode = doc["mode"].as<String>();
    if (doc.containsKey("brightness")) brightness = doc["brightness"];
    if (doc.containsKey("color")) {
      String hex = doc["color"];
      long number = strtol(&hex[1], nullptr, 16);
      currentColor = CRGB((number >> 16) & 0xFF, (number >> 8) & 0xFF, number & 0xFF);
    }

    saveSettings();
  }

  // Status push
  StaticJsonDocument<128> res;
  res["brightness"] = brightness;
  res["color"] = "#" + String(currentColor.r, HEX) + String(currentColor.g, HEX) + String(currentColor.b, HEX);
  res["charging"] = digitalRead(CHARGING_PIN) == HIGH;
  String output;
  serializeJson(res, output);
  ws.sendTXT(client, output);
}

void setup() {
  Serial.begin(115200);
  EEPROM.begin(64);
  loadSettings();

  pinMode(CHARGING_PIN, INPUT);
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("WiFi connected.");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });
  server.begin();

  ws.begin();
  ws.onEvent(handleWebSocket);
}

void loop() {
  ws.loop();
  handleLEDs();
}
