#include "Arduino.h"
#include "nespad.hpp"

Nespad::Nespad(int pin_clk, int pin_latch, int pin_data)
{
	this->pin_clk = pin_clk;
	this->pin_latch = pin_latch;
	this->pin_data = pin_data;

	pinMode(this->pin_clk, OUTPUT);
	pinMode(this->pin_latch, OUTPUT);
	pinMode(this->pin_data, INPUT_PULLUP);

	digitalWrite(this->pin_clk, LOW);
	digitalWrite(this->pin_latch, LOW);
}

void Nespad::read(void)
{
	digitalWrite(this->pin_latch, HIGH);
	delayMicroseconds(12);
	digitalWrite(this->pin_latch, LOW);

	// read the first bit
	this->btn.data = digitalRead(this->pin_data);
	delayMicroseconds(6);

	// read the remaining 7 bits
	for (int i = 1; i < 8; i++) {
		digitalWrite(this->pin_clk, HIGH);
		delayMicroseconds(6);

		digitalWrite(this->pin_clk, LOW);
		this->btn.data |= digitalRead(this->pin_data) << i;
		delayMicroseconds(6);
	}

	// invert (data pin is active low)
	this->btn.data = ~(this->btn.data);
}
