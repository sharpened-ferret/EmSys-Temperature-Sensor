#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 26

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));

  
  delay(1000);
}
