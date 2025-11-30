#include <WiFi.h>
#include <WebServer.h>

// 1. Network Credentials
const char *ssid = "ESP32_Hotspot";
const char *password = "12345678";

// 2. Create a WebServer object on Port 80 (Standard HTTP port)
WebServer server(80);

// 3. Define what happens when someone visits the root URL ("/")
void handleRoot() {
  // Send HTTP status 200 (OK), content type text, and the message
  server.send(200, "text/plain", "Hello World");
}

void setup() {
  Serial.begin(115200);

  // Start the Access Point
  WiFi.softAP(ssid, password);
  
  Serial.println("\nAccess Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // 4. Set up the URL Route
  // When a user visits "/", call the handleRoot function
  server.on("/", handleRoot);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // 5. Check for incoming client requests repeatedly
  server.handleClient();
}