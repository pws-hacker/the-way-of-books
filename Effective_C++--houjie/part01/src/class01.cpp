#include "include/class01.h"
#include <iostream>
#include <vector>
#include "include/guide.hpp"

const double Class01::staticConstInstance = 1.23;  // ����ʽ
void Class01::testMacroError()
{
	std::cout << "testMacroError" << std::endl;
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);  // a ���ۼӶ���
	std::cout << "first test: a = " << a << ",b = " << b << " ���ۣ��궨��ʹ�� a ���ۼӶ���" << std::endl;
	a = 5, b = 0;
	CALL_WITH_MAX(++a, b + 10);  // a ���ۼ�һ��
	std::cout << "second test: a = " << a << ",b = " << b << " ���ۣ��궨��ʹ�� a ���ۼ�һ��" << std::endl;
}

void Class01::testInlineFunc()
{
	std::cout << "testInlineFunc" << std::endl;
	int a = 5, b = 0;
	callWithMax(++a, b);  // a ���ۼӶ���
	std::cout << "first test: a = " << a << ",b = " << b << " ���ۣ�inline ��������ʹ�� a ���ۼ�һ��" << std::endl;
	a = 5, b = 0;
	callWithMax(++a, b + 10);  // a ���ۼ�һ��
	std::cout << "second test: a = " << a << ",b = " << b << " ���ۣ�inline ����ʹ�� a ���ۼ�һ��" << std::endl;
}
void Class01::testConstPoint()
{
	std::string testStr1 = "hello";
	std::string testStr2 = "hello";

	std::string* p = &testStr1;        // non-const pointer	, non-const data
	*p = "changeHello";   // ����ָ��ָ���ֵ
	p = &testStr2;			// ����ָ�뱾���ַ


	// �� * �����      const * ָ���� ָ��ָ���ֵ�ǳ���
	// Ҳ����Я�� std::string const * p1  = &testStr1;
	const std::string* p1 = &testStr1;  // non-const pointer	, const data    
	// *p1 = "changeValue";      // ����ָ��ָ���ֵ error
	std::cout << "���ۣ�const �� * ����� ��T const * ָ��ָ���ֵ�ǳ�����Ҳ����дΪ const T*" << std::endl;
	// �� * ���ұ�      const * ָ���� ָ�뱾����һ������
	std::string* const p2 = &testStr1; // const pointer	, non-const data
	// p2 = &testStr2;      // ����ָ�뱾���ַ error
	std::cout << "���ۣ�const �� * ���ұ� ��T* const ָ�뱾����һ������" << std::endl;
	const std::string* const p3 = &testStr1; // const pointer, const data
	
	// ������ ���þ���  T* ָ��
	// ���� ������ Ϊ const ��������ָ��Ϊ  const һ��(�� T* const)
	std::vector<int> vec1;
	vec1.push_back(1);
	const std::vector<int>::iterator iter = vec1.begin();
	*iter = 10;  // �ı� iter ��ָ�� ��û������
	//++iter;      // ����ָ���ַ��error

	std::vector<int> vec2;
	vec2.push_back(1);
	std::vector<int>::const_iterator cIter = vec2.begin();
	//*cIter = 10;  // �ı� iter ��ָ�� ��error
	++cIter;      // ����ָ���ַ��û������


}

void Class01::testClassConstFunc()
{
	CTestBlock ta("abc", "ta");
	outLog(ta[0]);				// ���� non-const CTestBlock::operator[]
	outLog("���ۣ��ǳ���������� �ǳ�����");

	const CTestBlock tb("abc", "tb"); 
	outLog(tb[0]);              // ���� const CTestBlock::operator[]
	outLog("���ۣ������������ ������--��������� const");
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
