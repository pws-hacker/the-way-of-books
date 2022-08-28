#include "advise40~51.h"
#include "advise52~58.h"
#include "advise59.h"

#include <stdio.h>
#include <string>
int main()
{
	Advise40 advise40;
	//advise40.test_01_error();
	advise40.test_02_demo();
	advise40.test_04_error();
	advise40.test_04_right();

	printf("\n");
	Advise50 advise50;
	advise50.test_01_demo();
	advise50.test_03_demo();

	printf("\n");
	Advise53 advise53;
	advise53.test_01_error();
	advise53.test_04_error();
	advise53.test_04_right1();
	advise53.test_04_right2();
	system("pause");
	return 0;
}