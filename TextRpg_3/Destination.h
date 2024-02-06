#pragma once
#include "Field.h"
#include "Shop.h"

#include "Enum.h"
#include "Define.h"

class Destination
{
private:
	int m_iInput;	// 목적지 저장... 왜 했더라...?

	Field* m_field;
	Shop* m_shop;
	Player* m_player;

public:
	Destination()
		: m_iInput(0)
		, m_field(nullptr)
		, m_shop(nullptr)
		, m_player(nullptr)
	{}

	~Destination();

public:
	void Initialize(Player* _player);
	void Update();
	void Release();
};

