#pragma once
#include "FieldInfo.h"

class OrgerMountain : public FieldInfo
{
private:

public:
	OrgerMountain() {}
	~OrgerMountain() {}

public:
	void Initialize(Character* _player);
	void Update();
	void Release();

private:
	void Debuff();
};

