#include "CharacterInfo.h"
#include <ctime>

PlayerInfo::PlayerInfo(int _jobNum)
	: m_exp(0)
	, m_maxExp(50)

	, m_maxHpUp(0)	// ������ �� hp ������
	, m_maxDamageUp(0)	// ������ �� ������ ������
	, m_maxExpUp(20)
{
	// �ٸ� �Է��� gamemanager���� ������ ��.
	switch (_jobNum)
	{
	case (int)PLAYERJOB::WARRIOR:
		wcscpy_s(m_name, L"����");
		m_hp = 300;
		m_maxHp = 300;
		m_damage = 10;
		m_level = 1;
		break;
	case (int)PLAYERJOB::MAGITION:
		wcscpy_s(m_name, L"������");
		m_hp = 100;
		m_maxHp = 100;
		m_damage = 30;
		m_level = 1;
		break;
	case (int)PLAYERJOB::THIEF:
		wcscpy_s(m_name, L"����");
		m_hp = 200;
		m_maxHp = 200;
		m_damage = 20;
		m_level = 1;
		break;
	default:
		break;
	}
	m_maxDamageUp = m_damage / 10;
	m_maxHpUp = m_maxHp / 10;

}

void PlayerInfo::ShowPlayerInfo()
{
	wcout << L"����: " << m_name << endl;
	wcout << L"����: " << m_level << endl;
	wcout << L"ü��: " << m_hp << "/" << m_maxHp << endl;
	wcout << L"���ݷ�: " << m_damage << endl;
	wcout << L"����ġ: " << m_exp << "/" << m_maxExp << endl;
	wcout << L"========================" << endl;
}

int PlayerInfo::Get_Damage()
{
	return m_damage;
}

int PlayerInfo::Get_HP()
{
	return m_hp;
}


void PlayerInfo::DamageCalculate(int _getDamage)
{
	m_hp -= _getDamage;
}

void PlayerInfo::ExpUp(int _getExp)
{
	m_exp += _getExp;

	if (m_exp >= m_maxExp)
	{
		++m_level;
		m_damage += m_maxDamageUp;
		m_maxHp += m_maxHpUp;
		m_maxExp += m_maxExpUp;
		m_exp = 0;
		InitHP();
	}

}

inline void PlayerInfo::InitHP()
{
	m_hp = m_maxHp;
}

MonsterInfo::MonsterInfo(int _hunting)
{
	srand(time(nullptr));

	int randNum = rand();
	int upNum = 3 * (randNum % 5 + 1);

	switch (_hunting)
	{
	case (int)MONSTERRANK::GOBLIN:
		wcscpy_s(m_name, L"���");
		m_level = randNum % 5 + 1;
		m_hp = 30 + upNum;
		m_maxHp = 30 + upNum;
		m_damage = 3 + upNum/10;

		break;

	case (int)MONSTERRANK::ORC:
		wcscpy_s(m_name, L"��ũ");
		m_level = randNum % 5 + 6;
		m_hp = 60 + upNum;
		m_maxHp = 60 + upNum;
		m_damage = 6 + upNum / 10;
		break;

	case (int)MONSTERRANK::OGRE:
		wcscpy_s(m_name, L"�����");
		m_level = randNum % 5 + 11;
		m_hp = 90 + upNum;
		m_maxHp = 90 + upNum;
		m_damage = 9 + upNum / 10;
		break;

	default :
		break;
	}
}

void MonsterInfo::ShowMonsterInfo(int _monNum)
{
	if(m_hp > 0)
	{
		wcout << L"��ȣ: " << _monNum+1 << endl;
		wcout << L"�̸�: " << m_name << endl;
		wcout << L"����: " << m_level << endl;
		wcout << L"ü��: " << m_hp << "/" << m_maxHp << endl;
		wcout << L"���ݷ�: " << m_damage << endl;
		wcout << L"========================" << endl;
	}
}

int MonsterInfo::Get_Damage()
{
	if (m_hp <= 0)
		m_damage = 0;
	return m_damage;
}

void MonsterInfo::DamageCalculate(int _getDamage)
{
	m_hp -= _getDamage;
}


int MonsterInfo::Get_HP()
{
	return m_hp;
}