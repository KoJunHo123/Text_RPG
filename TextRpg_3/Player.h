#pragma once

#include "Characetr.h"
#include "Inventory.h"

#include <fstream>

class Player : public Character
{

private:
	int			m_level;
	int			m_exp;
	int			m_maxExp;

	Inventory		m_inven;

#pragma region �η��η�
	//vector<item>	m_inven_2;

	//item m_weapon;
	//item m_armor;

	//int m_money;
#pragma endregion ���� �͵�

public:
	Player()
		: m_level(1)
		, m_exp(0)
		, m_maxExp(50)
		, m_inven{}
#pragma region �η��η�
		//, m_inven_2{}
		//, m_money(0)
#pragma endregion ����͵�
	{}

	Player(string _name, int _maxHp, int _damage);

	virtual ~Player() {}

private:
	// ������ ���� ��������
	// int GetRandomNum(int _first, int _second);

public:
	void Initialize(string _name, int _maxHp, int _damage);

	void CalculateExp(int _getExp);
	bool DebuffEffect();
	void ShowInfo()const;	// ��� ������ ������ ���� ����.

	void OpenInventory();
	void AddItem(int _choice) { m_inven.AddItem(_choice); }
	void AddEquipItem(int _choice, int _wa) { m_inven.AddEquipItem(_choice, _wa); }

	void UseItemEffect(int _iInput);

	void AddMoney(int _money) { m_inven.AddMoney(_money); }
	int GetMoney() { return m_inven.GetMoney(); }
	void UseMoney(int _money) { m_inven.UseMoney(_money); }

#pragma region �η��η�
	//void BuyItem(item _item);
	//void SellItem();
	//void ShowInventory();

	//void SetWeapon(item _weapon);
	//void SetArmor(item _armor);

	//void SetItem();
#pragma endregion ���� �͵�

	void SavePlayer(ofstream& _file);
	void LoadPlayer(ifstream& _file);
	void CopyPlayerData(Player* _player);
};