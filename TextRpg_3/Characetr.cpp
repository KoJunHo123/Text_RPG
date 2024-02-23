#include "Characetr.h"


Character::Character(string _name, int _maxHp, int _damage)
	: m_name(_name)
	, m_hp(_maxHp)
	, m_maxHp(_maxHp)
	, m_damage(_damage)
	, m_state(0)
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

