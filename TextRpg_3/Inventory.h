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

// - 인벤토리 : 5칸. 아이템 저장. 구매. 판매.

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
		, m_money(0)
	{}
	~Inventory() {}

public:
	bool UseItem(int _choice) { return m_item.UseConsumableItem(_choice); }
	void AddItem(int _choice) { m_item.AddConsumableItem(_choice); }
	void ShowInventory()const;
	void ShowEquip() const;

	// 장비 추가
	void AddEquipItem(int _rankChoice, int _wa) { m_item.AddEquipmentItem(_rankChoice, _wa); }
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

