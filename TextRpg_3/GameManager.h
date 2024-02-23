#pragma once

#include <iostream>
#include "Characetr.h"
#include "Player.h"
#include "Destination.h"
#include "Enum.h"
#include "Define.h"

using namespace std;


class GameManager
{
	Character*	m_player;
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


private:
	bool Title();
	void JobChoice();
	void Start();
	void SaveChoice();


	void SaveFile();
	void LoadFile();
};