#include "advise20~25.h"

void Advise20::test_01_error(int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		// �������
	}
}

void Advise20::test_01_right(int n)
{
	for (int i = 0; i < n ; i++)
	{
		// �������
	}
}
#define condition true
void Advise20::test_02_error_demo(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (condition)  // ���߼��ж�����Ƶ�ѭ�������������жϵĴ���
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
	// �����������һЩ��ȴʹ����ִ���߼��ж������� n-1 �Σ��� for ѭ���ܴ�ʱ�������Ż���Ȼ��ֵ�õ�
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
			// �������
		}
	}
}

void Advise20::test_03_right_demo()
{
	// ���Ч��
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 100; j++)  
		{
			// �������
		}
	}
}

// ��ʱ�临�ӶȽǶ���˵�����ж�����ȫ������
// ��ִ�� 100 * 3 = 300 ��
void Advise21::test_01_demo()
{
	double num[100];
	double sum = 0;
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		sum += num[i]; // ִ��100��
	}
}
// ��ʱ�临�ӶȽǶ���˵�����ж�����ȫ������
// ��ִ�� 25 * 9 = 225 ��
void Advise21::test_02_demo()
{
	// �ֽ� 4 ·����ʹ�� 4 ����ˮ�߸���ӷ�������ӷ�ÿһ����ռ��һ��ʱ�����ڣ��Ӷ���֤������Դ������
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
