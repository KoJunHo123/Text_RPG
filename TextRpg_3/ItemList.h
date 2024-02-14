#pragma once
#include <iostream>
#include "Enum.h"
#include "Define.h"

using namespace std;

struct tItem
{
	unsigned int count;
	unsigned int price;
};

struct tWeapon
{
	string			name;
	bool			own;
	int				addDmg;
	unsigned int	price;
};

struct tArmor
{
	string			name;
	bool			own;
	int				addHP;
	unsigned int	price;
};

class ItemList
{
private:
	tItem	m_redPotion;
	tItem	m_antiPoison;
	tItem	m_bandage;
	tItem	m_mentalCare;

	// 오래된
	tWeapon	m_oldWeapon;
	tArmor	m_oldArmor;

	// 새로운
	tWeapon	m_newWeapon;
	tArmor	m_newArmor;
	
	// 단단한
	tWeapon	m_hardWeapon;
	tArmor	m_hardArmor;

public:
	ItemList()
		: m_redPotion{ 0, 100 }
		, m_antiPoison{ 0, 100 }
		, m_bandage{ 0, 200 }
		, m_mentalCare{ 0, 300 }

		, m_oldWeapon{ "오래된 무기", false, 10, 100}
		, m_oldArmor{ "오래된 갑옷", false, 100, 100 }

		, m_newWeapon{ "새로운 무기", false, 20, 200 }
		, m_newArmor{ "새로운 갑옷", false, 200, 200 }
		
		, m_hardWeapon{ "튼튼한 무기", false, 30, 300 }
		, m_hardArmor{ "튼튼한 갑옷", false, 300, 300 }

	{}
	~ItemList(){}

public:
	// 소비 아이템
	tItem GetConsumableItem(int _input);
	void AddConsumableItem(int _input);
	bool UseConsumableItem(int _input);

	void ShowConsumableItem() const;
	void ShowConsumableItemPrice() const;

	// 장비 아이템
	tWeapon GetEquipWeapon(int _input);
	tArmor GetEquipArmor(int _input);

	bool CheckWeapon(int _input);
	bool CheckArmor(int _input);

	void ShowEquipmentItem() const;
	void ShowEquipmentItemPrice(int _iInput) const;
	
	void AddEquipmentItem(int _input, int _iInputWA);

	// 가격 갖고 오기
	int GetPrice(int _itemType, int _input, int _wa);

private:
	void ChoiceWeaponOrArmor(tWeapon& _weapon, tArmor& _armor, int _iInputWA);
};