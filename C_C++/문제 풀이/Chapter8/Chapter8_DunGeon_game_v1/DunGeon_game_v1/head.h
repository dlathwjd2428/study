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
	int offense; //공격력
	int defense; //방어력
	int HP = 50; //현재 체력
	int Max_HP; //최대 체력
	float EXP = 0; //현재 경험치
	float Max_EXP; //최대 경험치	
	float Get_EXP; //죽었을때 주는 경험치
	int defense_on; //방어 on/off
	int level; //레벨
	int player; //player와 enemy 구분 변수
	int attack_speed;//enemy일 경우 공격 속도 (10당 0.1초)
}Character;