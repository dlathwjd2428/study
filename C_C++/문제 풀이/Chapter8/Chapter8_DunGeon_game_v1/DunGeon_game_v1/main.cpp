#include "head.h""

int menu();
void Player_info(Character* player[]);
void Default_file(Character* Char_List[]);
int Dungeon_menu(Character* monster[]);
void SaveFile_w(Character* Char_List[]);
void SaveFile_r(Character* Char_List[]);

int monster_max = 0;

int main()
{
	Character* Char_List[MAX];

	Default_file(Char_List);

	while (1)
	{
		Char_List[MAX] = (Character*)malloc(sizeof(Character));
		
		
		system("cls");
		switch (menu())
		{
		case INDUNGEON:
			Dungeon_menu(Char_List);
			break;

		case PLAYER_INFO:
			Player_info(Char_List);
			break;

		case SAVE:
			SaveFile_w(Char_List);
			break;
		case LOAD:
			SaveFile_r(Char_List);
			break;

		case EXIT:
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
	printf("�÷��̾� �̸� �Է� : ");

	FILE* Default_fr = fopen("Default.txt", "r");

	if (Default_fr == NULL)
		printf("������ �����Ͱ� �����ϴ�, \n");
	else
	{
		for (int i = 0; i <= MAX; i++)
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
			fscanf(Default_fr, "%d %d %d %f %f %d %d %d", &Char_List[i]->offense,
															&Char_List[i]->defense,
															&Char_List[i]->Max_HP,
															&Char_List[i]->Max_EXP,
															&Char_List[i]->Get_EXP,
															&Char_List[i]->level,
															&Char_List[i]->player,
															&Char_List[i]->attack_speed);

			fscanf(Default_fr, "%d", &monster_max);
		}
		fclose(Default_fr);
	}
}

void SaveFile_r(Character* Char_List[])
{
	int ch = 0;
	char file_num[10];

	FILE* Save_fr;

	printf("=====Load=====\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%d������ : <���Ͽ��� : ", i);
	}
	printf("���� : ");

	scanf("%d", &ch);

	for (int num = '1'; num <= '10'; num++)
	{
		sprintf(file_num, "SaveFile%c.txt", num);
		Save_fr = fopen(file_num, "r");

		if (Save_fr == NULL)
			printf("������ �����Ͱ� �����ϴ�, \n");
		else
		{
			for (int i = 0; i < MAX; i++)
			{
				if (i == 1)
				{
					fscanf(Save_fr, "%d", &monster_max);
				}
				Char_List[i] = (Character*)malloc(sizeof(Character));
				fscanf(Save_fr, "%s %d %d %d %d %d %f %f %d %f %d %d", &Char_List[i]->name,
					&Char_List[i]->offense,
					&Char_List[i]->attack_speed,
					&Char_List[i]->HP,
					&Char_List[i]->defense,
					&Char_List[i]->defense_on,
					&Char_List[i]->EXP,
					&Char_List[i]->Get_EXP,
					&Char_List[i]->level,
					&Char_List[i]->Max_EXP,
					&Char_List[i]->Max_HP,
					&Char_List[i]->player);
			}
			fclose(Save_fr);
		}
	}

	
}

void SaveFile_w(Character* Char_List[])
{
	/*int f;
	FILE *fp;
	char ff[10];
	for (f = 'A'; f <= 'Z'; f++)
	{
		sprintf(ff, "%c.txt", f);
		fp = fopen(ff, "r");
		fclose(fp);
	}*/

	system("cls");

	char ch = 0;

	printf("=====Save=====");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d������ : <���Ͽ��� : ", i);
	}
	printf("\n���� : ");

	scanf("%c", &ch);

	FILE* Save_fw;
	char file_num[20];
	sprintf(file_num, "SaveFile%d.txt", ch-48);
	Save_fw = fopen(file_num, "w");

	for (int i = 0; i < MAX; i++)
	{
		fprintf(Save_fw, "%s %d %d %d %d %d %f %f %d %f %d %d", &Char_List[i]->name,
																&Char_List[i]->offense,
																&Char_List[i]->attack_speed,
																&Char_List[i]->HP,
																&Char_List[i]->defense,
																&Char_List[i]->defense_on,
																&Char_List[i]->EXP,
																&Char_List[i]->Get_EXP,
																&Char_List[i]->level,
																&Char_List[i]->Max_EXP,
																&Char_List[i]->Max_HP,
																&Char_List[i]->player);
	}
		
	fclose(Save_fw);

	printf("������ �Ϸ�Ǿ����ϴ�. \n");
	system("Pause");
}

void Player_info(Character* player[])
{
	system("cls");
	printf("======%s<%dLv>======\n", player[0]->name, player[0]->level);
	printf("���ݷ� = %d          ���� = %d       ����� = %d/50\n", player[0]->offense, player[0]->defense, player[0]->Max_HP);
	printf("����ġ = %d/10       GetEXP : %d\n", player[0]->Max_EXP, player[0]->Get_EXP);
	system("pause");
}

int Dungeon_menu(Character* monster[])
{
	int ch = 0;

	system("cls");
	printf("=====���� �Ա�=====\n");
	for (int i = 1; i < MAX; i++)
	{
		printf("  %d.%d������ : [%s]\n", i, i, monster[i]->name);
	}
	printf("  8.���ư���\n");
	printf("���� : ");
	scanf("%d", &ch);

	return ch;
}

void attack(Character* player[])
{
	printf("���� Ű : Space<����>,z<���>\n");
	printf("======%s<%dLv>======\n", player[0]->name, player[0]->level);
	printf("���ݷ� = %d          ���� = %d       ����� = %d/50\n", player[0]->offense, player[0]->defense, player[0]->Max_HP);
	printf("����ġ = %d/10       GetEXP : %d\n", player[0]->Max_EXP, player[0]->Get_EXP);
	printf("����� : On\n");
	printf("================\n");
	printf("======%s<%dLv>======\n", player[1]->name, player[1]->level);
	printf("���ݷ� = %d          ���� = %d       ����� = %d/50\n", player[0]->offense, player[0]->defense, player[0]->Max_HP);
	printf("����ġ = %d/10       GetEXP : %d\n", player[0]->Max_EXP, player[0]->Get_EXP);
	printf("����� : On\n");
	printf("================\n");
}