#pragma once
#include "Characetr.h"

class Monster : public Character
{
private:
	int m_returnExp;
	int m_returnMoney;

public:
	Monster()
		: m_returnExp(0)
		, m_returnMoney()
	{}

	Monster(string _name, int _maxHp, int _damage);

	~Monster() {}


public:
	// 초기화
	void Initialize(string _name, int _maxHp, int _damage);
	// 정보 출력
	void ShowInfo(int _i)const;

	// 경험치 반환
	int  GetReturnExp() { return m_returnExp; }
	// 공격 제거
	void RemoveAttack() { m_damage = 0; }
	// 획득 골드 설정
	void SetReturnMoney(int _money) { m_returnMoney = _money; }
	// 처치시 획득 골드
	int GetReturnMoney() { return m_returnMoney; }
};

