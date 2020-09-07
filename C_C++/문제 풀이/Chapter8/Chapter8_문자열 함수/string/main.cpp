#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int Strlen(const char *str);
char Strcpy(const char *name1, char *name2);

//char* Strcpy(char* Name, char* My_Name);
//char* Strcat(char str[]);
//int Strcmp(char a[], char b[]);

void main()
{
	char str[100] = { 0 };
	printf("문장 입력:");
	scanf("%s", &str);
	printf("문자열 길이 : %d\n",Strlen(str));


	char name1[10] = "hello";
	char name2[10];

	Strcpy(name1, name2);

	printf("name1 : %s name2 : %s", Strcpy(name1, name2));


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
	*name2 = *name1;
	
	return *name2;
}

//}
//
//char* Strcat(char str[])
//{
//	printf("%s\n", str);
//	strcat(str, "^^");
//	printf("%s\n", str);
//
//	return str;
//}
//
//int Strcmp(char a[], char b[])
//{
//	int i;
//
//	for (i = 0;; i++)
//	{
//		if (a[i] == b[i] && a[i] == NULL)
//			return 0;
//		else if (a[i] > b[i])
//			return 1;
//		else if (a[i] < b[i])
//			return -1;
//	}
//}
