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
	outLog("���ۣ�new derived class ���� base class ��ָ�룬delete base class ��ָ�룬��� base class ���� virtual �ؼ��֣���ִ�� derived class ��������");
}

void Class02::testAutoPtr()
{
	std::auto_ptr<IAutoPtrTest> autoPtr1(createAutoPtrTestCase("autoPtr1"));
	if (autoPtr1.get()) outLog("init autoPtr1 not null");
	std::auto_ptr<IAutoPtrTest> autoPtr2(autoPtr1);    // ����
	if (!autoPtr1.get()) outLog("autoPtr1 is null");
	autoPtr1 = autoPtr2;							   // ����
	if (!autoPtr2.get()) outLog("autoPtr2 is null");
	outLog("���ۣ�auto_ptr ��ͨ�� copy ���캯���� copy assignment �������������ǣ����ǻ��� null�����������õ�ָ�뽫ȡ����Դ��Ψһ����Ȩ");
}

void Class02::testSharedPtr()
{
	std::shared_ptr<IAutoPtrTest> sharedPtr1(createAutoPtrTestCase("sharedPtr1"));
	if (sharedPtr1.get()) outLog("init sharedPtr1 not null");
	std::shared_ptr<IAutoPtrTest> sharedPtr2(sharedPtr1);    // ����
	if (!sharedPtr1.get()) outLog("sharedPtr1 is null");
	sharedPtr1 = sharedPtr2;							   // ����
	if (!sharedPtr2.get()) outLog("sharedPtr2 is null");
	outLog("���ۣ�shared_ptr ��ͨ�� copy ���캯���� copy assignment �������������ǣ����ǲ����� null");
}

void Class02::testGetFunc()
{
	std::string* name = new std::string("saisai");
	CFont font(name);
	const std::string* nameExplicit = font.get();
	outLog(*nameExplicit);
	const std::string* nameImplicit = font;
	outLog(*nameImplicit);
	outLog("���ۣ�ѧϰ��ʽ��ȡ�ڲ���Դ����ʽ��ȡ�ڲ���Դ����д��");
}
