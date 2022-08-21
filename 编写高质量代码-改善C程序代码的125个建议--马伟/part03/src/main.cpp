#include <advise17_18_19.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
	Advise17 advise17;
	advise17.test_01_error();
	advise17.test_01_right();

	printf("\n");
	Advise18 advise18;
	advise18.test_02_error();
	advise18.test_02_right();

	printf("\n");
	Advise19 advise19;
	advise19.test_01_error();
	advise19.test_01_right();
	system("pause");
	return 0;
}