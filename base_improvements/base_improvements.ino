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

String jsonMsg;
String jsonTemps;
float total;
float average;
float current_temp;
unsigned long start_time;
unsigned long temp_time;

void setup() {
  ddev.connect();
}


//Removed serial printouts and eliminated if statement
void loop() {
  total = 0;
  start_time = millis();
  jsonMsg = "{\"device\": \"cag05ijt\", \"average\":";
  jsonTemps = ", \"values\":["; 
  
  
  for (int i = 0; i < 15; i++) {
    sensors.requestTemperatures();
    current_temp = sensors.getTempCByIndex(0);
    temp_time = millis() - start_time;
    total += current_temp;
    jsonTemps = jsonTemps + "{\"timestamp\": " + temp_time + ", \"value\": " + current_temp + "},";
    delay(1244);
  }
  sensors.requestTemperatures();
  current_temp = sensors.getTempCByIndex(0);
  temp_time = millis() - start_time;
  total += current_temp;
  jsonTemps = jsonTemps + "{\"timestamp\": " + temp_time + ", \"value\": " + current_temp + "}";
  delay(1500);
  
  average = total / 16;
  jsonMsg = jsonMsg + average + jsonTemps + "]}";
  ddev.sendJSON(jsonMsg);
}
