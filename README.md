
<b><h2><center>Library for the MCP3208, a 14 bit analog to digital converter from Microchip</center></h1></b>

This library is itended for microcontroller applications using Teensy (3.x to 4.x),  ESP's, and Arduinos where additional analog inputs are needed. My simple tests show no improvement over noise control but provide a reading slower that at Cortex M4. This is a very basic library offering single ended inputs only.

Perfomance is as follows
<table>
  <tr>
    <th>Data</th>   
    <th>Teensy 4.0</th>
    <th>MCP3208</th>
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
2. create an object instance(s)
<br>
MCP3208 MyADC(CS_PIN);
<br>
3. initialize the object(s)
<br>
bool success = MyADC.init(); // object attempts to return true if successful
<br>
4. call object.analogRead(channel)
<br>
uint16_t thing = MyADC.analogRead(CH0);
<br>
float data = thing * 3.3 / 4096.0f;
<br>
<br>

Typical wiring, note the use of a buffer to shift the output of MISO (DO) to be compatible with 3v3 MCU's

![header image](https://raw.github.com/KrisKasprzak/MCP3208/master/Images/MCP3208_Wiring.jpg)
<br>
<br>
<br>
Noise comparison from the MCP3208 (14 bit), a Cortex M4 (14 bit). Note that no input filtering was used in this test. shown are 1 average per point and sandwitched between and upper and lower guardrails. The ADC noise performace is improvement over the cortex M4 chip, the ESP32 suffers.
![header image](https://raw.github.com/KrisKasprzak/MCP3208/master/Images/MCP3208_Noise.jpg)







