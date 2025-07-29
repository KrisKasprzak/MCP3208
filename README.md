
<b><h2><center>Library for the MCP3208, a 14 bit analog to digital converter from Analog Devices</center></h1></b>

This library is itended for microcontroller applications using Teensy (3.x to 4.x),  ESP's, and Arduinos where additional analog inputs or higher resulution inputs are needed. This library supports all the features offered by the LTC1867 such as reading an input channel in single or differential mode, using GND or CH7 as the common pin, and putting the analog to digital converter to sleep to save power between infrequent reads. See the .h file for all the constants to set channels and options.

Perfomance is as follows
<table>
  <tr>
    <th>Data</th>
    <th>MCP3208</th>
    <th>Teensy 4.0</th>
  </tr>
  <tr>
    <td>analogRead</td>
    <td> 17 uS</td>
    <td>  26 uS</td>
  </tr>
</table>

Implentation of this library is straightforward

1. include the library
<br>
#include "MCP3208.h"
<br>
3. create an object instance(s)
<br>
MCP3208 MyADC(CS_PIN);
<br>
5. initialize the object(s)
<br>
bool success = MyADC.init(); // object attempts to return true if successful
<br>
7. call object.analogRead(channel)
<br>
uint16_t thing = MyADC.analogRead(CH0);
<br>
<br>

Typical wiring, note the use of a buffer to shift the output of MISO (DO) to be compatible with 3v3 MCU's

![header image](https://raw.github.com/KrisKasprzak/MCP3208/master/Images/MCP3208_Wiring.jpg)
<br>
<br>
<br>
Noise comparison from the LTC1867 (16 bit), a Cortex M4 (16 bit) and an ESP32 (12 bit as 16 bit is not available). Note that no input filtering was used in this test. shown are 1 average per point and sandwitched between and upper and lower guardrails. The ADC noise performace is improvement over the cortex M4 chip, the ESP32 suffers.
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/Comparison.jpg)
<br>
<br>
Noise from from the LTC1867 (16 bit), a Cortex M4 (16 bit) using analogRead() and analogReadAveraging(). Note that no input filtering was used in this test. Shown are 10 averages per point and sandwitched between and upper and lower guardrail.
![header image](https://raw.github.com/KrisKasprzak/LTC1867/master/images/16bit_10averages.jpg)
<br>






