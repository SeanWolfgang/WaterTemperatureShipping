#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <ds3231.h>

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
  // Begin serial monitor since code is still being tested with monitor
  Serial.begin(9600);

  // Initialize RTC module
  DS3231_init(DS3231_CONTROL_INTCN);
  
  // Initialize temperature sensors
  beginTemperatureSensors();
}

void loop() {
  // Each loop, request and print sensor data
  requestSensorTemperatures();
  printSensorTemperatures();
  Serial.print("\n");
}

void beginTemperatureSensors() {
  // For the time, each sensor must be initialized by calling variables verbosely
  // Consider implementations to begin sensor groups programatically to make code more easily adaptable
  tempSensor_1.begin();
  tempSensor_2.begin();
  tempSensor_3.begin();
  tempSensor_4.begin();
  tempSensor_5.begin();
}

void requestSensorTemperatures() {
  // For the time, each sensor's output must be requested by calling variables verbosely
  // Consider implementations to request sensor data programatically to make code more easily adaptable
  tempSensor_1.requestTemperatures();
  tempSensor_2.requestTemperatures();
  tempSensor_3.requestTemperatures();
  tempSensor_4.requestTemperatures();
  tempSensor_5.requestTemperatures();
}

void printSensorTemperatures() {
  // Print each sensor's output in a human readable format
  // Consider implementations to print sensor data programatically to make code more easily adaptable
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
