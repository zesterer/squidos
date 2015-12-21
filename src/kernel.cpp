//----STANDARD----
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

/*//Loop <count> times in a way that the compiler won't optimise out
static inline void delay(int32_t count)
{
	asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n" : : [count]"r"(count) : "cc");
}*/

#if defined(__cplusplus)
	extern "C" //Use C to link kernel_main
#endif

void kernelMain()
{
	//Initialize terminal
	Terminal::initialize();
	
	Terminal::writeString("SquidOS version ", Terminal::VGAColor::LIGHT_GREY);
	Terminal::writeChar(int_to_char(VERSION_MAJOR), Terminal::VGAColor::WHITE);
	Terminal::writeChar('.', Terminal::VGAColor::WHITE);
	Terminal::writeChar(int_to_char(VERSION_MINOR), Terminal::VGAColor::WHITE);
	Terminal::writeChar('.', Terminal::VGAColor::WHITE);
	Terminal::writeChar(int_to_char(VERSION_RELEASE), Terminal::VGAColor::WHITE);
	Terminal::writeString("\nHello, World!\n", Terminal::VGAColor::RED);
	
	/*while (true)
	{
		delay(150);
		
		Terminal::writeChar('.', Terminal::VGAColor::GREEN);
	}*/
}

















