//----LOCAL----
#include "terminal.h"

namespace Terminal
{
	size_t terminal_row;
	size_t terminal_column;
	uint8_t terminal_color;
	uint16_t* terminal_buffer;

	void initialize()
	{
		terminal_row = 0;
		terminal_column = 0;
		terminal_color = makeColor(VGAColor::LIGHT_GREY, VGAColor::BLACK);
		terminal_buffer = (uint16_t*)0xB8000;
	
		for (size_t y = 0; y < VGA_HEIGHT; y ++)
		{
			for (size_t x = 0; x < VGA_WIDTH; x ++)
			{
				const size_t index = y * VGA_WIDTH + x;
				terminal_buffer[index] = makeVGAEntry(' ', terminal_color);
			}
		}
	}
}
