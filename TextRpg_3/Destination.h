#pragma once
#include "Field.h"
#include "Shop.h"
// #include "Shop_2.h"
#include "Labyrinth.h"

#include "Enum.h"
#include "Define.h"

class Destination
{
private:
	Field* m_field;
	Shop* m_shop;
	Character* m_player;
	Labyrinth* m_labyrinth;

	// Shop_2* m_shop_2;

public:
	Destination()
		: m_field(nullptr)
		, m_shop(nullptr)
		, m_player(nullptr)
		, m_labyrinth(nullptr)
		// , m_shop_2(nullptr)
	{}

	~Destination();

public:
	void Initialize(Character* _player);
	void Update();

	template <typename T>
	void Release(T& _release);
};

