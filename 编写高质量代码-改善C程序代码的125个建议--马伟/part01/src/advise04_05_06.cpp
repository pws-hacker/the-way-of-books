#include "advise04_05_06.h"
#include <stdio.h>
#include <stdlib.h>

void AdviseFour::test01_right()
{
	double d1 = 2147483648.01;
	int i1 = 0;
	if (d1 > (double)INT_MAX || d1 < (double)INT_MIN)
	{
		printf("transform double to int fail,double value is out of range!");
	}
	else
	{
		i1 = (int)d1;
	}
	printf("i1=%d\n", i1);

}

void AdviseFive::test01_error_demo()
{
	char ch;
	ch = (char)0xff;
	if (ch == 0xff)  // �����ַ�Ĭ�����з��ŵı����������Ϊ�١� ���⣬��chתΪ���� int �Ƚϣ����int��32λ �Ὣ ch ����Ϊ 0xffffffff�����Ϊ��
	{
		printf("ch == 0xff is true\n");
	}
	else
	{
		printf("ch == 0xff is false\n");
	}
}

typedef struct tagNode
{
	char* pItem;
	//pNode pNext; // �±��� pNode �ڽṹ��Ϊ�������ʱ��������������ʶ
	struct tagNode* pNext; // C �����������ڽṹ�а���ָ�����Լ���ָ��
}* pNode;

typedef int INT_ARRAY_100[100];
INT_ARRAY_100 arr;  // ��������ļ�����


void AdviseSix::test01_right_demo()
{
	pNode node = new tagNode;
	node->pItem = (char*)'a';
}

typedef char* PCHAR;
int str_cmp(const PCHAR, const PCHAR)
{
	// "const PCHAR" ������ "const char*"
	// "const PCHAR" �е� const ����������ָ�뱾�����ԣ��γ��˳���ָ�� "char* const��һ��ָ�� char �ĳ���ָ�룩"
	return 0;
};
void AdviseSix::test02_error_demo()
{

}
