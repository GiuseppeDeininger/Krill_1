#ifndef KRILL_1_SERVER_H
#define KRILL_1_SERVER_H

#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncUDP.h>
#else
  #include <ESP8266WiFi.h>
  #include <WiFiUdp.h>
#endif

#define ssid "RoboValley"
#define password "3exdyw:NRTY9dcs"
// #define ssid "Ziggo4458759"
// #define password "xw6Rstjjncqj"

extern AsyncUDP udp;

void startWiFi();

#endif