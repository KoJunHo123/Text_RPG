#pragma once
#include "Characetr.h"

class Monster : public Character
{
private:
	int m_returnExp;
	int m_returnMoney;

public:
	Monster()
		: m_returnExp(0)
		, m_returnMoney()
	{}

	Monster(const char _name[], int _maxHp, int _damage);

	~Monster() {}


public:
	int  GetReturnExp() { return m_returnExp; }
	void Initialize(const char _name[], int _maxHp, int _damage, int _returnExp);
	void ShowInfo(int _i)const;
	void RemoveAttack();

	void SetReturnMoney(int _money);
	int GetReturnMoney();
};

