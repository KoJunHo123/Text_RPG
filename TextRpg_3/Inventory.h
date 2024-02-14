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

	// ��� �߰�
	void AddEquipItem(int _rankChoice, int _wa);

	// ��� ����
	int ChangeWeapon();
	int ChangeArmor();

	// ������ �߰�
	void AddMoney(int _money) { m_money += _money; }

	// ������ ��ȯ
	int GetMoney() { return m_money; }

	// ������ �Һ�
	void UseMoney(int _money) { m_money -= _money; }
};

