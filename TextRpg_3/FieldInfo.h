#pragma once

#include "Monster.h"
#include "Player.h"
#include "Define.h"
#include "Enum.h"

#include "ctime"
#include "random"

class FieldInfo
{
protected:
	Character* m_monster;	// 몬스터 동적할당
	Character* m_player;	// 플레이어 가져오기용
	int m_allow;		// 할당할 몬스터 수
	int m_debuff;		// 디버프 종류
	int m_debuffPer;	// 디버프 확률

	int m_alliveMonster;	// 생존한 몬스터 수 확인

public:
	FieldInfo()
		: m_monster(nullptr)
		, m_player(nullptr)
		, m_allow(0)
		, m_debuff(0)
		, m_debuffPer(0)
		, m_alliveMonster(0)
	{}
	~FieldInfo();

public:
	virtual void Initialize(Character* _player);
	void Update();
	void Release();
	// 랜덤한 숫자 가져오기
	// int GetRandomNum(int _first, int _second);

private:
	// 몬스터 전부 출력
	void ShowMonsterArr();
	
	// 전투신
	void Fight();
	// 데미지 계산
	void DamageCalculate(int _iAttack);
	// 승패판정
	bool Decision();

	// 디버프 획득
	virtual void Debuff();
	
};

