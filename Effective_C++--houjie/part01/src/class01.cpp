#include "..\include\class01.h"
#include <iostream>

const double Class01::staticConstInstance = 1.23;  // 定义式
void Class01::testMacroError()
{
	std::cout << "testMacroError" << std::endl;
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);  // a 被累加二次
	std::cout << "first test: a = " << a << ",b = " << b << " 结论：宏定义使用 a 被累加二次" << std::endl;
	a = 5, b = 0;
	CALL_WITH_MAX(++a, b + 10);  // a 被累加一次
	std::cout << "second test: a = " << a << ",b = " << b << " 结论：宏定义使用 a 被累加一次" << std::endl;
}

void Class01::testInlineFunc()
{
	std::cout << "testInlineFunc" << std::endl;
	int a = 5, b = 0;
	callWithMax(++a, b);  // a 被累加二次
	std::cout << "first test: a = " << a << ",b = " << b << " 结论：inline 函数定义使用 a 被累加一次" << std::endl;
	a = 5, b = 0;
	callWithMax(++a, b + 10);  // a 被累加一次
	std::cout << "second test: a = " << a << ",b = " << b << " 结论：inline 函数使用 a 被累加一次" << std::endl;
}
