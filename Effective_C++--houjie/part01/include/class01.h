#pragma once
#include <string>

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

// 验证 const 成员函数
// 验证 const 成员变量

// const 成员函数不可以更改对象内任何 non-static 成员变量
// 一个更改了"指针所指物"的成员函数虽然不能算是 const ,但如果只有指针(而非所指物)隶属于对象，不会引起编译器异议




#define INDEFINE_INSTANCE 1.23
// 改为 const
const double constInstance = 1.23;

class CTestBlock;
class Class01
{
public:
	void testMacroError();
	void testInlineFunc();
	void testConstPoint();
	void testClassConstFunc();
	void testClassConstVariable();




private:
	static const double staticConstInstance;  // 声明式 static const 编译器不允许类内赋初值
	const double classConstInstance = 1.23;   // const 编译器允许类内赋初值

	// 如果编译器不允许类内赋初值，可以使用 enum 替代下
	enum { enumConstInstance = 5 };
};


class CTestBlock
{
public:
	explicit CTestBlock(const std::string txt, const std::string id);
	~CTestBlock() {};

	// operator[] for const 对象
	const char& operator[](std::size_t position) const;
	// operator[] for non_const 对象
	char& operator[](std::size_t position);

private:
	std::string text;
};