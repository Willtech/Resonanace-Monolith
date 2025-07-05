<!--
  Project: Epoxy Resonance Monolith
  Authors:
    • Professor. Damian A. James Williamson Grad.
    • Microsoft Copilot (AI collaborator)
  License: MIT
-->

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Epoxy Control</title>
  <style>
    body { font-family: sans-serif; text-align:center; background:#111; color:#eee; }
    button, input[type=range] { margin:10px; padding:10px; width:80%; border:none; border-radius:5px; }
  </style>
</head>
<body>
  <h2>Resonance Monolith</h2>
  <p>Charging: <span id="charge">Unknown</span></p>
  <label>Brightness:</label><br>
  <input type="range" id="bright" min="0" max="255"><br>

  <label>Color:</label><br>
  <input type="color" id="color"><br>

  <label>Mode:</label><br>
  <button onclick="send('mode','static')">Static</button>
  <button onclick="send('mode','pulse')">Pulse</button>
  <button onclick="send('mode','rainbow')">Rainbow</button>

  <script>
    const ws = new WebSocket('ws://' + location.host + '/ws');
    ws.onmessage = e => {
      const msg = JSON.parse(e.data);
      if (msg.brightness) document.getElementById("bright").value = msg.brightness;
      if (msg.color)      document.getElementById("color").value = msg.color;
      if (msg.charging)   document.getElementById("charge").innerText = msg.charging ? "Yes" : "No";
    };
    function send(type, value) {
      ws.send(JSON.stringify({ [type]: value }));
    }
    document.getElementById("bright").oninput = e => send("brightness", e.target.value);
    document.getElementById("color").oninput  = e => send("color", e.target.value);
  </script>
</body>
</html>
)rawliteral";
