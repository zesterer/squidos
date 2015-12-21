//----LOCAL----
#include "std.h"

namespace SquidOS
{
	namespace Kernel
	{
		namespace C
		{
			char int_to_char(uint8_t v)
			{
				return (char)(48 + v % 10);
			}

			size_t strlen(const char* str)
			{
				size_t ret = 0;
				while (str[ret] != 0)
					ret ++;
				return ret;
			}
			
			void wait(uint32_t time)
			{
				volatile uint32_t i = time;
				while (i != 0)
					i --;
			}
		}
	}
}
