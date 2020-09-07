#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char* Strlen(char str[]);
char* Strcpy(char* Name, char* My_Name);
char* Strcat(char str[]);
int Strcmp(char a[], char b[]);

void main()
{
	char str[10] = "Hello";
	char Name[10];
	char My_Name[10];

	char str1[10] = "string!!";
	char str2[10] = "string";

	printf("이름입력 > ");
	scanf("%s", &My_Name);

	Strlen(str);
	Strcpy(Name, My_Name);
	Strcat(str);
	printf("%s==%s:%d\n", str1, str2, Strcmp(str1, str2));
}

char* Strlen(char str[])
{
	printf("%s문자열의 길이 : %d\n", str, strlen(str));
	return str;
}

char* Strcpy(char* Name, char* My_Name)
{
	strcpy(Name, My_Name);
	printf("Name : %s\n", Name);
	printf("My_Name : %s\n", My_Name);

	return Name;
}

char* Strcat(char str[])
{
	printf("%s\n", str);
	strcat(str, "^^");
	printf("%s\n", str);

	return str;
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
