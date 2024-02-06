#include "Monster.h"

Monster::Monster(const char _name[], int _maxHp, int _damage)
	: Character(_name, _maxHp, _damage)
	, m_returnExp(0)
	, m_returnMoney(0)
{

}

void Monster::Initialize(const char _name[], int _maxHp, int _damage, int _returnExp)
{
	strcpy_s(m_name, sizeof(m_name), _name);
	m_hp = _maxHp;
	m_maxHp = _maxHp;
	m_damage = _damage;
	m_returnExp = _returnExp;
}

void Monster::ShowMonster(int _i)const
{
	if (0 < m_hp)
	{
		cout << _i + 1 << "번" << endl;
		cout << "이름 : " << m_name << endl;
		cout << "체력 : " << m_hp << '/' << m_maxHp << endl;
		cout << "공격력 : " << m_damage << endl;
		cout << "======================================" << endl;
	}
}

void Monster::RemoveAttack()
{
	m_damage = 0;
}

void Monster::SetReturnMoney(int _money)
{
	m_returnMoney = _money;
}

int Monster::GetReturnMoney()
{
	return m_returnMoney;
}
