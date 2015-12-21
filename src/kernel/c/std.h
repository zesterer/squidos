#ifndef KERNEL_C_STD_H
#define KERNEL_C_STD_H

//----STANDARD----
#include "stddef.h"
#include "stdint.h"

namespace SquidOS
{
	namespace Kernel
	{
		namespace C
		{
			extern char int_to_char(uint8_t v);

			extern size_t strlen(const char* str);
		}
	}
}

#endif
