#pragma once

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


#define INDEFINE_INSTANCE 1.23
// ��Ϊ const
const double constInstance = 1.23;

class Class01
{
public:
	void testMacroError();
	void testInlineFunc();



private:
	static const double staticConstInstance;  // ����ʽ static const ���������������ڸ���ֵ
	const double classConstInstance = 1.23;   // const �������������ڸ���ֵ

	// ������������������ڸ���ֵ������ʹ�� enum �����
	enum { enumConstInstance = 5 };
};

