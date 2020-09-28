#include "head.h"

int menu();

void Dungeon_menu(Character* monster[]);
void InDungeon(Character* player[], int ch);

void Default_file(Character* Char_List[]);
void FileSave(Character* Char_List[]);
void FileLoad(Character* Char_List[]);

void _info(Character* player[], int info);
void Player_info(Character* player[], int info);
void Monster_info(Character* player[], int info);

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
			printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է����ּ���.");
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
	printf("    1.���� ����\n");
	printf("    2.Player ����\n");
	printf("    3.Save\n");
	printf("    4.Load\n");
	printf("    5.����\n");
	printf("    �Է�> ");

	scanf("%d", &ch);

	return ch;
}

void Default_file(Character* Char_List[])
{
	FILE* Default_fr = fopen("Default.txt", "r");

	if (Default_fr == NULL)
		printf("������ �����Ͱ� �����ϴ�, \n");
	else
	{
		Char_List[0] = (Character*)malloc(sizeof(Character));

		printf("�÷��̾� �̸� �Է� : ");
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
	printf("=====���� �Ա�=====\n");
	for (int i = 1; i <= monster_count; i++)
	{
		printf("  %d.%d������ : [%s]\n", i, i, monster[i]->name);
	}
	printf("  8.���ư���\n");
	printf("���� : ");
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
	printf("���� Ű : Space<����>, z<���>\n");
	while (1)
	{
		srand((unsigned)time(NULL));
		if (player[0]->HP <= 0 || player[ch]->HP <= 0)
		{
			break;
		}
		system("cls");

		Player_info(player, 0);
		Monster_info(player, ch);
	}
}

void _info(Character* player[], int info)
{
	printf("======%s<%dLv>======\n", player[info]->name, player[info]->level);
	printf("���ݷ� = %d          ���� = %d       ����� = %d/%d\n", player[info]->offense, player[info]->defense, player[info]->HP, player[info]->Max_HP);
	printf("����ġ = %d/%d       GetEXP : %d\n", player[info]->EXP, player[info]->Max_EXP, player[info]->Get_EXP);
}

void Player_info(Character* player[], int info)
{
	char my_key = 0;

	_info(Char_List, info);

	printf("����� : ");

	if (my_key == _getch())
	{
		if (my_key == 64)
		{
			player[0]->defense_on = 1;
		}
		else if (my_key == 90 || my_key == 122)
		{
			player[0]->defense_on = 0;
		}
	}

	if (player[info]->defense_on == 0)
	{
		printf("On\n");
	}
	else
	{
		printf("Off\n");
	}
	printf("============\n");
}

void Monster_info(Character* player[], int info)
{
	_info(Char_List, info);

	printf("����� : ");

	player[info]->defense_on = rand() % 2;

	if (player[info]->defense_on == 0)
	{
		printf("On\n");
		printf("============\n");
		printf("%s�� ����ߴ�!!",player[info]->name);
	}
	else if (player[info]->defense_on == 1)
	{		
		printf("Off\n");
		printf("============\n");
		printf("%s�� ���ݼ��� �ߴ�!!",player[info]->name);
	}

	Sleep(player[info]->attack_speed);
}

void FileSave(Character* Char_List[])
{
	system("cls");

	int ch = 0;

	printf("=====Save=====");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d������ : <���Ͽ��� : ", i);
		if (FileSave == NULL)
		{
			printf("X\n");
		}
		else
		{
			printf("O\n");
		}
	}
	printf("\n���� : ");

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

	printf("������ �Ϸ�Ǿ����ϴ�. \n");
	system("Pause");
}

void FileLoad(Character* Char_List[])
{		
	system("cls");

	int ch = 0;

	printf("=====Load=====");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d������ : <���Ͽ��� : ", i);
	}
	printf("\n���� : ");

	scanf("%d", &ch);

	FILE* FileLoad;
	char file_num[20] = { 0 };
	sprintf(file_num, "SaveFile%d.txt", ch);
	FileLoad = fopen(file_num, "r");

	if (FileLoad == NULL)
		printf("������ �����Ͱ� �����ϴ�, \n");
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

		printf("�ҷ����Ⱑ �Ϸ�Ǿ����ϴ�. \n");
		system("Pause");
	}
}