#define _CRT_SECURE_NO_WARNINGS

#include "advise70.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Advise70::test_01_demo(void)
{
	// 字符数组赋初值
	char cArr[] = { 'I','L','O','V','E','C' };
	// 字符串赋初值
	char sArr[] = "ILOVEC";

	// 用 sizeof() 求长度
	printf("cArr 的长度=%d\n", sizeof(cArr));
	printf("sArr 的长度=%d\n", sizeof(sArr));

	// 用 strlen() 求长度
	printf("cArr的长度=%d\n", strlen(cArr));
	printf("cArr的长度=%d\n", strlen(sArr));

	// 用 printf 的 %s 打印内容
	printf("cArr的内容=%s\n", cArr);
	printf("sArr的内容=%s\n", sArr);
}

void Advise70::test_02_error(void)
{
	char* sArr = (char*)"ILOVEC";
	//sArr[0] = 'Y';  // 能正确编译，却运行异常，结果是未定义
	printf("%s\n", sArr);
}

void Advise70::test_02_right(void)
{
	// 正确声明字符串常量
	const char* sArr = (char*)"ILOVEC";
	// 如果确实需要修改，应该这样写
	char arr[] = "ILOVEC";
	arr[0] = 'Y';
	printf("%s\n", sArr);
	printf("%s\n", arr);
}

void Advise70::test_03_error(void)
{
	char dst[5];
	const char* src = "ILOVEC";
	strcpy(dst, src);  // 源字符串长度超过 目标字符数组长度
	printf("%s", dst);
}

void Advise70::test_03_right(void)
{
	const char* src = "copy ILOVEC";
	// 调用前 保证 dest 足以容纳 src
	char* dst = (char*)malloc(strlen(src) + 1);
	strcpy(dst, src);
	printf("%s\n", dst);
	// 用 strncpy 函数来替换 strcpy
	// 该函数把 src 所指的由 null 结束的字符串的前 len 各字节复制到 dest 所指的数组中
	// 如果 src 的长度小于 len ,则 dest 数组将用额外的 null 填充到 len 长度。如果 src 的长度 大于 len ，则只有 len 个字符会背复制到 dest 中
	// 需要注意：如果 src 的长度大于 len 时，也就是 src 的前len个字节将不包含 null 字符，则它的结果 dest 将不会以 null 字符结束，所以 dest 将不再是一个字符串
	char* dest = (char*)malloc(strlen(src) + 2);
	strncpy(dest, src, strlen(src) + 2); // dest 内存： 63 6f 70 79 20 49 4c 4f 56 45 43 00 00  最后一个 00 就是填充的
	printf("%s\n", dest);
}

void Advise70::test_04_demo(void)
{
	char* src = (char*)"I Love C";
	char dest[5];
	memcpy(dest, src + 2 * sizeof(char), 4 * sizeof(char));
	// 或者 mepcpy(dest,src+2,4);
	dest[4] = '\0';
	printf("%s\n", dest);
}
