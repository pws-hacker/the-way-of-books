#include "advise102~104.h"
#include <stdlib.h>
#include <stdio.h>


#define MIN_MEN_SIZE 10
// 在外面分配内存，在这里释放，有可能在外面再次释放，分配和释放在不同抽象层次
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

// 应改为
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
		// 处理异常错误
		return;
	}
	//if (CompareMemorySize1(p, size) == -1) // 错误
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

// 错误写法
int CopyFile11(FILE* src, FILE* dst, size_t bufsize)
{
	//char buf[bufsize];  // 数组 char buf[bufsize] 的长度由参数来决定，显然不符合要求
	//while (fgets(buf, bufsize, src))
	//{
	//	if (fputs(buf, dst) == EOF)
	//	{
	//		// 
	//	}
	//}
	return 0;
}

// 正确写法
int CopyFile12(FILE* src, FILE* dst, size_t bufsize)
{
	if (bufsize == 0)
	{
		// 处理
		return 0;
	}
	char* buf = (char*)malloc(bufsize);
	if (buf == NULL)
	{
		// 处理
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
		// 处理
	fclose(file);
	fclose(file1);
}
