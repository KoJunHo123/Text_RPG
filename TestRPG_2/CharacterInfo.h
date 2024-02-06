#pragma once
#include <iostream>
#include <ctime>

#define InErr cout << "잘못된 입력입니다." << endl;

using namespace std;

enum class PLAYERJOB
{
	WARRIOR = 1,
	MAGITION,
	THIEF,
	END
};

enum class MONSTERRANK
{
	GOBLIN = 1,
	ORC,
	OGRE,
	END
};


class CharacterInfo
{
protected:
	wchar_t m_name[16];
	int		m_hp;
	int		m_damage;
	int		m_maxHp;
	int		m_level;

public:
	CharacterInfo()
		: m_name{}
		, m_hp(0)
		, m_damage(0)
		, m_maxHp(0)
		, m_level(0)
	{}

	~CharacterInfo()
	{
	}

};

class PlayerInfo : public CharacterInfo
{
private:
	int		m_exp;
	int		m_maxExp;
	int		m_maxHpUp;
	int		m_maxDamageUp;
	int		m_maxExpUp;

public:
	PlayerInfo()
		: m_exp(0)
		, m_maxExp(50)
		, m_maxHpUp(0)
		, m_maxDamageUp(0)
		, m_maxExpUp(20)
	{}
	PlayerInfo(int _jobNum);
	~PlayerInfo()
	{}

public:
	void ShowPlayerInfo();
	int Get_Damage();
	int Get_HP();
	void DamageCalculate(int _getDamage);
	void ExpUp(int _getExp);
	void InitHP();

};

class MonsterInfo : public CharacterInfo
{
private:
public:
	MonsterInfo()
	{
	}
	MonsterInfo(int _hunt);
	~MonsterInfo()
	{
	}

public:
	void ShowMonsterInfo(int _monNum);
	int Get_Damage();
	int Get_HP();
	void DamageCalculate(int _getDamage);
};

