#include <Krill_1_Server.h>
#include <SPIFFS.h>

AsyncUDP udp;
WiFiServer server(80);

void startWiFi() {
    // WiFi.mode(WIFI_STA);
    // WiFi.begin(ssid, password);
    // if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    //     Serial.println("WiFi Failed");
    //     while(1) {
    //         delay(1000);
    //     }
    // }

    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
    
    server.begin();

    if(udp.listen(1234)) {
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
    }
}