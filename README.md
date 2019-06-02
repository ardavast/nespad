# nespad
Nespad is an Arduino library that can be used to connect to an NES gamepad to an Arduino.

### Example
```cpp
#include <nespad.hpp>

const int pin_pad1_clk = 2;
const int pin_pad1_latch = 3;
const int pin_pad1_data = 4;

Nespad pad1 = Nespad(pin_pad1_clk, pin_pad1_latch, pin_pad1_data);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	pad1.read();

	if (pad1.btn.a)      Serial.println("A");
	if (pad1.btn.b)      Serial.println("B");
	if (pad1.btn.select) Serial.println("select");
	if (pad1.btn.start)  Serial.println("start");
	if (pad1.btn.up)     Serial.println("up");
	if (pad1.btn.down)   Serial.println("down");
	if (pad1.btn.left)   Serial.println("left");
	if (pad1.btn.right)  Serial.println("right");

	delay(100);
}
```
