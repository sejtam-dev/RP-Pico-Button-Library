#include "button_test.h"

Button button(16);

int main()
{
	stdio_init_all();

	while(true)
	{
		button.tick();

		switch(button.getState())
		{
		case ButtonState::ShortPress:
			printf("Short press!\n");
			break;
		case ButtonState::LongPress:
			printf("Long press!\n");
			break;
		}
	}
}