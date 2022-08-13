#include <stdio.h>

using namespace std;

// 建议2: 防止整数类型产生回绕与溢出

// 有符号与无符号整数间的区别在于怎样解释整数的最高位
// C编译程序认为：符号标志为0，则该数为正；符号标志为1，则该数为负

// 负数采用2的补码的形式来表示，即：
/*
	1.对原码各位求反(符号位除外)
	2.再将求反的结果加1
	3.最后将符号位设置为1
	例：在32位操作系统中，有符号整数 -2 的存储方法如下
	1,取绝对值2的二进制编码 00000000 00000000 00000000 00000010
	2.求反                  01111111 11111111 11111111 11111101
	3.求反结果加1			01111111 11111111 11111111 11111110
	4.符号位设置为1			11111111 11111111 11111111 11111110
*/

// 建议2-1 char 类型变量的值应该限制在 signed char 与 unsigned char 的交集范围内
// 优点=获得最大程度的可移植性，同时不会牺牲效率

// 实际上，char 类型存储的是整数而不是字符，为了处理字符，计算机使用一种数字编码的方式来操作
// 默认的 char 类型可以是 signed char 类型(取值范围 -127 ~ 127 ) 也可以是 unsigned char 类型(取值范围 0 ~ 255)

// 建议2-2 使用显式声明为 signed char 或 unsigned char 的类型来执行算数运算

// 建议2-3 使用 rsize_t 或 size_t 类型来表示一个对象所占用空间的整数值单位
// size_t 是一种无符号整数类型
// sizeof 操作符的结果返回 size_t 类型；该类型保证能容纳实现所建立的最大对象的字节大小。
// size_t 类型的限制是由 SIZE_MAX 宏定义的

// 建议2-4 禁止把 size_t 类型和它所代表的真实类型混用

// 建议2-5 小心使用无符号类型带来的陷阱

// 建议2-6 防止无符号整数回绕 
/*
	涉及无符号操作的计算永远不会产生溢出
	因为无法由最终的无符号整型表示的结果将会根据这种最终类型可以表示的最大值加1执行求模操作
	如果数值超过无符号整型数据的限定长度时就会发生回绕
	回绕：如果无符号整型变量的值超过了无符号整型的上限，就会返回0，然后又从0开始增大
	如果无符号整型变量的值低于无符号整型的下限，那么就会到达无符号整型的上限，然后从上限开始减小。
*/

// 建议2-7 防止有符号整数溢出
// 当两个操作数都是有符号整数时，就有可能发生整数溢出
// 程序很难区分先前计算出的结果是否正确，而且如果计算结果将作为一个缓冲区的大小、数组的下标、循环计数器与内存分配函数的实参等时将会非常危险
class AdviseTwo
{
public:
	AdviseTwo() {};
	~AdviseTwo() {};

	void test01_error(); 
	void test01_right();

	char* test02_error_copy(size_t n, const char* str);
	char* test02_right1_copy(size_t n, const char* str);
	char* test02_right2_copy(size_t n, const char* str);  // rsize_t 解决方法

	void test03_error();

	void test04_error();
	void test04_right();

	void test05_error_demo1();
	void test05_error_demo2(int argc, char* argv[]); // 回绕溢出示例
	void test05_error_demo3(int argc, char* argv[]);
	void test05_right_demo();

	void test06_error_demo1(); // 整数溢出示例

};