#include "advise102~104.h"
#include <stdlib.h>
#include <stdio.h>


#define MIN_MEN_SIZE 10
// ����������ڴ棬�������ͷţ��п����������ٴ��ͷţ�������ͷ��ڲ�ͬ������
int CompareMemorySize1(char* p, size_t size)
{
	if (size < MIN_MEN_SIZE)
	{
		free(p);
		p = NULL;
		return -1;
	}
	return 0;
}

// Ӧ��Ϊ
int CompareMemorySize2( size_t size)
{
	if (size < MIN_MEN_SIZE)
	{
		return -1;
	}
	return 0;
}

void AllocMemory(size_t size)
{
	char* p = (char*)malloc(size);
	if (p == NULL)
	{
		// �����쳣����
		return;
	}
	//if (CompareMemorySize1(p, size) == -1) // ����
	if (CompareMemorySize2(size) == -1)
	{
		free(p);
		p = NULL;
		return;
	}
	free(p);
	p = NULL;
}

void Advise102::test_01_demo()
{
	AllocMemory(5);
}

// ����д��
int CopyFile11(FILE* src, FILE* dst, size_t bufsize)
{
	//char buf[bufsize];  // ���� char buf[bufsize] �ĳ����ɲ�������������Ȼ������Ҫ��
	//while (fgets(buf, bufsize, src))
	//{
	//	if (fputs(buf, dst) == EOF)
	//	{
	//		// 
	//	}
	//}
	return 0;
}

// ��ȷд��
int CopyFile12(FILE* src, FILE* dst, size_t bufsize)
{
	if (bufsize == 0)
	{
		// ����
		return 0;
	}
	char* buf = (char*)malloc(bufsize);
	if (buf == NULL)
	{
		// ����
		return 0;
	}
	while (fgets(buf, bufsize, src))
	{
		if (fputs(buf, dst) == EOF)
		{
			// 
		}
	}
	free(buf);
	buf = NULL;
	return 0;
}

void Advise102::test_02_demo()
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "D:\\tem.txt", "w");
	FILE* file1;
	errno_t err1;
	err1 = fopen_s(&file1, "D:\\tem.txt", "r");
	if (err != 0 || err1 != 0)
	{
		fclose(file);
		fclose(file1);
		return;
	}
	int ret = CopyFile12(file,file1,20);
	if(ret == 0)
		// ����
	fclose(file);
	fclose(file1);
}
