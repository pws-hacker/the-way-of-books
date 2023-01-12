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
	CTestConstFunc ta("abc", "ta");
	outLog(ta[0]);				// ���� non-const CTestBlock::operator[]
	outLog("���ۣ��ǳ���������� �ǳ�����");

	const CTestConstFunc tb("abc", "tb"); 
	outLog(tb[0]);              // ���� const CTestBlock::operator[]
	outLog("���ۣ������������ ������--��������� const");
}

void Class01::testClassConstVariable()
{
	// �������и���  
	// һ�� bitwise const ,bitwise const ���� C++ �Գ����� (constness) �Ķ��壬��� const ��Ա���������Ը��Ķ������κ� non_static ��Ա����
	// ����Ϊ const ȴ�ܸĳ�Ա������ֵ
	const CTestConstVariable tc((char*)"bcd","tc");
	char* pc = &tc[0];
	
	//*pc = 'j';   // �������ｲ���Ըı������ֵ�����ǲ���ȴ��д��Ȩ�޳�ͻ
	outLog(tc[0]);

	outLog("���ۣ�д��Ȩ�޳�ͻ");

	// ���� logical const
	// ����һ�� const ��Ա���������޸���������Ķ����ڵ�ĳЩ bits,��ֻ���ڿͻ�����ⲻ��������²ŵ����

}

void Class01::testClassConstAndNon_constFunc()
{
	CTestConstNon_constFunc testFunc("cde","testFunc");
	testFunc[0] = 'a';
	outLog(testFunc[0]);
	outLog("���ۣ�ʹ�� non-const �汾���� const �汾�ɱ�������ظ�");
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
		// ���� ,�� const ��Ա�����ڲ��ܸ�ֵ�� non-const ��Ա����
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
	// ...�߽����
	// ...־�����ݷ���
	// �ȵ�
	return text[position];
}

char& CTestConstNon_constFunc::operator[](std::size_t position)
{
	// ...�߽����
	// ...־�����ݷ���
	// �ȵ�
	//return text[position];

	// ����д���Ա�������ظ�
	// �� const �� non-const ��Ա��������ʵ�ʵȼ۵�ʵ��ʱ���� non-const �汾���� const �汾�ɱ�������ظ�
	// ����ת��
	// һ��������Ϊ (*this) ��� const ,��ʹ���������� operator[] ʱ���Ե��� const �汾
	// �ڶ����� �� const operator[] �ķ���ֵ���Ƴ� const
	// const_cast ǿ������ת��������,ת���� ���ʽ�е� const ����
	return const_cast<char&>(static_cast<const CTestConstNon_constFunc&>(*this)[position]);
}
