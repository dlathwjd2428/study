#include "head.h"

int menu();

void Dungeon_menu(Character* monster[]);
void InDungeon(Character* player[], int ch);

void Default_file(Character* Char_List[]);
void FileSave(Character* Char_List[]);
void FileLoad(Character* Char_List[]);

void _info(Character* player[], int info);
void LevelUp(Character* character);
int GetRandomInt(int min, int max);
void Attack(Character* c1, Character* c2);
void OnGameEnd(Character* winner, Character* loser);

int monster_count = 0;

Character* Char_List[MAX];

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Default_file(Char_List);

	while (1)
	{
		system("cls");
		switch (menu())
		{
		case INDUNGEON:
			Dungeon_menu(Char_List);
			break;

		case PLAYER_INFO:
			system("cls");
			_info(Char_List, 0);
			system("pause");
			break;

		case SAVE:
			FileSave(Char_List);
			break;
		case LOAD:
			FileLoad(Char_List);
			break;

		case EXIT:
			free(*Char_List);
			exit(0);
			
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
	system("cls");
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

		printf("플레이어 이름 입력 : ");
		scanf("%s", Char_List[0]->name);
		fscanf(Default_fr, "%d", &Char_List[0]->offense);
		fscanf(Default_fr, "%d", &Char_List[0]->defense);
		fscanf(Default_fr, "%d", &Char_List[0]->Max_HP);		
		fscanf(Default_fr, "%d", &Char_List[0]->Max_EXP);
		fscanf(Default_fr, "%d", &Char_List[0]->Get_EXP);		
		fscanf(Default_fr, "%d", &Char_List[0]->level);
		fscanf(Default_fr, "%d", &Char_List[0]->player);
		fscanf(Default_fr, "%d", &Char_List[0]->attack_speed);
		Char_List[0]->HP = Char_List[0]->Max_HP;
		Char_List[0]->EXP = Char_List[0]->Get_EXP;
		Char_List[0]->defense_on = 1;

		fscanf(Default_fr, "%d", &monster_count);

		for (int i = 1; i <= monster_count; i++)
		{
			Char_List[i] = (Character*)malloc(sizeof(Character));

			fscanf(Default_fr, "%s", Char_List[i]->name);				
			fscanf(Default_fr, "%d", &Char_List[i]->offense);
			fscanf(Default_fr, "%d", &Char_List[i]->defense);
			fscanf(Default_fr, "%d", &Char_List[i]->Max_HP);			
			fscanf(Default_fr, "%d", &Char_List[i]->Max_EXP);
			fscanf(Default_fr, "%d", &Char_List[i]->Get_EXP);		
			fscanf(Default_fr, "%d", &Char_List[i]->level);
			fscanf(Default_fr, "%d", &Char_List[i]->player);
			fscanf(Default_fr, "%d", &Char_List[i]->attack_speed);
			Char_List[i]->HP = Char_List[i]->Max_HP;
			Char_List[i]->EXP = 0;
			Char_List[i]->defense_on = 1;
		}
		fclose(Default_fr);
	}
}

void Dungeon_menu(Character* monster[])
{
	int ch = 0; 

	system("cls");
	printf("=====던전 입구=====\n");
	for (int i = 1; i <= monster_count; i++)
	{
		printf("  %d.%d층던전 : [%s]\n", i, i, monster[i]->name);
	}
	printf("  8.돌아가기\n");
	printf("선택 : ");
	scanf("%d", &ch);

	if (ch >0 && ch < 8)
	{
		InDungeon(Char_List, ch);
	}
	else
	{
		Dungeon_menu(Char_List);
	}
	
}

void InDungeon(Character* player[], int ch)
{
	while (1)
	{
		system("cls");

		printf("조작 키 : Space<공격>, z<방어>\n");
		
		_info(Char_List, 0);

		printf("방어모드 : ");

		int my_key = 0;

		if (_kbhit() != 0)
		{
			my_key = _getch();

			if (my_key == 90 || my_key == 122)
			{
				player[0]->defense_on = 0;
			}
			else
			{
				player[0]->defense_on = 1;
				player[ch]->HP -= player[0]->offense;
			}
		}

		if (player[0]->defense_on == 1)
		{
			printf("On\n");
		}
		else
		{
			printf("Off\n");
		}
		printf("============\n");

		_info(Char_List, ch);

		printf("방어모드 : ");

		Attack(player[ch], player[0]);
	}
}

void _info(Character* player[], int info)
{
	printf("======%s<%dLv>======\n", player[info]->name, player[info]->level);
	printf("공격력 = %d          방어력 = %d       생명력 = %d/%d\n", player[info]->offense, player[info]->defense, player[info]->HP, player[info]->Max_HP);
	printf("경험치 = %d/%d       GetEXP : %d\n", player[info]->EXP, player[info]->Max_EXP, player[info]->Get_EXP);
}

void FileSave(Character* Char_List[])
{
	system("cls");

	FILE* FileSave;
	char file_num[20] = { 0 };

	int ch = 0;

	printf("=====Save=====");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d번슬롯 : <파일여부 : ", i);

		sprintf(file_num, "SaveFile%d.txt", i);

		if (file_num == NULL)
		{
			printf("X\n");
		}
		else
		{
			printf("O\n");
		}
	}
	printf("\n선택 : ");

	scanf("%d", &ch);

	sprintf(file_num, "SaveFile%d.txt", ch);
	FileSave = fopen(file_num, "w");

	for (int i = 0; i <= monster_count; i++)
	{
		if (i == 1)
		{
			fprintf(FileSave, "%d\n", monster_count);
		}
		fprintf(FileSave, "%s ", Char_List[i]->name);
		fprintf(FileSave, "%d ", Char_List[i]->offense);
		fprintf(FileSave, "%d ", Char_List[i]->attack_speed);
		fprintf(FileSave, "%d ", Char_List[i]->HP);
		fprintf(FileSave, "%d ", Char_List[i]->defense);
		fprintf(FileSave, "%d ", Char_List[i]->defense_on);
		fprintf(FileSave, "%d ", Char_List[i]->EXP);
		fprintf(FileSave, "%d ", Char_List[i]->Get_EXP);
		fprintf(FileSave, "%d ", Char_List[i]->level);
		fprintf(FileSave, "%d ", Char_List[i]->Max_EXP);
		fprintf(FileSave, "%d ", Char_List[i]->Max_HP);
		fprintf(FileSave, "%d", Char_List[i]->player);
		fprintf(FileSave, "\n");
	}

	fclose(FileSave);

	printf("저장이 완료되었습니다. \n");
	system("Pause");
}

void FileLoad(Character* Char_List[])
{		
	system("cls");

	int ch = 0;

	printf("=====Load=====");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d번슬롯 : <파일여부 : ", i);
	}
	printf("\n선택 : ");

	scanf("%d", &ch);

	FILE* FileLoad;
	char file_num[20] = { 0 };
	sprintf(file_num, "SaveFile%d.txt", ch);
	FileLoad = fopen(file_num, "r");

	if (FileLoad == NULL)
		printf("가져올 데이터가 없습니다, \n");
	else
	{
		Char_List[0] = (Character*)malloc(sizeof(Character));

		fscanf(FileLoad, "%s ", Char_List[0]->name);
		fscanf(FileLoad, "%d ", &Char_List[0]->offense);
		fscanf(FileLoad, "%d ", &Char_List[0]->attack_speed);
		fscanf(FileLoad, "%d ", &Char_List[0]->HP);
		fscanf(FileLoad, "%d ", &Char_List[0]->defense);
		fscanf(FileLoad, "%d ", &Char_List[0]->defense_on);
		fscanf(FileLoad, "%d ", &Char_List[0]->EXP);
		fscanf(FileLoad, "%d ", &Char_List[0]->Get_EXP);
		fscanf(FileLoad, "%d ", &Char_List[0]->level);
		fscanf(FileLoad, "%d ", &Char_List[0]->Max_EXP);
		fscanf(FileLoad, "%d ", &Char_List[0]->Max_HP);
		fscanf(FileLoad, "%d", &Char_List[0]->player);
		fscanf(FileLoad, "%d\n", &monster_count);

		for (int i = 1; i <= monster_count; i++)
		{
			Char_List[i] = (Character*)malloc(sizeof(Character));
			fscanf(FileLoad, "%s ", Char_List[i]->name);
			fscanf(FileLoad, "%d ", &Char_List[i]->offense);
			fscanf(FileLoad, "%d ", &Char_List[i]->attack_speed);
			fscanf(FileLoad, "%d ", &Char_List[i]->HP);
			fscanf(FileLoad, "%d ", &Char_List[i]->defense);
			fscanf(FileLoad, "%d ", &Char_List[i]->defense_on);
			fscanf(FileLoad, "%d ", &Char_List[i]->EXP);
			fscanf(FileLoad, "%d ", &Char_List[i]->Get_EXP);
			fscanf(FileLoad, "%d ", &Char_List[i]->level);
			fscanf(FileLoad, "%d ", &Char_List[i]->Max_EXP);
			fscanf(FileLoad, "%d ", &Char_List[i]->Max_HP);
			fscanf(FileLoad, "%d", &Char_List[i]->player);
		}

		fclose(FileLoad);

		printf("불러오기가 완료되었습니다. \n");
		system("Pause");
	}
}

void LevelUp(Character* ch)
{
	ch->offense += GetRandomInt(0, 5);
	int randomHP = GetRandomInt(0, 11);
	ch->Max_HP += randomHP;
	ch->HP = ch->Max_HP;
}

int GetRandomInt(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min);
}

void Attack(Character* c1, Character* c2)
{
	if (c1->player == 0)
	{
		c1->defense_on = GetRandomInt(0, 2);

		if (c1->defense_on == 0)
		{
			printf("On\n");
			printf("============\n");
			printf("%s가 방어했다!!", c1->name);
		}
		else if (c1 -> defense_on == 1)
		{
			printf("Off\n");
			printf("============\n");
			printf("%s가 공격성공 했다!!", c1->name);
		}
		Sleep(c1->attack_speed);
	}

	if (c2->defense_on == 1)
	{
		// 방어모드 켜진거
		if (c2->defense > c1->offense)
		{
			// 상대 방어력이 내 공격력보다 높음
			// 상대는 데미지를 입지 않고 내가 딜반사 당함
			if (c1->player == 0)
			{
				// 플레이어만 딜반사 당함 (몬스터는 안 당함)
				c1->HP -= c2->defense - c1->offense;
			}
		}
		else
		{
			// 상대 방어력이 내 공격력보다 낮음
			// 상대는 방어력만큼 뺀 데미지를 받음
			c2->HP -= c1->offense - c2->defense;
		}
	}
	else
	{
		// 방어모드 꺼진거
		c2->HP -= c1->offense;
	}

	if (c2->HP <= 0)
	{
		// c2 사망, c1 승
		OnGameEnd(c1, c2);
	}
	else if (c1->HP <= 0)
	{
		// c1 사망, c2 승
		OnGameEnd(c2, c1);
	}
}

void OnGameEnd(Character* winner, Character* loser)
{
	if (winner->player == 1)
	{
		// 플레이어 승
		printf("%s 승리!!\n",winner->name);
		printf("%s가 경험치 %d를 얻었습니다.", loser->Get_EXP);

		int totalExp = winner->EXP + loser->Get_EXP;

		while (totalExp >= winner->Max_EXP)
		{
			LevelUp(winner);
			totalExp -= winner->Max_EXP;
		}
		winner->EXP = totalExp;
	}
	else if (loser->player == 1)
	{
		// 플레이어 패배
		if (loser->EXP == 0)
		{
			system("cls");
			printf("패배하였습니다.\n");
			system("pause");
			free(*Char_List);
			exit(0);
		}

		int totalExp = winner->EXP + loser->EXP;

		while (totalExp >= winner->Max_EXP)
		{
			LevelUp(winner);
			totalExp -= winner->Max_EXP;
		}
		loser->EXP = 0;
		winner->EXP = totalExp;
	}
}