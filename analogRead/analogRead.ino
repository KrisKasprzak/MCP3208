/*

Simple example on using this library

connection
CAUTION MISO will output approx 4.8 volts and will destroy the input pin or a Teensy 4.x (pins are not 5v tolerant)

MPC3208         Teensy
Vdd             3v3
GND             GND
SDI             MOSI (pin 11)
SDO             MISO (pin 12)
SCK             SCL (pin 13)
CS              PIN 10 (your choice)
Vref            3v3
CH0             center of a 10K pot across 3v3 and GND

*/
#include "MCP3208.h"

#define CS_PIN 16

MCP3208 MyADC(CS_PIN);  // my chip select pin

void setup() {

  Serial.begin(9600);

  while (!Serial) {
    delay(100);
  }
  analogReadResolution(14);

  delay(1000);

  Serial.print("ADC.init() success: ");  // just sets some defaults
  Serial.println(MyADC.init());          // just sets some defaults

  Serial.print("MyADC read time (us): ");
  uint32_t timer = micros();
  MyADC.analogRead(CH0);
  Serial.println(micros() - timer);

  Serial.print("Teensy read time (us): ");
  timer = micros();
  analogRead(A0);
  Serial.println(micros() - timer);

  delay(1000);
}

void loop() {


  // uncomment to see MyADC noise vs MCU

  /*
  Serial.print(0);
  Serial.print(",");
  Serial.print(3.3);
  Serial.print(",");
  Serial.print(analogRead(A0) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH2) * 3.3 / 4096.0, 5);
  Serial.print(",");
*/
  Serial.print(analogRead(A6) * 2.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH0) * 3.3 / 4096.0, 5;
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH1) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH2) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH3) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH4) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH5) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.print(MyADC.analogRead(CH6) * 3.3 / 4096.0, 5);
  Serial.print(",");
  Serial.println(MyADC.analogRead(CH7) * 3.3 / 4096.0, 5);

  Serial.println();
  delay(200);
}
