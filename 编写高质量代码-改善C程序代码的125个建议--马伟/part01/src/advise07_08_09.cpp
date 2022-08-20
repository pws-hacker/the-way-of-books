#include "advise07_08_09.h"
#include <stdio.h>
#include <string>

void AdviseSeven::test_01_error()
{
	char* p1, p2;
	p1 = (char*)'a';
	//p2 = (char*)'b';  // 错误 p2 类型为 char
	char *p3, p4;
	p3 = (char*)'a';
	//p4 = (char*)'b';  // 错误 p2 类型为 char

}

void AdviseSeven::test_01_right()
{
	char* p1;
	char* p2;
	p1 = (char*)'a';
	p2 = (char*)'b';
}

int max(int x, int y);
void AdviseEight::test_01_right()
{
	int result;
	// 外部变量声明
	extern int g_X;
	extern int g_Y;
	result = max(g_X, g_Y);
	printf("the max value is %d\n", result);

}
int g_test_extern = 1;
static int g_test_static_variable = 1;
void AdviseEight::test_02_right()
{
	// 验证声明外部变量
	g_test_extern += 2;   // 外部不用引用头文件就可以使用
	// 验证静态全局变量
	g_test_static_variable = 2;  // 运行报错

}
// 定义两个全局变量
int g_X = 10;
int g_Y = 20;
int max(int x, int y)
{
	return (x > y ? x : y);
}

size_t sunm_index(size_t index)
{
	size_t i;
	// 静态局部变量编译时赋初值，只赋一次
	// 以后每次调用函数时不再重新赋初值，而是保留上次函数结束时的值。又称为带"内部存储器"功能
	static size_t sum;  // 不可重入，全局变量也是一样不可重入
	for (i = 0; i <= index; i++)
	{
		sum += i;
	}
	return sum;
}
void AdviseNine::test_01_right()
{
	printf("%d\n", sunm_index(1));  //1
	printf("%d\n", sunm_index(2));  //4
	printf("%d\n", sunm_index(3));  //10
}
