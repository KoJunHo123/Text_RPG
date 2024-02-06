#pragma once
#include <iostream>
#include "CharacterInfo.h"


enum class START
{
	START = 1,
	EXIT,
	END
};

enum class ACT
{
	HUNT = 1,
	MARKET,
	EXIT,
	END
};

enum class HUNT
{
	GOBLIN = 1,
	ORC,
	ORGER,
	END
};

class GameManager
{
private:
	PlayerInfo m_player;
	MonsterInfo* m_monster;
	int m_start;
	int m_jobChoice;
	int m_actChoice;
	int m_hunting;
	int m_allocNum;
	int m_attack;

public:
	GameManager()
		: m_player{}
		, m_monster(nullptr)
		, m_start(0)
		, m_jobChoice(0)
		, m_actChoice(0)
		, m_hunting(0)
		, m_allocNum(0)
		, m_attack(0)
	{}

	~GameManager()
	{}

public:
	void StratGame();
	bool JobChoice();
	int ActChoice();
	void HuntingGround();
	void Battle();
	void DamageCalculate();
	bool WinOrLose();
};

