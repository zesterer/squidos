//----STANDARD----

#if !defined(__cplusplus)
	#include "stdbool.h" //C doesn't have bools by default
#endif

#include "stddef.h"
#include "stdint.h"

//----LOCAL----
#include "terminal.h"

//----DEFINES----
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_RELEASE 1

#if defined(__linux__)
	#error "No cross-compiler in use. Cannot compile"
#endif

//Make sure it only compiles with 32-bit x86 targets
#if !defined(__i386__)
	#error "Must be compiled with an i686 elf cross-compiler"
#endif

#if defined(__cplusplus)
	extern "C" //Use C to link kernel_main
#endif

void kernelMain()
{
	//Initialize terminal
	Terminal::initialize();
	
	Terminal::writeString("SquidOS version ", Terminal::VGAColor::WHITE);
	Terminal::writeChar(int_to_char(VERSION_MAJOR), Terminal::VGAColor::WHITE);
	Terminal::writeChar('.', Terminal::VGAColor::WHITE);
	Terminal::writeChar(int_to_char(VERSION_MINOR), Terminal::VGAColor::WHITE);
	Terminal::writeChar('.', Terminal::VGAColor::WHITE);
	Terminal::writeChar(int_to_char(VERSION_RELEASE), Terminal::VGAColor::WHITE);
	Terminal::writeString("\nHello, World!", Terminal::VGAColor::RED);
}

















