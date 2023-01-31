#pragma once
#include "guide.hpp"


// 条款06 若不想使用编辑器自动生成的函数，就该明确拒绝
//  阻止 copying
//  一、可以将 copy 构造函数或 copy assignment 操作符声明为 private 
//    不足够安全因为 member 函数 和 friend 函数还是可以调用你的 private 函数
//    可以声明 但不定义，如果某人不慎调用会产生一个连接错误
//	  参数名称并非必要 函数不被实现并且很少被使用可以不写参数名称
//  二、将连接期的错误移至编译期是可能的
//		只要将 copy 构造函数 和 copy assignment 操作符声明为 private 就可以办到
//		但不是在于自己实现的类，而是在一个专门为了阻止 copying 动作而设计的 base class

// 阻止对象被拷贝 只需要继承 UnCopyAble 基类就可以了
class UnCopyAble
{
protected:
	UnCopyAble() {};			// 允许 derived 对象构造和析构
	~UnCopyAble() {};
private:
	UnCopyAble(const UnCopyAble&) {};			// 但阻止 copying
	UnCopyAble& operator=(const UnCopyAble&) {};
};

// 注意这里 是私有继承
class HomeForSale : public UnCopyAble
{

};

// 条款07 为多态基类声明 virtual 析构函数
//   C++ 指出 当 derived class 对象经由一个 base class 指针被删除，而该 base class 带一个 non-virtual 析构函数
//		其结果未有定义--实际执行时通常发生的是对象的 derived 成分没被销毁。 造成 局部销毁 对象
//	 任何 class 只要带有 virtual 函数几乎确定应该有一个 virtual 析构函数

class CBaseClassVirtual
{
public:
	CBaseClassVirtual() {};
	~CBaseClassVirtual() { outLog("CBaseClassVirtual 析构函数执行"); };
};


class CTestClassVirtual : public CBaseClassVirtual
{
public:
	CTestClassVirtual() {};
	~CTestClassVirtual() { outLog("CTestClassVirtual 析构函数执行"); };
};



class Class02
{
public:
	void testClassVirtual();
	void testAutoPtr();
	void testSharedPtr();
	void testGetFunc();




};



// 条款08 别让异常逃离析构函数



// 条款09 绝不在构造和析构过程中调用 virtual 函数


// 条款10 令 operator= 返回一个 reference to *this
//   连锁赋值 
// int x,y,z;
// x = y = z = 15;
// 赋值采用右结合定律
// x = (y = (z = 15));
// 为了实现连锁赋值，赋值操作符必须返回一个 reference 指向操作符的左侧实参
// 这只是个协议，string vector complex tr1::shared_ptr 共同遵守

class CChainAssignment
{
public:
	// 返回 reference 指向当前对象
	// 适用于所有赋值相关运算
	CChainAssignment& operator = (const CChainAssignment& rhs)
	{
		return *this;
	}
};

// 条款11 在 operator = 中处理 “自我赋值”
//	“自我赋值” 发生在对象被赋值给自己时
// class CAssignmentSelf { ... };
// CAssignmentSelf ca;
// ca = ca;
// a[i] = a[j];   如果 i = j ，潜在的自我赋值
// *px = *py;	  如果 px 和 py 指向同一个对象，潜在的自我赋值

// 自我赋值不安全实例
class CAssignmentSelfNotSafe
{
public:
	CAssignmentSelfNotSafe(const CAssignmentSelfNotSafe&) {};
	~CAssignmentSelfNotSafe() {};
};

class CAssignmentSelfNotSafeCase
{
public:
	void swap(CAssignmentSelfNotSafeCase& rhs)  // 交换 *this 与 rhs 的数据
	{

	};

	// 如果实参 rhs.pTest 指针与 私有 pTest 指针 指向同一个对象 
	CAssignmentSelfNotSafeCase& operator=(const CAssignmentSelfNotSafeCase& rhs)
	{
		// 解决方案 传统方法   证同测试
		if (this->pTest == rhs.pTest) return *this;



		delete pTest;									// 停止使用当前 pTest 指针
		// rhs.pTest 这里可能会访问一个空指针
		// 如果已经 证同测试 ，new 这里异常的话(因为内存不足或者copy构造函数异常)
		// 最终都会持有一个 空地址
		pTest = new CAssignmentSelfNotSafe(*rhs.pTest); // 使用 rhs 中的 pTest 的副本
		return *this;
	}

	// 1.解决异常安全性
	//CAssignmentSelfNotSafeCase& operator=(const CAssignmentSelfNotSafeCase& rhs)
	//{
	//	CAssignmentSelfNotSafe* pOrig = pTest; // 记住原先的 pTest
	//	pTest = new CAssignmentSelfNotSafe(*rhs.pTest);  // 令 pTest 指向 *rhs.pTest 的副本
	//	delete pOrig;							// 删除原先的 pOrig
	//	return *this;
	//}

	// 2.使用 copy and swap 技术
	//CAssignmentSelfNotSafeCase& operator=(const CAssignmentSelfNotSafeCase& rhs)
	//{
	//	CAssignmentSelfNotSafeCase temp(rhs);
	//	swap(temp);
	//	return *this;
	//}


private:
	CAssignmentSelfNotSafe* pTest;
};

// 条款12 复制对象时勿忘其每一个成分
//  设计良好之面向对象系统(OO-systems)会将对象的内部封装起来，只留两个函数负责对象拷贝(复制)，那便是带着合适名称的 copy 构造函数和 copy assingment 操作符
//  我们称为 copying 函数
//    当自己编写一个 copying 函数，确保：1.复制所有 local 成员变量 2.调用所有 base classes 内的适当的 copying 函数
// 
// copying 函数应该确保复制“对象内的所有成员变量”及“所有 base class 成分”
// 不要尝试以某个 copying 函数实现另一个 copying 函数。应该将共同机能放进第三个函数中，并由两个 copying 函数共同调用

class CCopyingFuncBase
{
public:
	CCopyingFuncBase(const CCopyingFuncBase& rhs)
		: m_sName(rhs.m_sName)
	{
		outLog("CCopyingFuncBase copy constructor");
	};
	// 自己实现 operator= 函数，再每一次新增成员变量的时候都要进行赋值
	// 如果外部类继承这个类，在初始化的时候也要进行内部类的赋值动作
	CCopyingFuncBase& operator=(const CCopyingFuncBase& rhs)
	{
		outLog("CCopyingFuncBase copy assignment operator");
		m_sName = rhs.m_sName;			// 复制 rhs 的数据
		return *this;
	};
private:
	std::string m_sName;
	int m_iAge;							// 也要进行拷贝
};

class CCopyingFuncDerived : public CCopyingFuncBase
{
public:
	CCopyingFuncDerived(const CCopyingFuncDerived& rhs)
		: CCopyingFuncBase(rhs)
		, priority(rhs.priority)
	{
		outLog("CCopyingFuncDerived copy constructor");
	};

	CCopyingFuncDerived& operator=(const CCopyingFuncDerived& rhs)
	{
		outLog("CCopyingFuncDerived copy assignment operator");
		CCopyingFuncBase::operator=(rhs);		// 对 base class 成分进行赋值动作
		priority = rhs.priority;
		return *this;
	}

private:
	int priority;
};


// 条款13 以对象管理资源
//  auto_ptr 是 “类指针对象” 智能指针
//		获得资源后立刻放进管理对象内
//		管理对象运用析构函数确保资源被释放
//	由于 auto_ptr 被销毁时会自动删除它所指之物，所以一定注意别让多个 atuo_ptr 同时指向同一对象
//  性质(重要)：若通过 copy 构造函数或 copy assigment 操作符复制它们，它们会变成 null , 而复制所得的指针将取得资源的唯一拥有权
class IAutoPtrTest
{

};
class CAutoPtrTest : public IAutoPtrTest
{
public:
	CAutoPtrTest(const std::string& name)
		: m_sName(name)
	{

	}
	std::string m_sName;
};

// 引用计数型 智慧指针(RCSP)
//	即 RCSP 也是智能指针，持续追踪共有多少对象指向某笔资源，并在无人指向它时自动删除该资源
//  实例 tr1::shared_ptr
//	
//  auto_ptr 和 tr1::shared_ptr 两者都是在其析构函数内做 delete 而不是 delete[] 动作
//		在动态分配而得的 array 身上使用 auto_ptr 或 tr1::shared_ptr 不是好主意

// 1.为防止资源泄露，请使用 RAII 对象，它们在构造函数中获得资源并在析构函数中释放资源
// 2.两个常被使用的 RAII classes 分别是 tr1::shared_ptr 和 auto_ptr 。前者通常是较佳选择，因为 copy 行为比较直观
//		若选择 auto_ptr ，复制动作会使它(被复制物)指向 null



// 条款14 在资源管理类中小心 copying 行为
// 资源取得时机便是初始化时机 (Resource Acquisition Is Initialization;RAII)
//  资源管理者 (resourse handlers) class 的基本结构由 RAII 守则支配
//	也就是 “资源在构造期间获得，在析构期间释放”

// 每一位 RAII class 作者一定需要面对：当一个 RAII 对象被复制，会发生什么事
//   1.禁止复制
//		将 copying 操作声明为 private
//	 2.对底层资源使用 引用计数法
//		通常只要内含一个 tr1::shared_ptr 成员变量，RAII classes 便可实现出 reference-counting copying 行为
//	 3.复制底部资源
//		在此情况下复制资源管理对象，应该同时也复制其包裹的资源，也就是进行 深度拷贝
//	 4.转移底部资源的拥有权
//		某些场合希望永远只有一个 RAII 对象指向一个未加工资源，即使 RAII 对象被复制依然如此，
//		此时资源的拥有权会从被复制物转移到目标物

// 条款15 在资源管理类中提供对原始资源的访问
//	APIs 往往要求访问原始资源，所以每一个 RAII class 应该提供一个“取得其管理资源”的办法
//  对原始资源的访问可能经由显式转换或隐式转换。一般而言显式转换比较安全，但隐式转换对客户比较方便

class CFont
{
public:
	explicit CFont(const std::string* name)
		: m_pName(name)
	{
	};
	~CFont()
	{
		delete m_pName;
		m_pName = NULL;
	};

public:
	// 提供显式转换函数
	const std::string* get() const
	{
		return m_pName;
	};
	// 隐式转换函数， 结构为： 类型() 
	operator const std::string* () const
	{
		return m_pName;
	}
private:
	const std::string* m_pName;
};

