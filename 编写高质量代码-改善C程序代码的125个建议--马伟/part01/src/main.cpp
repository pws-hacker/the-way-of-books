#include "advise02.h"
#include <stdlib.h>

int main()
{
	AdviseTwo adviseTwo;
	adviseTwo.test01_error();
	adviseTwo.test01_right();
	const char* str = "hello world!";
	size_t str_length = 13 ;
	char* str_copy = adviseTwo.test02_error_copy(str_length, str);
	printf("str_copy = %s\n", str_copy);

	adviseTwo.test04_error();

	adviseTwo.test05_error_demo1();
	printf("\n");
	char* argv[3];
	argv[0] = (char*)"a";
	//argv[1] = (char*)"65536";
	argv[1] = (char*)"5";
	argv[2] = (char*)"abcdefghijklmnopq";
	adviseTwo.test05_error_demo2(3,argv);

	printf("\n");
	char* len[2];
	len[1] = (char*)"3";
	//len[1] = (char*)"1073741824";
	adviseTwo.test05_error_demo3(sizeof(len) / sizeof(char*),len);

	printf("\n");
	adviseTwo.test06_error_demo1();
	system("pause");
	return 0;
}