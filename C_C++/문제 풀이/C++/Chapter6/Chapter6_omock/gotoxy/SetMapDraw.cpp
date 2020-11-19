#include "MapDraw.h"

int MapDraw::StartMenu()
{
	int ch = 0;
	DrawMap(0, 0, Width, Height);
	DrawMidText("�ۡܿ�  ��ۡ�", Width, Height*0.25);
	DrawMidText("1.���� ����", Width, Height*0.35);
	DrawMidText("2.���� ����", Width, Height*0.45);
	DrawMidText("3.����", Width, Height*0.55);
	DrawBox(Width, Height*0.65, Width*0.35, Height*0.15);
	gotoxy(Width, Height*0.7);
	cin >> ch;

	return ch;
}

int MapDraw::SetMenu()
{
	int ch = 0;
	DrawBox(0, 0, Width, Height);
	DrawMidText("---��     ��---", Width, Height*0.1);
	DrawMidText("1.�� ������ ����", Width, Height*0.2);
	DrawMidText("2.Ŀ�� Ŀ����", Width, Height*0.3);
	DrawMidText("3.�� Ŀ����", Width, Height*0.4);
	DrawMidText("4.������ ����", Width, Height*0.5);
	DrawMidText("5.���ư���", Width, Height*0.6);
	DrawMidText("���� : ", Width, Height*0.7);
	return ch;
}

void MapDraw::ReSetMenu()
{
	int _width, _height;
	switch (SetMenu())
	{
	case RE_MAPSIZE:
		DrawBox(0, 0, Width, Height);
		DrawMidText("�� ũ�� ����", Width, Height*0.1);
		DrawMidText("���� : ", Width, Height*0.2);
		cin >> _width;
		DrawMidText("���� : ", Width, Height*0.3);
		cin >> _height;

		if ((_width < 20 && _width >90) || (_height < 20 || _height>45))
		{
			system("cls");
			DrawMidText("���� �Ұ���", Width, Height*0.3);
			DrawMidText("<���� : 20 ~ 90, ���� : 20 ~ 45>", Width, Height*0.4);
		}
		else
		{
			this->Width = _width;
			this->Height = _height;
		}
		break;

	case RE_CURSER:
		DrawMidText("1.<��,��> 2.<��,��>", Width, Height*0.3);
		DrawMidText("3.<��,��> 4.<��,��> 5.��Ÿ", Width, Height*0.3);
		DrawMidText("6.���ư���", Width, Height*0.4);
		DrawMidText("����", Width, Height*0.5);
		break;

	case RE_STONE:
		DrawMidText("1.<��,��> 2.<��,��>", Width, Height*0.3);
		DrawMidText("3.<��,��> 4.<��,��> 5.��Ÿ", Width, Height*0.3);
		DrawMidText("6.���ư���", Width, Height*0.4);
		DrawMidText("����", Width, Height*0.5);
		break;
	case RE_SKIP:
		break;
	case RETURN:
		break;
	default:
		break;
	}
}
