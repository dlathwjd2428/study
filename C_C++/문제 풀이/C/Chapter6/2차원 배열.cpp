#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row = 0, col = 0;
	scanf("%d %d", &row, &col);
	int **map;

	map = (int*)malloc(sizeof(int)) * row;

	for (int i = 0; i < row; i++)            // ���� ũ�⸸ŭ �ݺ�
	{
		map[i] = (int*)malloc(sizeof(int) * col);    // (int�� ũ�� * col)��ŭ ���� �޸� �Ҵ�. �迭�� ����
	}
	
	for (int i = 0; i < row; i++)    // ���� ũ�⸸ŭ �ݺ�
	{
		for (int j = 0; j < col; j++)    // ���� ũ�⸸ŭ �ݺ�
		{
			map[i][j] = i + j;             // 2���� �迭�� �� ��ҿ� i + j ���� �Ҵ�
		}
	}
}