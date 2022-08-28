#define _CRT_SECURE_NO_WARNINGS

#include "advise52~58.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD "123456"

int Test(char* str)
{
	int flag;
	char buffer[7];
	flag = strcmp(str, PASSWORD);
	strcpy(buffer, str);  // 会造成数组越界
	return flag;
}
void Advise53::test_01_error(void)
{
	int flag = 0;
	char str[1024];
	while (true)
	{
		printf("请输入密码：   ");
		scanf("%s", str);
		flag = Test(str);
		if (flag)
		{
			printf("密码错误!\n");
		}
		else
		{
			printf("密码正确!\n");
			break;
		}
	}
}
#define MAX  10
void Advise53::test_02_demo()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,0 };
	int b[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int c[MAX] = { 1,2,3,4,5,6,7,8,9,0 };
}

#define ARRAY_NUM 10

int* Advise53::test_03_error_demo(int num,int value)
{
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * ARRAY_NUM);
	if (arr != NULL)  // 没有进行越界检查  num > 或 小于 0 的情况
	{
		arr[num] = value;
	}
	else
	{
		// 处理 arr = NULL 
	}
	return arr;
}

int* Advise53::test_03_right_demo(size_t num, int value)
{
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * ARRAY_NUM);
	// 越上界检查
	if (num <= ARRAY_NUM)
	{
		if (arr != NULL)  // 没有进行越界检查  num > 或 小于 0 的情况
		{
			// num 是 size_t 类型，数组下界检查
			arr[num] = value;
		}
		else
		{
			// 处理 arr = NULL 
		}
	}
	return arr;
}

// 由于 arr 参数是一个形参，它是一个指针类型
void Init1(int arr[])
{
	size_t i = 0;
	// 书上是这样写的 我觉得不妥，应该 	sizeof(arr) / sizeof(int);
	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		arr[i] = i;
	}
}

void Advise53::test_04_error(void)
{
	int i = 0;
	int a[10];
	Init1(a);
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	};
}

// 我们可以通过传入数组的长度的方式来解决这个问题
void Init2(int arr[], size_t arr_len)
{
	size_t i = 0;

	for (i = 0; i < arr_len; i++)
	{
		arr[i] = i;
	}
}
void Advise53::test_04_right1(void)
{
	int i = 0;
	int a[10];
	Init2(a,sizeof(a)/sizeof(int));
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	};
}

// 还可以通过指针的方式来解决，这里的 arr 参数是一个指向 arr[10]类型 的指针
void Init3(int(*arr)[10])  // 必须传入数组的大小，会报不完整类型错误
{
	size_t i = 0;

	for (i = 0; i < sizeof(*arr) / sizeof(int); i++)
	{
		(*arr)[i] = i;  // [] 优先级 比 * 高
	}
}
void Advise53::test_04_right2(void)
{
	int i = 0;
	int a[10];
	Init3(&a);  // 传地址
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	};
}

void Advise53::test_05_demo(void)
{
	//   定义数组 a 时，编译器在某个地方保存了 a 的首元素的首地址，假设10000（即 a 是一个地址，编译器会为数组 a 分配一个空间，但不会为 a 本身分配空间）
	char a[6] = "hello";
	int i = 0;
	int c1;
	c1 = a[i];
	// 取 a[i] 的内容：
	// 1.计算 a[i] :10000 + i*sizeof(char)
	// 2.取 10000 + i*sizeof(char) 地址上的内容

	//   而定义指针变量，编译器为之分配一个空间，在对一个指针变量进行引用的时候(比如(*p)),编译器首先需要得到 p 的地址，从中取值
	//   然后把得到的值作为地址，再取值

	char* p = (char*)"hello";
	char c2;
	c2 = *p;
	// 取 p 的内容 , 假设 p 的地址为 1001，
	// 1.取出地址 1001 上的内容 2001
	// 2.再取出地址 2001 上的内容

	// 第一种情况 定义为数组，声明为指针
	// 声明与定义的区别
	// 声明告诉编译器存在这么一个变量，但是编译器并不会为它分配任何内存(即并不实现它)
	// 定义则是实现这个变量，真正在内存(堆或栈)中为此变量分配空间，定义只能出现一次，声明可以出现多次
	//
	// 文件1：f1.c
	int a3[3] = { 1,2,3 };
	// 文件2: f2.c
	//extern int* a3;   // 编译器认为 a 是一个指针变量，32位系统占 4 字节，编译器按照本文件中声明的类型来处理 文件1 中的数组，显然声明方法是不对的
	printf("%d\n", a3[0]);

	// 正确声明
	//extern int a3[];
	// 或者
	//extern int a3[3];

	// 第二种情况 定义为指针 声明为数组
	// 文件3 f3.c
	char* pa1 = (char*)"hello";
	// 文件4 f4.c
	//extern char pa1[];   // 报错 本来针对数组需要对内存进行直接引用，但是这时编译器执行的却是对内存进行间接引用
	printf("%c\n", pa1[0]);  


	// 总之，声明与定义应该完全匹配
}

void Advise56::test_01_demo(void)
{
	// 可以这样运算
	int* p;
	int arr[10];
	p = arr;
	p = p + 5;
	++p;
	// 这样不可以
	int* cp;
	int ip;
	p = &ip;
	p = p + 5;
	++p;
}

void Advise56::test_02_error(void)
{
	int arr[10];
	int* p;
	for (p = &arr[0]; p < &arr[11]; p++)
	{
		// 对 arr[11] 的引用将导致未定义的行为
	}
}

