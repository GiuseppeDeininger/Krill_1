#ifndef KRILL_1_SERVER_H
#define KRILL_1_SERVER_H

#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncUDP.h>
#else
  #include <ESP8266WiFi.h>
  #include <WiFiUdp.h>
#endif

#define ssid "Krill_1"
#define password "RIPangler2"
// #define ssid "OnePlus 5"
// #define password "1a0semo9"
// #define ssid "RoboValley"
// #define password "3exdyw:NRTY9dcs"
// #define ssid "Ziggo4458759"
// #define password "xw6Rstjjncqj"

extern AsyncUDP udp;
extern WiFiServer server;

void startWiFi();

#endif