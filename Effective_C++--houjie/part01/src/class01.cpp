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
	CTestConstFunc ta("abc", "ta");
	outLog(ta[0]);				// 调用 non-const CTestBlock::operator[]
	outLog("结论：非常量对象调用 非常函数");

	const CTestConstFunc tb("abc", "tb"); 
	outLog(tb[0]);              // 调用 const CTestBlock::operator[]
	outLog("结论：常量对象调用 常函数--函数后面加 const");
}

void Class01::testClassConstVariable()
{
	// 两个流行概念  
	// 一是 bitwise const ,bitwise const 正是 C++ 对常量性 (constness) 的定义，因此 const 成员函数不可以更改对象内任何 non_static 成员变量
	// 声明为 const 却能改成员变量的值
	const CTestConstVariable tc((char*)"bcd","tc");
	char* pc = &tc[0];
	
	//*pc = 'j';   // 书中这里讲可以改变里面的值，但是测试却是写入权限冲突
	outLog(tc[0]);

	outLog("结论：写入权限冲突");

	// 二是 logical const
	// 主张一个 const 成员函数可以修改它所处理的对象内的某些 bits,但只有在客户端侦测不出的情况下才得如此

}

void Class01::testClassConstAndNon_constFunc()
{
	CTestConstNon_constFunc testFunc("cde","testFunc");
	testFunc[0] = 'a';
	outLog(testFunc[0]);
	outLog("结论：使用 non-const 版本调用 const 版本可避免代码重复");
}

class CTestPoint
{
	int x; // 这里则不一定会
	int y;
};

// 此对象与另一个编译单元的全局函数对象 初始化次序不定
extern CTestPoint indefiniteCase;
// 非成员函数不允许使用 const
// 解决方法
const CTestPoint& getTestPointCase()
{
	// non-local static 对象用 local static 对象替换。local static 会在程序启动之前初始化
	// 但是，这些函数“内涵static对象”的事实使它们在多线程系统中带有不确定性
	static CTestPoint definiteCase;
	return definiteCase;
}
void Class01::testVariableInitialize()
{
	int x;  // 这种写法会初始化
	CTestPoint test;
	int y = 0;							// 内置类型手动初始化
	const char* txt = "A C-style string"; // 对指针进行手工初始化
	double d;
	std::cin >> d;	// 以读取 input stream 的方式完成初始化

	CTestPoint point = getTestPointCase();
	// point.x = 1;	// 返回 const T& 可以限制改动

}

void Class01::testCopyAssignment()
{
	std::string non_reference("non_reference");
	std::string reference("reference");
	std::string & testReference = non_reference;
	testReference = reference;
	non_reference = "1";
	reference = "2";
	outLog("结论：C++ 不允许让 reference 改指向不同对象");

	std::string newDog("PersePhone");
	std::string oldDog("Satch");
	NameObject<int> p(newDog, 2);
	NameObject<int> s(oldDog, 36);
	//p = s;   // 报错
	outLog("如果在一个内涵 reference 或者 const  成员变量的类内支持赋值操作，必须自己定义 copy assignment 操作符");
}

CTestConstFunc::CTestConstFunc(const std::string txt,const std::string id)
	: text(txt)
{
	outLog(id);
}

const char& CTestConstFunc::operator[](std::size_t position) const
{
	outLog("excute const func.");
	return text[position];
}

char& CTestConstFunc::operator[](std::size_t position)
{
	outLog("excute non-const func.");
	return text[position];
}

CTestConstVariable::CTestConstVariable(char* txt, const std::string id)
	: pText(txt)
	, textLength(0)
	, lengthIsValid(false)
{
	outLog(id);
}

char& CTestConstVariable::operator[](std::size_t position) const
{
	outLog("excute const func.");
	return pText[position];
}

char& CTestConstVariable::operator[](std::size_t position)
{
	outLog("excute non-const func.");
	return pText[position];
}

std::size_t CTestConstVariable::length() const
{
	if (!lengthIsValid)
	{
		// 错误 ,在 const 成员函数内不能赋值给 non-const 成员变量
		textLength = std::strlen(pText);
		lengthIsValid = true;
	}
	return textLength;
}

CTestConstNon_constFunc::CTestConstNon_constFunc(const std::string txt, const std::string id)
	: text(txt)
{
	outLog(id);
}

const char& CTestConstNon_constFunc::operator[](std::size_t position) const
{
	// ...边界检验
	// ...志记数据访问
	// 等等
	return text[position];
}

char& CTestConstNon_constFunc::operator[](std::size_t position)
{
	// ...边界检验
	// ...志记数据访问
	// 等等
	//return text[position];

	// 这样写可以避免代码重复
	// 当 const 和 non-const 成员函数有着实质等价的实现时，令 non-const 版本调用 const 版本可避免代码重复
	// 两次转型
	// 一次是用来为 (*this) 添加 const ,这使接下来调用 operator[] 时得以调用 const 版本
	// 第二次是 从 const operator[] 的返回值中移除 const
	// const_cast 强制类型转换操作符,转换掉 表达式中的 const 性质
	return const_cast<char&>(static_cast<const CTestConstNon_constFunc&>(*this)[position]);
}

// C++规定 对象的成员变量的初始化动作发生在进入构造函数本体之前。
CTestVariableInitialize::CTestVariableInitialize(const std::string& name, const std::list<int>& idList)
	: m_sName(name)   // 直接初始化
	, m_listId(idList)  // 执行的是  复制 构造 函数
{
	// 如果不使用直接初始化 ，赋值版本 会首先调用 默认构造函数 初始化成员变量，然后再赋予新值
	m_sName = name;   // 这些都是赋值 而非初始化
	m_listId = idList;



}

CTestVariableInitialize::~CTestVariableInitialize()
{
}
