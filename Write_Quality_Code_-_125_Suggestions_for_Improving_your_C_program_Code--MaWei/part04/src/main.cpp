#include "advise27~30.h"
#include "advise31~34.h"
#include "advise35~40.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	Advise29 advise29;
	advise29.test_00_demo();
	advise29.test_01_error_demo();
	advise29.test_01_right_demo();

	printf("\n");
	Advise33 advise33;
	advise33.test_01_demo();

	Advise34 advise34;
	advise34.test_01_error_demo();
	advise34.test_01_right_demo();

	printf("\n");
	Advise35 advise35;
	advise35.test_01_demo();
	size_t sum1 = 0;
	size_t sum2 = 0;
	advise35.test_03_error(5, &sum1);
	advise35.test_03_right(5, &sum2);
	printf("sum1 = %d\n", sum1);
	printf("sum2 = %d\n", sum2);

	Advise37 advise37;
	advise37.test_01_demo();

	printf("\n");
	Advise39 advise39;
	advise39.test_01_demo();
	advise39.test_02_demo();
	advise39.test_03_demo();
	return 0;
}