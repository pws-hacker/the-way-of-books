

using namespace std;

// 建议17 if 语句应该尽量保持简洁，减少嵌套的层数
// 建议17-1 先处理正常情况，再处理异常情况    如果把执行概率更大的代码放在后面，意味着 if 语句将进行多次无谓的比较
// 建议17-2 避免 "悬挂" 的 else  ,C 语言规则：else 始终与同一对括号内最近的未匹配的 if 相结合。  
// 建议17-3 避免在 if/else 语句后面加分号 ";"
// 建议17-4 对深层嵌套的 if 语句进行重构

class Advise17
{
public:
	Advise17() {};
	~Advise17() {};

	void test_01_error();
	void test_01_right();

};

// 建议18 谨慎 0 值比较
// 建议18-1 避免布尔型与 0或1 进行比较
// 建议18-2 整型变量应该直接与 0 进行比较 -> 不要模仿布尔型变量的风格
// 建议18-3 避免浮点变量用 "==" 或 "!=" 与 0 进行比较  
// C语言中 FLT_EPSILON 与 DBL_EPSILON 在 float.h 中定义
// C++  std::numeric_limits<float>::epsilon()  std::numeric_limits<double>::epsilon() 在 limits 中定义
// 建议18-4 指针变量应该用 "==" 或 "!=" 与 NULL 进行比较


class Advise18
{
public:
	Advise18() { flag = true; };
	~Advise18() {};

	void test_01_error();
	void test_01_right();

	// 如果两个同符号的浮点数之差的绝对值小于或等于某一个可接受的误差 EPSILON(即精度) ,就认为它们是相等的，否则就是不相等的 
	void test_02_error();  
	void test_02_right();
private:
	bool	flag;
};

// 建议19 避免使用嵌套的 "? : "
// 嵌套使用可以使代码变得简洁，但代码的可读性却因此降低了不少。
// 为了能够提高程序的执行效率，应该把时间花在寻求 可替代的高效算法上，而不是一味地追求以某个稍微不同的方式来实现同一个算法上。
class Advise19
{
public:
	Advise19() { };
	~Advise19() {};

	void test_01_error();
	void test_01_right();

private:
};