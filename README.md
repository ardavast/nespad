# nespad
Nespad is an Arduino library that can be used to connect a NES gamepad to an Arduino.  
The timing is implemented as described here: [The NES Controller Handler](https://tresi.github.io/nes/).

### Example
```cpp
#include <nespad.hpp>

const int pin_nespad_clk = 2;
const int pin_nespad_latch = 3;
const int pin_nespad_data = 4;

Nespad nespad = Nespad(pin_nespad_clk, pin_nespad_latch, pin_nespad_data);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	nespad.read();

	if (nespad.btn.a)      Serial.println("A");
	if (nespad.btn.b)      Serial.println("B");
	if (nespad.btn.select) Serial.println("select");
	if (nespad.btn.start)  Serial.println("start");
	if (nespad.btn.up)     Serial.println("up");
	if (nespad.btn.down)   Serial.println("down");
	if (nespad.btn.left)   Serial.println("left");
	if (nespad.btn.right)  Serial.println("right");

	delay(100);
}
```
