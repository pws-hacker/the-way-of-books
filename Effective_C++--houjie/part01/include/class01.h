#pragma once
#include <string>
#include <list>

// ��һ�� �Լ�ϰ�� C++

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


// ����04 ȷ������ʹ��ǰ���ȱ���ʼ��
// ��Щ�ﾳ��δ�ػ��ʼ��

// array( ����C���� )����֤�����ݳ�ʼ������ vector ( ���� C++ STL) �д˱�֤
// ��Ѵ���ʽ����Զ��ʹ�ö���֮ǰ�Ƚ�����ʼ��

// �������  ��ֵ  ��   ��ʼ��
// ��Ա����������������(��ô���ʼ���븳ֵ�ĳɱ���ͬ)��Ҳһ��Ҫʹ�ó�ֵ�С�
// �����Ա������ const �� reference �����Ǿ�һ����Ҫ��ֵ�����ܱ���ֵ
// ������Ա�����ĳ�ʼ�����д����ԣ������ʼ�� array ʱ��Ҫָ����С����˴����С���Ǹ���Ա�����������г�ֵ

// ���뵥Ԫ��ָ������һĿ���ļ�����ЩԴ�룬���������ǵ�һԴ���ļ��������������ͷ�ļ�
// ���⣺���ĳ���뵥Ԫ�ڵ�ĳ�� non-local static ����ĳ�ʼ������ʹ������һ���뵥Ԫ�ڵ�ĳ�� non-local static����
//		�����õ���������������δ����ʼ������ΪC++�ԡ����岻ͬ���뵥Ԫ�ڵ� non-local static ���󡱵ĳ�ʼ����������ȷ����

// ��Ҫ���κ�һ�� non-const static �������� local �� non-local ,
//		�ڶ��̻߳����¡��ȴ�ĳ�·������������鷳
// ���и����Ľ�������ǣ��ڳ���ĵ��߳������׶��ֹ��������� reference-returning ����
//		���������ʼ���йص� ���������ơ�


// �ڶ��� ���죬��������ֵ

// ����05 �˽� C++ ĬĬ��д��������Щ����
//  �������ڵ���ʱ�ᴴ��  Ĭ�Ϲ��캯�� �������캯�� �������� ������Щ�������� public �� inline
//  ���������һ���вι��캯�������������ٴ���Ĭ�Ϲ��캯��

//  ��һ���ں� reference ��Ա�� class ��֧�ָ�ֵ�����������Լ����� copy assignment ������
//  ��� const ��ԱҲһ�� 
//  ���ĳ�� ���� �� copy assignment ����������Ϊ private ���༭�����ܾ�Ϊ�� ������ ���� 
//  copy assignment ������
//  �����һ���ں� reference ���� const  ��Ա����������֧�ָ�ֵ�����������Լ����� copy assignment ������

class TestConstructor
{
public:
	TestConstructor() {};		// Ĭ�Ϲ��캯��
	~TestConstructor() {};		// ��������
	TestConstructor(const TestConstructor& test) {};  // �������캯��

	TestConstructor& operator=(const TestConstructor& rhs) {};   // copy assignment ������
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
// ��Ϊ const
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
	static const double staticConstInstance;  // ����ʽ static const ���������������ڸ���ֵ
	// class ר������������ static ��Ϊ�������ͣ���Ҫ���⴦��
	static const int staticConstInstance2 = 1;  // ����ʽ static const ������Ϊ ���� ���������������ڸ���ֵ
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

class CTestVariableInitialize
{
public:
	CTestVariableInitialize(const std::string& name,const std::list<int>& idList);
	~CTestVariableInitialize();
private:
	std::string m_sName;
	std::list<int> m_listId;

};