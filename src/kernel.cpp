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

void kernel_main()
{
	//Initialize terminal
	terminal_initialize();
	
	terminal_writestring("SquidOS version ", COLOR_WHITE);
	terminal_putchar(int_to_char(VERSION_MAJOR), COLOR_WHITE);
	terminal_putchar('.', COLOR_WHITE);
	terminal_putchar(int_to_char(VERSION_MINOR), COLOR_WHITE);
	terminal_putchar('.', COLOR_WHITE);
	terminal_putchar(int_to_char(VERSION_RELEASE), COLOR_WHITE);
	terminal_writestring(" test test test test test test test test test test test test test test test test test test test test test test test test test test test test ", COLOR_RED);
}

















