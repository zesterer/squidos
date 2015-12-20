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
