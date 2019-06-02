#ifndef _NESPAD_HPP_
#define _NESPAD_HPP_

#include "Arduino.h"

class Nespad {
public:
	Nespad(int pin_clk, int pin_latch, int pin_data);
	void read(void);

	union {
		struct {
			unsigned int a : 1;
			unsigned int b : 1;
			unsigned int select : 1;
			unsigned int start : 1;
			unsigned int up : 1;
			unsigned int down : 1;
			unsigned int left : 1;
			unsigned int right : 1;
		};
		uint8_t data;
	} btn;

private:
	int pin_clk;
	int pin_latch;
	int pin_data;
};

#endif /* !_NESPAD_HPP_ */
