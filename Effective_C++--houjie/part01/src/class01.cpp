#include "include/class01.h"
#include <iostream>
#include <vector>
#include "include/guide.hpp"

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
void Class01::testConstPoint()
{
	std::string testStr1 = "hello";
	std::string testStr2 = "hello";

	std::string* p = &testStr1;        // non-const pointer	, non-const data
	*p = "changeHello";   // 更改指针指向的值
	p = &testStr2;			// 更改指针本身地址


	// 在 * 号左边      const * 指的是 指针指向的值是常量
	// 也可以携程 std::string const * p1  = &testStr1;
	const std::string* p1 = &testStr1;  // non-const pointer	, const data    
	// *p1 = "changeValue";      // 更改指针指向的值 error
	std::cout << "结论：const 在 * 号左边 ，T const * 指针指向的值是常量，也可以写为 const T*" << std::endl;
	// 在 * 号右边      const * 指的是 指针本身是一个常量
	std::string* const p2 = &testStr1; // const pointer	, non-const data
	// p2 = &testStr2;      // 更改指针本身地址 error
	std::cout << "结论：const 在 * 号右边 ，T* const 指针本身是一个常量" << std::endl;
	const std::string* const p3 = &testStr1; // const pointer, const data
	
	// 迭代器 作用就像  T* 指针
	// 声明 迭代器 为 const 就像声明指针为  const 一样(即 T* const)
	std::vector<int> vec1;
	vec1.push_back(1);
	const std::vector<int>::iterator iter = vec1.begin();
	*iter = 10;  // 改变 iter 所指物 ，没有问题
	//++iter;      // 更改指针地址，error

	std::vector<int> vec2;
	vec2.push_back(1);
	std::vector<int>::const_iterator cIter = vec2.begin();
	//*cIter = 10;  // 改变 iter 所指物 ，error
	++cIter;      // 更改指针地址，没有问题


}

void Class01::testClassConstFunc()
{
	CTestBlock ta("abc", "ta");
	outLog(ta[0]);				// 调用 non-const CTestBlock::operator[]
	outLog("结论：非常量对象调用 非常函数");

	const CTestBlock tb("abc", "tb"); 
	outLog(tb[0]);              // 调用 const CTestBlock::operator[]
	outLog("结论：常量对象调用 常函数--函数后面加 const");
}

void Class01::testClassConstVariable()
{

}

CTestBlock::CTestBlock(const std::string txt,const std::string id)
	: text(txt)
{
	outLog(id);
}

const char& CTestBlock::operator[](std::size_t position) const
{
	outLog("excute const func.");
	return text[position];
}

char& CTestBlock::operator[](std::size_t position)
{
	outLog("excute non-const func.");
	return text[position];
}
