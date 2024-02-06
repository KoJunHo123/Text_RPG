#pragma once

enum HUNTRANK
{
	EASY = 1,
	NORMAL,
	HARD,
	BACK
};

struct MonsterChar
{
	int MonsterRank;
	int MonsterHP;
	int MonsterDmg;
	wchar_t mName[8];

	int monsterCount;
};

// 몬스터 동적 할당
void AllocateMonster(MonsterChar** _mC, int _choice);
// 몬스터 초기화
void InitMonster(MonsterChar* _mC, int _rank, int _monsterCount);
// 몬스터 상태 포기
void ShowMonster(MonsterChar* _mC);
// 몬스터 메모리 해제
void ReleaseMonster(MonsterChar* _mC);