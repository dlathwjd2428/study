#include "head.h"

int menu();

void Dungeon_menu(Character* monster[]);
void InDungeon(Character* player[], int ch);

void Default_file(Character* Char_List[]);
void FileSave(Character* Char_List[]);
void FileLoad(Character* Char_List[]);
void Copy_Monster(Character* from, Character* to);
void _info(Character* player[], int info, int menu);
void LevelUp(Character* character);
int GetRandomInt(int min, int max);
void print_dungeon(Character* player[], int ch);
void OnGameEnd(Character* winner, Character* loser);

int monster_count = 0;

Character* Char_List[MAX];
Character* Monst;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand((unsigned int)time(NULL));
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
			_info(Char_List, 0, 2);
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
	printf("    입력 : ");

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

void Copy_Monster(Character* from, Character* to)
{
	strcpy(to->name, from->name);
	to->offense = from->offense;
	to->defense = from->defense;
	to->HP = from->HP;
	to->Max_HP = from->Max_HP;
	to->EXP = from->EXP;
	to->Max_EXP = from->Max_EXP;
	to->Get_EXP = from->Get_EXP;
	to->defense_on = from->defense_on;
	to->level = from->level;
	to->player = from->player;
	to->attack_speed = from->attack_speed;
}

void Dungeon_menu(Character* monster[])
{
	int ch = 0, i;
	while (1)
	{
		system("cls");
		printf("=====던전 입구=====\n");
		for (i = 1; i <= monster_count; i++)
		{
			printf("  %d.%d층던전 : [%s]\n", i, i, monster[i]->name);
		}
		printf("  %d.돌아가기\n", i);
		printf("선택 : ");
		scanf("%d", &ch);

		if (ch > 0 && ch < i)
		{
			Monst = (Character*)malloc(sizeof(Character));
			Copy_Monster(Char_List[ch], Monst);
			InDungeon(Char_List, ch);
		}
		else if (ch == i) return;
	}

}


void _info(Character * player[], int info, int menu)
{
	printf("======%s<%dLv>======\n", player[info]->name, player[info]->level);
	printf("공격력 = %d          방어력 = %d       생명력 = %d/%d\n", player[info]->offense, player[info]->defense, player[info]->HP, player[info]->Max_HP);
	printf("경험치 = %d/%d       GetEXP : %d\n", player[info]->EXP, player[info]->Max_EXP, player[info]->Get_EXP);
	if (menu != 2)
	{
		printf("방어모드 : ");
		if (player[info]->defense_on == 1)
			printf("On\n");
		else printf("Off\n");
		printf("============\n");
	}
}

void print_dungeon(Character * player[], int ch)
{
	system("cls");
	printf("조작 키 : Space(공격), z<(방어)\n");
	_info(Char_List, 0, 1);
	_info(Char_List, ch, 1);
}
void InDungeon(Character * player[], int ch)
{
	int my_key = 0;
	clock_t start = clock();
	print_dungeon(player, ch);
	while (1)
	{

		if (clock() - start >= player[ch]->attack_speed * 10)
		{
			player[ch]->defense_on = GetRandomInt(0, 2);
			start = clock();

			if (player[ch]->defense_on == 1)
			{
				print_dungeon(player, ch);
				printf("%s가 방어했다!!", player[ch]->name);
				Sleep(100);
			}
			else if (player[ch]->defense_on == 0)
			{
				if (player[0]->defense_on == 1)
				{
					if (player[ch]->offense > player[0]->defense)
					{
						player[0]->HP -= player[ch]->offense - player[0]->defense;
					}
				}
				else
				{
					player[0]->HP -= player[ch]->offense;
				}
				print_dungeon(player, ch);
				printf("%s가 공격성공 했다!!", player[ch]->name);
				Sleep(100);
			}
		}

		if (_kbhit() != 0)
		{
			my_key = _getch();
			if (my_key == 90 || my_key == 122)
			{
				player[0]->defense_on = 1;
				print_dungeon(player, ch);
				printf("%s가 방어했다!!", player[0]->name);
			}
			else if (my_key == 32)
			{
				player[0]->defense_on = 0;

				if (player[ch]->defense_on == 1)
				{
					if (player[ch]->defense > player[0]->offense)
					{
						player[0]->HP -= player[ch]->defense - player[0]->offense;
						print_dungeon(player, ch);
						printf("%s가 공격반사 당했다!!", player[0]->name);
						Sleep(100);
					}
					else if (player[ch]->defense == player[0]->offense)
					{
						print_dungeon(player, ch);
						printf("%s가 공격실패 했다!!", player[0]->name);
						Sleep(100);
					}
					else
					{
						player[ch]->HP -= player[0]->offense - player[ch]->defense;
						print_dungeon(player, ch);
						printf("%s가 공격성공 했다!!", player[0]->name);
						Sleep(100);
					}
				}
				else
				{
					player[ch]->HP -= player[0]->offense; print_dungeon(player, ch);
					printf("%s가 공격성공 했다!!", player[0]->name);
					Sleep(100);
				}
			}
		}
		if (player[0]->HP <= 0)
		{
			OnGameEnd(player[ch], player[0]);
			break;
		}
		else if (player[ch]->HP <= 0)
		{
			OnGameEnd(player[0], player[ch]);
			break;
		}
	}
}


void FileSave(Character * Char_List[])
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

		if (fopen(file_num, "r") == NULL)
		{
			printf("O\n");
		}
		else
		{
			printf("X\n");
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
	//system("Pause");
}

void FileLoad(Character * Char_List[])
{
	system("cls");

	int ch = 0;
	char file_num[20] = { 0 };
	FILE* FileLoad;

	printf("=====Load=====");

	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d번슬롯 : <파일여부 : ", i);

		sprintf(file_num, "SaveFile%d.txt", i);

		if (fopen(file_num, "r") == NULL)
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
	FileLoad = fopen(file_num, "r");

	if (FileLoad == NULL)
	{
		printf("해당 저장 파일이 없습니다. \n");
		system("Pause");
	}
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
		//system("Pause");
	}
}

void LevelUp(Character * ch)
{
	int randomOff, randomDef, randomHP, randomEXP;
	printf("%s 레벨업!!\n", ch->name);
	ch->level++;

	randomOff = GetRandomInt(0, 5);
	ch->offense += randomOff;
	printf("공격력 %d 증가!!\n", randomOff);

	randomDef = GetRandomInt(0, 5);
	ch->defense += randomDef;
	printf("방어력 %d 증가!!\n", randomDef);

	randomHP = GetRandomInt(0, 11);
	ch->Max_HP += randomHP;
	ch->HP = ch->Max_HP;
	printf("생명력 %d 증가!!\n", randomHP);

	randomEXP = GetRandomInt(0, 6);
	ch->Max_EXP += randomEXP;
}

int GetRandomInt(int min, int max)
{
	return rand() % (max - min);
}


void OnGameEnd(Character * winner, Character * loser)
{
	int totalExp;

	if (winner->player == 1)
	{
		// 플레이어 승
		system("cls");
		printf("%s 승리!!\n", winner->name);
		printf("%s가 경험치 %d를 얻었습니다.\n", winner->name, loser->Get_EXP);

		totalExp = winner->EXP + loser->Get_EXP;

		if (totalExp >= winner->Max_EXP)
		{
			LevelUp(winner);
			totalExp = 0;
		}
		winner->EXP = winner->Get_EXP = totalExp;
		Copy_Monster(Monst, loser);

	}
	else if (loser->player == 1)
	{
		// 플레이어 패배
		system("cls");
		printf("%s 승리!!\n", winner->name);
		printf("%s가 경험치 %d를 얻었습니다.\n", winner->name, loser->Get_EXP);
		if (loser->Get_EXP == 0)
		{
			printf("Game Over\n");
			free(*Char_List);
			system("Pause");
			exit(0);
		}
		totalExp = winner->EXP + loser->EXP;
		loser->EXP = loser->Get_EXP = 0;
		loser->HP = loser->Max_HP;
		while (totalExp >= winner->Max_EXP)
		{
			LevelUp(winner);
			totalExp = 0;
		}
		winner->EXP = totalExp;;
	}

	system("Pause");
	return;
}