#pragma once

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


#define INDEFINE_INSTANCE 1.23
// 改为 const
const double constInstance = 1.23;

class Class01
{
public:
	void testMacroError();
	void testInlineFunc();



private:
	static const double staticConstInstance;  // 声明式 static const 编译器不允许类内赋初值
	const double classConstInstance = 1.23;   // const 编译器允许类内赋初值

	// 如果编译器不允许类内赋初值，可以使用 enum 替代下
	enum { enumConstInstance = 5 };
};

