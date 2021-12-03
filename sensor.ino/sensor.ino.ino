#include <OneWire.h>
#include <DallasTemperature.h>
#include "dotDevice.h"

#define ONE_WIRE_BUS 26

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temp_in_c;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensors.requestTemperatures();
  delay(1000);
  temp_in_c = sensors.getTempCByIndex(0);
  Serial.println(temp_in_c);

  
  
}
