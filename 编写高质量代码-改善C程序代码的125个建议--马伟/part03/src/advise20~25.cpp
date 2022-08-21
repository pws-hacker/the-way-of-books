#include "advise20~25.h"

void Advise20::test_01_error(int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		// 处理代码
	}
}

void Advise20::test_01_right(int n)
{
	for (int i = 0; i < n ; i++)
	{
		// 处理代码
	}
}
#define condition true
void Advise20::test_02_error_demo(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (condition)  // 将逻辑判断语句移到循环外面来减少判断的次数
		{
			// Do Something
		}
		else
		{
			// Do Other Something
		}
	}
}

void Advise20::test_02_right_demo(int n)
{
	// 代码简洁度少了一些，却使程序执行逻辑判断语句减少 n-1 次，在 for 循环很大时，这种优化显然是值得的
	if (condition)
	{
		for (int i = 0; i < n; i++)
		{
			// Do Something
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			// Do Other Something
		}
	}
}

void Advise20::test_03_error_demo()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 处理代码
		}
	}
}

void Advise20::test_03_right_demo()
{
	// 提高效率
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 100; j++)  
		{
			// 处理代码
		}
	}
}

// 从时间复杂度角度来说，把判断条件全部加上
// 共执行 100 * 3 = 300 次
void Advise21::test_01_demo()
{
	double num[100];
	double sum = 0;
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		sum += num[i]; // 执行100次
	}
}
// 从时间复杂度角度来说，把判断条件全部加上
// 共执行 25 * 9 = 225 次
void Advise21::test_02_demo()
{
	// 分解 4 路，即使用 4 段流水线浮点加法，浮点加法每一个段占用一个时钟周期，从而保证最大的资源利用率
	double num[100];
	double sum = 0;
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	double sum4 = 0;
	int i = 0;
	for (i = 0; i < 100; i += 4)
	{
		sum1 += num[i];
		sum2 += num[i + 1];
		sum3 += num[i + 2];
		sum4 += num[i + 3];
	}
	sum = sum1 + sum2 + sum3 + sum4;
}
