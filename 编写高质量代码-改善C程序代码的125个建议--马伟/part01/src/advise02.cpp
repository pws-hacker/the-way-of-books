#include "advise02.h"

void AdviseTwo::test01_error()
{
	char c = 150; // char ���Ϳ������������ͣ�1.�з��ŵ�(signed char)���޷��ŵ�(unsigned char)
	int i = 900;
	// TODO �˽�Ϊʲô������� -8 
	printf("i/c=%d\n", i / c); // -8 
}

void AdviseTwo::test01_right()
{
	unsigned char c = 150;
	int i = 900;
	printf("i/c=%d\n", i / c); // 6
}
