#pragma once
#include "FieldInfo.h"

class GoblinForest : public FieldInfo
{
private:

public:
	GoblinForest(){}
	~GoblinForest(){}

public:
	void Initialize(Player* _player);
	void Update();
	void Release();

private:
	void Debuff();
};

