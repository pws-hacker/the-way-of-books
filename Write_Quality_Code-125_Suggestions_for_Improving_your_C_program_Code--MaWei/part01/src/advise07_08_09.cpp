#include "advise07_08_09.h"
#include <stdio.h>
#include <string>

void AdviseSeven::test_01_error()
{
	char* p1, p2;
	p1 = (char*)'a';
	//p2 = (char*)'b';  // ���� p2 ����Ϊ char
	char *p3, p4;
	p3 = (char*)'a';
	//p4 = (char*)'b';  // ���� p2 ����Ϊ char

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
	// �ⲿ��������
	extern int g_X;
	extern int g_Y;
	result = max(g_X, g_Y);
	printf("the max value is %d\n", result);

}
int g_test_extern = 1;
static int g_test_static_variable = 1;
void AdviseEight::test_02_right()
{
	// ��֤�����ⲿ����
	g_test_extern += 2;   // �ⲿ��������ͷ�ļ��Ϳ���ʹ��
	// ��֤��̬ȫ�ֱ���
	g_test_static_variable = 2;  // ���б���

}
// ��������ȫ�ֱ���
int g_X = 10;
int g_Y = 20;
int max(int x, int y)
{
	return (x > y ? x : y);
}

size_t sunm_index(size_t index)
{
	size_t i;
	// ��̬�ֲ���������ʱ����ֵ��ֻ��һ��
	// �Ժ�ÿ�ε��ú���ʱ�������¸���ֵ�����Ǳ����ϴκ�������ʱ��ֵ���ֳ�Ϊ��"�ڲ��洢��"����
	static size_t sum;  // �������룬ȫ�ֱ���Ҳ��һ����������
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
