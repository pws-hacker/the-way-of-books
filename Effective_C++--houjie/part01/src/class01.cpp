#include "..\include\class01.h"
#include <iostream>

const double Class01::staticConstInstance = 1.23;  // ����ʽ
void Class01::testMacroError()
{
	std::cout << "testMacroError" << std::endl;
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);  // a ���ۼӶ���
	std::cout << "first test: a = " << a << ",b = " << b << " ���ۣ��궨��ʹ�� a ���ۼӶ���" << std::endl;
	a = 5, b = 0;
	CALL_WITH_MAX(++a, b + 10);  // a ���ۼ�һ��
	std::cout << "second test: a = " << a << ",b = " << b << " ���ۣ��궨��ʹ�� a ���ۼ�һ��" << std::endl;
}

void Class01::testInlineFunc()
{
	std::cout << "testInlineFunc" << std::endl;
	int a = 5, b = 0;
	callWithMax(++a, b);  // a ���ۼӶ���
	std::cout << "first test: a = " << a << ",b = " << b << " ���ۣ�inline ��������ʹ�� a ���ۼ�һ��" << std::endl;
	a = 5, b = 0;
	callWithMax(++a, b + 10);  // a ���ۼ�һ��
	std::cout << "second test: a = " << a << ",b = " << b << " ���ۣ�inline ����ʹ�� a ���ۼ�һ��" << std::endl;
}
