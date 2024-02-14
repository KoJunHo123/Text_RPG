#pragma once

#include "Characetr.h"
#include "Inventory.h"

#include <fstream>

class Player : public Character
{

private:
	int			m_level;
	int			m_exp;
	int			m_maxExp;

	Inventory	m_inven;

public:
	Player()
		: m_level(1)
		, m_exp(0)
		, m_maxExp(50)
		, m_inven{}
	{}

	Player(const char _name[], int _maxHp, int _damage);

	virtual ~Player() {}

private:
	// 랜덤한 숫자 가져오기
	// int GetRandomNum(int _first, int _second);

public:
	void Initialize(const char _name[], int _maxHp, int _damage);

	void CalculateExp(int _getExp);
	bool DebuffEffect();
	void ShowInfo()const;	// 멤버 변수를 보여줄 일이 없음.

	void OpenInventory();
	void AddItem(int _choice) { m_inven.AddItem(_choice); }
	void AddEquipItem(int _choice, int _wa) { m_inven.AddEquipItem(_choice, _wa); }

	void UseItemEffect(int _iInput);

	void AddMoney(int _money) { m_inven.AddMoney(_money); }
	int GetMoney() { return m_inven.GetMoney(); }
	void UseMoney(int _money) { m_inven.UseMoney(_money); }

	/*void SavePlayer(ofstream& _file);
	void LoadPlayer(ifstream& _file);*/
};