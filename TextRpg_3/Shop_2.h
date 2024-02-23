#pragma once
#include "Player.h"
#include "Define.h"

class Shop_2
{
private:
	Character*	m_player;
	item		m_item[3][2];

public:
	Shop_2()
		: m_player(nullptr)
		, m_item{}
	{}
	~Shop_2(){}

public:
	void Initialize(Character* _player);
	void Update();

};

