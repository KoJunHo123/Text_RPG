#pragma once

#include <iostream>
#include <random>

#include "Define.h"

using namespace std;

class Character abstract
{
protected:
	char	m_name[32];
	int		m_hp;
	int		m_maxHp;
	int		m_damage;

	int		m_state;	// 캐릭터 상태이상 판단

public:
	Character()
		: m_name{}
		, m_hp(0)
		, m_maxHp(0)
		, m_damage(0)
		, m_state(0)
	{}

	Character(const char _name[], int _maxHp, int _damage);

	virtual ~Character() {}

public:
	// 데미지 반환
	int GetDamage() { return m_damage; }
	// hp 반환
	int GetHp() { return m_hp; }
	// hp 최대로
	void InitHp() { m_hp = m_maxHp; }
	// hp 깎임
	void HpCalculate(int _damage) { m_hp -= _damage; }
	// 상태창 반환
	int GetState() { return m_state; }
	// 상태 추가
	void AddState(int _buff) { m_state |= _buff; }
	// 상태 제거
	void RemoveState(int _buff) { m_state &= ~_buff; }

	// 플레이어/몬스터 초기화
	virtual void Initialize(const char _name[], int _maxHp, int _damage) = 0;
	
	// 플레이어와 몬스터에서 부르는 함수가 다르기 때문에 순수 가상 함수를 써서는 안 됨.
	// 플레이어 정보 출력
	virtual void ShowInfo() const {}
	// 몬스터 정보 출력
	virtual void ShowInfo(int _i) const{}
};

