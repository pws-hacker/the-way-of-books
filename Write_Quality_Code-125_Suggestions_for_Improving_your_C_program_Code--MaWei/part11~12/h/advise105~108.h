
using namespace std;

// 建议105 确保安全释放内存
// void free(void* ptr);
// 函数用于释放指针ptr所指向的内存空间，如果 ptr 为 NULL，或者指向不存在的内存块，将不做任何操作

// 建议105-1 malloc等内存分配函数与 free 必须配对使用
// 建议105-2 在 free 之后必须为指针赋一个新值，不用则置为NULL

// 建议106 避免内存越界
// 内存越界访问分如下两种：
//   1.读越界，即读了不属于自己的数据
//	 2.写越界，又称缓冲区溢出

// 建议106-1 避免数组越界
// 建议106-2 避免 sprintf,vsprintf,strcpy,strcat与 gets 越界
// 尽量使用安全的字符串库函数 snprintf,strncpy,strncat与 fgets 来替换
// 建议106-3 避免 memcpyt 与 memset 函数长度越界
// 建议106-4 避免忽略字符串最后的 '\0' 字符而导致的越界
// 在 C 语言中，字符串是一个以 '\0' 字符结尾的字符数组，但是当使用 strlen 库函数来获取字符串长度时，其长度值并不包含 '\0'

// 建议107 避免内存泄露
// 内存泄露常见场景
// 1.指针重新赋值
// 2.错误的内存释放
// 3.返回值的不正确处理  某些函数返回对动态分配的内存的引用
// 4.在内存分配后忘记使用 free 进行释放
//	a.确保没有在访问空指针
//	b.每个内存分配函数都应该有一个 free 函数与之对应，alloca 函数除外
//  c.每次分配内存之后都应该及时初始化，可以结合 memset 函数进行初始化，calloc 函数除外
//  d.每当向指针写入值时，都要确保对可用字节数和所写入的字节数进行交叉核对
//  e.在对指针赋值前，一定要确保没有内存位置会 变为孤立的
//  f.每当释放结构话的元素(而该元素又包含指向动态分配的内存位置的指针)时，都应先遍历子内存位置并从那里开始释放，然后再遍历回父节点
//  g.始终正确处理返回动态分配的内存引用的函数返回值

// 建议108 避免 calloc 参数相乘的值超过 size_t 表示的范围
// void* calloc(size_t num,size_t size) 通过参数 num 乘以 size 来决定需要分配多少内存
// 注意：可分配的内存的最大数量需要限制在 小于 SIZE_MAX 的值内

class Advise105
{
public:
	Advise105() {};
	~Advise105() {};

	void test_01_demo();

	void test_02_error();
	void test_02_right();

	// 内存泄露
	void test_03_error();
	void test_03_right();
	void test_04_error();
	void test_04_right();
	void test_05_error();

	void test_06_demo(size_t num);
};