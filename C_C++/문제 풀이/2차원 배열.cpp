#include <stdio.h>

int main()
{
	//int ver = 0; //세로
	//int hor = 0; //가로

	//scanf_s("%d %d", &ver, &hor);

	int map[5][5] = {{0,1,0,1,0},
					 {1,0,1,0,1},
					 {0,1,0,1,0},
					 {1,0,1,0,1}, 
					 {0,1,0,1,0},};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (map[y][x] == 0)
			{
				printf("□");
			}
			else
			{
				printf("■");
			}
		}
		printf("\n");
	}

	/*switch (map[5][5])
	{
	case 0:
		printf("□");
		break;
	case 1:
		printf("■");
		break;
	default:
		break;
	}*/

}