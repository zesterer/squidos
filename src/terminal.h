#ifndef TERMINAL_H
#define TERMINAL_H

//----STANDARD----
#include "stddef.h"
#include "stdint.h"

//----LOCAL----
#include "string.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

namespace Terminal
{
	extern size_t terminal_row;
	extern size_t terminal_column;
	extern uint8_t terminal_color;
	extern uint16_t* terminal_buffer;

	enum VGAColor
	{
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		BROWN = 6,
		LIGHT_GREY = 7,
		DARK_GREY = 8,
		LIGHT_BLUE = 9,
		LIGHT_GREEN = 10,
		LIGHT_CYAN = 11,
		LIGHT_RED = 12,
		LIGHT_MAGENTA = 13,
		LIGHT_BROWN = 14,
		WHITE = 15,
	};

	inline uint8_t makeColor(VGAColor fg, VGAColor bg)
	{
		return fg | bg << 4;
	}

	inline uint16_t makeVGAEntry(char c, uint8_t color)
	{
		uint16_t c16 = c;
		uint16_t color16 = color;
		return c16 | color16 << 8;
	}

	extern void initialize();

	inline void setColor(uint8_t color)
	{
		terminal_color = color;
	}

	inline void putEntryAt(char c, uint8_t color, size_t x, size_t y)
	{
		const size_t index = y * VGA_WIDTH + x;
		terminal_buffer[index] = makeVGAEntry(c, color);
	}

	inline void writeChar(char c, VGAColor fg)
	{
		switch (c)
		{
			case '\n':
				terminal_row ++;
				terminal_column = 0;
				break;
		
			default:
				putEntryAt(c, fg, terminal_column, terminal_row);
				terminal_column ++;
				break;
		}
	
		if (terminal_column == VGA_WIDTH)
		{
			terminal_column = 0;
			terminal_row ++;
		}
	
		if (terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}

	inline void writeString(const char* data, VGAColor fg)
	{
		size_t datalen = strlen(data);
	
		for (size_t i = 0; i < datalen; i ++)
			writeChar(data[i], fg);
	}
}

#endif
