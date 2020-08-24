#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void file_w();
void file_r();

int main()
{
	file_w();
	file_r();
}

void file_w()
{
	FILE* f = fopen("gugudan.txt", "w");
	for (int i = 2; i < 10; i++)
	{
		fprintf(f, "========%d단========\n", i);
		for (int j = 1; j < 10; j++)
		{
			fprintf(f, "%d x %d = %d \n", i, j, (i*j));
		}
		fprintf(f, "====================\n");
	}
	fclose(f);
}

void file_r()
{
	char c;

	FILE * f = fopen("gugudan.txt", "r");

	if (f == NULL)
	{
		printf("파일 오픈 실패 !\n");
	}
	else
	{
		while ((c = fgetc(f)) != -1)
		{
			printf("%c", c);
		}
	}

	fclose(f);
}
