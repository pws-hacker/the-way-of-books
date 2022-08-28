
using namespace std;

// ����41 ����ָ������Ĵ洢ʵ��
// ָ���4����������
// 1.ָ������� ���﷨�Ƕȿ���ֻҪ��ָ������������ָ������ȥ����ʣ�µĲ��־���ָ������
// 2.ָ����ָ������� ���﷨����ֻ��Ҫ��ָ����������е�ָ�����ֺ�������ߵ�ָ�������� "*" ȥ����ʣ�µĲ��־���ָ����ָ�������
// 3.ָ���ֵ 
// ָ���ֵ��ָָ�뱾���洢����ֵ�����ֵ������������һ����ַ��������һ��һ�����ֵ
// ˵һ��ָ���ֵ��xx���൱��˵��ָ��ָ������ xx Ϊ�׵�ַ��һƬ�ڴ�����һ��ָ��ָ����ĳ���ڴ������൱��˵��ָ���ֵ������ڴ�������׵�ַ
// 4.ָ�뱾����ռ�ݵ��ڴ���  ռ��4���ֽ�

// ����42 ָ����������ʼ��
// ʹ��δ��ʼ����ָ������ĺ���ǲ�ȷ���ģ���ȫȡ���ڳ���Ա��������
// ����43 ���� "int* p = NULL" �� "*p = NUL"
// 
// ����44 �����(null)ָ����NULLָ��
// ����44-1 �����(null)ָ����NULLָ��ĸ���
// ����44-2 ��NULLָ����ֹ�Եݹ����ݽṹ�ļ������
// ����44-2 ��NULLָ����ֹ�Եݹ����ݽṹ�ļ������
// ����44-3 ��NULLָ������������ʧ��ʱ�ķ���ֵ
// ����44-4 ��NULLָ��������ֵ ����ֵ�Ǳ�־�����β��һ���ض�ֵ��
// ����44-5 �����NULLָ�������

// ����45 ����ʹ�� void ָ��
// �κ����͵�ָ�붼����ֱ�Ӹ�ֵ�� void ָ�룬Ҫ�� void ָ�븳ֵ���������͵�ָ�룬�������ǿ������ת��
// ����45-1 ����� void ָ�������������
// �����㷨������ָ�����ȷ��֪����ָ���������͵Ĵ�С��Ҳ���Ǳ���֪���ڴ�Ŀ�ĵ�ַ��ȷ��ֵ
// ����45-2 ��������Ĳ�����������������ָ�룬Ӧ�ý����������Ϊ void*

// ����46 ����ʹ��ָ��ĳ���ȷ������ָ�����͵ĳ���
// ����47 �����ָ��ת��Ϊ����Ҫ����ϸ��ָ������ �� char* ָ������ת void* ת int*
// ����48 ���⽫һ�����͵Ĳ�����Ӧ������һ�ֲ����ݵ�����
// ��C�����У�������ͬ����������֮���໥ת��
// ���ڴ�����������͵��ڲ�������ʽ��������ϵͳ���������һ�����͵Ĳ�����Ӧ������һ�ֲ����ݵ����ͣ��Ϳ��ܲ���һЩδ֪���������
// �����Ĵ���Ҳ�����п���ֲ�ԡ�
// ������һ�㽫������λ�νṹ��Ա���䵽��ͬ�� int ���ȵĴ洢�ռ䣬ֻҪ������ȫ�ʺ����ִ洢��λ��
// ������һ���洢��λ�У��ڴ�ķ���˳���ɱ���������Ķ�
// ��Щ���������� "��������" ������һ����Առ�ݴ洢��λ�ĵ׶�λ��
// ��Щ���������� "��������" ������һ����Առ�ݴ洢��λ�ĸ߶�λ��

// 
struct int32
{
	unsigned int ui1 : 8;
	unsigned int ui2 : 8;
	unsigned int ui3 : 8;
	unsigned int ui4 : 8;  // ռ�� 8 λ����˼
};
class Advise40
{
public:
	Advise40() {};
	~Advise40() {};

	void test_01_error();

	void test_02_demo();
	double* test_03_error(size_t num);

	void test_04_error(void);
	void test_04_right(void);

	void test_05_error(void);
	void test_05_right(void);
};

// ����49 ����ָ��������֮���ת��
// C ����Ψһ������ָ�������֮���໥ת����ֵʱ ����0 ������֮�⣬�����κ�������ָ��֮����໥ת�������ܳ��ֲ����ĺ��������ȡ���ڱ༭��
// һ���������Ϳ���ת��Ϊ�κ�ָ������
// �κ�ָ������Ҳ����ת��Ϊһ����������

// ����50 ���� "const int* p" �� "int* const p"

// ����51 �������⺯�������Ĵ��ݷ�ʽ
// ����51-1 ���⺯�������Ĵ��ݹ���  ����Լ��
// ����51-2 ���պ����Ĳ������ݷ�ʽ   1.ֵ���� 2.��ַ����
// ����51-3 ��������Ĳ�����ָ�룬�����ø�ָ�������붯̬�ڴ�
// ����51-4 ��������ʹ�ÿɱ����

class Advise50
{
public:
	Advise50() {};
	~Advise50() {};


	void test_01_demo(void);

	void test_02_demo(void);
	void test_03_demo(void);

	void test_04_demo(void);
};