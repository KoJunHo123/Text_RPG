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
	// �ʱ�ȭ
	void Initialize(string _name, int _maxHp, int _damage);
	// ���� ���
	void ShowInfo(int _i)const;

	// ����ġ ��ȯ
	int  GetReturnExp() { return m_returnExp; }
	// ���� ����
	void RemoveAttack() { m_damage = 0; }
	// ȹ�� ��� ����
	void SetReturnMoney(int _money) { m_returnMoney = _money; }
	// óġ�� ȹ�� ���
	int GetReturnMoney() { return m_returnMoney; }
};

