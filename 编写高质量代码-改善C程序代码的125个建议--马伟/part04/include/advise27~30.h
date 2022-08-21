#include <stdlib.h>
using namespace std;

// 建议27 理解函数声明
// 《C Traps and Pitfalls》一个例子：有一段程序存储在起始地址为0的一段内存上，要调用这段程序，该如何去做？
// 答案 ： (* (void (*)() ) 0 ) ();
// float* f1(); 返回 float* 的函数
// float (*f2)();  返回 float 的函数指针
// 一旦知道了如何声明一个给定类型的变量，该类型的类型转换符就很容易得到：只需要去掉声明中变量名和声明末尾的分号，再将剩余的部分用一个括号整个"封装"起来
// 即： float (*f2)() 函数指针的 类型转换符为 (float (*)())


//建议29 尽量使函数的功能单一
// 示例 ：利用 链栈 将数据逆序输出

// 建议30 避免把没有关联的语句放在一个函数中
// 为了提高代码的可复用性而刻意地将不同函数中使用的相同代码语句提出来，抽象成一个新的函数。
// 如果代码的关联度较高，并且完成同一个功能，是可取的。
// 如果把没有任何关联的语句放在一起，就会造成 维护、测试及升级非常麻烦，函数功能也不明确。

class Advise29
{
public:
	Advise29() {};
	~Advise29() {};

	void test_00_demo();
	void test_01_error_demo();
	void test_01_right_demo();

	void test_02_demo();

};