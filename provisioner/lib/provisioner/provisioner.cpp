
#include "provisioner.h"
#include "html.h"

Provisioner::Provisioner() {}
Provisioner provisioner;

void Provisioner::get_creds(char * ssid, char * pass) {
    _start_provisioner();
    _wait_for_completion();
    strcpy(ssid, _ssid);
    strcpy(pass, _pass);
}

void Provisioner::_start_provisioner() {

    Serial.println("\n  >> entering provisioning mode...\n");

    WiFi.mode(WIFI_AP);
    WiFi.softAP(AP_SSID);

    _web_server.on("/", [this]() {
        Serial.println("\t.. base route hit");
        _web_server.send(200, "text/html", CONFIG_PAGE);
    });

    _web_server.on("/save", [this]() {

        Serial.println("\t.. save route hit");

        strcpy(_ssid, _web_server.arg("ssid").c_str());
        strcpy(_pass, _web_server.arg("pass").c_str());

        Serial.print("\n\tnew SSID: "); Serial.println(_ssid);
        Serial.print("\tnew PASS: ");   Serial.println(_pass);

        if (strlen(_ssid) < 4 || strlen(_pass) < 4) {
            Serial.println("\t.. error - SSID or password failed validation");
            _web_server.send(200, "text/html", INSTRUCTIONS_PAGE);
        } else {
            _provisioning_complete = true;
            _web_server.send(200, "text/html", SAVED_PAGE);
        }

    });

    _web_server.on("/favicon.ico", [this]() { _web_server.send(200); });
    _web_server.begin();

    // these four lines below were added after the video was made
    
    Serial.print("     attach to network:    ");
    Serial.println(AP_SSID);

    Serial.print("     navigate browser to:  ");
    Serial.println(WiFi.softAPIP());

}

void Provisioner::_wait_for_completion() {
    while (!_provisioning_complete) {
        _web_server.handleClient();
        delay(100);
    }
    Serial.println("\n  >> exiting provisioning mode...");
}