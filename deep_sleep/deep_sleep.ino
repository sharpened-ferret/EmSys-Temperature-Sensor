#include <OneWire.h>
#include <DallasTemperature.h>
#include "dotDevice.h"

#define ONE_WIRE_BUS 26

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const char* ssid = "STINKnet2400";
const char* password = "milkfast923";
const char* server = "ws://ec2-52-15-138-171.us-east-2.compute.amazonaws.com:1234"; 
const char* gid = "cag05ijt";

dotDevice ddev(ssid, password, server);

float temp_in_c;
String jsonMsg = "{\"device\": \"cag05ijt\", \"average\":";
String jsonTemps = ", \"values\":[";
float total = 0;
float average;
float current_temp;
unsigned long start_time;
unsigned long temp_time;

void setup() {
  start_time = millis();
  ddev.connect();
  delay(1000);

  for (int i = 0; i < 15; i++) {
    sensors.requestTemperatures();
    current_temp = sensors.getTempCByIndex(0);
    temp_time = millis() - start_time;
    total += current_temp;
    jsonTemps = jsonTemps + "{\"timestamp\": " + temp_time + ", \"value\": " + current_temp + "},";

  }
  sensors.requestTemperatures();
  current_temp = sensors.getTempCByIndex(0);
  temp_time = millis() - start_time;
  total += current_temp;
  jsonTemps = jsonTemps + "{\"timestamp\": " + temp_time + ", \"value\": " + current_temp + "}";
 
  
  average = total / 16;
  jsonMsg = jsonMsg + average + jsonTemps + "]}";
  ddev.sendJSON(jsonMsg);

  delay(1000);
  
  unsigned long sleep_time = (30000 - (millis()-start_time))*1000;
  esp_sleep_enable_timer_wakeup(sleep_time);
  esp_deep_sleep_start();
}

void loop() {}
