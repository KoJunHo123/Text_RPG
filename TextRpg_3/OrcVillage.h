#pragma once
#include "FieldInfo.h"

class OrcVillage : public FieldInfo
{
private:

public:
	OrcVillage() {}
	~OrcVillage() {}

public:
	void Initialize(Character* _player);
	void Update();
	void Release();

private:
	void Debuff();
};

