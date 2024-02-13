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

void Character::Initialize(const char _name[], int _maxHp, int _damage, int _returnExp)
{
}

void Character::ShowInfo() const
{
}

void Character::ShowInfo(int _i) const
{
}


// �ܺ� �Լ� ����
int GetRandomNum(int _first, int _second)
{

	// �õ尪�� ��� ���� ��¥ ���� ����.
	random_device rd;

	// �޸��� Ʈ������ ���� ���� ���� �˰���(��ü�� ŭ(2kb �̻�), �޸� �����ϸ� minstd_rand()�� ��������...?)
	// mt19937
	minstd_rand gen(rd());

	// (a, b) ������ ������ ���� ���� ����
	uniform_int_distribution<int> dis(_first, _second);

	return dis(gen);
}
