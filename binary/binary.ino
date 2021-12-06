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

float total;
float average;
float current_temp;
unsigned long start_time;
unsigned long temp_time;

struct tempStruct{
        char gid1[4];
        char gid2[4];
        uint16_t cmd;
        uint16_t avg;
        uint16_t time0;
        uint16_t value0;
        uint16_t time1;
        uint16_t value1;
        uint16_t time2;
        uint16_t value2;
        uint16_t time3;
        uint16_t value3;
        uint16_t time4;
        uint16_t value4;
        uint16_t time5;
        uint16_t value5;
        uint16_t time6;
        uint16_t value6;
        uint16_t time7;
        uint16_t value7;
        uint16_t time8;
        uint16_t value8;
        uint16_t time9;
        uint16_t value9;
        uint16_t time10;
        uint16_t value10;
        uint16_t time11;
        uint16_t value11;
        uint16_t time12;
        uint16_t value12;
        uint16_t time13;
        uint16_t value13;
        uint16_t time14;
        uint16_t value14;
        uint16_t time15;
        uint16_t value15;
    } message;

inline uint16_t floatToFixed(double input)
{
    return (uint16_t)(round(input * (1 << 8)));
}

void setup() {
  Serial.begin(115200);
  ddev.connect();
}

void loop() {
  Serial.println("START_LOOP");
  total = 0;
  start_time = millis();
  
  struct tempStruct message;

  uint16_t testVal = 1;
  message.cmd = testVal;
  Serial.println(message.cmd);
  strcpy (message.gid1, "cag0");
  strcpy (message.gid2, "5ijt");
  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time0 = (uint16_t) current_temp;
  message.value0 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time1 = (uint16_t) current_temp;
  message.value1 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time2 = (uint16_t) current_temp;
  message.value2 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time3 = (uint16_t) current_temp;
  message.value3 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time4 = (uint16_t) current_temp;
  message.value4 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time5 = (uint16_t) current_temp;
  message.value5 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time6 = (uint16_t) current_temp;
  message.value6 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time7 = (uint16_t) current_temp;
  message.value7 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time8 = (uint16_t) current_temp;
  message.value8 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time9 = (uint16_t) current_temp;
  message.value9 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time10 = (uint16_t) current_temp;
  message.value10 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time11 = (uint16_t) current_temp;
  message.value11 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time12 = (uint16_t) current_temp;
  message.value12 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time13 = (uint16_t) current_temp;
  message.value13 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time14 = (uint16_t) current_temp;
  message.value14 = (uint16_t) temp_time;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time15 = (uint16_t) current_temp;
  message.value15 = (uint16_t) temp_time;
  
  average = total / 16;

  message.avg = (uint16_t) floatToFixed(average);
  Serial.println("Pre-send");
  Serial.println((char *)&message);

  Serial.println(sizeof(message));
  Serial.println(message.value1);
  ddev.sendBIN((char *)&message, sizeof(tempStruct));
}
