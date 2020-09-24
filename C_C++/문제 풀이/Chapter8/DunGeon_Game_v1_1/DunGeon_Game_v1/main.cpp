#include "head.h"

int menu();
void Default_file(Character* Char_List[]);
int Dungeon_menu(Character* monster[]);
void Player_info(Character* player[], int info);
void FileSave(Character* Char_List[]);
void FileLoad(Character* Char_List[]);

int monster_count = 0;
int set_info = 0;


int main()
{
	Character* Char_List[MAX];

	Default_file(Char_List);

	while (1)
	{

		system("cls");
		switch (menu())
		{
		case INDUNGEON:
			set_info = 1;
			switch (Dungeon_menu(Char_List))
			{
			case 1: 
				Player_info(Char_List, set_info);
			}
			
			break;

		case PLAYER_INFO:
			system("cls");
			Player_info(Char_List, set_info);
			break;

		case SAVE:
			FileSave(Char_List);
			break;
		case LOAD:
			FileLoad(Char_List);
			break;

		case EXIT:
			free(Char_List);
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

int Dungeon_menu(Character* monster[])
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

	return ch;
}

void Player_info(Character* player[], int info)
{
	printf("======%s<%dLv>======\n", player[0]->name, player[0]->level);
	printf("공격력 = %d          방어력 = %d       생명력 = %d/%d\n", player[0]->offense, player[0]->defense, player[0]->HP, player[0]->Max_HP);
	printf("경험치 = %d/%d       GetEXP : %d\n", player[0]->EXP, player[0]->Max_EXP, player[0]->Get_EXP);
	if (info == 1)
	{
		printf("방어모드 : ");
	}
	system("pause");
}

void FileSave(Character* Char_List[])
{
	system("cls");

	int ch = 0;

	printf("=====Save=====");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d번슬롯 : <파일여부 : ", i);
	}
	printf("\n선택 : ");

	scanf("%d", &ch);

	FILE* FileSave;
	char file_num[20] = {0};
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