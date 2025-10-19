
#include "provisioner.h"

void setup() {
    Serial.begin(115200);
    Serial.println("\n  awake...");

    char ssid[32];
    char pass[32];

    provisioner.get_creds(ssid, pass);

    WiFi.mode(WIFI_STA);    // Added 10/18/25 - see README.md
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {}

    Serial.println("\n  connected...");

}

void loop() {}