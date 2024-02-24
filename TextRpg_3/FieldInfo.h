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

	Character* m_player;	// �÷��̾� ���������
	int m_allow;		// �Ҵ��� ���� ��
	int m_debuff;		// ����� ����
	int m_debuffPer;	// ����� Ȯ��


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


	// �߻� Ŭ���� : ���� ���� �Լ��� �� �� ���� ������ ������ Ŭ����
	// �ڷ������μ��� ���������� ��ü ������ �Ұ����� Ŭ����(��� ��쿡��.)

public:
	virtual void Initialize(Character* _player) = 0;	// ���� ���� �Լ�(�� ������ �������̵� ����)
	// �������̵��� ���� ��ü�� ���ٰ� ǥ��.
	// ���� ����� ����. ���� �����ϰ� ������ ���߿� -> �ٵ� �̷��ٰ� ��ü�� ���� �� �ִ� �� �ƴ�.
	// �θ� Ÿ�� ��ü �ƿ� �Ⱦ��ٴ� ���ε�.

	void Update();
	void Release();
	// ������ ���� ��������
	// int GetRandomNum(int _first, int _second);

private:
	// ���� ���� ���
	void ShowMonsterArr();
	
	// ������
	void Fight();
	// ������ ���
	void DamageCalculate(int _iAttack);
	// ��������
	bool Decision();

	// ����� ȹ��
	virtual void Debuff() = 0;	
	
};

