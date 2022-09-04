#define _CRT_SECURE_NO_WARNINGS

#include "advise76.h"
#include <stdio.h>
#include <stdlib.h>

void flush()
{
	char c;
	// getchar() 从标准输入 stdin 获取一个字符（一个无符号字符）
	while ((c = getchar()) != '\n' && c != EOF);
}
void Advise76::test_01_demo()
{
	char c[6];
	printf("请输入数据(hello):\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%c", &c[i]); 
		//flush();   // 如果单个输入后就换行，需要在输入缓冲区进行过滤
	}
	c[5] = '\0';
	printf("输出数据:\n");
	printf("%s\n", c);
}

void Advise76::test_02_demo()
{
	FILE* fp = NULL;
	fp = fopen("myfile.txt", "r");
	if (fp == NULL)
	{
		perror("错误信息");
		return;
	}
	fclose(fp);
	fp = NULL;
	free(fp);
}
void OpenFile()
{
	FILE* fp = NULL;
	// w 会创建一个文件 如果已经有了则删除重新创建一个空文件
	errno_t err = fopen_s(&fp, "myfile.txt", "w");
	if (err != 0)
	{
		perror("OpenFile");
		return;
	}
	fclose(fp);
	fp = NULL;
	free(fp);
}
void Advise76::test_03_demo()
{
	OpenFile();
}

void Advise76::test_04_demo()
{
	int a, b;
	a = b = 0;
	// 输入重定向，输入数据将从 in.txt 文件中读取
	FILE* fpIn = freopen("in.txt", "r", stdin);
	// 输出重定向，输出数据将保存在 out.txt 文件中
	FILE* fpOut = freopen("out.txt", "a+", stdout);
	if (fpIn == NULL || fpOut == NULL)
		return;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		fprintf(stdout,"%d\n", a + b);
		fflush(stdout);
		fflush(stdin);
	}

	// 关闭文件
	fclose(fpIn);
	fclose(fpOut); // 不知为何 这行代码控制台会输出 句柄无效  是因为 输入输出流没有转回控制台，而 main 函数有 system("pause") 所以句柄无效
	fpIn = NULL;
	fpOut = NULL;
	free(fpIn);
	free(fpOut);
	return;
}

void Advise76::test_05_error()
{
	FILE* fp = NULL;
	char c;
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout); 
	fp = fopen("test.txt", "r");
	if (fp == NULL)
		return;
	while (!feof(fp))
	{
		c = fgetc(fp);
		// feof() 用于检测文件，当文件内部位置指针指向文件结束时，并未立即置位FILE结构中的文件结束标记，只有再执行一次读文件操作，才会置位结束标志
		// 所以 要么判断 fgetc(fp) 不等于 EOF，要么把 fgetc(fp) 至于 feof前面。如下文的函数
		if (c != EOF)
		{
			printf("%c:\t%x\n", c, c);
		}
	}
	fclose(fp);
	fp = NULL;
	free(fp);
}

void Advise76::test_05_right()
{
	FILE* fp = NULL;
	char c;
	fp = fopen("test.txt", "r");
	if (fp == NULL)
		return;
	while (true)
	{
		c = fgetc(fp);
		if (feof(fp))  //再判断前 使用 fgetc读文件函数 所以当文件结束时就判断为 true 了
			break;
		printf("%c:\t%x\n", c, c);
	}
	fclose(fp);
	fp = NULL;
	free(fp);
}
