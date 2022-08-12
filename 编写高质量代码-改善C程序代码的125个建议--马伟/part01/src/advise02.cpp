#include "advise02.h"

void AdviseTwo::test01_error()
{
	char c = 150; // char 类型可以有两种类型：1.有符号的(signed char)和无符号的(unsigned char)
	int i = 900;
	// TODO 了解为什么结果会是 -8 
	printf("i/c=%d\n", i / c); // -8 
}

void AdviseTwo::test01_right()
{
	unsigned char c = 150;
	int i = 900;
	printf("i/c=%d\n", i / c); // 6
}
