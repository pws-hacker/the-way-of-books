#include "advise27~30.h"
#include <stdio.h>
#include <stdlib.h>

int test_main()
{
	printf("test: (*(int (*)())((int)&test_main)) ();");
	return 0;
}

void Advise29::test_00_demo()
{
	(*(int (*)())((int)&test_main)) ();
}

typedef int ElementType;
typedef struct node
{
	ElementType data;
	struct node* next;
}StackNode,*LinkStack;
void InvertedSequence_demo1(int num)
{
	int i = 0;
	int result = 0;
	LinkStack ls;
	// 初始化
	ls = (LinkStack)malloc(sizeof(StackNode));
	ls->next = NULL;
	printf("\n数据输入为：\n");
	for (i = 0; i < num; i++)
	{
		// 入栈
		StackNode* temp;
		temp = (StackNode*)malloc(sizeof(StackNode));
		if (temp != NULL)
		{
			temp->data = i;
			temp->next = ls->next;
			ls->next = temp;
			printf("%d ", i);
		}
		// 这里不能 free ，因为入栈是保存下来，出栈时还要使用。
	}
	printf("\n数据输出为：\n");
	while (ls->next != NULL)
	{
		// 出栈
		StackNode* temp = ls->next;
		result = temp->data;;
		ls->next = temp->next;
		free(temp);		// 这里可以 free ，出栈使用完了不会再用到了。
		printf("%d ", result);
	}
	printf("\n");
}
void Advise29::test_01_error_demo()
{
	InvertedSequence_demo1(20);
}

#define STACK_SIZE 100
// 初始化
void InitStack(LinkStack ls)
{
	ls->next = NULL;
}
// 是否为空
bool IsEmpty(LinkStack ls)
{
	if (ls->next == NULL)
		return true;
	else
		return false;
}
// 入栈
bool Push(LinkStack ls, ElementType element)
{
	StackNode* temp;
	temp = (LinkStack)malloc(sizeof(StackNode));
	if (temp == NULL) { return false; };
	temp->data = element;
	temp->next = ls->next;
	ls->next = temp;
	return true;
}
// 出栈
bool Pop(LinkStack ls, ElementType* element)
{
	if (IsEmpty(ls))
		return false;
	else
	{
		StackNode* temp = ls->next;
		*element = temp->data;
		ls->next = temp->next;
		free(temp);
		return true;
	}
}
// 逻辑清晰，可读性强
void InvertedSequence_demo2(int num)
{
	int i = 0;
	int result = 0;
	LinkStack ls;
	ls = (LinkStack)malloc(sizeof(StackNode));
	// 初始化
	InitStack(ls);
	printf("\n数据输入为：\n");
	for (i = 0; i < num; i++)
	{
		// 入栈
		Push(ls, i);
		printf("%d ", i);
	}
	printf("\n数据输出为：\n");
	while (!IsEmpty(ls))
	{
		// 出栈
		Pop(ls, &result);
		printf("%d ", result);
	}
	printf("\n");
}
void Advise29::test_01_right_demo()
{
	InvertedSequence_demo2(20);
}
typedef struct Rect
{
	int length;
	int width;
} RECT;
typedef struct Point
{
	int x;
	int y;
} POINT;
void Advise29::test_02_demo()
{
	// 不要这样写，没有任何关联，要分别写两个函数分别初始化 RECT ,POINT
	RECT rect;
	rect.length = 0;
	rect.width = 0;
	POINT point;
	point.x = 0;
	point.y = 0;
}
