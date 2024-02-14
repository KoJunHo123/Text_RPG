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
	cout << "1. ������ ����    2. ���ο� ����    3. ưư�� ����    4. ���ư��� : ";
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
			cout << "�������� ����Ǿ����ϴ�." << endl;
			system("pause");
			return (m_wear.weapon.addDmg - save);
		}
		else
		{
			cout << "�������� �����ϴ�." << endl;
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
	cout << "1. ������ ����    2. ���ο� ����    3. ưư�� ����    4. ���ư��� : ";
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
			cout << "�������� ����Ǿ����ϴ�." << endl;
			system("pause");
			return (m_wear.armor.addHP - save);
		}
		else
			cout << "�������� �����ϴ�." << endl;
		break;

	case (int)EQUIPRANK::BACK:
		break;
	}
	return 0;
}

void Inventory::ShowInventory()const
{
	cout << "�Һ�â" << endl;
	m_item.ShowConsumableItem();
	cout << "�����ݾ�	: " << m_money << endl;
}

void Inventory::ShowEquip() const
{
	cout << "���â" << endl;
	cout << "���� ���� : " << m_wear.weapon.name << endl;
	cout << "���� ���� : " << m_wear.armor.name << endl;

	cout << "���� ���" << endl;
	m_item.ShowEquipmentItem();
	cout << "�����ݾ�	: " << m_money << endl;
}