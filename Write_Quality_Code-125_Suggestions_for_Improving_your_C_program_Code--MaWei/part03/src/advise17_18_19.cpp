#include "advise17_18_19.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits>
#include <assert.h>

void Advise17::test_01_error()
{
	int x = 0;
	int a = 1;
	int b = 3;
	int c = 5;
	int d = 7;
	if (a < b)
	{
		x += b;
		if (b < c)
		{
			x += c;
			if (c < d)
			{
				x++;
				if (a > d)
				{
					x = d;
				}
			}
		}
	}
	printf("%d\n", x);
}

void Advise17::test_01_right()
{
	int x = 0;
	int a = 1;
	int b = 3;
	int c = 5;
	int d = 7;
	do 
	{
		if (a >= b)
			break;
		x += b;
		if (b >= c)
			break;
		x += c;
		if (c >= d)
			break;
		x++;
		if (a <= d)
			break;
		x = d;
	} while (false);
	printf("%d\n", x);
}

void Advise18::test_01_error()
{
	// 在 Visual C++ 中将 true 定义为 1
	// 在 Visual Basic 中将 true 定义为 -1;
	// 所以 这样写 不具备良好的可移植性
	if (flag == 1)
	{
		// 表示 flag 为真
	}
	if (flag == 0)
	{
		// 表示 flag 为假
	}
}

void Advise18::test_01_right()
{
	if (flag)
	{
		// 表示 flag 为真
	}
	if (!flag)
	{
		// 表示 flag 为假
	}
}

void Advise18::test_02_error()
{

	float a = 10.22222225;
	float b = 10.22222229;
	if (a == b)
	{
		printf("a == b \n"); // a == b
	}
	else
	{
		printf("a != b \n");
	}
}

void Advise18::test_02_right()
{
	float x = 10.22222225;
	float y = 10.22222229;
	if (abs(x - y) <= FLT_EPSILON)
	{
		// 则a == b
		printf("x == y \n"); // x == y
	}
	if (abs(x - y) > FLT_EPSILON)
	{
		// 则a != b
		printf("x != y \n");
	}

	float m = 0.00000001;
	// 浮点数与 0 进行比较
	if (abs(m) <= numeric_limits<float>::epsilon())
	{
		// 则m == 0
		printf("m == 0 \n"); // m == 0
	}
	if (abs(m) > numeric_limits<float>::epsilon())
	{
		// 则m != 0
		printf("m == 0 \n");
	}
}
unsigned int f1(unsigned int x)
{
	unsigned int temp;
	if (x <= 1)
	{
		if (x != 0)
		{
			temp = 0;
		}
		else
		{
			temp = 1;
		}
	}
	else
	{
		if (x == 4)
		{
			temp = 2;
		}
		else
		{
			temp = x + 1;
		}
	}
	return temp;
}

unsigned int f(unsigned int x)
{
	return ((x <= 1) ? (1 - x) : (x == 4) ? 2 : (x + 1)); // 可读性差，算法也没有精进
	// 相当于
	// f1(4);

}

void Advise19::test_01_error()
{
	printf("f(4) = %d\n", f(4));
	printf("f1(4) = %d\n", f1(4));
}

unsigned int f2(unsigned int x)
{
	assert(x >= 0 && x <= 4);
	if (x == 1)
	{
		return 0;
	}
	if (x == 4)
	{
		return 2;
	}
	return x + 1;
}

// 列表方式
unsigned int f3(unsigned int x)
{
	assert(x >= 0 && x <= 4);
	static const unsigned temp[] = { 1,0,3,4,2 };
	return temp[x];
}
void Advise19::test_01_right()
{
	printf("f2(4) = %d\n", f2(4));
	printf("f3(4) = %d\n", f3(4));

}
