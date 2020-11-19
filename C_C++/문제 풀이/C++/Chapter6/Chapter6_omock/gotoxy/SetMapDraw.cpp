#include "MapDraw.h"

int MapDraw::StartMenu()
{
	int ch = 0;
	DrawMap(0, 0, Width, Height);
	DrawMidText("○●오  목○●", Width, Height*0.25);
	DrawMidText("1.게임 시작", Width, Height*0.35);
	DrawMidText("2.게임 설정", Width, Height*0.45);
	DrawMidText("3.종료", Width, Height*0.55);
	DrawBox(Width, Height*0.65, Width*0.35, Height*0.15);
	gotoxy(Width, Height*0.7);
	cin >> ch;

	return ch;
}

int MapDraw::SetMenu()
{
	int ch = 0;
	DrawBox(0, 0, Width, Height);
	DrawMidText("---옵     션---", Width, Height*0.1);
	DrawMidText("1.맵 사이즈 변경", Width, Height*0.2);
	DrawMidText("2.커서 커스텀", Width, Height*0.3);
	DrawMidText("3.돌 커스텀", Width, Height*0.4);
	DrawMidText("4.물리기 설정", Width, Height*0.5);
	DrawMidText("5.돌아가기", Width, Height*0.6);
	DrawMidText("선택 : ", Width, Height*0.7);
	return ch;
}

void MapDraw::ReSetMenu()
{
	int _width, _height;
	switch (SetMenu())
	{
	case RE_MAPSIZE:
		DrawBox(0, 0, Width, Height);
		DrawMidText("맵 크기 설정", Width, Height*0.1);
		DrawMidText("가로 : ", Width, Height*0.2);
		cin >> _width;
		DrawMidText("세로 : ", Width, Height*0.3);
		cin >> _height;

		if ((_width < 20 && _width >90) || (_height < 20 || _height>45))
		{
			system("cls");
			DrawMidText("변경 불가능", Width, Height*0.3);
			DrawMidText("<가로 : 20 ~ 90, 세로 : 20 ~ 45>", Width, Height*0.4);
		}
		else
		{
			this->Width = _width;
			this->Height = _height;
		}
		break;

	case RE_CURSER:
		DrawMidText("1.<○,●> 2.<♧,♣>", Width, Height*0.3);
		DrawMidText("3.<♡,♥> 4.<☞,☜> 5.기타", Width, Height*0.3);
		DrawMidText("6.돌아가기", Width, Height*0.4);
		DrawMidText("선택", Width, Height*0.5);
		break;

	case RE_STONE:
		DrawMidText("1.<○,●> 2.<☆,★>", Width, Height*0.3);
		DrawMidText("3.<♤,♠> 4.<☏,☎> 5.기타", Width, Height*0.3);
		DrawMidText("6.돌아가기", Width, Height*0.4);
		DrawMidText("선택", Width, Height*0.5);
		break;
	case RE_SKIP:
		break;
	case RETURN:
		break;
	default:
		break;
	}
}
