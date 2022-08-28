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
	strcpy(buffer, str);  // ���������Խ��
	return flag;
}
void Advise53::test_01_error(void)
{
	int flag = 0;
	char str[1024];
	while (true)
	{
		printf("���������룺   ");
		scanf("%s", str);
		flag = Test(str);
		if (flag)
		{
			printf("�������!\n");
		}
		else
		{
			printf("������ȷ!\n");
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
	if (arr != NULL)  // û�н���Խ����  num > �� С�� 0 �����
	{
		arr[num] = value;
	}
	else
	{
		// ���� arr = NULL 
	}
	return arr;
}

int* Advise53::test_03_right_demo(size_t num, int value)
{
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * ARRAY_NUM);
	// Խ�Ͻ���
	if (num <= ARRAY_NUM)
	{
		if (arr != NULL)  // û�н���Խ����  num > �� С�� 0 �����
		{
			// num �� size_t ���ͣ������½���
			arr[num] = value;
		}
		else
		{
			// ���� arr = NULL 
		}
	}
	return arr;
}

// ���� arr ������һ���βΣ�����һ��ָ������
void Init1(int arr[])
{
	size_t i = 0;
	// ����������д�� �Ҿ��ò��ף�Ӧ�� 	sizeof(arr) / sizeof(int);
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

// ���ǿ���ͨ����������ĳ��ȵķ�ʽ������������
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

// ������ͨ��ָ��ķ�ʽ������������ arr ������һ��ָ�� arr[10]���� ��ָ��
void Init3(int(*arr)[10])  // ���봫������Ĵ�С���ᱨ���������ʹ���
{
	size_t i = 0;

	for (i = 0; i < sizeof(*arr) / sizeof(int); i++)
	{
		(*arr)[i] = i;  // [] ���ȼ� �� * ��
	}
}
void Advise53::test_04_right2(void)
{
	int i = 0;
	int a[10];
	Init3(&a);  // ����ַ
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	};
}

void Advise53::test_05_demo(void)
{
	//   �������� a ʱ����������ĳ���ط������� a ����Ԫ�ص��׵�ַ������10000���� a ��һ����ַ����������Ϊ���� a ����һ���ռ䣬������Ϊ a �������ռ䣩
	char a[6] = "hello";
	int i = 0;
	int c1;
	c1 = a[i];
	// ȡ a[i] �����ݣ�
	// 1.���� a[i] :10000 + i*sizeof(char)
	// 2.ȡ 10000 + i*sizeof(char) ��ַ�ϵ�����

	//   ������ָ�������������Ϊ֮����һ���ռ䣬�ڶ�һ��ָ������������õ�ʱ��(����(*p)),������������Ҫ�õ� p �ĵ�ַ������ȡֵ
	//   Ȼ��ѵõ���ֵ��Ϊ��ַ����ȡֵ

	char* p = (char*)"hello";
	char c2;
	c2 = *p;
	// ȡ p ������ , ���� p �ĵ�ַΪ 1001��
	// 1.ȡ����ַ 1001 �ϵ����� 2001
	// 2.��ȡ����ַ 2001 �ϵ�����

	// ��һ����� ����Ϊ���飬����Ϊָ��
	// �����붨�������
	// �������߱�����������ôһ�����������Ǳ�����������Ϊ�������κ��ڴ�(������ʵ����)
	// ��������ʵ������������������ڴ�(�ѻ�ջ)��Ϊ�˱�������ռ䣬����ֻ�ܳ���һ�Σ��������Գ��ֶ��
	//
	// �ļ�1��f1.c
	int a3[3] = { 1,2,3 };
	// �ļ�2: f2.c
	//extern int* a3;   // ��������Ϊ a ��һ��ָ�������32λϵͳռ 4 �ֽڣ����������ձ��ļ������������������� �ļ�1 �е����飬��Ȼ���������ǲ��Ե�
	printf("%d\n", a3[0]);

	// ��ȷ����
	//extern int a3[];
	// ����
	//extern int a3[3];

	// �ڶ������ ����Ϊָ�� ����Ϊ����
	// �ļ�3 f3.c
	char* pa1 = (char*)"hello";
	// �ļ�4 f4.c
	//extern char pa1[];   // ���� �������������Ҫ���ڴ����ֱ�����ã�������ʱ������ִ�е�ȴ�Ƕ��ڴ���м������
	printf("%c\n", pa1[0]);  


	// ��֮�������붨��Ӧ����ȫƥ��
}

void Advise56::test_01_demo(void)
{
	// ������������
	int* p;
	int arr[10];
	p = arr;
	p = p + 5;
	++p;
	// ����������
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
		// �� arr[11] �����ý�����δ�������Ϊ
	}
}

