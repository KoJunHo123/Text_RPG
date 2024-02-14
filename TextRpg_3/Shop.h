#pragma once

#include "Player.h"
#include "ItemList.h"

class Shop
{
private:
	Character* m_player;
	ItemList m_item;

public:
	Shop()
		: m_player(nullptr)
	{}
	~Shop(){}

public:
	void Initialize(Character* _player);
	void Update();

private:
	void SellConsumable();
	void SellEquipment();
};

