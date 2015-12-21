//----LOCAL----
#include "terminal.h"

namespace SquidOS
{
	namespace Kernel
	{
		namespace Terminal
		{
			void Terminal::initialize()
			{
				terminal_row = 0;
				terminal_column = 0;
				terminal_buffer = (uint16_t*)VGA_MEMORY;
	
				//Zero out the VGA screen
				for (size_t y = 0; y < VGA_HEIGHT; y ++)
				{
					for (size_t x = 0; x < VGA_WIDTH; x ++)
					{
						const size_t index = y * VGA_WIDTH + x;
						terminal_buffer[index] = 0x0000;
					}
				}
			}
			
			void Terminal::setForeColor(size_t x, size_t y, VGAColor color)
			{
				if (color == VGAColor::TRANSPARENT)
					return;
				
				const size_t index = y * VGA_WIDTH + x;
				terminal_buffer[index] &= 0xF0FF;
				terminal_buffer[index] |= color << 8;
			}
			
			void Terminal::setBackColor(size_t x, size_t y, VGAColor color)
			{
				if (color == VGAColor::TRANSPARENT)
					return;
				
				const size_t index = y * VGA_WIDTH + x;
				terminal_buffer[index] &= 0x0FFF;
				terminal_buffer[index] |= color << 12;
			}
			
			void Terminal::setCharacter(size_t x, size_t y, char character)
			{
				const size_t index = y * VGA_WIDTH + x;
				terminal_buffer[index] &= 0xFF00;
				terminal_buffer[index] |= character;
			}
			
			void Terminal::setText(size_t x, size_t y, char character, VGAColor fore, VGAColor back)
			{
				this->setCharacter(x, y, character);
				this->setForeColor(x, y, fore);
				this->setBackColor(x, y, back);
			}
	
			void Terminal::writeChar(char c, VGAColor fore, VGAColor back)
			{
				switch (c)
				{
					case '\n':
						terminal_row ++;
						terminal_column = 0;
						break;
		
					default:
						this->setText(terminal_column, terminal_row, c, fore, back);
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
	
			void Terminal::writeString(const char* str, VGAColor fore, VGAColor back)
			{
				size_t datalen = C::strlen(str);
	
				for (size_t i = 0; i < datalen; i ++)
					writeChar(str[i], fore, back);
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
