

using namespace std;

// ����3 ������ʹ�ø������� float ,double ,long double
// �����������ͼ�û�й涨ÿ������ռ�����ֽڣ�Ҳû�й涨�������ֱ�ʾ��ʽ
// sizeof(long double) vs ���� 8 ��GCC ���� 12

// ʮ����ת�����ƣ���Ҫ���������ֺ�С�����ֱַ�ת��
// ���У��������ֳ��� 2��ȡ������С�����ֳ���2��ȡ����λ
class AdviseThree
{
public:
	AdviseThree() {};
	~AdviseThree() {};

	void test01_error();
	void test01_right();

};