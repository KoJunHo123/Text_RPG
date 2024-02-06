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

// ���� ���� �Ҵ�
void AllocateMonster(MonsterChar** _mC, int _choice);
// ���� �ʱ�ȭ
void InitMonster(MonsterChar* _mC, int _rank, int _monsterCount);
// ���� ���� ����
void ShowMonster(MonsterChar* _mC);
// ���� �޸� ����
void ReleaseMonster(MonsterChar* _mC);