#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int Strlen(const char *str);
char Strcpy(const char *name1, char *name2);
int Strcmp(char a[], char b[]);
char Strcat(char *name1, char *s_cat);

void main()
{
	char str[100] = { 0 };
	printf("문장 입력:");
	scanf("%s", &str);
	printf("문자열 길이 : %d\n",Strlen(str));

	////

	char name1[10] = "hello";
	char name2[10] = { 0 };
	char s_cmp[10] = "hello!!";

	Strcpy(name1, name2);

	printf("name1 : %s name2 : %s\n", name1, name2);

	////

	Strcmp(name1, s_cmp);
	if (Strcmp(name1, s_cmp) == 0)
	{
		printf("%s == %s\n", name1, s_cmp);
	}
	else
	{
		printf("%s != %s\n", name1, s_cmp);
	}

	////

	char s_cat[10] = "^^";

	printf("%s\n", name1);
	Strcat(name1, s_cat);
	printf("%s", name1);
}

int Strlen(const char *str)
{
	const char *string_str = str;

	while (*str != 0)
	{
		*str++;
	}

	return str - string_str;
}

char Strcpy(const char *name1, char *name2)
{
	char *temp = name2;

	while (*name1)
	{
		*name2++ = *name1++;
	}

	return *temp;
}

int Strcmp(char a[], char b[])
{
	int i;

	for (i = 0;; i++)
	{
		if (a[i] == b[i] && a[i] == NULL)
			return 0;
		else if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
	}
}

char Strcat(char *name1, char *s_cat)
{
	int i = 0;

	while(name1[i] != '\0')
	{
		i++;
	}

	for (int j = 0; s_cat[j] != '\0'; j++)
		name1[i + j] = s_cat[j];

	return *name1;
}


