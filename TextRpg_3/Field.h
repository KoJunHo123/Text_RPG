#pragma once
#include "Player.h"

#include "GoblinForest.h"
#include "OrcVillage.h"
#include "OrgerMountain.h"

#include "Enum.h"
#include "Define.h"

class Field
{
private:
	Character* m_player;
	FieldInfo* m_fieldInfo;

	int m_iInput;

public:
	Field()
		: m_player(nullptr)
		, m_fieldInfo(nullptr)
		, m_iInput(0)
	{}

	~Field();

public:
	void Initialize(Character* _player);
	void Update();
	void Release();

public:

};

