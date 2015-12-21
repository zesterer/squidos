#ifndef KERNEL_TERMINAL_TERMINAL_H
#define KERNEL_TERMINAL_TERMINAL_H

//----LOCAL----
#include "c/std.h"

namespace SquidOS
{
	namespace Kernel
	{
		namespace Terminal
		{
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
	
			static const size_t VGA_WIDTH = 80;
			static const size_t VGA_HEIGHT = 25;
			static const uint16_t* VGA_MEMORY = (uint16_t*)0xB8000;
	
			struct Terminal
			{
				size_t terminal_row;
				size_t terminal_column;
				uint8_t terminal_color;
				uint16_t* terminal_buffer;
		
				uint8_t makeColor(VGAColor fg, VGAColor bg);
				inline uint16_t makeVGAEntry(char c, uint8_t color);
				void initialize();
				void setColor(uint8_t color);
				void putEntryAt(char c, uint8_t color, size_t x, size_t y);
				void writeChar(char c, VGAColor fg);
				void writeString(const char* str, VGAColor fg);
				void printTest(const char* str, bool success = true);
			};
		}
	}
}

#endif
