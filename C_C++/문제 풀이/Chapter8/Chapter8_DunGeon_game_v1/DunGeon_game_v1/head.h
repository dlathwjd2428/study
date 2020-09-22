#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define MAX 8

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
	float EXP; //���� ����ġ
	float Max_EXP; //�ִ� ����ġ	
	float Die_EXP; //�׾����� �ִ� ����ġ
	bool defense_on; //��� on/off
	int level; //����
	bool player; //player�� enemy ���� ����
	int attack_speed;//enemy�� ��� ���� �ӵ� (10�� 0.1��)
}Character;