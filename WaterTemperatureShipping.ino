#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_1 2
#define ONE_WIRE_BUS_2 3
#define ONE_WIRE_BUS_3 4
#define ONE_WIRE_BUS_4 5
#define ONE_WIRE_BUS_5 6

OneWire oneWire_temp1(ONE_WIRE_BUS_1);
OneWire oneWire_temp2(ONE_WIRE_BUS_2);
OneWire oneWire_temp3(ONE_WIRE_BUS_3);
OneWire oneWire_temp4(ONE_WIRE_BUS_4);
OneWire oneWire_temp5(ONE_WIRE_BUS_5);

DallasTemperature tempSensor_1(&oneWire_temp1);
DallasTemperature tempSensor_2(&oneWire_temp2);
DallasTemperature tempSensor_3(&oneWire_temp3);
DallasTemperature tempSensor_4(&oneWire_temp4);
DallasTemperature tempSensor_5(&oneWire_temp5);

/* At 76.2 air temperature, following errors were noted
 * Sensor 1: +1.70
 * Sensor 2: -0.66
 * Sensor 3: -0.33
 * Sensor 4: +1.36
 * Sensor 5: +0.24
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Dallas Temperature Control Library Demo - TwoPin_DS18B20");

  beginTemperatureSensors();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\n");
  requestSensorTemperatures();
  printSensorTemperatures();
}

void beginTemperatureSensors() {
  tempSensor_1.begin();
  tempSensor_2.begin();
  tempSensor_3.begin();
  tempSensor_4.begin();
  tempSensor_5.begin();
}

void requestSensorTemperatures() {
  tempSensor_1.requestTemperatures();
  tempSensor_2.requestTemperatures();
  tempSensor_3.requestTemperatures();
  tempSensor_4.requestTemperatures();
  tempSensor_5.requestTemperatures();
}

void printSensorTemperatures() {
  Serial.print("Sensor 1: ");
  Serial.println(tempSensor_1.getTempCByIndex(0) * 9/5 + 32);

  Serial.print("Sensor 2: ");
  Serial.println(tempSensor_2.getTempCByIndex(0) * 9/5 + 32);

  Serial.print("Sensor 3: ");
  Serial.println(tempSensor_3.getTempCByIndex(0) * 9/5 + 32);

  Serial.print("Sensor 4: ");
  Serial.println(tempSensor_4.getTempCByIndex(0) * 9/5 + 32);

  Serial.print("Sensor 5: ");
  Serial.println(tempSensor_5.getTempCByIndex(0) * 9/5 + 32);
}
