#include "advise10_11_12.h"
#include <stdio.h>

void Advise11::test_01_demo()
{
	const int i1 = 10;
	int* p1 = (int*)&i1;  // �������Ǹ�����ͬ��ָ�룬���� const ������ֵ�Ǳ����� ���ݶ�(ֻ��) ��
	int* p2 = p1;
	*p1 = 100;
	printf("%d %d %d\n", i1, *p1, *p2); // 10 ,100 ,100
	printf("%p %p %p\n", &i1, p1, p2);  // ��ַ��ͬ
	//printf("%d\n", *(int*)0x0115F634);  // ͨ����ַ���ڴ��ļ��ɵ�֪������ ��ջ��
	// ��Ȼ��ַ��ͬ���� const ������ȡ�������ݶΣ�ͨ��ָ���ȡ������ ��ջ�� 
}
