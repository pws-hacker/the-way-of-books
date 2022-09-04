#define _CRT_SECURE_NO_WARNINGS

#include "advise76.h"
#include <stdio.h>
#include <stdlib.h>

void flush()
{
	char c;
	// getchar() �ӱ�׼���� stdin ��ȡһ���ַ���һ���޷����ַ���
	while ((c = getchar()) != '\n' && c != EOF);
}
void Advise76::test_01_demo()
{
	char c[6];
	printf("����������(hello):\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%c", &c[i]); 
		//flush();   // ������������ͻ��У���Ҫ�����뻺�������й���
	}
	c[5] = '\0';
	printf("�������:\n");
	printf("%s\n", c);
}

void Advise76::test_02_demo()
{
	FILE* fp = NULL;
	fp = fopen("myfile.txt", "r");
	if (fp == NULL)
	{
		perror("������Ϣ");
		return;
	}
	fclose(fp);
	fp = NULL;
	free(fp);
}
void OpenFile()
{
	FILE* fp = NULL;
	// w �ᴴ��һ���ļ� ����Ѿ�������ɾ�����´���һ�����ļ�
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
	// �����ض����������ݽ��� in.txt �ļ��ж�ȡ
	FILE* fpIn = freopen("in.txt", "r", stdin);
	// ����ض���������ݽ������� out.txt �ļ���
	FILE* fpOut = freopen("out.txt", "a+", stdout);
	if (fpIn == NULL || fpOut == NULL)
		return;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		fprintf(stdout,"%d\n", a + b);
		fflush(stdout);
		fflush(stdin);
	}

	// �ر��ļ�
	fclose(fpIn);
	fclose(fpOut); // ��֪Ϊ�� ���д������̨����� �����Ч  ����Ϊ ���������û��ת�ؿ���̨���� main ������ system("pause") ���Ծ����Ч
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
		// feof() ���ڼ���ļ������ļ��ڲ�λ��ָ��ָ���ļ�����ʱ����δ������λFILE�ṹ�е��ļ�������ǣ�ֻ����ִ��һ�ζ��ļ��������Ż���λ������־
		// ���� Ҫô�ж� fgetc(fp) ������ EOF��Ҫô�� fgetc(fp) ���� feofǰ�档�����ĵĺ���
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
		if (feof(fp))  //���ж�ǰ ʹ�� fgetc���ļ����� ���Ե��ļ�����ʱ���ж�Ϊ true ��
			break;
		printf("%c:\t%x\n", c, c);
	}
	fclose(fp);
	fp = NULL;
	free(fp);
}
