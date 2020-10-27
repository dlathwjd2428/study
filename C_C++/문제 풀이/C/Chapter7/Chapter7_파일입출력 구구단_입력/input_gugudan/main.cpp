#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void file_a();
void file_r();

int main()
{
	file_a();
	file_r();
}

void file_a()
{
	int dan = 0;

	scanf("%d", &dan);
	FILE* f = fopen("gugudan.txt", "a");

	fprintf(f, "========%d단========\n", dan);
		for (int j = 1; j < 10; j++)
		{
			fprintf(f, "%d x %d = %d \n", dan, j, (dan*j));
		}
		fprintf(f, "====================\n");

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
