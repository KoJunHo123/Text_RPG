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

	~Player() {}

private:
	// 랜덤한 숫자 가져오기
	// int GetRandomNum(int _first, int _second);

public:
	void CalculateExp(int _getExp);
	bool DebuffEffect();
	void ShowInfo()const;	// 멤버 변수를 보여줄 일이 없음.

	void OpenInventory();
	void OpenShop();

	void UseItemEffect(int _iInput);

	void AddMoney(int _money);


	void SavePlayer(ofstream& _file);
	void LoadPlayer(ifstream& _file);
};