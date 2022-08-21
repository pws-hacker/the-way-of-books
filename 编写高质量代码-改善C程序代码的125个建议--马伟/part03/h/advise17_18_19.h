

using namespace std;

// ����17 if ���Ӧ�þ������ּ�࣬����Ƕ�׵Ĳ���
// ����17-1 �ȴ�������������ٴ����쳣���    �����ִ�и��ʸ���Ĵ�����ں��棬��ζ�� if ��佫���ж����ν�ıȽ�
// ����17-2 ���� "����" �� else  ,C ���Թ���else ʼ����ͬһ�������������δƥ��� if ���ϡ�  
// ����17-3 ������ if/else ������ӷֺ� ";"
// ����17-4 �����Ƕ�׵� if �������ع�

class Advise17
{
public:
	Advise17() {};
	~Advise17() {};

	void test_01_error();
	void test_01_right();

};

// ����18 ���� 0 ֵ�Ƚ�
// ����18-1 ���Ⲽ������ 0��1 ���бȽ�
// ����18-2 ���ͱ���Ӧ��ֱ���� 0 ���бȽ� -> ��Ҫģ�²����ͱ����ķ��
// ����18-3 ���⸡������� "==" �� "!=" �� 0 ���бȽ�  
// C������ FLT_EPSILON �� DBL_EPSILON �� float.h �ж���
// C++  std::numeric_limits<float>::epsilon()  std::numeric_limits<double>::epsilon() �� limits �ж���
// ����18-4 ָ�����Ӧ���� "==" �� "!=" �� NULL ���бȽ�


class Advise18
{
public:
	Advise18() { flag = true; };
	~Advise18() {};

	void test_01_error();
	void test_01_right();

	// �������ͬ���ŵĸ�����֮��ľ���ֵС�ڻ����ĳһ���ɽ��ܵ���� EPSILON(������) ,����Ϊ��������ȵģ�������ǲ���ȵ� 
	void test_02_error();  
	void test_02_right();
private:
	bool	flag;
};

// ����19 ����ʹ��Ƕ�׵� "? : "
// Ƕ��ʹ�ÿ���ʹ�����ü�࣬������Ŀɶ���ȴ��˽����˲��١�
// Ϊ���ܹ���߳����ִ��Ч�ʣ�Ӧ�ð�ʱ�仨��Ѱ�� ������ĸ�Ч�㷨�ϣ�������һζ��׷����ĳ����΢��ͬ�ķ�ʽ��ʵ��ͬһ���㷨�ϡ�
class Advise19
{
public:
	Advise19() { };
	~Advise19() {};

	void test_01_error();
	void test_01_right();

private:
};