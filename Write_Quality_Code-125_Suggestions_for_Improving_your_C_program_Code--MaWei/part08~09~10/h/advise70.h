

using namespace std;

// 建议70 不要忽视字符串的 null('\0') 结尾符
// C 语言的字符串实际上就是一个以 null('\0') 字符结尾的字符数组。
// 建议70-1 正确认识字符数组和字符串
// 对于字符数组，其长度是固定的，其中任何一个数组元素都可以为 null 字符，因此字符数组不一定是 字符串
// 对于字符串，必须以 null 结尾，其后的字符不属于该字符串，字符串一定是字符数组。
// 建议70-2 字符数组必须能够同时容纳字符数据和 null 结尾符
// 建议70-3 谨慎字符数组的初始化
		// char cArr[6] = { 'I','L','O','V','E','C' };
		// char sArr[6] = "ILOVEC;  // 显然空间不足
		// 建议 char sArr[] = "ILOVEC; 这样写

// 建议71 尽量使用 const 指针来引用字符串常量
// 建议72 区别 strlen 函数与 sizeof 运算符
// strlen 是一个函数，用来计算指定字符串 str 的长度，但不包括结束字符
// sizeof 在编译时计算缓冲区的长度，不能用来返回动态分配的内存空间的大小

// 建议73 在使用不受限制的字符串函数时，必须保证结果字符串不会溢出内存
// 建议73-1 避免字符串拷贝发生溢出
// 建议73-2 区别 串 拷贝 strcpy 与内存拷贝 memcpy
// 从 源src 所指的内存地址的起始位置开始复制 len 个字节到目标 dest 所指的内存地址的起始位置中。如果两个地址存在重叠，则最终行为未定义
// 区别
// 1.拷贝对象不同， strcpy 只能拷贝字符串，memcpy 可以拷贝任意对象
// 2.拷贝方法不同 strcpy 不需要指定拷贝的长度，遇到字符串末尾符 结束拷贝， memcpy 根据第三个参数 len 来决定复制长度
// 使用 memcpy 注意：
// a.如果目标数组 dest 本身已有数据，拷贝会覆盖原有数据(最多覆盖len)
// b.dest 和 src 所指的内存区域是可以重叠的。但结果是未定义的

// 建议73-3 避免 strcpy 与 memcpy 函数内存重叠
// 1.拷贝的目的地址(dest)数据覆盖了源地址(src)
// 2.拷贝的目的地址(dest)所指的区域本来就是源地址(src)的一部分
// 建议73-4 去呗字符串比较与内存比较


class Advise70
{
public:
	Advise70() {};
	~Advise70() {};

	void test_01_demo(void); // 测试 字符数组和字符串的区别

	void test_02_error(void); // 测试修改字符串常量
	void test_02_right(void);

	void test_03_error(void); // strcpy 拷贝字符串函数 发生溢出
	void test_03_right(void); // strcpy 拷贝字符串函数 发生溢出

	void test_04_demo(void);

	void test_05_error1(void); // strcpy 内存重叠
	void test_05_error2(void); // memcpy 内存重叠
	void test_05_right(void);  // 正确写法
};