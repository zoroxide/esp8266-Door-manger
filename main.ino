#include "door_lock.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <Servo.h>

// Create a web server object
ESP8266WebServer server(80);


void setup() {
  // Initialize Serial port
  Serial.begin(sCommunication);

  // Initialize servo motor
  //doorLock.attach(D1);

  // Set up WiFi access point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Print IP address
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  // Set up routes
  server.on("/", hRoot);
  server.on("/close", hCloseDoor);
  server.on("/open", hOpenDoor);
  server.on("/log", handleLog);
  server.begin();
}

void loop() {
  server.handleClient();
}


