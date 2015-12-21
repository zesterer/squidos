//----LOCAL----
#include "terminal.h"

namespace SquidOS
{
	namespace Kernel
	{
		namespace Terminal
		{
			uint8_t Terminal::makeColor(VGAColor fg, VGAColor bg)
			{
				return fg | bg << 4;
			}
	
			uint16_t Terminal::makeVGAEntry(char c, uint8_t color)
			{
				uint16_t c16 = c;
				uint16_t color16 = color;
				return c16 | color16 << 8;
			}
	
			void Terminal::initialize()
			{
				terminal_row = 0;
				terminal_column = 0;
				terminal_color = makeColor(VGAColor::LIGHT_GREY, VGAColor::BLACK);
				terminal_buffer = (uint16_t*)VGA_MEMORY;
	
				for (size_t y = 0; y < VGA_HEIGHT; y ++)
				{
					for (size_t x = 0; x < VGA_WIDTH; x ++)
					{
						const size_t index = y * VGA_WIDTH + x;
						terminal_buffer[index] = makeVGAEntry(' ', terminal_color);
					}
				}
			}
	
			void Terminal::setColor(uint8_t color)
			{
				terminal_color = color;
			}
	
			void Terminal::putEntryAt(char c, uint8_t color, size_t x, size_t y)
			{
				const size_t index = y * VGA_WIDTH + x;
				terminal_buffer[index] = makeVGAEntry(c, color);
			}
	
			void Terminal::writeChar(char c, VGAColor fg)
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
	
			void Terminal::writeString(const char* str, VGAColor fg)
			{
				size_t datalen = C::strlen(str);
	
				for (size_t i = 0; i < datalen; i ++)
					writeChar(str[i], fg);
			}
	
			void Terminal::printTest(const char* str, bool success)
			{
		
				writeChar('[', VGAColor::WHITE);
		
				if (success)
					writeString("SUCCESS", VGAColor::GREEN);
				else
					writeString("FAILURE", VGAColor::RED);
		
				writeString("] ", VGAColor::WHITE);
				writeString(str, VGAColor::WHITE);
				writeChar('\n', VGAColor::WHITE);
			}
		}
	}
}
