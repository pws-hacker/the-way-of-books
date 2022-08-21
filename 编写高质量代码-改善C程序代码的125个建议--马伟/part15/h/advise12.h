using namespace std;

// 建议12 尽量减少使用除法运算与求模运算
// 对计算机来说，除法与求模是整数算术运算中最复杂的运算 在嵌入式领域会消耗大量资源

// 建议12-1 用倒数相乘来实现除法运算

class Advise12
{
	Advise12() {};
	~Advise12() {};

	void test_right_demo();	// 尽量使用其他方法来代替除法与求模运算

};