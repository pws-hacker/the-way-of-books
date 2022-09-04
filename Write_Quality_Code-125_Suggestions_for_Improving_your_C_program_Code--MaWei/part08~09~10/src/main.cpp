#include "advise70.h"
#include "advise76.h"

#include <stdlib.h>
#include <stdio.h>
int main()
{
	Advise70 advise70;
	advise70.test_01_demo();
	advise70.test_02_error();
	advise70.test_02_right();
	advise70.test_03_right();
	advise70.test_04_demo();
	advise70.test_05_error1();
	advise70.test_05_error2();
	advise70.test_05_right();

	printf("\n");
	Advise76 advise76;
	advise76.test_01_demo();
	advise76.test_02_demo();
	advise76.test_03_demo();
	advise76.test_04_demo();
	advise76.test_05_error();
	advise76.test_05_right();

	system("pause");
	return 0;
}