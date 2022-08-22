#include "advise02.h"
#include <stdlib.h>
#include <string.h>

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

char* AdviseTwo::test02_error_copy(size_t n, const char* str)
{
	int i;
	char* p;
	if (n == 0)
	{
		/* 处理 n == 0 的情况 */
	}
	p = (char*)malloc(n); 
	if (p == NULL)
	{
		/* 处理 p == NULL 的情况 */
	}
	for (i = 0; i < n; ++i) // 当 p 所引用的动态分配的缓冲区在 n > INT_MAX 时将会发生溢出
	{
		p[i] = *str++;  // 当 INT_MAX < N <= SIZE_MAX ，且整型变量 i 的增值超过 INT_MAX 时， i 的值将是从 INT_MIN 开始的负值
	}
	return p;
}

char* AdviseTwo::test02_right1_copy(size_t n, const char* str)
{
	size_t i;
	char* p;
	if (n == 0 || n > SIZE_MAX)
	{
		/* 处理 n == 0 的情况 */
	}
	p = (char*)malloc(n);
	if (p == NULL)
	{
		/* 处理 p == NULL 的情况 */
	}
	for (i = 0; i < n; ++i)
	{
		p[i] = *str++; 
	}
	return p;
}

char* AdviseTwo::test02_right2_copy(size_t n, const char* str)
{
	rsize_t i;
	char* p;
	if (n == 0 || n > RSIZE_MAX)
	{
		/* 处理 n == 0 的情况 || n > RSIZE_MAX 的情况 */
	}
	p = (char*)malloc(n);
	if (p == NULL)
	{
		/* 处理 p == NULL 的情况 */
	}
	for (i = 0; i < n; ++i)
	{
		p[i] = *str++;
	}
	return p;
}

void AdviseTwo::test03_error()
{
	unsigned int x;
	size_t y;
	/*
		size_t 类型在不同的平台上很可能代表的是 unsigned int、unsigned long int、unsigned long long int类型
		当代表 unsigned int 时 不会出什么问题，但是当是其他类型时
		执行 "x = y" 时，可能把 y 的高位给截掉，从而导致结果出错。
	*/
	//x = y;

}

void AdviseTwo::test04_error()
{
	int array[] = { 1,2,3,4,5,6 }; // 一个整型 4 个字节
	int i = -1; // -1 在32位机器上存储为 0xffffffff ，而它被解释为无符号整数时就是2^32 - 1,即 4294967295
	if (i <= sizeof(array)) // 当有符号整数和无符号整数类型进行运算时，有符号整数类型会先自动转化成无符号整数类型(特别注意)
	{
		printf("i <= sizeof (array) \n");
	}
	else
	{
		printf("i > sizeof (array) \n");
	}
}

void AdviseTwo::test04_right()
{
	int array[] = { 1,2,3,4,5,6 }; // 一个整型 4 个字节
	int i = -1;
	if (i <= (int)sizeof(array)) // 强转为 int
	{
		printf("i <= sizeof (array) \n");
	}
	else
	{
		printf("i > sizeof (array) \n");
	}
}

void AdviseTwo::test05_error_demo1()
{
	unsigned int a = 4294967295;
	unsigned int b = 2;
	unsigned int c = 4;
	printf("%u\n", a + b); // %u 无符号十进制整型 // 向下回绕 1
	printf("%u\n", b - c);// 向上回绕 4294967294
}

void AdviseTwo::test05_error_demo2(int argc ,char* argv[])
{
	unsigned short s; // unsigned short 能够存储的最大十进制数是 (0 ~ 65535)
	int i;
	char buf[100];
	if (argc < 3)
		return;
	i = atoi(argv[1]);  // 如果传进来 65536
	s = i;              // 这里就会产生回绕，从而 s 实际为 0
	if (s >= 100)       // 从而 没有被过滤
	{
		printf("拷贝字节数太大，请退出！\n");
		return;
	}
	printf("s = %d\n", s);
	memcpy(buf, argv[2], i);  // 65536 传进来导致程序崩溃 因为 buf 初始化为 buf[100]
	buf[i] = '\0';
	printf("成功拷贝%d个字节\n", i);
	printf("buf=%s\n", buf);

}

int* copyarray(int* arr, int len)
{
	int i = 0;
	// 由于 len = 1073741824 ,运算后产生无符号整数运算回绕，所得结果为 0x0，即为 newarray 分配的内存为 0
	int* newarray = (int*)malloc(len * sizeof(int)); 
	if (newarray == NULL)
	{
		// 处理 newarray == NULL 的情况
	}
	printf("为 newarray 成功分配%d字节内存\n", len * sizeof(int));
	printf("循环运行次数:%d (0x%x) \n", len, len);
	for (i = 0; i < len; i++)
	{
		newarray[i] = arr[i];
	}
	return newarray;
}
void AdviseTwo::test05_error_demo3(int argc, char* argv[])
{
	int arr[] = { 1,2,3,4,5 };
	copyarray(arr, atoi(argv[1]));
}

void AdviseTwo::test05_right_demo()
{
	unsigned int a = 4294967295;
	unsigned int b = 2;
	unsigned int c = 4;

	if (UINT_MAX - a < b)
	{
		// 处理错误条件
	}
	else
	{
		printf("%u\n", a + b);
	}
	if (b < c)
	{
		// 处理错误条件
	}
	else
	{
		printf("%u\n", b - c);
	}

}

void AdviseTwo::test06_error_demo1()
{
	int s1 = 2147483647;
	int s2 = 1073741824;
	int s3 = -1879048193;
	int s4 = 1;
	int s5 = 4;
	// 0x%x 十六进制  // INT_MIN (-2147483647 - 1) INT_MAX (2147483647)
	printf("%d (0x%x) + %d (0x%x) = %d (0x%x) \n", s1, s1, s4, s4,s1 + s4 ,s1 + s4); // 输出 -2147483648
	printf("%d (0x%x) - %d (0x%x) = %d (0x%x) \n", s2, s2, s3, s3,s2 - s3 ,s2 - s3);
	printf("%d (0x%x) * %d (0x%x) = %d (0x%x) \n", s2, s2, s5, s5,s2 * s5 ,s2 * s5);
}
