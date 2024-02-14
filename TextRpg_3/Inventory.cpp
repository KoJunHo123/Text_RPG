#include "Inventory.h"

bool Inventory::UseItem(int _choice)
{
	return m_item.UseConsumableItem(_choice);
}

void Inventory::AddItem(int _choice)
{
	m_item.AddConsumableItem(_choice);
}

void Inventory::AddEquipItem(int _rankChoice, int _wa)
{
	m_item.AddEquipmentItem(_rankChoice, _wa);
}

int Inventory::ChangeWeapon()
{
	int iInput = 0;
	cout << "1. 오래된 무기    2. 새로운 무기    3. 튼튼한 무기    4. 돌아가기 : ";
	cin >> iInput;

	int save = m_wear.weapon.addDmg;

	switch (iInput)
	{
	case (int)EQUIPRANK::OLD:
	case (int)EQUIPRANK::NEW:
	case (int)EQUIPRANK::HARD:
		if (m_item.CheckWeapon(iInput))
		{
			m_wear.weapon = m_item.GetEquipWeapon(iInput);
			cout << "아이템이 변경되었습니다." << endl;
			system("pause");
			return (m_wear.weapon.addDmg - save);
		}
		else
		{
			cout << "아이템이 없습니다." << endl;
			system("pause");
		}
		break;

	case (int)EQUIPRANK::BACK:
		break;
	}
	return 0;
}

int Inventory::ChangeArmor()
{
	int iInput = 0;
	cout << "1. 오래된 갑옷    2. 새로운 갑옷    3. 튼튼한 갑옷    4. 돌아가기 : ";
	cin >> iInput;

	int save = m_wear.armor.addHP;

	switch (iInput)
	{
	case (int)EQUIPRANK::OLD:
	case (int)EQUIPRANK::NEW:
	case (int)EQUIPRANK::HARD:
		if (m_item.CheckArmor(iInput))
		{
			m_wear.armor = m_item.GetEquipArmor(iInput);
			cout << "아이템이 변경되었습니다." << endl;
			system("pause");
			return (m_wear.armor.addHP - save);
		}
		else
			cout << "아이템이 없습니다." << endl;
		break;

	case (int)EQUIPRANK::BACK:
		break;
	}
	return 0;
}

void Inventory::ShowInventory()const
{
	cout << "소비창" << endl;
	m_item.ShowConsumableItem();
	cout << "소지금액	: " << m_money << endl;
}

void Inventory::ShowEquip() const
{
	cout << "장비창" << endl;
	cout << "착용 무기 : " << m_wear.weapon.name << endl;
	cout << "착용 갑옷 : " << m_wear.armor.name << endl;

	cout << "소지 장비" << endl;
	m_item.ShowEquipmentItem();
	cout << "소지금액	: " << m_money << endl;
}