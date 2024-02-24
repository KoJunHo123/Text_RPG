#pragma once

#include "Monster.h"
#include "Player.h"
#include "Define.h"
#include "Enum.h"

#include <vector>
#include <ctime>
#include <random>

class FieldInfo abstract
{
protected:
	vector<Character*> m_monster;
	vector<Character*>::iterator m_monIter;

	Character* m_player;	// 플레이어 가져오기용
	int m_allow;		// 할당할 몬스터 수
	int m_debuff;		// 디버프 종류
	int m_debuffPer;	// 디버프 확률


public:
	FieldInfo()
		: m_monster()
		, m_monIter(m_monster.begin())
		, m_player(nullptr)
		, m_allow(0)
		, m_debuff(0)
		, m_debuffPer(0)
	{}
	virtual ~FieldInfo();


	// 추상 클래스 : 순수 가상 함수를 단 한 개라도 보유한 상태의 클래스
	// 자료형으로서는 존재하지만 객체 생성은 불가능한 클래스(어떠한 경우에도.)

public:
	virtual void Initialize(Character* _player) = 0;	// 순수 가상 함수(걍 ㄹㅇ로 오버라이딩 전용)
	// 오버라이딩을 위해 몸체가 없다고 표현.
	// 전방 선언과 같음. 먼저 선언하고 구현은 나중에 -> 근데 이런다고 객체를 만들 수 있는 건 아님.
	// 부모 타입 객체 아예 안쓴다는 마인드.

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
	virtual void Debuff() = 0;	
	
};

