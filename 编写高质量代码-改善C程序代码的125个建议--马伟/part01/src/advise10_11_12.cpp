#include "advise10_11_12.h"
#include <stdio.h>

void Advise11::test_01_demo()
{
	const int i1 = 10;
	int* p1 = (int*)&i1;  // 表面上是给了相同的指针，但是 const 变量的值是保存在 数据段(只读) 的
	int* p2 = p1;
	*p1 = 100;
	printf("%d %d %d\n", i1, *p1, *p2); // 10 ,100 ,100
	printf("%p %p %p\n", &i1, p1, p2);  // 地址相同
	//printf("%d\n", *(int*)0x0115F634);  // 通过地址查内存文件可得知其属于 堆栈段
	// 虽然地址相同，但 const 变量读取的是数据段，通过指针读取到的是 堆栈段 
}
