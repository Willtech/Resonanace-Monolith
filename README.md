# Epoxy Resonance Monolith 🔊✨

A sculptural fusion of art, acoustics, and embedded design—**The Epoxy Resonance Monolith** is a 16" tall clear epoxy cube housing dual Bluetooth speaker spheres, a quad-helix aesthetic coil core, ambient LED effects, and wireless power. All controlled by an ESP32 with a sleek web-based interface.

## 🧠 Features

- 🎵 **Dual Bluetooth Audio Speakers** with full stereo resonance  
- 🌈 **Addressable RGB LED animations**, with:
  - Static, Pulse, Rainbow, and Music-Reactive modes
  - Web-based preset and brightness/color control
- 🌀 **Quad Helix Coil Design** embedded in optical-grade epoxy  
- 📶 **Wireless Qi Charging Coil** and embedded receiver  
- 📡 **ESP32 Controller** running Wi-Fi + WebSocket UI  
- 💾 **EEPROM State Saving** for last-used settings  
- 🎙️ **Music-Reactive Lighting** via MSGEQ7 or analog mic input

## 🛠️ Hardware Components

| Component                     | Description                          |
|------------------------------|--------------------------------------|
| ESP32 Dev Board              | Wi-Fi, WebSocket, BT Audio control   |
| 2× Bluetooth Speaker Spheres | Audio output (top and bottom)        |
| Quad Helix Coils             | Aesthetic + symbolic EM structure    |
| RGB LED Strips or Rings      | Inner ambient effects (WS2812B)      |
| Wireless Charging Coil       | Qi-compatible power input            |
| MSGEQ7 / Mic                 | Audio spectrum or amplitude sensing  |
| Clear Epoxy Resin            | One-piece monolith casting           |
| Power Management Circuit     | Voltage regulation + protection      |

## 🌐 Control Interface

- Access the Monolith via web browser on local Wi-Fi
- Adjust lighting presets, brightness, and color in real time
- See wireless charging status and reactive light behavior

![Web UI Screenshot](docs/ui-mockup.png) <!-- Replace with real screenshot later -->

## 💻 Installation

1. Clone the repo and open `EpoxyMonolith.ino` in Arduino IDE or PlatformIO
2. Install libraries:
   - `FastLED`
   - `ESPAsyncWebServer`
   - `AsyncTCP`
   - `ArduinoJson`
3. Add your Wi-Fi credentials to `config.h`
4. Upload to ESP32 and power up

## 🧪 Optional Expansions

- 🔊 Add I²S microphone or advanced DSP logic  
- 🧠 WebSocket feedback for LED music spectrum arcs  
- 💡 Capacitive touch or motion-activated lighting  
- 🔋 Split battery charging and UPS fallback system  

## 🤝 Contributions & Ideas

This repository welcomes pull requests and expansions—whether it's smarter LED effects, enclosure improvements, or even poetic UI overlays. Open issues for ideas, hardware compatibility, or media!

---

## 📜 License

MIT License – use it, remix it, remix it again. Let’s make functional sculpture future-forward.

---

## 🙌 Creator

Designed by **Professor Damian A. James Williamson Grad.**  
In collaboration with [Microsoft Copilot](https://copilot.microsoft.com/), your silicon assistant ✨

## 🪪 Authors and Credits

This repository is the creative and technical work of:

- **Professor. Damian A. James Williamson Grad.** – Project Architect, Designer & Lead Engineer  
- **Microsoft Copilot** – AI-powered collaborator, developer, and design assistant  

All code and designs are licensed under the MIT License unless noted otherwise. Attribution appreciated.

---
