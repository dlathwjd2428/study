#include<stdio.h>

int main()
{
	int Arr[10] = { 10,17,3,9,37,10,8,9,13,21 };
	int even = 0; //Â¦¼ö
	int odd = 0; //È¦¼ö

	printf("1¹ø¹®Á¦\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}

	printf("\n\n2¹ø¹®Á¦\nInvert_Arr : ");
	for (int i = 9; i >= 0; i--)
	{
		printf("%d,", Arr[i]);
	}
	printf("\nArr : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}

	printf("\n\n3¹ø¹®Á¦\nÈ¦¼ö ¹øÂ° ¿ø¼Ò : ");
	for (int i = 1; i < 10; i+=2)
	{
		printf("%d,", Arr[i]);

		odd += Arr[i];
	}
	printf("\nÈ¦¼ö ¹øÂ° ÃÑÇÕ : %d", odd);

	printf("\nÂ¦¼ö ¹øÂ° ¿ø¼Ò : ");
	for (int i = 0; i < 10; i += 2)
	{
		printf("%d,", Arr[i]);

		even += Arr[i];
	}
	printf("\nÂ¦¼ö ¹øÂ° ÃÑÇÕ : %d", even);

	printf("\n\n4¹ø¹®Á¦\nArr : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", Arr[i]);
	}


}