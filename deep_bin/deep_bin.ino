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
        char gid[8] = {'c','a','g','0','5','i','j','t'};
        uint16_t cmd = 1;
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
    return (uint16_t)(input * (1 << 8));
}

void setup() {
  start_time = millis();
  ddev.connect();

  
  struct tempStruct message;

  uint16_t testVal = 1;
  message.cmd = testVal;
  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time0 = (uint16_t) temp_time;
  message.value0 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time1 = (uint16_t) temp_time;
  message.value1 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time2 = (uint16_t) temp_time;
  message.value2 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time3 = (uint16_t) temp_time;
  message.value3 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time4 = (uint16_t) temp_time;
  message.value4 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time5 = (uint16_t) temp_time;
  message.value5 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time6 = (uint16_t) temp_time;
  message.value6 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time7 = (uint16_t) temp_time;
  message.value7 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time8 = (uint16_t) temp_time;
  message.value8 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time9 = (uint16_t) temp_time;
  message.value9 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time10 = (uint16_t) temp_time;
  message.value10 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time11 = (uint16_t) temp_time;
  message.value11 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time12 = (uint16_t) temp_time;
  message.value12 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time13 = (uint16_t) temp_time;
  message.value13 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time14 = (uint16_t) temp_time;
  message.value14 = current_temp;

  
  sensors.requestTemperatures();
  current_temp = floatToFixed(sensors.getTempCByIndex(0));
  temp_time = millis() - start_time;
  total += current_temp;
  message.time15 = (uint16_t) temp_time;
  message.value15 = current_temp;
  
  average = total / 16;

  message.avg = (uint16_t) floatToFixed(average);
  ddev.sendBIN((char *)&message, sizeof(tempStruct));

  delay(1000);

  unsigned long sleep_time = ((30000 - (millis()-start_time))*1000);
  esp_sleep_enable_timer_wakeup(sleep_time);
  esp_deep_sleep_start();
}

void loop() {}
