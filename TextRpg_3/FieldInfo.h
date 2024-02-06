#pragma once

#include "Monster.h"
#include "Player.h"
#include "Define.h"
#include "Enum.h"

#include "ctime"
#include "random"

class FieldInfo
{
protected:
	Monster* m_monster;	// ���� �����Ҵ�
	Player* m_player;	// �÷��̾� ���������
	int m_allow;		// �Ҵ��� ���� ��
	int m_debuff;		// ����� ����
	int m_debuffPer;	// ����� Ȯ��

	int m_alliveMonster;	// ������ ���� �� Ȯ��

public:
	FieldInfo()
		: m_monster(nullptr)
		, m_player(nullptr)
		, m_allow(0)
		, m_debuff(0)
		, m_debuffPer(0)
		, m_alliveMonster(0)
	{}
	~FieldInfo();

public:
	virtual void Initialize(Player* _player);
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
	virtual void Debuff();
	
};
