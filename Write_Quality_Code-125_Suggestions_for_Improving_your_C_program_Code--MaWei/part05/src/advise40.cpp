#include "advise40.h"
#include <stdio.h>
#include <stdlib.h>

void Advise40::test_01_error()
{
	//int* p;
	//printf("%x\n", p); // vs ���뱨��  �п����� Release ģʽ���64144714 ��Debug ģʽ����� cccccccc
}

void Advise40::test_02_demo()
{
	char a[20] = "qwertyuiopasdfghijl";
	int* p = (int*)a;
	// ����������������ָ��p��ֵ���� sizeof(int) ,int ռ 4 �ֽڣ����Ա�������4.��p��ָ��ĵ�ַ��ԭ���ı���a�ĵ�ַ��ߵ�ַ����������4�ֽ�
	// ���� char ���͵ĳ�����һ���ֽڣ����������� tyuiopasdfghijl
	p++;  
	printf("%s\n", p);
}

double* Advise40::test_03_error(size_t num)
{
	double* arr = NULL;
	if (num > SIZE_MAX / sizeof(arr))
	{
		// ���� num > SIZE_MAX / sizeof(arr)
	}
	else
	{
		// ���� sizeof ����ָ��ĳ��ȣ���Ӧ����ָ��ָ�����͵ĳ���
		// ��ȷд�� 		arr = (double*)malloc(sizeof(double) * num);
		// ���� sizeof(*arr) ���� arr �����õ����ݽṹ�ĳ���
		arr = (double*)malloc(sizeof(arr) * num);
		if (arr = NULL)
		{
			// ���� arr == NULL
		}
	}
	return arr;
}
