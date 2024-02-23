#pragma once

#include <iostream>
#include <random>
#include <string>

#include "Define.h"

using namespace std;
using std::system;

class Character
{
protected:
	string	m_name;
	int		m_hp;
	int		m_maxHp;
	int		m_damage;

	int		m_state;	// ĳ���� �����̻� �Ǵ�

public:
	Character()
		: m_name{}
		, m_hp(0)
		, m_maxHp(0)
		, m_damage(0)
		, m_state(0)
	{}

	Character(string _name, int _maxHp, int _damage);

	virtual ~Character() {}

public:
	// ������ ��ȯ
	int GetDamage() { return m_damage; }
	// hp ��ȯ
	int GetHp() { return m_hp; }
	// hp �ִ��
	void InitHp() { m_hp = m_maxHp; }
	// hp ����
	void HpCalculate(int _damage) { m_hp -= _damage; }
	// ����â ��ȯ
	int GetState() { return m_state; }
	// ���� �߰�
	void AddState(int _buff) { m_state |= _buff; }
	// ���� ����
	void RemoveState(int _buff) { m_state &= ~_buff; }

	// �÷��̾�/���� �ʱ�ȭ
	virtual void Initialize(string _name, int _maxHp, int _damage) = 0;
	
	// �÷��̾�� ���Ϳ��� �θ��� �Լ��� �ٸ��� ������ ���� ���� �Լ��� �Ἥ�� �� ��.
	// �÷��̾� ���� ���
	virtual void ShowInfo() const {}
	// ���� ���� ���
	virtual void ShowInfo(int _i) const{}
};

