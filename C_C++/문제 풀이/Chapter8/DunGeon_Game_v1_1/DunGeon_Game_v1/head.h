#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX 10

enum
{
	INDUNGEON = 1,
	PLAYER_INFO,
	SAVE,
	LOAD,
	EXIT
};

typedef struct _Character
{
	char name[20];
	int offense; //���ݷ�
	int defense; //����
	int HP; //���� ü��
	int Max_HP; //�ִ� ü��
	int EXP; //���� ����ġ
	int Max_EXP; //�ִ� ����ġ	
	int Get_EXP; //�׾����� �ִ� ����ġ
	int defense_on ; //��� on/off
	int level; //����
	int player; //player�� enemy ���� ����
	int attack_speed;//enemy�� ��� ���� �ӵ� (10�� 0.1��)
}Character;