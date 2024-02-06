#pragma once

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Destination.h"
#include "Enum.h"
#include "Define.h"

using namespace std;


class GameManager
{
	Player*		m_player;
	Destination m_destination;


public:
	GameManager()
		: m_player(nullptr)
		, m_destination{}
	{}

	~GameManager();

public:
	void Initialize();
	void Update();
	void Release();

public:
	bool Title();
	void JobChoice();
};