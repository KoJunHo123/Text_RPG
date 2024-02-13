#pragma once

#include "Player.h"
#include "Inventory.h"

class Shop
{
private:
	Character* m_player;

public:
	Shop()
		: m_player(nullptr)
	{}
	~Shop(){}

public:
	void Initialize(Character* _player);
	void Update();

};

