#pragma once

#include "Player.h"
#include "Inventory.h"

class Shop
{
private:
	Player* m_player;

public:
	Shop()
		: m_player(nullptr)
	{}
	~Shop(){}

public:
	void Initialize(Player* _player);
	void Update();

};

