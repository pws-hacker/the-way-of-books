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
	// ��ʼ��
	ls = (LinkStack)malloc(sizeof(StackNode));
	ls->next = NULL;
	printf("\n��������Ϊ��\n");
	for (i = 0; i < num; i++)
	{
		// ��ջ
		StackNode* temp;
		temp = (StackNode*)malloc(sizeof(StackNode));
		if (temp != NULL)
		{
			temp->data = i;
			temp->next = ls->next;
			ls->next = temp;
			printf("%d ", i);
		}
		// ���ﲻ�� free ����Ϊ��ջ�Ǳ�����������ջʱ��Ҫʹ�á�
	}
	printf("\n�������Ϊ��\n");
	while (ls->next != NULL)
	{
		// ��ջ
		StackNode* temp = ls->next;
		result = temp->data;;
		ls->next = temp->next;
		free(temp);		// ������� free ����ջʹ�����˲������õ��ˡ�
		printf("%d ", result);
	}
	printf("\n");
}
void Advise29::test_01_error_demo()
{
	InvertedSequence_demo1(20);
}

#define STACK_SIZE 100
// ��ʼ��
void InitStack(LinkStack ls)
{
	ls->next = NULL;
}
// �Ƿ�Ϊ��
bool IsEmpty(LinkStack ls)
{
	if (ls->next == NULL)
		return true;
	else
		return false;
}
// ��ջ
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
// ��ջ
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
// �߼��������ɶ���ǿ
void InvertedSequence_demo2(int num)
{
	int i = 0;
	int result = 0;
	LinkStack ls;
	ls = (LinkStack)malloc(sizeof(StackNode));
	// ��ʼ��
	InitStack(ls);
	printf("\n��������Ϊ��\n");
	for (i = 0; i < num; i++)
	{
		// ��ջ
		Push(ls, i);
		printf("%d ", i);
	}
	printf("\n�������Ϊ��\n");
	while (!IsEmpty(ls))
	{
		// ��ջ
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
	// ��Ҫ����д��û���κι�����Ҫ�ֱ�д���������ֱ��ʼ�� RECT ,POINT
	RECT rect;
	rect.length = 0;
	rect.width = 0;
	POINT point;
	point.x = 0;
	point.y = 0;
}
