#pragma once
#include <string>
#include <list>

// 第一章 自己习惯 C++

// 条款01 视C++为一个语言城邦
// 次语言
// a.C
// b.Object-Oriented C++
// c.Template C++
// d.STL

// 条款02 尽量以 const,enum,inline 替换 #define 
// 使用 预处理器 #define 在发生错误时 不容易追踪，容易浪费时间
// 

// enum hack 指的被记得的理由
// 1.enum hack 类似于 #define 而不似 const
//		取一个 const 的地址是合法的，取一个 #define 地址不合法

#define CALL_WITH_MAX(a,b) (a) > (b) ? (a) : (b)
// 这样的宏 有太多缺点，让人痛苦不堪 测试 见testMacroError
// 
// 注意：无论何时写宏 记住为宏中所有的参数加上小括号。

// template inline  获得宏的效率以及一般函数的所有可预料行为和类型安全性 
template <typename T>
inline void callWithMax(const T& a, const T& b)
{
	a > b ? a : b;
}
// 还可以 写出  private inline 的类内成员函数
// 记住
// 1.对于单纯常量，最好以 const 对象或 enums 替换 #defines
// 2.对于形似函数的宏(macros)，最好改用 inline 函数替换 #defines


// 条款03 尽可能使用 const
// 常量指针，指针常量
// 函数 返回 常量值，降低因客户错误而造成的意外，而又不至于放弃安全性和高效性
// 
// const 成员函数  目的是为了确认该成员函数可作用于 const 对象身上
//   第一：使 class 接口比较容易理解，得知哪个函数可以改动对象内容哪个函数不行
//   第二：它们使“操作 const 对象” 成为可能

// 验证 const 成员函数  testClassConstFunc


// const 成员函数不可以更改对象内任何 non-static 成员变量  testClassConstVariable
// 一个更改了"指针所指物"的成员函数虽然不能算是 const ,但如果只有指针(而非所指物)隶属于对象，不会引起编译器异议
// 验证 const 成员变量


// 条款04 确定对象被使用前已先被初始化
// 有些语境下未必会初始化

// array( 来自C语言 )不保证其内容初始化，而 vector ( 来自 C++ STL) 有此保证
// 最佳处理方式，永远在使用对象之前先将它初始化

// 别混淆了  赋值  和   初始化
// 成员变量属于内置类型(那么其初始化与赋值的成本相同)，也一定要使用初值列。
// 如果成员变量是 const 或 reference 。它们就一定需要初值，不能被赋值
// 两个成员变量的初始化带有次序性，例如初始化 array 时需要指定大小，因此代表大小的那个成员变量必须先有初值

// 编译单元是指产出单一目标文件的那些源码，基本上它是单一源码文件加上其所含入的头文件
// 问题：如果某编译单元内的某个 non-local static 对象的初始化动作使用了另一编译单元内的某个 non-local static对象
//		它所用到的这个对象可能尚未被初始化，因为C++对“定义不同编译单元内的 non-local static 对象”的初始化次序并无明确定义

// 重要：任何一种 non-const static 不论它是 local 或 non-local ,
//		在多线程环境下“等待某事发生”都会有麻烦
// 书中给出的解决方案是：在程序的单线程启动阶段手工调用所有 reference-returning 函数
//		可消除与初始化有关的 “竞速形势”


// 第二章 构造，析构，赋值

// 条款05 了解 C++ 默默编写并调用哪些函数
//  编译器在调用时会创建  默认构造函数 拷贝构造函数 析构函数 所有这些函数都是 public 且 inline
//  如果声明了一个有参构造函数，编译器不再创建默认构造函数

//  在一个内含 reference 成员的 class 内支持赋值操作，必须自己定义 copy assignment 操作符
//  面对 const 成员也一样 
//  如果某个 基类 将 copy assignment 操作符声明为 private 。编辑器将拒绝为其 派生类 生成 
//  copy assignment 操作符
//  如果在一个内涵 reference 或者 const  成员变量的类内支持赋值操作，必须自己定义 copy assignment 操作符

class TestConstructor
{
public:
	TestConstructor() {};		// 默认构造函数
	~TestConstructor() {};		// 析构函数
	TestConstructor(const TestConstructor& test) {};  // 拷贝构造函数

	TestConstructor& operator=(const TestConstructor& rhs) {};   // copy assignment 操作符
};

template<class T>
class NameObject
{
public:
	NameObject(std::string& name, const T& value)
		: nameValue(name)
		, objectValue(value)
	{
	};
	//NameObject& operator=(const NameObject<T>& test) { return *this; };

private:
	std::string& nameValue;
	const T objectValue;
};



#define INDEFINE_INSTANCE 1.23
// 改为 const
const double constInstance = 1.23;

class CTestConstFunc;
class CTestConstVariable;
class CTestConstNon_constFunc;
class CTestVariableInitialize;
class Class01
{
public:
	void testMacroError();
	void testInlineFunc();
	void testConstPoint();
	void testClassConstFunc();
	void testClassConstVariable();
	void testClassConstAndNon_constFunc();
	void testVariableInitialize();
	void testCopyAssignment();



private:
	static const double staticConstInstance;  // 声明式 static const 编译器不允许类内赋初值
	// class 专属常量，又是 static 且为整数类型，需要特殊处理
	static const int staticConstInstance2 = 1;  // 声明式 static const 且类型为 整形 ，编译器允许类内赋初值
	const double classConstInstance = 1.23;   // const 编译器允许类内赋初值

	// 如果编译器不允许类内赋初值，可以使用 enum 替代下
	enum { enumConstInstance = 5 };
};


class CTestConstFunc
{
public:
	explicit CTestConstFunc(const std::string txt, const std::string id);
	~CTestConstFunc() {};

	// operator[] for const 对象
	const char& operator[](std::size_t position) const;
	// operator[] for non_const 对象
	char& operator[](std::size_t position);

private:
	std::string text;
};

class CTestConstVariable
{
public:
	explicit CTestConstVariable(char* txt, const std::string id);
	~CTestConstVariable() {};

	// operator[] for const 对象
	char& operator[](std::size_t position) const;
	// operator[] for non_const 对象
	char& operator[](std::size_t position);

	std::size_t length() const;
	

private:
	char* pText;
	// 利用 mutable(可变的) mutable 释放掉 not-static 成员变量的 bitwise constness 约束
	mutable std::size_t textLength;   // 最近一次计算的文本区块长度
	mutable bool lengthIsValid;
};


class CTestConstNon_constFunc
{
public:
	explicit CTestConstNon_constFunc(const std::string txt, const std::string id);
	~CTestConstNon_constFunc() {};
	// 这样两个版本兼容 const 和 non-const 代码重复
	// operator[] for const 对象
	const char& operator[](std::size_t position) const;
	// operator[] for non_const 对象
	char& operator[](std::size_t position);
private:
	std::string text;
};

class CTestVariableInitialize
{
public:
	CTestVariableInitialize(const std::string& name,const std::list<int>& idList);
	~CTestVariableInitialize();
private:
	std::string m_sName;
	std::list<int> m_listId;

};