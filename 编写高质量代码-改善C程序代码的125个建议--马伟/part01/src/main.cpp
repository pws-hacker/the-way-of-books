#include "advise02.h"
#include "advise04_05_06.h"
#include "advise07_08_09.h"
#include "advise10_11_12.h"
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

	AdviseFour adviseFour;
	adviseFour.test01_right();

	printf("\n");
	AdviseFive adviseFive;
	adviseFive.test01_error_demo();

	AdviseSix adviseSix;
	adviseSix.test01_right_demo();
	adviseSix.test02_error_demo();

	printf("\n");
	AdviseEight adviseEight;
	adviseEight.test_01_right();
	adviseEight.test_02_right();
	adviseSix.test02_error_demo();

	printf("\n");
	AdviseNine adviseNine;
	adviseNine.test_01_right();

	printf("\n");
	Advise11 advise11;
	advise11.test_01_demo();
	system("pause");
	return 0;
}