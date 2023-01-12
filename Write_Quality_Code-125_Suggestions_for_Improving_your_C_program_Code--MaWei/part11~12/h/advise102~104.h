

using namespace std;

// ����102 ǳ̸������ڴ�ṹ
/*
* ���ֲ�ͬ����������
* 1.�洢ʱ������
*	a.δ��ʼ�����ݶ�
*	b.�ѳ�ʼ�����ݶ�
*	c.�����

* 2.����ʱ������
*	a.ջ(stack)
*	b.��(heap)
*	c.δ��ʼ�������ݶ�(.bss)
*	d.�ѳ�ʼ�������ݶ�(.data)
*	e.�����(.text)
*/

// ����103 ǳ̸�Ѻ�ջ
// a.���ݽṹ�еĶѺ�ջ
	// 1.ջ
	// �Ƚ���������ȳ�
	// ʹ�����ַ�ʽ��ʵ�֣�ʹ���������ʽ��ʵ��ջ������ջҲ��Ϊ��̬ջ
	// ʹ����������ʽ��ʵ��ջ������ջҳ��Ϊ��̬ջ
	// 2.��
	// ������һ�־���������������ݽṹ��������ʵ�����ȶ���
	// 
// b.�ڴ�����еĶѺ�ջ
// �ڴ���䷽ʽ 
//   1.�Ӿ�̬�洢�������
//   2.��ջ�Ϸ���
//   3.�Ӷ��Ϸ���

// �ڴ�����е�ջ�����Ҫ������������
// 1.�������ͷŷ�ʽ
// 2.�������Ƭ����
// �Զ���˵��Ƶ��������ͷŲ�ͬ��С�Ķѿռ��Ʊػ�����ڴ�ռ�Ĳ��������Ӷ����³���Ч�ʽ��͡���ջ��˵��������������
// 3.�����Ч��
// ջ�ǻ���ϵͳ�ṩ�����ݽṹ������� ���ڵײ��ջ�ṩ֧��
// ������ C/C++ �������ṩ�ģ��ѵķ���Ч��Ҫ��ջ�ͺܶ�
// 4.����Ĵ�С����
// ����ϵͳ�����������洢�ռ��ڴ��ַ(�ڴ���������),ͬʱ�����ı����������ɵ͵�ַ��ߵ�ַ���еģ����ڴ�������С�����ڼ����ϵͳ����Ч�������ڴ�
// ջ��һ���������ڴ����򣬵�ַ���������������½��еģ����ڴ��ַ��С�ķ�������
// ջ���ĵ�ַ��ջ���������һ�㶼����ϵͳԤ�ȹ涨�õģ��������Ŀռ䳬��ջ��ʣ��ռ�ʱ��������ʾ�����������ڶѣ��ܹ���ջ�л�õĿռ���Խ�С
// 5.�洢������

// ����104 �����������ڴ�
// 1.void* malloc(size_t size); 
// �Ӷ��з����ڴ�ռ䣬�ڴ�����СΪ size.����ڴ����ɹ��������׵�ַ�����ʧ�ܷ��� NULL
// 2.void* calloc(size_t num,size_t size);
// �Ӷ��з��� num �����ڵ��ڴ浥Ԫ��ÿ���ڴ浥Ԫ�Ĵ�СΪ size������ڴ����ɹ����ص�һ���ڴ浥Ԫ���׵�ַ�����򷵻�NULL
// ��ʹ�� calloc ���������ڴ�ʱ���Ὣ�ڴ����ݳ�ʼ��0��melloc �򲻻�
// 3.void* realloc(void* ptr,size_t size);
// ���Ķ����Ѿ����õ��ڴ�ռ䣬������ͼֱ�ӴӶ��ϵ�ǰ�ڴ�κ�����ֽ��л�ø�����ڴ�ռ�
// �����жϵ�ǰ��ָ���Ƿ����㹻�������洢�ռ䣬����У������� ptr ָ��ĵ�ַ������ ptr����
// �����ǰ�ڴ�κ���Ŀ����ֽڲ��������Ȱ��� size ָ���Ĵ�С����ռ�(ʹ�ö��ϵ�һ���ܹ�������һҪ����ڴ��),����ԭ�����ݴ�ͷ��β�������·�����ڴ�����
// Ȼ���ͷ�ԭ��ptr��ָ�ڴ�����ͬʱ�����·�����ڴ�������׵�ַ�������·���洢����ĵ�ַ��
// 4.void* alloca(size_t size);
// ��ջ�з����ڴ�ռ䣬�ڴ�����СΪ size ,����ɹ������׵�ַ��ʧ�ܷ���NULL
// �����ͷ��ڴ�ռ䣬�Զ��ͷ�
// 5.void* aligned_alloc(size_t alignment,size_t size);
// ���ڱ߽����Ķ�̬�ڴ���亯��
// ���ղ��� alignment �涨�Ķ��뷽ʽΪ������ж�̬�洢���� size �� size_t ���͵Ĵ洢��Ԫ
// ����ɹ������׵�ַ�����ʧ�ܷ��� NULL
// ����� malloc ��aligned_allo ��֤���صĵ�ַ���ܶ���ģ�ͬʱҪ�� size������ alignment ������������

// ����104-1 ���ڴ���亯���ķ���ֵ������м��
// ����104-2 �ڴ���Դ�ķ������ͷ�Ӧ���޶���ͬһģ�����ͬһ������ڽ���
// ����ڴ�ķ�����ͷ��ڲ�ͬ��ģ��������ڣ�������Ӵ����Ա׷���ڴ���������ڵĸ��������ҿ��ܻᵼ���ڴ�й¶���ڴ�˫���ͷţ��Ƿ������Ѿ��ͷŵ��ڴ棬д�����ͷŻ�δ������ڴ����������

// ����104-3 ������ڴ���亯���ķ���ָ�����ǿ������ת��
// ����104-4 ȷ��ָ��ָ��һ��Ϸ����ڴ�
// ����Ϊ�ṹ��ָ����������ڴ滹�ǲ����ģ�������Ϊ�ṹ���Ա�е�����ָ����������㹻���ڴ�
// ����104-5 ȷ��Ϊ��������㹻���ڴ�ռ�
// ����104-6 ��ָֹ���㳤�ȵ��ڴ����
// ����ڳ�������ͼ���� malloc/calloc/realloc ���ڴ���亯�� ���䳤��Ϊ 0 ���ڴ棬��ô����ζ���ɾ��������������
// ���ܷ��� NULL ��ָ�룬�ֻ����ǳ���Ϊ�����ֵ�ģ��Ӷ����²�������Ԥ�ϵĽ��

// ����104-7 ������͵Ķ�ջ����
// C99 ��׼�����˶Ա䳤�����֧�֣�����䳤����ĳ��ȴ���δ���κμ��ʹ������������ױ�����������ʵʩ���� �� Dos����
// ����104-8 �����ڴ����ɹ�������δ��ʼ��  memset
//  ����ԭ��
//	1.û�г�ʼ���Ĺ���
//  2.����Ϊ�ڴ��Ĭ�ϳ�ֵȫ��Ϊ0���Ӷ��������ó�ֵ����(������)

class Advise102
{
public:
	Advise102() {};
	~Advise102() {};

	void test_01_demo();

	void test_02_demo();

};