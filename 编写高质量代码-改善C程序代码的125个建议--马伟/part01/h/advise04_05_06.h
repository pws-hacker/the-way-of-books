using namespace std;

// 建议4 数据类型转换必须做范围检查
// 数据类型转换一般分为 隐式转换和显式转换，也成为自动转换和强制转换

// 隐式转换（4种）
// 1.一般算数转换：通过某些运算符将操作数的值从一种类型自动转换成另一种类型，这一规则为"由低级向高级转换"
// char,short -> int -> unsigned -> long -> double <- float
// 需要注意：所有的浮点运算都是以双精度进行的，即使表达式中仅含 float 单精度变量，也是先转换成 double 类型后再进行运算
// 同时，char 类型的变量和 short 类型的变量参与运算，则必须先转成 int 类型
// 2.输出转换
// 3.赋值转换
// 4.函数调用转换

// 显示转换（2种）
// 1.强制性数据类型转换
// 2.利用标准函数转换

// 建议4-1 整数转换为新类型时必须做范围检查
// 1.无符号类型与有符号类型进行互换时，必须进行取值范围的验证
// 2.在数据类型由"高级向低级"转换的时候，同样必须进行取值范围验证

// 建议4-2 浮点数转换为新类型时必须做范围检查


class AdviseFour
{
public:
	AdviseFour() {};
	~AdviseFour() {};

	void test01_right();

};

// ANSI 标准没有准确定义像 char int 和 long 这样的内部数据类型，而是由编译器决定的
class AdviseFive
{
public:
	AdviseFive() {};
	~AdviseFive() {};

	void test01_error_demo();

};

// 建议6 使用 typedef 来定义类型的新别名
// 建议6-1 掌握 typedef 的 4种应用形式
// 1.为基本数据类型定义新的类型名
// 2.为自定义数据类型(结构体、共同体和枚举类型)定义简洁的类型名称
// 3.为数组定义简洁的类型名称
// 4.为指针定义简洁的名称

// 建议6-2 小心使用 typedef 带来的陷阱
// 建议6-3 typedef 不同于 #define -> typedef 用来定义一种类型的新别名，不同于宏，不是简单的字符串替换
class AdviseSix
{
public:
	AdviseSix() {};
	~AdviseSix() {};

	void test01_right_demo();

	void test02_error_demo();
};

