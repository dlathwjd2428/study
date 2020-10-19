#include "head.h"

int menu();

void Dungeon_menu(Character* monster[]);
void InDungeon(Character* player[], int ch);

void Default_file(Character* Char_List[]);
void FileSave(Character* Char_List[]);
void FileLoad(Character* Char_List[]);

void _info(Character* player[], int info);
void LevelUp(Character* character);
int RandNum(int min, int max);
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

	char my_key = 0;

	system("cls");
	while (1)
	{
		_info(Char_List, 0);

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

		if (player[0]->defense_on == 0)
		{
			printf("On\n");
		}
		else
		{
			printf("Off\n");
		}
		printf("============\n");
		Attack(player[ch], player[0]);
	}
	
}

void _info(Character* player[], int info)
{
	printf("======%s<%dLv>======\n", player[info]->name, player[info]->level);
	printf("���ݷ� = %d          ���� = %d       ����� = %d/%d\n", player[info]->offense, player[info]->defense, player[info]->HP, player[info]->Max_HP);
	printf("����ġ = %d/%d       GetEXP : %d\n", player[info]->EXP, player[info]->Max_EXP, player[info]->Get_EXP);
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
		printf("\n%d������ : <���Ͽ��� : ", i);

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
	printf("\n���� : ");

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

void LevelUp(Character* ch)
{
	ch->offense += RandNum(0, 5);
	int randomHP = RandNum(0, 11);
	ch->Max_HP += randomHP;
	ch->HP += randomHP;
}

int RandNum(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min);
}

void Attack(Character* c1, Character* c2)
{
	if (c1->player == 1)
	{
		c1->defense_on = RandNum(0, 2);
	}

	if (c2->defense_on == 1)
	{
		// ����� ������
		if (c2->defense > c1->offense)
		{
			// ��� ������ �� ���ݷº��� ����
			// ���� �������� ���� �ʰ� ���� ���ݻ� ����
			if (c1->player == 0)
			{
				// �÷��̾ ���ݻ� ���� (���ʹ� �� ����)
				c1->HP -= c2->defense - c1->offense;
			}
		}
		else
		{
			// ��� ������ �� ���ݷº��� ����
			// ���� ���¸�ŭ �� �������� ����
			c2->HP -= c1->offense - c2->defense;
		}
	}
	else
	{
		// ����� ������
		c2->HP -= c1->offense;
	}

	if (c2->HP <= 0)
	{
		// c2 ���, c1 ��
		OnGameEnd(c1, c2);
	}
	else if (c1->HP <= 0)
	{
		// c1 ���, c2 ��
		OnGameEnd(c2, c1);
	}
}

void OnGameEnd(Character* winner, Character* loser)
{
	if (winner->player == 0)
	{
		// �÷��̾� ��
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
		// �÷��̾� �й�
		if (loser->EXP == 0)
		{
			// ���� ���� �߰�
			return;
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