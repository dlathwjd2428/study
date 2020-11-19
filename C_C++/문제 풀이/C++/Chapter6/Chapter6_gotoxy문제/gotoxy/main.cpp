#include "MapDraw.h"

void main()
{
	int Width = 20;
	int Height = 20;
	MapDraw DrawManager;
	DrawManager.BoxDraw(0, 0, Width, Height);
	//DrawManager.DrawMidText("Hello~~", Width, Height*0.5);
	//DrawManager.TextDraw("Hello~~", Width, Height*0.6);
	DrawManager.DrawPoint("¢»", Width* 0.5, Height * 0.5);
	_getch();
	DrawManager.ErasePoint(Width*0.5, Height*0.5);
	DrawManager.gotoxy(0, Height + 1);
}
