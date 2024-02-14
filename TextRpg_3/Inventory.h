#pragma once
#include <iostream>
#include "Enum.h"
#include "Define.h"
#include "ItemList.h"
using namespace std;

struct WearItem
{
	tWeapon weapon;
	tArmor armor;
};

class Inventory
{
private:
	ItemList m_item;
	WearItem m_wear;

	unsigned int m_money;

public:
	Inventory()
		: m_item{}
		, m_wear{}
		, m_money(1000000)
	{}
	~Inventory() {}

public:
	bool UseItem(int _choice);
	void AddItem(int _choice);
	void ShowInventory()const;
	void ShowEquip() const;

	// 장비 추가
	void AddEquipItem(int _rankChoice, int _wa);

	// 장비 변경
	int ChangeWeapon();
	int ChangeArmor();

	// 소지금 추가
	void AddMoney(int _money) { m_money += _money; }

	// 소지금 반환
	int GetMoney() { return m_money; }

	// 소지금 소비
	void UseMoney(int _money) { m_money -= _money; }
};

