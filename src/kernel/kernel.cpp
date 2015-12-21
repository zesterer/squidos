//----LOCAL----
#include "kernel.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_RELEASE 1


namespace SquidOS
{
	namespace Kernel
	{
		void Kernel::initialize()
		{
			//Initialize terminal
			this->terminal.initialize();
			
			terminal.printTest("Bootstrap initialization", true);
			terminal.printTest("Kernel instancing", true);
			terminal.printTest("Terminal initialization", true);
	
			terminal.writeString("SquidOS v", Terminal::VGAColor::WHITE, Terminal::VGAColor::BLACK);
			terminal.writeChar(C::int_to_char(VERSION_MAJOR), Terminal::VGAColor::WHITE, Terminal::VGAColor::BLACK);
			terminal.writeChar('.', Terminal::VGAColor::WHITE, Terminal::VGAColor::BLACK);
			terminal.writeChar(C::int_to_char(VERSION_MINOR), Terminal::VGAColor::WHITE);
			terminal.writeChar('.', Terminal::VGAColor::WHITE, Terminal::VGAColor::BLACK);
			terminal.writeChar(C::int_to_char(VERSION_RELEASE), Terminal::VGAColor::WHITE, Terminal::VGAColor::BLACK);
			terminal.writeChar('\n', Terminal::VGAColor::WHITE, Terminal::VGAColor::BLACK);
	
			terminal.writeString("> Welcome to SquidOS\n", Terminal::VGAColor::RED);
			terminal.writeString("> If you see this text, then congratulations. The kernel booted correctly\n", Terminal::VGAColor::GREEN);
			terminal.writeString("> If you don't see this text, something went horribly wrong.\n", Terminal::VGAColor::GREEN);
			
			while (true)
			{
				C::wait(64000000);
				terminal.writeChar('.', Terminal::VGAColor::LIGHT_BLUE);
			}
		}
	}
}
