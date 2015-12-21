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
			this->terminal.initialize();
		
			//Initialize terminal
			terminal.printTest("Started kernel", true);
			terminal.printTest("Initialized terminal", true);
	
			terminal.writeString("SquidOS v ", Terminal::VGAColor::LIGHT_GREY);
			terminal.writeChar(C::int_to_char(VERSION_MAJOR), Terminal::VGAColor::WHITE);
			terminal.writeChar('.', Terminal::VGAColor::WHITE);
			terminal.writeChar(C::int_to_char(VERSION_MINOR), Terminal::VGAColor::WHITE);
			terminal.writeChar('.', Terminal::VGAColor::WHITE);
			terminal.writeChar(C::int_to_char(VERSION_RELEASE), Terminal::VGAColor::WHITE);
			terminal.writeChar('\n', Terminal::VGAColor::WHITE);
	
			terminal.writeString("> Welcome to SquidOS\n", Terminal::VGAColor::RED);
			terminal.writeString("> If you see this text, then congratulations. The kernel booted correctly\n", Terminal::VGAColor::GREEN);
			terminal.writeString("> If you don't see this text, something went horribly wrong.\n", Terminal::VGAColor::GREEN);
		}
	}
}
