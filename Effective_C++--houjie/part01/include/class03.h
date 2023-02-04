#pragma once


class Class03
{
public:
	void testInts();

};

// 第四章 设计与声明

// 条款18 让接口容易被正确使用，不易被误用
//	欲开发一个“容易被正确使用，不容易被误用”的接口，首先必须考虑客户可能做出什么样的错误
//	“促进正确使用”的办法包括接口的一致性，以及与内置类型的行为兼容
//	“阻止误用”的办法包括建立新类型、限制类型上的操作，束缚对象值，以及消除客户的资源管理责任
//	tr1::shared_ptr 支持定制型删除器，可防范 DLL 问题，可被用来解除互斥锁

class CDate
{
public:
	// 客户可能会犯两个错误
	//	1.CDate d1(30,3,1995);   // 传参顺序错误
	//	2.CDate d2(2,30,1995);   // 非法输入 2 月没有 30天
	CDate(int month, int day, int year) {};
};

struct SYear { explicit SYear(int y) {}; };
struct SMonth { explicit SMonth(int m) {}; };
struct SDay { explicit SDay(int d) {}; };

// 类型确认，限制其值
class CMonth
{
public:
	static CMonth Jan() { return CMonth(1); };
private:
	explicit CMonth(int m) { };				// 私有化 阻止生成新的月份
};

class CDateRemake
{
public:
	// 改造版 明智而审慎地导入新类型可预防“接口被误用”
	// 令 SDay SMonth SYear 成为成熟且经充分锻炼的 classes 并封装其内数据，比 struct 效果还要好
	CDateRemake(const SMonth& month, const SDay& day, const SYear& year) {};
};


// 条款19 设计 class 犹如设计 type
//	重载函数和操作符、控制内存的分配和归还、定义对象的初始化和终结
//	带着和“语言设计者当初设计语言内置类型时”一样的谨慎来研讨 class 的设计

// 设计高效的 classes 应该问自己的问题
//		1.新 type 的对象应该如何被创建和销毁
//			影响 构造函数和析构函数以及内存分配函数和释放函数 (operator new,operator new[],operator delete,operator delete[])
// 
//		2.对象的初始化和对象的赋值该有什么样的差别
//			决定 构造函数和赋值(assgnment)操作符 的行为，以及其间的差异
// 
//		3.新 type 的对象如果被 pass by value ，意味着什么
//			决定 copy 构造函数
// 
//		4.什么是新 type 的“合法值”
//			对 class 的成员变量而言，只有某些数值集是有效的。这些数值集决定你必须维护的 约束条件，也决定成员函数必须进行的 错误检查工作

//		5.你的新 type 需要配合某个继承图系吗
//			特别关注 基类的 “virtual 或 non-virtual 函数”的影响
// 
//		6.你的新 type 需要什么样的转换
//			如果希望允许 T1 被隐式转换为 T2，就必须在 class T1 内写一个类型转换函数(operator T2)
//			或者在 class T2 内写一个 non-explicit-one-argument(可被单一实参调用)的构造函数。
//			如果只允许 explicit 构造函数存在，就要写专门负责执行转换的函数，且不得为类型转换操作符
//				(type conversion operators) 或 non-explicit-one-argument 构造函数
// 
//		7.什么样的操作符和函数对此新 type 而言是合理的
//			决定声明哪些函数
// 
//		8.什么样的标准函数应该驳回
//			声明为 private 者
// 
//		9.谁该取用新 type 的成员
//			哪个成员为 public protected private ,决定哪一个 classes 或 functions 应该是 friends，以及将它们嵌套于另一个内是否合理
// 
//		10.什么是新 type 的“未声明接口”
//			对效率，异常安全性以及资源运用(例如多任务锁定和动态内存)提供何种保证
// 
//		11.你的新 type 有多么一般化
//			如果定义一整个 types 家族，应该定义一个 新的 class template
// 
//		12.你真的需要一个新 type 吗
//			如果只是定义新的 derived class 以便为既有的 class 添加机能，考虑是否定义一个或多个 non-member 函数 或 templates 更能达到目标

// 条款20 宁以 pass-by-reference-to-const 替换 pass-by-value
//		pass-by-value 费时
//		不适用 内置类型，内置类型使用 pass-by-value 比较适当

// 条款21 必须返回对象，别妄想返回其 reference


