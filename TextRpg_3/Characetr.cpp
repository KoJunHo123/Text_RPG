#include "Characetr.h"


Character::Character(const char _name[], int _maxHp, int _damage)
	: m_name{}
	, m_hp(_maxHp)
	, m_maxHp(_maxHp)
	, m_damage(_damage)
	, m_state(0)
{
	strcpy_s(m_name, sizeof(m_name), _name);
}

int Character::GetState()
{
	return m_state;
}

void Character::AddState(int _buff)
{
	m_state |= _buff;
}

void Character::RemoveState(int _buff)
{
	m_state &= ~_buff;
}

int GetRandomNum(int _first, int _second)
{

	// 시드값을 얻기 위한 진짜 난수 생성.
	random_device rd;

	// 메르센 트위스터 유사 난수 생성 알고리즘(객체가 큼(2kb 이상), 메모리 부족하면 minstd_rand()가 나을수도...?)
	// mt19937
	minstd_rand gen(rd());

	// (a, b) 사이의 균일한 정수 분포 생성
	uniform_int_distribution<int> dis(_first, _second);

	return dis(gen);
}
