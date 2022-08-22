#include "advise31~34.h"
#include <stdio.h>
#include <ctype.h>


void InitRemote()
{
	// Զ�̳�ʼ��
	// ʵ��
}

void Init_error()
{
	// ���س�ʼ��
	// ʵ��
	InitRemote();
}
void InitLocal()
{
	// ���س�ʼ��
	// ʵ��
}
void Init_right()
{
	// �����������ĳ��󼶱�Ӧ����ͬһ���
	InitLocal();
	InitRemote();
}
void Advise31::test_01_error()
{
	Init_error();
}

void Advise31::test_01_right()
{
	Init_right();
}

// ϣ������
void ShellSort(int v[], int n)
{
	int i, j, gap, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; (j >= 0) && (v[j] > v[j + gap]); j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
				// �ȼ��� 
				// Swap(&v[j],&v[j + gap]);
			}
		}
	}
}
// ð������
void BubbleSort(int v[], int n)
{
	int i, j, temp;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < (n - (j + 1)); i++)
		{
			if (v[i] > v[i + 1])
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				// �ȼ��� 
				// Swap(&v[i],&v[i + 1]);
			}
		}
	}
}
// �����������򷨶���ִ�н������������԰���Щ��������һ������
void Swap(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
void Execute(void* func)
{
	int arr[] = { 4,6,2,3,1,9,7,5,8 };
	(*(void (*)(int v[], int n))func)(arr, sizeof(arr) / sizeof(int));
	for (auto it : arr)
		printf("%d ", it);
	printf("\n");
}
void Advise33::test_01_demo()
{
	printf("ϣ������\n");
	Execute(&ShellSort);
	printf("ð������\n");
	Execute(&BubbleSort);
}

// �������뺯��
char* StrToUpper(char* str)
{
	static char buffer[255];
	int i;
	for (i = 0; str[i]; i++)
	{
		buffer[i] = toupper(str[i]);
	}
	buffer[i] = '\0';
	return buffer;
}
// �����뺯�����޸ĺ���ԭ��
char* StrToUpper(char* in_str ,char* out_str)
{
	int i;
	for (i = 0; in_str[i]; i++)
	{
		out_str[i] = toupper(in_str[i]);
	}
	out_str[i] = '\0';
	return out_str;
}

void Advise34::test_01_error_demo()
{
	char in_str1[] = { "abcdef" };
	char in_str2[] = { "ghijkl" };
	int i, j;
	char* out_str1 = StrToUpper(in_str1);
	char* out_str2 = StrToUpper(in_str2);
	for (i = 0; out_str1[i]; i++)
	{
		printf("%c", out_str1[i]);  // GHIJKL
	}
	printf("\n");
	for (j = 0; out_str2[j]; j++)
	{
		printf("%c", out_str2[j]);  // GHIJKL
	}
	printf("\n\n");
}

void Advise34::test_01_right_demo()
{
	char in_str1[] = { "abcdef" };
	char in_str2[] = { "ghijkl" };
	int i, j;
	char out_str1[7];
	char out_str2[7];
	StrToUpper(in_str1, out_str1);
	StrToUpper(in_str2, out_str2);
	for (i = 0; out_str1[i]; i++)
	{
		printf("%c", out_str1[i]);  // ABCDEF
	}
	printf("\n");
	for (j = 0; out_str2[j]; j++)
	{
		printf("%c", out_str2[j]);  // GHIJKL
	}
	printf("\n\n");
}

void Advise34::test_02_demo()
{

}
