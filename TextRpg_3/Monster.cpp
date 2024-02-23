#include "Monster.h"

Monster::Monster(string _name, int _maxHp, int _damage)
	: Character(_name, _maxHp, _damage)
	, m_returnExp(0)
	, m_returnMoney(0)
{

}

void Monster::Initialize(string _name, int _maxHp, int _damage)
{
	m_name = _name;
	m_hp = _maxHp;
	m_maxHp = _maxHp;
	m_damage = _damage;
	m_returnExp = _maxHp / 3;
}

void Monster::ShowInfo(int _i)const
{
	if (0 < m_hp)
	{
		cout << _i + 1 << "��" << endl;
		cout << "�̸� : " << m_name << endl;
		cout << "ü�� : " << m_hp << '/' << m_maxHp << endl;
		cout << "���ݷ� : " << m_damage << endl;
		cout << "======================================" << endl;
	}
}

