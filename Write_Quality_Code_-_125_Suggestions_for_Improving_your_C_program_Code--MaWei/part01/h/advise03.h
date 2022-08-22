

using namespace std;

// 建议3 尽量少使用浮点类型 float ,double ,long double
// 浮点数据类型既没有规定每种类型占多少字节，也没有规定采用哪种表示形式
// sizeof(long double) vs 上是 8 ，GCC 上是 12

// 十进制转二进制，需要把整数部分和小数部分分别转换
// 其中，整数部分除以 2，取余数，小数部分乘以2，取整数位
class AdviseThree
{
public:
	AdviseThree() {};
	~AdviseThree() {};

	void test01_error();
	void test01_right();

};