#include "advise35.h"
#include <stdio.h>
int f1()
{
	return 100;
}

// 为保证可抑制性，还是加上 void 比较规范些
int f2(void)
{
	return 100;
}
void Advise35::test_01_demo()
{
	printf("%d\n", f1());  
	printf("%d\n", f2());  // vs 中不可编译成功 GCC中却可以

}

// 设计不合理，控制参数 calculate_flag 使函数间的耦合度增大，违背了函数的功能单一原则。
int Calculate(int a, int b, const int calculate_flag)
{
	int sum = 0;
	switch (calculate_flag)
	{
	case 1:
		sum = a + b;
		break;
	case 2:
		sum = a - b;
		break;
	case 3:
		sum = a * b;
		break;
	case 4:
		sum = a / b;
		break;
	default:
		printf("error\n");
		break;
	}
	return sum;
}
// 不如分为 4 个函数清晰
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
}
void Advise35::test_02_demo(void)
{
	 Calculate(1,2,1);
}

void Advise35::test_03_error(size_t index, size_t* sum)
{
	size_t i;
	*sum = 0;
	for (i = 1; i <= index; i++)
	{
		// 参数 sum 成了工作变量
		*sum += i;
	}

}

// 对必须改变的参数，我们先用局部变量代之，再将局部变量的内容赋给该参数
void Advise35::test_03_right(size_t index, size_t* sum)
{
	size_t i;
	size_t tmp = 0;

	for (i = 1; i <= index; i++)
	{
		tmp += i;
	}

	*sum = tmp;
}
