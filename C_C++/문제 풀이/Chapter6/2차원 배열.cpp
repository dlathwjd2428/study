#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 0, col = 0;
	scanf("%d %d", &row, &col);
	int **map;

	map = (int*)malloc(sizeof(int)) * row;

	for (int i = 0; i < row; i++)            // 세로 크기만큼 반복
	{
		map[i] = (int*)malloc(sizeof(int) * col);    // (int의 크기 * col)만큼 동적 메모리 할당. 배열의 가로
	}
	
	for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
	{
		for (int j = 0; j < col; j++)    // 가로 크기만큼 반복
		{
			map[i][j] = i + j;             // 2차원 배열의 각 요소에 i + j 값을 할당
		}
	}
}