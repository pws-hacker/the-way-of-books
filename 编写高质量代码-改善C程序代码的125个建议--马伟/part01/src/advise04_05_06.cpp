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
	if (ch == 0xff)  // 对于字符默认是有符号的编译器，语句为假。 另外，将ch转为整型 int 比较，如果int是32位 会将 ch 扩充为 0xffffffff，语句为假
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
	//pNode pNext; // 新别名 pNode 在结构体为建立完成时，编译器还不认识
	struct tagNode* pNext; // C 语言是允许在结构中包含指向它自己的指针
}* pNode;

typedef int INT_ARRAY_100[100];
INT_ARRAY_100 arr;  // 定义数组的简洁别名


void AdviseSix::test01_right_demo()
{
	pNode node = new tagNode;
	node->pItem = (char*)'a';
}

typedef char* PCHAR;
int str_cmp(const PCHAR, const PCHAR)
{
	// "const PCHAR" 不等于 "const char*"
	// "const PCHAR" 中的 const 给予了整个指针本身常量性，形成了常量指针 "char* const（一个指向 char 的常量指针）"
	return 0;
};
void AdviseSix::test02_error_demo()
{

}
