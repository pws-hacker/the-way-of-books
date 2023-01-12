#pragma once
#include <string>

// ����01 ��C++Ϊһ�����Գǰ�
// ������
// a.C
// b.Object-Oriented C++
// c.Template C++
// d.STL

// ����02 ������ const,enum,inline �滻 #define 
// ʹ�� Ԥ������ #define �ڷ�������ʱ ������׷�٣������˷�ʱ��
// 

// enum hack ָ�ı��ǵõ�����
// 1.enum hack ������ #define ������ const
//		ȡһ�� const �ĵ�ַ�ǺϷ��ģ�ȡһ�� #define ��ַ���Ϸ�

#define CALL_WITH_MAX(a,b) (a) > (b) ? (a) : (b)
// �����ĺ� ��̫��ȱ�㣬����ʹ�಻�� ���� ��testMacroError
// 
// ע�⣺���ۺ�ʱд�� ��סΪ�������еĲ�������С���š�

// template inline  ��ú��Ч���Լ�һ�㺯�������п�Ԥ����Ϊ�����Ͱ�ȫ�� 
template <typename T>
inline void callWithMax(const T& a, const T& b)
{
	a > b ? a : b;
}
// ������ д��  private inline �����ڳ�Ա����
// ��ס
// 1.���ڵ�������������� const ����� enums �滻 #defines
// 2.�������ƺ����ĺ�(macros)����ø��� inline �����滻 #defines

// ����03 ������ʹ�� const
// ����ָ�룬ָ�볣��
// ���� ���� ����ֵ��������ͻ��������ɵ����⣬���ֲ����ڷ�����ȫ�Ժ͸�Ч��
// 
// const ��Ա����  Ŀ����Ϊ��ȷ�ϸó�Ա������������ const ��������
//   ��һ��ʹ class �ӿڱȽ�������⣬��֪�ĸ��������ԸĶ����������ĸ���������
//   �ڶ�������ʹ������ const ���� ��Ϊ����

// ��֤ const ��Ա����  testClassConstFunc


// const ��Ա���������Ը��Ķ������κ� non-static ��Ա����  testClassConstVariable
// һ��������"ָ����ָ��"�ĳ�Ա������Ȼ�������� const ,�����ֻ��ָ��(������ָ��)�����ڶ��󣬲����������������
// ��֤ const ��Ա����



#define INDEFINE_INSTANCE 1.23
// ��Ϊ const
const double constInstance = 1.23;

class CTestConstFunc;
class CTestConstVariable;
class CTestConstNon_constFunc;
class Class01
{
public:
	void testMacroError();
	void testInlineFunc();
	void testConstPoint();
	void testClassConstFunc();
	void testClassConstVariable();
	void testClassConstAndNon_constFunc();




private:
	static const double staticConstInstance;  // ����ʽ static const ���������������ڸ���ֵ
	const double classConstInstance = 1.23;   // const �������������ڸ���ֵ

	// ������������������ڸ���ֵ������ʹ�� enum �����
	enum { enumConstInstance = 5 };
};


class CTestConstFunc
{
public:
	explicit CTestConstFunc(const std::string txt, const std::string id);
	~CTestConstFunc() {};

	// operator[] for const ����
	const char& operator[](std::size_t position) const;
	// operator[] for non_const ����
	char& operator[](std::size_t position);

private:
	std::string text;
};

class CTestConstVariable
{
public:
	explicit CTestConstVariable(char* txt, const std::string id);
	~CTestConstVariable() {};

	// operator[] for const ����
	char& operator[](std::size_t position) const;
	// operator[] for non_const ����
	char& operator[](std::size_t position);

	std::size_t length() const;
	

private:
	char* pText;
	// ���� mutable(�ɱ��) mutable �ͷŵ� not-static ��Ա������ bitwise constness Լ��
	mutable std::size_t textLength;   // ���һ�μ�����ı����鳤��
	mutable bool lengthIsValid;
};


class CTestConstNon_constFunc
{
public:
	explicit CTestConstNon_constFunc(const std::string txt, const std::string id);
	~CTestConstNon_constFunc() {};
	// ���������汾���� const �� non-const �����ظ�
	// operator[] for const ����
	const char& operator[](std::size_t position) const;
	// operator[] for non_const ����
	char& operator[](std::size_t position);
private:
	std::string text;
};