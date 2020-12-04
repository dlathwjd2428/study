#include "MapDraw.h"


MapDraw::MapDraw()
{
	Width = 20;
	Height = 20;

	board = new int *[Width];
	for (int i = 0; i < Width; i++)
	{
		board[i] = new int[Height];
		memset(board[i], 0, sizeof(int)*Height);
	}
}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}
void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}


void MapDraw::DrawMap(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "┬";
			cout << "┐";
		}
		else if (y == Height - 1)
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "┴";
			cout << "┘";
		}
		else
		{
			cout << "├";
			for (int x = 1; x < Width - 1; x++)
				cout << "┼";
			cout << "┤";
		}
	}
	return;
}

void MapDraw::DrawBox(int Start_x, int Start_y, int Width, int Height)
{
	if (Start_x > Width)
		Start_x -= Width;
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == Height - 1)
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┘";
		}
		else
		{
			cout << "│";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "│";
		}
	}
	return;
}

int MapDraw::DrawStone(int y, int x, int stone)
{ // stone이 1이면 흑, 2면 백
	if (board[y][x] || x < 0 || x >= Width || y < 0 || y >= Height)
		return 0;
	gotoxy(x, y);
	if (stone == BLACK)
	{
		DRAW_BLACK;
		board[y][x] = BLACK;
	}
	else if (stone == WHITE)
	{
		DRAW_WHITE;
		board[y][x] = WHITE;
	}
	else
		return 0;
	return 1;
}

MapDraw::~MapDraw()
{
}
