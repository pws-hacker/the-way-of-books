#include "include/class02.h"

#include <memory>

IAutoPtrTest* createAutoPtrTestCase(const std::string& name)
{
	IAutoPtrTest* test = new CAutoPtrTest(name);
	return test;
}

void Class02::testClassVirtual()
{
	CBaseClassVirtual* testClassVirtual = new CTestClassVirtual();
	if (testClassVirtual) delete testClassVirtual;
	outLog("结论：new derived class 返回 base class 的指针，delete base class 的指针，如果 base class 不带 virtual 关键字，则不执行 derived class 析构函数");
}

void Class02::testAutoPtr()
{
	std::auto_ptr<IAutoPtrTest> autoPtr1(createAutoPtrTestCase("autoPtr1"));
	if (autoPtr1.get()) outLog("init autoPtr1 not null");
	std::auto_ptr<IAutoPtrTest> autoPtr2(autoPtr1);    // 交换
	if (!autoPtr1.get()) outLog("autoPtr1 is null");
	autoPtr1 = autoPtr2;							   // 拷贝
	if (!autoPtr2.get()) outLog("autoPtr2 is null");
	outLog("结论：auto_ptr 若通过 copy 构造函数或 copy assignment 操作符复制它们，它们会变成 null，而复制所得的指针将取得资源的唯一所有权");
}

void Class02::testSharedPtr()
{
	std::shared_ptr<IAutoPtrTest> sharedPtr1(createAutoPtrTestCase("sharedPtr1"));
	if (sharedPtr1.get()) outLog("init sharedPtr1 not null");
	std::shared_ptr<IAutoPtrTest> sharedPtr2(sharedPtr1);    // 交换
	if (!sharedPtr1.get()) outLog("sharedPtr1 is null");
	sharedPtr1 = sharedPtr2;							   // 拷贝
	if (!sharedPtr2.get()) outLog("sharedPtr2 is null");
	outLog("结论：shared_ptr 若通过 copy 构造函数或 copy assignment 操作符复制它们，它们不会变成 null");
}

void Class02::testGetFunc()
{
	std::string* name = new std::string("saisai");
	CFont font(name);
	const std::string* nameExplicit = font.get();
	outLog(*nameExplicit);
	const std::string* nameImplicit = font;
	outLog(*nameImplicit);
	outLog("结论：学习显式获取内部资源和隐式获取内部资源函数写法");
}

// 每个 STR_ARR 有4行，每行有一个 string
typedef std::string STR_ARR[4];
void Class02::testNewDeleteArray()
{
	// new 100 个string数组
	std::string* strArr = new std::string[100];
	// delete
	delete[] strArr;

	// new STR_ARR
	std::string* testSTR_ARR = new STR_ARR;
	delete[] testSTR_ARR; // delete
	outLog("结论：如果你在 new 表达式中使用 [] ，必须在相应的 delete 表达式中也使用 []");
}

int priority()
{
	// 测试异常
	int a = 5, b = 0;
	int test = a / b;
	return 1;
}
void Class02::testNewedSharePtr()
{
	processWidget((std::tr1::shared_ptr<CWidget>)new CWidget, priority());
}

CChainAssignment& CChainAssignment::operator=(const CChainAssignment& rhs)
{
	return *this;
}
