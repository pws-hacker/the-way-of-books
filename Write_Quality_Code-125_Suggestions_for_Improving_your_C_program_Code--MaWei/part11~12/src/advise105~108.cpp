#include "advise105~108.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void Advise105::test_01_demo()
{
	printf("start~\n");
	free(NULL);
}

void Advise105::test_02_error()
{
	char* str = (char*)"abcd";
	char c[10];
	memcpy(c, str, strlen(str));
	printf("%s:%d\n", c, strlen(c));
}

void Advise105::test_02_right()
{
	char* str = (char*)"abcd";
	char c[10];
	memcpy(c, str, strlen(str)+1);
	printf("%s:%d\n", c, strlen(c));
}

void Advise105::test_03_error()
{
	char* p = (char*)malloc(10);
	char* np = (char*)malloc(10);
	p = np;  // 指针重新赋值，内存泄露
}

void Advise105::test_03_right()
{
	char* p = (char*)malloc(10);
	char* np = (char*)malloc(10);
	if (!p || !np)
		return;
	free(p);  // 避免内存泄露
	p = NULL;
	p = np;
}

typedef	struct tagNode
{
	int id;
	char* data;
} Node,* pNode;

void Advise105::test_04_error()
{
	pNode p_node = NULL;
	p_node = (pNode)malloc(sizeof(Node));
	if (!p_node)
		return;
	p_node->id = 0;
	p_node->data = (char*)malloc(10);

	// 错误的内存释放
	free(p_node);   // p_node->data 内存泄露
}

void Advise105::test_04_right()
{
	pNode p_node = NULL;
	p_node = (pNode)malloc(sizeof(Node));
	if (!p_node)
		return;
	p_node->id = 0;
	p_node->data = (char*)malloc(10);

	// 错误的内存释放
	free(p_node->data);
	free(p_node);   // p_node->data 内存泄露
}
char* f()
{
	return (char*)malloc(10);
}
void Advise105::test_05_error()
{
	f();  // 调用并未处理该内存位置的返回位置。
}

void Advise105::test_06_demo(size_t num)
{
	long* buf;
	size_t number = num;
	if (number > SIZE_MAX / sizeof(long))
	{
		// 如果超出了 SIZE_MAX 范围，进行错误处理
	}
	buf = (long*)calloc(number, sizeof(long));
	if (buf == NULL)
	{
		// 处理
	}
}
