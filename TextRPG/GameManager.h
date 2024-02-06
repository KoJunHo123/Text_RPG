#pragma once

#include "Player.h"
#include "Monster.h"

enum PLAYERCHOICE
{
	HUNTING = 1,
	EXIT
};

enum BATTLE
{
	ATTACK = 1,
	RUN
};

enum KILLDEATH
{
	KILL = 1,
	DEATH
};


// ���� ����
void JobChoice(PlayerChar* _pC);

// ����� ������
int ActChoice(PlayerChar* _pC);

// ��/��/�� ����
void RankChoice(PlayerChar* _pC);

// ����
void Battle(PlayerChar* _pC, MonsterChar* _mC);

// ���, ų ����
void KillDeath(PlayerChar* _pC, MonsterChar* _mC, bool* _back, int _deathMonster);


