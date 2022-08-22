#include "advise02.h"
#include <stdlib.h>
#include <string.h>

void AdviseTwo::test01_error()
{
	char c = 150; // char ���Ϳ������������ͣ�1.�з��ŵ�(signed char)���޷��ŵ�(unsigned char)
	int i = 900;
	// TODO �˽�Ϊʲô������� -8 
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
		/* ���� n == 0 ����� */
	}
	p = (char*)malloc(n); 
	if (p == NULL)
	{
		/* ���� p == NULL ����� */
	}
	for (i = 0; i < n; ++i) // �� p �����õĶ�̬����Ļ������� n > INT_MAX ʱ���ᷢ�����
	{
		p[i] = *str++;  // �� INT_MAX < N <= SIZE_MAX �������ͱ��� i ����ֵ���� INT_MAX ʱ�� i ��ֵ���Ǵ� INT_MIN ��ʼ�ĸ�ֵ
	}
	return p;
}

char* AdviseTwo::test02_right1_copy(size_t n, const char* str)
{
	size_t i;
	char* p;
	if (n == 0 || n > SIZE_MAX)
	{
		/* ���� n == 0 ����� */
	}
	p = (char*)malloc(n);
	if (p == NULL)
	{
		/* ���� p == NULL ����� */
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
		/* ���� n == 0 ����� || n > RSIZE_MAX ����� */
	}
	p = (char*)malloc(n);
	if (p == NULL)
	{
		/* ���� p == NULL ����� */
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
		size_t �����ڲ�ͬ��ƽ̨�Ϻܿ��ܴ������ unsigned int��unsigned long int��unsigned long long int����
		������ unsigned int ʱ �����ʲô���⣬���ǵ�����������ʱ
		ִ�� "x = y" ʱ�����ܰ� y �ĸ�λ���ص����Ӷ����½������
	*/
	//x = y;

}

void AdviseTwo::test04_error()
{
	int array[] = { 1,2,3,4,5,6 }; // һ������ 4 ���ֽ�
	int i = -1; // -1 ��32λ�����ϴ洢Ϊ 0xffffffff ������������Ϊ�޷�������ʱ����2^32 - 1,�� 4294967295
	if (i <= sizeof(array)) // ���з����������޷����������ͽ�������ʱ���з����������ͻ����Զ�ת�����޷�����������(�ر�ע��)
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
	int array[] = { 1,2,3,4,5,6 }; // һ������ 4 ���ֽ�
	int i = -1;
	if (i <= (int)sizeof(array)) // ǿתΪ int
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
	printf("%u\n", a + b); // %u �޷���ʮ�������� // ���»��� 1
	printf("%u\n", b - c);// ���ϻ��� 4294967294
}

void AdviseTwo::test05_error_demo2(int argc ,char* argv[])
{
	unsigned short s; // unsigned short �ܹ��洢�����ʮ�������� (0 ~ 65535)
	int i;
	char buf[100];
	if (argc < 3)
		return;
	i = atoi(argv[1]);  // ��������� 65536
	s = i;              // ����ͻ�������ƣ��Ӷ� s ʵ��Ϊ 0
	if (s >= 100)       // �Ӷ� û�б�����
	{
		printf("�����ֽ���̫�����˳���\n");
		return;
	}
	printf("s = %d\n", s);
	memcpy(buf, argv[2], i);  // 65536 ���������³������ ��Ϊ buf ��ʼ��Ϊ buf[100]
	buf[i] = '\0';
	printf("�ɹ�����%d���ֽ�\n", i);
	printf("buf=%s\n", buf);

}

int* copyarray(int* arr, int len)
{
	int i = 0;
	// ���� len = 1073741824 ,���������޷�������������ƣ����ý��Ϊ 0x0����Ϊ newarray ������ڴ�Ϊ 0
	int* newarray = (int*)malloc(len * sizeof(int)); 
	if (newarray == NULL)
	{
		// ���� newarray == NULL �����
	}
	printf("Ϊ newarray �ɹ�����%d�ֽ��ڴ�\n", len * sizeof(int));
	printf("ѭ�����д���:%d (0x%x) \n", len, len);
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
		// �����������
	}
	else
	{
		printf("%u\n", a + b);
	}
	if (b < c)
	{
		// �����������
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
	// 0x%x ʮ������  // INT_MIN (-2147483647 - 1) INT_MAX (2147483647)
	printf("%d (0x%x) + %d (0x%x) = %d (0x%x) \n", s1, s1, s4, s4,s1 + s4 ,s1 + s4); // ��� -2147483648
	printf("%d (0x%x) - %d (0x%x) = %d (0x%x) \n", s2, s2, s3, s3,s2 - s3 ,s2 - s3);
	printf("%d (0x%x) * %d (0x%x) = %d (0x%x) \n", s2, s2, s5, s5,s2 * s5 ,s2 * s5);
}
