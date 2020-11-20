#include "SetMenu.h"

int Menu::StartMenu()
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

void Menu::SetMenu()
{
	while (1)
	{
		int ch = 0;
		system("cls");
		DrawBox(0, 0, Width, Height);
		DrawMidText("---��     ��---", Width, Height*0.1);
		DrawMidText("1.�� ������ ����", Width, Height*0.2);
		DrawMidText("2.Ŀ�� Ŀ����", Width, Height*0.3);
		DrawMidText("3.�� Ŀ����", Width, Height*0.4);
		DrawMidText("4.������ ����", Width, Height*0.5);
		DrawMidText("5.���ư���", Width, Height*0.6);
		DrawMidText("���� : ", Width, Height*0.7);

		cin >> ch;

		switch (ch)
		{
		case RE_MAPSIZE:
			Re_MapSize();
			break;
		case RE_CURSER:
			Re_Curser();
			break;

		case RE_STONE:
			Re_Stone();
			break;
		case RE_SKIP:
			Re_Skip();
			break;
		case RETURN:
			StartMenu();
			break;
		default:
			break;
		}
	}
}

void Menu::Re_MapSize()
{
	int _width, _height;

	while (1)
	{
		DrawBox(0, 0, Width, Height);
		DrawMidText("�� ũ�� ����", Width, Height*0.1);
		DrawMidText("���� : ", Width, Height*0.2);
		cin >> _width;
		DrawMidText("���� : ", Width, Height*0.3);
		cin >> _height;

		if ((_width < 20 || _width >90) || (_height < 20 || _height>45))
		{
			system("cls");
			DrawBox(0, 0, Width, Height);
			DrawMidText("���� �Ұ���", Width, Height*0.3);
			DrawMidText("<���� : 20 ~ 90, ���� : 20 ~ 45>", Width, Height*0.4);
			gotoxy(0, Height);
			system("pause");
		}
		else
		{
			this->Width = _width;
			this->Height = _height;
			break;
		}
	}
}

void Menu::Re_Curser()
{
	int curser;

	system("cls");
	DrawBox(0, 0, Width, Height);
	DrawMidText("1.<��,��> 2.<��,��>", Width, Height*0.2);
	DrawMidText("3.<��,��> 4.<��,��> 5.��Ÿ", Width, Height*0.3);
	DrawMidText("6.���ư���", Width, Height*0.4);
	DrawMidText("���� : ", Width, Height*0.5);
	cin >> curser;

	switch (curser)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}

void Menu::Re_Stone()
{
	int stone;

	system("cls");
	DrawBox(0, 0, Width, Height);
	DrawMidText("1.<��,��> 2.<��,��>", Width, Height*0.3);
	DrawMidText("3.<��,��> 4.<��,��> 5.��Ÿ", Width, Height*0.3);
	DrawMidText("6.���ư���", Width, Height*0.4);
	DrawMidText("���� : ", Width, Height*0.5);
	cin >> stone;

	switch (stone)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}

void Menu::Re_Skip()
{
	int skip;

	system("cls");
	DrawBox(0, 0, Width, Height);
	DrawMidText("���� ����", Width, Height*0.3);
	DrawMidText("1.������ Ƚ�� ����", Width, Height*0.3);
	DrawMidText("2.������ OFF", Width, Height*0.4);
	DrawMidText("3.���ư���", Width, Height*0.5);
	DrawMidText("���� : ", Width, Height*0.6);
	cin >> skip;

	switch (skip)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}