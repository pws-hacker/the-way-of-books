#include "advise40~51.h"
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

void Advise40::test_04_error(void)
{
	float f = 0.f;
	int i = 0;
	float* fp;
	int* ip;
	// �� float* ǿתΪ int*
	ip = (int*)&f;
	fp = (float*)&i;
	printf("i:%d\n", i);  // ��� i: 0
	printf("f:%f\n", f);  // ��� f: 0.000000
	(*ip)++;
	(*fp)++;
	printf("i:%d\n", i);  // ��� i: 1065353216
	printf("f:%f\n", f);  // ��� f: 0.000000
}

void Advise40::test_04_right(void)
{
	float f = 0.f;
	int i = 0;
	float* fp;
	int* ip;
	// ��ȷд��
	ip = (int*)&i;
	fp = (float*)&f;
	printf("i:%d\n", i);  // ��� i: 0
	printf("f:%f\n", f);  // ��� f: 0.000000
	(*ip)++;
	(*fp)++;
	printf("i:%d\n", i);  // ��� i: 1
	printf("f:%f\n", f);  // ��� f: 1.000000
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
// "const int* p"   const ���ε��� *p  �����Բ���ͨ��  *p  �޸ĵ�ַ��ֵ
void Advise50::test_01_demo(void)
{
	int i1 = 10;
	int i2 = 20;
	const int* p = &i1;
	printf("%d\n", *p);  // ��� 10
	p = &i2;
	printf("%d\n", *p);  // ��� 20
	i2 = 30;
	printf("%d\n", *p);  // ��� 30
}
// "int* const p"   const ���ε��� p  �����Բ����޸� p ֵ��ָ�볣��ֻ�� ָ���ʼ��ʱ���ڴ��ַ
void Advise50::test_02_demo(void)
{
	int i1 = 10;
	int i2 = 20;
	int* const p = &i1;
	printf("%d\n", *p);  // ��� 10
	// p = &i2;  ����������ֵ��
	printf("%d\n", *p);  // ��� 20
	i2 = 30;
	printf("%d\n", *p);  // ��� 30
}

void Advise50::test_03_demo(void)
{
	const int i = 10;
	int* p;
	p = (int*)&i;  // ǿתΪ int* 
	printf("*p=%d\n", *p);
	*p = 20;  // �����ǺϷ���
	printf("i=%d\n", i);
	printf("*p=%d\n", *p);
}

void Advise50::test_04_demo(void)
{
	// "const int i" �� "int const i"��ȫ��ͬ�ĸ���
	const int i = 10;
	// i++; // ������
	int const ii = 10;
	// ii++; // ������
}
