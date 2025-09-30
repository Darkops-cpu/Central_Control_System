#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "TECNO POVA 5 PRO";
const char* password = "123456789";

// Define control pins
#define FORWARD_PIN 12
#define BACKWARD_PIN 13
#define LEFT_PIN 14
#define RIGHT_PIN 27
#define STOP_PIN 26

WebServer server(80);

String activeCommand = "None";

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>ESP32 Control Panel</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<style>button{width:100px;height:50px;margin:5px;font-size:16px;}</style></head><body>";
  html += "<h2>ESP32 Bot Control</h2>";
  html += "<p>Active: <b>" + activeCommand + "</b></p>";
  html += "<form action='/cmd'><button name='cmd' value='FWD'>Forward</button>";
  html += "<button name='cmd' value='BACK'>Backward</button><br>";
  html += "<button name='cmd' value='LEFT'>Left</button>";
  html += "<button name='cmd' value='RIGHT'>Right</button><br>";
  html += "<button name='cmd' value='STOP'>Stop</button></form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void resetPins() {
  digitalWrite(FORWARD_PIN, LOW);
  digitalWrite(BACKWARD_PIN, LOW);
  digitalWrite(LEFT_PIN, LOW);
  digitalWrite(RIGHT_PIN, LOW);
  digitalWrite(STOP_PIN, LOW);
}

void handleCommand() {
  String cmd = server.arg("cmd");
  resetPins();

  if (cmd == "FWD") {
    digitalWrite(FORWARD_PIN, HIGH);
    activeCommand = "Forward";
  } else if (cmd == "BACK") {
    digitalWrite(BACKWARD_PIN, HIGH);
    activeCommand = "Backward";
  } else if (cmd == "LEFT") {
    digitalWrite(LEFT_PIN, HIGH);
    activeCommand = "Left";
  } else if (cmd == "RIGHT") {
    digitalWrite(RIGHT_PIN, HIGH);
    activeCommand = "Right";
  } else if (cmd == "STOP") {
    digitalWrite(STOP_PIN, HIGH);
    activeCommand = "Stop";
  } else {
    activeCommand = "Unknown";
  }

  handleRoot(); // Return to home after action
}

void setup() {
  Serial.begin(115200);

  // Set pin modes
  pinMode(FORWARD_PIN, OUTPUT);
  pinMode(BACKWARD_PIN, OUTPUT);
  pinMode(LEFT_PIN, OUTPUT);
  pinMode(RIGHT_PIN, OUTPUT);
  pinMode(STOP_PIN, OUTPUT);
  resetPins();

  // Connect to WiFi
  WiFi.begin(ssid, password);
Serial.println("Connecting to WiFi...");

unsigned long startAttemptTime = millis();
unsigned long lastPrint = 0;

while (WiFi.status() != WL_CONNECTED) {
  delay(100);

  // Spam status every 1s
  if (millis() - lastPrint > 1000) {
    Serial.print("Still trying... Status: ");
    Serial.println(WiFi.status());
    lastPrint = millis();
  }

  // Timeout after 15 seconds (optional)
  if (millis() - startAttemptTime > 15000) {
    Serial.println("Failed to connect to WiFi. Restarting...");
    ESP.restart();  // try again
  }
}

  Serial.println("\nConnected! IP: ");
  Serial.println(WiFi.localIP());

  // Route handlers
  server.on("/", handleRoot);
  server.on("/cmd", handleCommand);
  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();
}
