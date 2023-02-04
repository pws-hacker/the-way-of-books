#pragma once


class Class03
{
public:
	void testInts();

};

// ������ ���������

// ����18 �ýӿ����ױ���ȷʹ�ã����ױ�����
//	������һ�������ױ���ȷʹ�ã������ױ����á��Ľӿڣ����ȱ��뿼�ǿͻ���������ʲô���Ĵ���
//	���ٽ���ȷʹ�á��İ취�����ӿڵ�һ���ԣ��Լ����������͵���Ϊ����
//	����ֹ���á��İ취�������������͡����������ϵĲ�������������ֵ���Լ������ͻ�����Դ��������
//	tr1::shared_ptr ֧�ֶ�����ɾ�������ɷ��� DLL ���⣬�ɱ��������������

class CDate
{
public:
	// �ͻ����ܻ᷸��������
	//	1.CDate d1(30,3,1995);   // ����˳�����
	//	2.CDate d2(2,30,1995);   // �Ƿ����� 2 ��û�� 30��
	CDate(int month, int day, int year) {};
};

struct SYear { explicit SYear(int y) {}; };
struct SMonth { explicit SMonth(int m) {}; };
struct SDay { explicit SDay(int d) {}; };

// ����ȷ�ϣ�������ֵ
class CMonth
{
public:
	static CMonth Jan() { return CMonth(1); };
private:
	explicit CMonth(int m) { };				// ˽�л� ��ֹ�����µ��·�
};

class CDateRemake
{
public:
	// ����� ���Ƕ������ص��������Ϳ�Ԥ�����ӿڱ����á�
	// �� SDay SMonth SYear ��Ϊ�����Ҿ���ֶ����� classes ����װ�������ݣ��� struct Ч����Ҫ��
	CDateRemake(const SMonth& month, const SDay& day, const SYear& year) {};
};


// ����19 ��� class ������� type
//	���غ����Ͳ������������ڴ�ķ���͹黹���������ĳ�ʼ�����ս�
//	���ź͡���������ߵ������������������ʱ��һ���Ľ��������� class �����

// ��Ƹ�Ч�� classes Ӧ�����Լ�������
//		1.�� type �Ķ���Ӧ����α�����������
//			Ӱ�� ���캯�������������Լ��ڴ���亯�����ͷź��� (operator new,operator new[],operator delete,operator delete[])
// 
//		2.����ĳ�ʼ���Ͷ���ĸ�ֵ����ʲô���Ĳ��
//			���� ���캯���͸�ֵ(assgnment)������ ����Ϊ���Լ����Ĳ���
// 
//		3.�� type �Ķ�������� pass by value ����ζ��ʲô
//			���� copy ���캯��
// 
//		4.ʲô���� type �ġ��Ϸ�ֵ��
//			�� class �ĳ�Ա�������ԣ�ֻ��ĳЩ��ֵ������Ч�ġ���Щ��ֵ�����������ά���� Լ��������Ҳ������Ա����������е� �����鹤��

//		5.����� type ��Ҫ���ĳ���̳�ͼϵ��
//			�ر��ע ����� ��virtual �� non-virtual ��������Ӱ��
// 
//		6.����� type ��Ҫʲô����ת��
//			���ϣ������ T1 ����ʽת��Ϊ T2���ͱ����� class T1 ��дһ������ת������(operator T2)
//			������ class T2 ��дһ�� non-explicit-one-argument(�ɱ���һʵ�ε���)�Ĺ��캯����
//			���ֻ���� explicit ���캯�����ڣ���Ҫдר�Ÿ���ִ��ת���ĺ������Ҳ���Ϊ����ת��������
//				(type conversion operators) �� non-explicit-one-argument ���캯��
// 
//		7.ʲô���Ĳ������ͺ����Դ��� type �����Ǻ����
//			����������Щ����
// 
//		8.ʲô���ı�׼����Ӧ�ò���
//			����Ϊ private ��
// 
//		9.˭��ȡ���� type �ĳ�Ա
//			�ĸ���ԱΪ public protected private ,������һ�� classes �� functions Ӧ���� friends���Լ�������Ƕ������һ�����Ƿ����
// 
//		10.ʲô���� type �ġ�δ�����ӿڡ�
//			��Ч�ʣ��쳣��ȫ���Լ���Դ����(��������������Ͷ�̬�ڴ�)�ṩ���ֱ�֤
// 
//		11.����� type �ж�ôһ�㻯
//			�������һ���� types ���壬Ӧ�ö���һ�� �µ� class template
// 
//		12.�������Ҫһ���� type ��
//			���ֻ�Ƕ����µ� derived class �Ա�Ϊ���е� class ��ӻ��ܣ������Ƿ���һ������ non-member ���� �� templates ���ܴﵽĿ��

// ����20 ���� pass-by-reference-to-const �滻 pass-by-value
//		pass-by-value ��ʱ
//		������ �������ͣ���������ʹ�� pass-by-value �Ƚ��ʵ�

// ����21 ���뷵�ض��󣬱����뷵���� reference


