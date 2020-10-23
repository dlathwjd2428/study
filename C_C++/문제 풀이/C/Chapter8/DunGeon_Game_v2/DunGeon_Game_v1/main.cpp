#include "head.h"

int menu();

void Dungeon_menu(Character* monster[]);
void InDungeon(Character* player[], int ch);

void Default_file(Character* Char_List[]);
void FileSave(Character* Char_List[]);
void FileLoad(Character* Char_List[]);
void Copy_Monster(Character* from, Character* to);
void _info(Character* player[], int info);
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
		fscanf(Default_fr, "%d", &Char_List[0]->Max_HP);
		fscanf(Default_fr, "%d", &Char_List[0]->Max_EXP);
		fscanf(Default_fr, "%d", &Char_List[0]->Get_EXP);
		fscanf(Default_fr, "%d", &Char_List[0]->level);
		fscanf(Default_fr, "%d", &Char_List[0]->player);
		Char_List[0]->HP = Char_List[0]->Max_HP;
		Char_List[0]->EXP = Char_List[0]->Get_EXP;
		Char_List[0]->defense_on = 1;

		fscanf(Default_fr, "%d", &monster_count);

		for (int i = 1; i <= monster_count; i++)
		{
			Char_List[i] = (Character*)malloc(sizeof(Character));

			fscanf(Default_fr, "%s", Char_List[i]->name);
			fscanf(Default_fr, "%d", &Char_List[i]->offense);
			fscanf(Default_fr, "%d", &Char_List[i]->Max_HP);
			fscanf(Default_fr, "%d", &Char_List[i]->Max_EXP);
			fscanf(Default_fr, "%d", &Char_List[i]->Get_EXP);
			fscanf(Default_fr, "%d", &Char_List[i]->level);
			fscanf(Default_fr, "%d", &Char_List[i]->player);
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
	to->HP = from->HP;
	to->Max_HP = from->Max_HP;
	to->EXP = from->EXP;
	to->Max_EXP = from->Max_EXP;
	to->Get_EXP = from->Get_EXP;
	to->defense_on = from->defense_on;
	to->level = from->level;
	to->player = from->player;
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


void _info(Character * player[], int info)
{
	printf("======%s<%dLv>======\n", player[info]->name, player[info]->level);
	printf("공격력 = %d          생명력 = %d/%d\n", player[info]->offense, player[info]->HP, player[info]->Max_HP);
	printf("경험치 = %d/%d       GetEXP : %d\n", player[info]->EXP, player[info]->Max_EXP, player[info]->Get_EXP);
}

void print_dungeon(Character * player[], int ch)
{
	system("cls");
	printf("조작 키 : Space(공격), z<(방어)\n");
	_info(Char_List, 0);
	_info(Char_List, ch);
}

void Monster_RCP(Character * player[], int ch)
{
	if (player[ch]->defense_on == 0)
	{
		printf("%s : 가위!!\n", player[ch]->name);
	}
	else if (player[ch]->defense_on == 1)
	{
		printf("%s : 바위!!\n", player[ch]->name);
	}
	else if (player[ch]->defense_on == 2)
	{
		printf("%s : 보!!\n", player[ch]->name);
	}

	if (player[0]->defense_on == player[ch]->defense_on)
	{
		printf("\n무승부...");
	}
	else if (player[0]->defense_on == 0 && player[ch]->defense_on == 2)
	{
		player[ch]->HP -= player[0]->offense;
	}
	else if (player[0]->defense_on == 2 && player[ch]->defense_on == 0)
	{
		player[0]->HP -= player[ch]->offense;
	}
	else if (player[0]->defense_on > player[ch]->defense_on )
	{
		player[ch]->HP -= player[0]->offense;
	}
	else if (player[0]->defense_on < player[ch]->defense_on)
	{
		player[0]->HP -= player[ch]->offense;
	}
	system("pause");
	system("cls");

}
void InDungeon(Character * player[], int ch)
{
	//print_dungeon(player, ch);
	while (1)
	{
		print_dungeon(player, ch);
		player[ch]->defense_on = GetRandomInt(0, 3);

		printf("%s 입력\n가위 : 0, 바위 : 1, 보 : 2\n입력 : ", player[0]->name);
		scanf("%d", &player[0]->defense_on);

		if (player[0]->defense_on == 0)
		{
			printf("%s : 가위!!\n", player[0]->name);
			Monster_RCP(player, ch);
		}
		else if (player[0]->defense_on == 1)
		{
			printf("%s : 바위!!\n", player[0]->name);
			Monster_RCP(player, ch);
		}
		else if (player[0]->defense_on == 2)
		{
			printf("%s : 보!!\n", player[0]->name);
			Monster_RCP(player, ch);
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
		fprintf(FileSave, "%d ", Char_List[i]->HP);
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
		fscanf(FileLoad, "%d ", &Char_List[0]->HP);
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
			fscanf(FileLoad, "%d ", &Char_List[i]->HP);
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