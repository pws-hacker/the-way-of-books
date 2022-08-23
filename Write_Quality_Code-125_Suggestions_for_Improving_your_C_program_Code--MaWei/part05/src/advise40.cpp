#include "advise40.h"
#include <stdio.h>
#include <stdlib.h>

void Advise40::test_01_error()
{
	//int* p;
	//printf("%x\n", p); // vs 编译报错  有可能是 Release 模式输出64144714 ，Debug 模式下输出 cccccccc
}

void Advise40::test_02_demo()
{
	char a[20] = "qwertyuiopasdfghijl";
	int* p = (int*)a;
	// 编译器这样处理：把指针p的值加上 sizeof(int) ,int 占 4 字节，所以被加上了4.即p所指向的地址由原来的变量a的地址向高地址方向增加了4字节
	// 由于 char 类型的长度是一个字节，所以语句输出 tyuiopasdfghijl
	p++;  
	printf("%s\n", p);
}

double* Advise40::test_03_error(size_t num)
{
	double* arr = NULL;
	if (num > SIZE_MAX / sizeof(arr))
	{
		// 处理 num > SIZE_MAX / sizeof(arr)
	}
	else
	{
		// 这里 sizeof 的是指针的长度，而应该是指针指向类型的长度
		// 正确写法 		arr = (double*)malloc(sizeof(double) * num);
		// 或者 sizeof(*arr) 返回 arr 所引用的数据结构的长度
		arr = (double*)malloc(sizeof(arr) * num);
		if (arr = NULL)
		{
			// 处理 arr == NULL
		}
	}
	return arr;
}
