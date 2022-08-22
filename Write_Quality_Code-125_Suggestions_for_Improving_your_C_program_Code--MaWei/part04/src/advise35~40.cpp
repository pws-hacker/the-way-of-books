#define  _CRT_SECURE_NO_WARNINGS

#include "advise35~40.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f1()
{
	return 100;
}

// Ϊ��֤�������ԣ����Ǽ��� void �ȽϹ淶Щ
int f2(void)
{
	return 100;
}
void Advise35::test_01_demo()
{
	printf("%d\n", f1());  
	printf("%d\n", f2());  // vs �в��ɱ���ɹ� GCC��ȴ����

}

// ��Ʋ��������Ʋ��� calculate_flag ʹ���������϶�����Υ���˺����Ĺ��ܵ�һԭ��
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
// �����Ϊ 4 ����������
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
		// ���� sum ���˹�������
		*sum += i;
	}

}

// �Ա���ı�Ĳ������������þֲ�������֮���ٽ��ֲ����������ݸ����ò���
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

// error demo 1
char* GetHello1(void)
{
	char p[] = "hello world!";
	return p;
}

// right 1 malloc
char* GetHello2(void)
{
	char* p = NULL;
	p = (char*)malloc(sizeof(char));
	return p;
}

// �ַ�������
char* GetHello3(void)
{
	char* p = (char*)"hello world!";
	return p;
}
void Advise37::test_01_demo()
{
	char* str1 = NULL;
	char* str2 = NULL;
	char* str3 = NULL;
	//str1 = GetHello1();
	str2 = GetHello2();
	str3 = GetHello3();
	strcpy(str2, "hello world!");
	//printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
}

long fab_1(const int index)
{
	if (index == 1 || index == 2)
	{
		return 1;
	}
	else
	{
		return fab_1(index - 1) + fab_1(index - 2);
	}
}
void Advise39::test_01_demo()
{
	printf("fab_1(10) = %d\n", fab_1(10));
}

long fab_2(const int index)
{
	if (index == 1 || index == 2)
	{
		return 1;
	}
	else
	{
		long l1 = 1;
		long l2 = 1;
		long l3 = 0;
		// ������ֵ
		for (int i = 0; i < index - 2; i++)
		{
			l3 = l1 + l2;
			l1 = l2;
			l2 = l3;
		}
		return l3;
	}
}
void Advise39::test_02_demo()
{
	printf("fab_2(10) = %d\n", fab_2(10));
}

#define Mul(x) (x * x)
void Advise39::test_03_demo()
{
	printf("%d\n", Mul(20));  // 400 
	printf("%d\n", Mul(10 + 10));  // 120 ������

	int i = 10;
	printf("%d\n", Mul(++i));  // 140 ������ ++ִ��������
}
