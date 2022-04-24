#pragma once

#include "pico.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define DEBOUNCE_TIME 150
#define LONG_PRESS_TIME 1000

enum class ButtonState
{
	ShortPress, // 0-3 sec
	LongPress,  // 3-unlimited sec
	Holding,
	None		// Not pressed
};

enum class ButtonType
{
	PullUp,
	PullDown
};

class Button
{
private:
	uint8_t pin;
	ButtonType type;

	long lastTime;
	ButtonState state = ButtonState::None;

public:
	Button(uint8_t pin, ButtonType type = ButtonType::PullDown);

	void init();
	void tick();

	ButtonState getState();
};