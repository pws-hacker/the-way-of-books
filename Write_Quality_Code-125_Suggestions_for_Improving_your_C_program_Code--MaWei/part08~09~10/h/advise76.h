

using namespace std;

// 建议76 谨慎使用 printf 和 scanf 函数
// scanf 缓冲区问题

// 建议77 谨慎文件打开操作
// 建议77-1 正确指定 fopen 的 mode 参数
// r(read) w(write) a(append) t(text) b(banary二进制模式) +(读取和写入)
// 建议77-2 必须检查 fopen 函数的返回值
// 建议77-3 尽量避免重复打开已经被打开的文件
// 建议77-4 区别 fopen 与 fopen_s
// 由于 fopen 函数打开的文件能够共享，给安全埋下了很大的隐患
// 如果 fopen_s 函数打开，则不能被共享，别人无法 读/写和访问该文件
// fopen_s 返回一个 errno_t 类型，若成功返回 0 ，失败返回 非 0
// 建议77-5 区别 fopen 与 freopen 函数
// freopen 函数主要用于 将标准输入/输出流(stdin:标准输入流，stdout:标准输出流，stderr:标准错误输出流) 重定向到文件中
// 如果成功重定向文件流，将会返回一个 filename 所指定文件的指针，否则返回 NULL

// 建议79 正确理解 EOF 宏
// EOF 宏不但能够表示读文件到了结尾这一状态(可以用 fof() 来检验) 还能表示 I/O 操作中的读、写错误(通常可以用 ferror() 来检测)以及其他一些关联操作的错误状态

// 建议80 尽量使用 feof 和 ferror 检测文件结束和错误
// 建议81 尽量使用 fgets 替换 gets 函数
// 建议82 尽量使用 fputs 替换 puts 函数
// 建议83 合理选择单个字符读写函数
// 建议84 区别格式化读写函数
// 建议85 尽量使用 fread 与 fwrite 函数来读写二进制文件
// 建议86 尽量使用 fseek 替换 rewind 函数
// 建议87 尽量使用 setvbuf 替换 setbuf 函数
// 建议88 谨慎 remove 函数删除已打开的文件
// 建议89 谨慎 rename 函数重命名已经存在的文件
// 


class Advise76
{
public:
	Advise76() {};
	~Advise76() {};

	void test_01_demo();
	void test_02_demo();
	void test_03_demo();
	void test_04_demo(); // 重定向

	void test_05_error();
	void test_05_right();


};