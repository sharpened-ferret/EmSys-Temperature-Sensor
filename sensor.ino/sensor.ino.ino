#include <OneWire.h>
#include <DallasTemperature.h>
#include "dotDevice.h"

#define ONE_WIRE_BUS 26

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const char* ssid = "NETGEAR35";
const char* password = "magicalfinch482";
const char* server = "ws://192.168.1.2:1234"; 
const char* gid = "cag05ijt";

dotDevice ddev(ssid, password, server);

float temp_in_c;

String jsonMsg;
String jsonTemps;
float total;
float average;
float current_temp;
unsigned long start_time;
unsigned long temp_time;

void setup() {
  Serial.begin(115200);
  ddev.connect();
}

void loop() {
  total = 0;
  start_time = millis();
  jsonMsg = "{\"device\": \"cag05ijt\", \"average\":";
  jsonTemps = ", \"values\":["; 
  
  
  
  for (int i = 0; i < 16; i++) {
    sensors.requestTemperatures();
    current_temp = sensors.getTempCByIndex(0);
    temp_time = millis() - start_time;
    total += current_temp;
    jsonTemps = jsonTemps + "{\"timestamp\": " + temp_time + ", \"value\": " + current_temp + "}";

    if (i < 15) {
      jsonTemps += ", ";  
    }
    
    Serial.println(current_temp);
    delay(1500);
  }
  average = total / 16;
  jsonMsg = jsonMsg + average + jsonTemps + "]}";
  Serial.println("Block Complete!");
  ddev.sendJSON(jsonMsg);
  Serial.println(jsonMsg);  
  
}
