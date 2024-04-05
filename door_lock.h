#include <FS.h> // Include the SPIFFS library

#define sCommunication 115200
#define ssid "door lock" // SSID
#define password "123456789"


// Handle root page
void hRoot();
// Handle opening the door
void hOpenDoor();

void hCloseDoor();

void handleLog();

String readLogFile();

void logEvent(String event);
