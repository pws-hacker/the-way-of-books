#include "advise07_08_09.h"
#include <stdio.h>
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
// ��������ȫ�ֱ���
int g_X = 10;
int g_Y = 20;
int max(int x, int y)
{
	return (x > y ? x : y);
}

