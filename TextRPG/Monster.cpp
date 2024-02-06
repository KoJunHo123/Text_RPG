#include "Monster.h"

#include <time.h>
#include <iostream>

using namespace std;

void AllocateMonster(MonsterChar** _mC, int _choice)
{
	srand(time(nullptr));

	int rankCount = 0;
	switch (_choice)
	{
	case EASY: rankCount = 3;
		break;
	case NORMAL: rankCount = 2;
		break;
	case HARD: rankCount = 1;
		break;
	default:
		return;
	}

	int monsterCount = (rand() % rankCount) + 1;

	*_mC = new MonsterChar[monsterCount];
	for (int i = 0; i < monsterCount; ++i)
	{
		InitMonster(*_mC + i, _choice, monsterCount);
	}
}

void InitMonster(MonsterChar* _mC, int _rank, int _monsterCount)
{
    _mC->MonsterRank = _rank;
	_mC->MonsterHP = 30 * _mC->MonsterRank;
	_mC->MonsterDmg = 3 * _mC->MonsterRank;

	_mC->monsterCount = _monsterCount;

	switch (_rank)
	{
	case EASY:
		wcsncpy_s(_mC->mName, L"쉬움", 8);
		break;
	case NORMAL:
		wcsncpy_s(_mC->mName, L"보통", 8);
		break;
	case HARD:
		wcsncpy_s(_mC->mName, L"어려움", 8);
		break;
	}
}

void ShowMonster(MonsterChar* _mC)
{
	for (int i = 0; i < _mC->monsterCount; ++i)
	{
		if ((_mC + i)->MonsterHP > 0)
		{
			cout << i + 1 << "번 몬스터 : ";
			wcout << (_mC + i)->mName << endl;
			cout << "체력 : " << (_mC + i)->MonsterHP << "\t공격력 : " << (_mC + i)->MonsterDmg << endl;
			cout << "======================================" << endl;
		}
	}
}

void ReleaseMonster(MonsterChar* _mC)
{
	delete[] _mC;
	_mC = nullptr;
}
