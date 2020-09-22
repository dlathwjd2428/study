#include "head.h""

int menu();
void Player_info(Character* player[]);
void Default_file(Character* Char_List[]);

int main()
{

	Character* Char_List[MAX];

	Character new_player;
	printf("플레이어 이름 입력 : ");

	Default_file(Char_List);

	while (1)
	{
		Char_List[MAX] = (Character*)malloc(sizeof(Character));
		
		
		system("cls");
		switch (menu())
		{
		case INDUNGEON:

			break;

		case PLAYER_INFO:
			Player_info(Char_List);
			break;

		case SAVE:
			break;
		case LOAD:
			break;

		case EXIT:
			break;

		default:
			printf("잘못입력하였습니다. 다시 입력해주세요.");
			Sleep(700);
			break;
		}
	}
	
}

int menu()
{
	int ch = 0;

	printf("=======DunGeon=======\n");
	printf("    1.던전 입장\n");
	printf("    2.Player 정보\n");
	printf("    3.Save\n");
	printf("    4.Load\n");
	printf("    5.종료\n");
	printf("    입력> ");

	scanf("%d", &ch);

	return ch;
}

void Default_file(Character* Char_List[])
{
	FILE* Default_fr = fopen("Default.txt", "r");

	if (Default_fr == NULL)
		printf("가져올 데이터가 없습니다, \n");
	else
	{
		Char_List[0] = (Character*)malloc(sizeof(Character));
		scanf("%s", Char_List[0]->name);
		fscanf(Default_fr, "%d %d %d %d %f %f %f %d %d", &Char_List[0]->offense,
														&Char_List[0]->defense,
														&Char_List[0]->Max_HP,
														&Char_List[0]->Max_EXP,
														&Char_List[0]->Die_EXP,
														&Char_List[0]->level,
														&Char_List[0]->player,
														&Char_List[0]->attack_speed);

		for (int i = 0; i < MAX; i++)
		{
			Char_List[i] = (Character*)malloc(sizeof(Character));

			if (i == 0)
			{
				scanf("%s", Char_List[0]->name);
			}
			else
			{
				fscanf(Default_fr, "%s", Char_List[i]->name);
			}
			fscanf(Default_fr, "%d %d %d %d %f %f %f %d %d", &Char_List[i]->offense,
															 &Char_List[i]->defense,
															 &Char_List[i]->Max_HP,
															 &Char_List[i]->Max_EXP,
															 &Char_List[i]->Die_EXP,
															 &Char_List[i]->level,
															 &Char_List[i]->player,
															 &Char_List[i]->attack_speed);
		}
		fclose(Default_fr);
	}
}

//void SaveFile(Character* Student_List[])
//{
//	FILE* SaveFile = fopen("StudentFile.txt", "w");
//
//	
//
//	fclose(SaveFile);
//
//	printf("저장이 완료되었습니다. \n");
//	system("Pause");
//}

void Player_info(Character* player[])
{
	system("cls");
	printf("======%s<%dLv>======\n", player[0]->name, player[0]->level);
	printf("공격력 = %d          방어력 = %d       생명력 = %d/50\n", player[0]->offense, player[0]->defense, player[0]->HP);
	printf("경험치 = %d/10       GetEXP : %d\n", player[0]->EXP, player[0]->EXP);
	system("pause");
}