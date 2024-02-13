#pragma once

#include <iostream>
#include <random>

#include "Define.h"

using namespace std;

class Character
{
protected:
	char	m_name[32];
	int		m_hp;
	int		m_maxHp;
	int		m_damage;

	int		m_state;	// 캐릭터 상태이상 판단

public:
	Character()
		: m_name{}
		, m_hp(0)
		, m_maxHp(0)
		, m_damage(0)
		, m_state(0)
	{}

	Character(const char _name[], int _maxHp, int _damage);

	~Character()
	{}

public:
	int GetDamage() { return m_damage; }
	int GetHp() { return m_hp; }
	void InitHp() { m_hp = m_maxHp; }
	void HpCalculate(int _other) { m_hp -= _other; }

	int GetState();
	void AddState(int _buff);
	void RemoveState(int _buff);

	virtual void Initialize(const char _name[], int _maxHp, int _damage, int _returnExp);
	
	virtual void ShowInfo() const;
	virtual void ShowInfo(int _i) const;
};

