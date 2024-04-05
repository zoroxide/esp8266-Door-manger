#include "door_lock.h"
#include <FS.h> // Include the SPIFFS library

String doorLog = "";

void hRoot(){
    String html = "<html><body>";
    // Add HTML content here for displaying users and open button
    html += "<a href='/log'>View Log</a><br>";
    html += "<a href='/open'>Open Door</a><br>";
    html += "<a href='/close'>Close Door</a><br>";
    html += "</body></html>";
    server.send(200, "text/html", html);
}

void hOpenDoor() {
  // Code to open the door
  // doorLock.write(90); // Adjust angle as per your servo motor
  digitalWrite(LED_BUILTIN, HIGH);
  // Log the event
  logEvent("Door opened\n");

  server.send(200, "text/plain", "Door opened");
}

void hCloseDoor(){
  // doorLock.write(0);
  digitalWrite(LED_BUILTIN, LOW);
  // Log the event
  logEvent("Door Closed\n");

  server.send(200, "text/plain", "Door closed");
}

// Handle log page
void handleLog() {
  String logContent = readLogFile();
  server.send(200, "text/plain", logContent);
}

// Function to log an event to the file
void logEvent(String event) {
  File file = SPIFFS.open(logFilePath, "a");
  if (!file) {
    Serial.println("Failed to open log file for writing");
    return;
  }
  file.println(event);
  file.close();
}

// Function to read the log file
String readLogFile() {
  String content = "";
  File file = SPIFFS.open(logFilePath, "r");
  if (!file) {
    Serial.println("Failed to open log file for reading");
    return content;
  }
  while (file.available()) {
    content += (char)file.read();
  }
  file.close();
  return content;
}