#pragma once
#include <iostream>
#include "Enum.h"
#include "Define.h"
using namespace std;

struct tItem
{
	unsigned int count;
	unsigned int price;
};

class Inventory
{
private:
	tItem	m_redPotion;
	tItem	m_antiPoison;
	tItem	m_bandage;
	tItem	m_mentalCare;

	unsigned int m_money;

public:
	Inventory()
		: m_redPotion{ 0, 100 }
		, m_antiPoison{ 0, 100 }
		, m_bandage{ 0, 200 }
		, m_mentalCare{ 0, 300 }
		, m_money(0)
	{}
	~Inventory() {}

public:
	int UseItem(int _choice);
	bool AddItem(int _choice);
	void ShowInventory()const;
	void ShowShopItem()const;
	
	void AddMoney(int _money);
	int GetMoney();

	bool CompareMoney(int _item, int _pMoney);
	
};

