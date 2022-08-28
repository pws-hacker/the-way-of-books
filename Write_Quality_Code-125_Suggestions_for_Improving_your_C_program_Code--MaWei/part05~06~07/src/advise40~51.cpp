#include "advise40~51.h"
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

void Advise40::test_04_error(void)
{
	float f = 0.f;
	int i = 0;
	float* fp;
	int* ip;
	// 将 float* 强转为 int*
	ip = (int*)&f;
	fp = (float*)&i;
	printf("i:%d\n", i);  // 输出 i: 0
	printf("f:%f\n", f);  // 输出 f: 0.000000
	(*ip)++;
	(*fp)++;
	printf("i:%d\n", i);  // 输出 i: 1065353216
	printf("f:%f\n", f);  // 输出 f: 0.000000
}

void Advise40::test_04_right(void)
{
	float f = 0.f;
	int i = 0;
	float* fp;
	int* ip;
	// 正确写法
	ip = (int*)&i;
	fp = (float*)&f;
	printf("i:%d\n", i);  // 输出 i: 0
	printf("f:%f\n", f);  // 输出 f: 0.000000
	(*ip)++;
	(*fp)++;
	printf("i:%d\n", i);  // 输出 i: 1
	printf("f:%f\n", f);  // 输出 f: 1.000000
}

void Advise40::test_05_error(void)
{
	struct int32 tmp;
	unsigned char* cp;
	tmp.ui1 = 0;
	tmp.ui2 = 0;
	tmp.ui3 = 0;
	tmp.ui4 = 0;
	cp = (unsigned char*)&tmp;
	(*cp)++;
}

void Advise40::test_05_right(void)
{
	struct int32 tmp;
	tmp.ui1 = 0;
	tmp.ui2 = 0;
	tmp.ui3 = 0;
	tmp.ui4 = 0;
	tmp.ui1++;
}
// "const int* p"   const 修饰的是 *p  ，所以不能通过  *p  修改地址的值
void Advise50::test_01_demo(void)
{
	int i1 = 10;
	int i2 = 20;
	const int* p = &i1;
	printf("%d\n", *p);  // 输出 10
	p = &i2;
	printf("%d\n", *p);  // 输出 20
	i2 = 30;
	printf("%d\n", *p);  // 输出 30
}
// "int* const p"   const 修饰的是 p  ，所以不能修改 p 值，指针常量只能 指向初始化时的内存地址
void Advise50::test_02_demo(void)
{
	int i1 = 10;
	int i2 = 20;
	int* const p = &i1;
	printf("%d\n", *p);  // 输出 10
	// p = &i2;  不能这样赋值了
	printf("%d\n", *p);  // 输出 20
	i2 = 30;
	printf("%d\n", *p);  // 输出 30
}

void Advise50::test_03_demo(void)
{
	const int i = 10;
	int* p;
	p = (int*)&i;  // 强转为 int* 
	printf("*p=%d\n", *p);
	*p = 20;  // 这种是合法的
	printf("i=%d\n", i);
	printf("*p=%d\n", *p);
}

void Advise50::test_04_demo(void)
{
	// "const int i" 与 "int const i"完全相同的概念
	const int i = 10;
	// i++; // 不允许
	int const ii = 10;
	// ii++; // 不允许
}
