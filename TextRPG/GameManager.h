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


// 직업 선택
void JobChoice(PlayerChar* _pC);

// 사냥터 나가기
int ActChoice(PlayerChar* _pC);

// 초/중/고 선택
void RankChoice(PlayerChar* _pC);

// 전투
void Battle(PlayerChar* _pC, MonsterChar* _mC);

// 사망, 킬 판정
void KillDeath(PlayerChar* _pC, MonsterChar* _mC, bool* _back, int _deathMonster);


