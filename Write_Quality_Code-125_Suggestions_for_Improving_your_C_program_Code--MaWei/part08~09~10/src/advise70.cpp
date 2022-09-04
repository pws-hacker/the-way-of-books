#define _CRT_SECURE_NO_WARNINGS

#include "advise70.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Advise70::test_01_demo(void)
{
	// �ַ����鸳��ֵ
	char cArr[] = { 'I','L','O','V','E','C' };
	// �ַ�������ֵ
	char sArr[] = "ILOVEC";

	// �� sizeof() �󳤶�
	printf("cArr �ĳ���=%d\n", sizeof(cArr));
	printf("sArr �ĳ���=%d\n", sizeof(sArr));

	// �� strlen() �󳤶�
	printf("cArr�ĳ���=%d\n", strlen(cArr));
	printf("cArr�ĳ���=%d\n", strlen(sArr));

	// �� printf �� %s ��ӡ����
	printf("cArr������=%s\n", cArr);
	printf("sArr������=%s\n", sArr);
}

void Advise70::test_02_error(void)
{
	char* sArr = (char*)"ILOVEC";
	//sArr[0] = 'Y';  // ����ȷ���룬ȴ�����쳣�������δ����
	printf("%s\n", sArr);
}

void Advise70::test_02_right(void)
{
	// ��ȷ�����ַ�������
	const char* sArr = (char*)"ILOVEC";
	// ���ȷʵ��Ҫ�޸ģ�Ӧ������д
	char arr[] = "ILOVEC";
	arr[0] = 'Y';
	printf("%s\n", sArr);
	printf("%s\n", arr);
}

void Advise70::test_03_error(void)
{
	char dst[5];
	const char* src = "ILOVEC";
	strcpy(dst, src);  // Դ�ַ������ȳ��� Ŀ���ַ����鳤��
	printf("%s", dst);
}

void Advise70::test_03_right(void)
{
	const char* src = "copy ILOVEC";
	// ����ǰ ��֤ dest �������� src
	char* dst = (char*)malloc(strlen(src) + 1);
	strcpy(dst, src);
	printf("%s\n", dst);
	// �� strncpy �������滻 strcpy
	// �ú����� src ��ָ���� null �������ַ�����ǰ len ���ֽڸ��Ƶ� dest ��ָ��������
	// ��� src �ĳ���С�� len ,�� dest ���齫�ö���� null ��䵽 len ���ȡ���� src �ĳ��� ���� len ����ֻ�� len ���ַ��ᱳ���Ƶ� dest ��
	// ��Ҫע�⣺��� src �ĳ��ȴ��� len ʱ��Ҳ���� src ��ǰlen���ֽڽ������� null �ַ��������Ľ�� dest �������� null �ַ����������� dest ��������һ���ַ���
	char* dest = (char*)malloc(strlen(src) + 2);
	strncpy(dest, src, strlen(src) + 2); // dest �ڴ棺 63 6f 70 79 20 49 4c 4f 56 45 43 00 00  ���һ�� 00 ��������
	printf("%s\n", dest);
}

void Advise70::test_04_demo(void)
{
	char* src = (char*)"I Love C";
	char dest[5];
	memcpy(dest, src + 2 * sizeof(char), 4 * sizeof(char));
	// ���� mepcpy(dest,src+2,4);
	dest[4] = '\0';
	printf("%s\n", dest);
}

void Advise70::test_05_error1(void)
{
	const char* str = "1234567";
	int len = strlen(str);
	char* p1 = (char*)malloc(len+1);
	memcpy(p1, str, strlen(str));
	p1[7] = '\0';
	printf("memcpy ǰ:p=%s\n", p1);
	// �����ص�
	//strcpy(p + 1, p);  // �������
	printf("memcpy ��:p=%s\n", p1);
	free(p1);
}

void Advise70::test_05_error2(void)
{
	const char* str = "1234567";
	char* p2 = (char*)malloc(8);
	memcpy(p2, str, strlen(str));
	p2[7] = '\0';
	printf("memcpy ǰ:p=%s\n", p2);
	// �����ص�
	memcpy(p2 + 1, p2,7);
	printf("memcpy ��:p=%s\n", p2);  // "11234567" gcc �������Ǵ����
	free(p2);
}

void Advise70::test_05_right(void)
{
	// ʹ�� memmove ����
	const char* str = "1234567";
	char* p2 = (char*)malloc(8);
	memcpy(p2, str, strlen(str));
	p2[7] = '\0';
	printf("memcpy ǰ:p=%s\n", p2);
	// �����ص�
	memmove(p2 + 1, p2, 7);
	printf("memcpy ��:p=%s\n", p2);  // "11234567" gcc �������Ǵ����
	free(p2);
}
