#include "Inventory.h"

int Inventory::UseItem(int _choice)
{
	switch (_choice)
	{
	case (int)ITEM::REDP:
		if (0 < m_redPotion.count)
			--m_redPotion.count;
		else
		{
			cout << "������ �������� �����ϴ�." << endl;
			return -1;
		}
		break;

	case (int)ITEM::ANTI:
		if (0 < m_antiPoison.count)
			--m_antiPoison.count;
		else
		{
			cout << "������ �������� �����ϴ�." << endl;
			return -1;
		}
		break;

	case (int)ITEM::BAND:
		if (0 < m_bandage.count)
			--m_bandage.count;
		else
		{
			cout << "������ �������� �����ϴ�." << endl;
			return -1;
		}
		break;

	case (int)ITEM::MENTAL:
		if (0 < m_mentalCare.count)
			--m_mentalCare.count;
		else
		{
			cout << "������ �������� �����ϴ�." << endl;
			return -1;
		}
		break;

	case (int)ITEM::RETURN:
		return 0;

	default:
		InErr;
		break;
	}
	return 1;
}

bool Inventory::AddItem(int _choice)
{
	switch (_choice)
	{
	case (int)ITEM::REDP:
		cout << "���� ���� ����" << endl;
		++m_redPotion.count;
		m_money -= m_redPotion.price;
		break;

	case (int)ITEM::ANTI:
		cout << "�ص��� ����" << endl;
		++m_antiPoison.count;
		m_money -= m_antiPoison.price;
		break;

	case (int)ITEM::BAND:
		cout << "�ش� ����" << endl;
		++m_bandage.count;
		m_money -= m_bandage.price;
		break;

	case (int)ITEM::MENTAL:
		cout << "û��ȯ ����" << endl;
		++m_mentalCare.count;
		m_money -= m_mentalCare.price;
		break;

	case (int)ITEM::RETURN:
		return false;

	default:
		InErr;
		break;
	}
	return true;
}

void Inventory::ShowInventory()const
{
	cout << "�κ��丮" << endl;
	cout << "���� ����	: " << m_redPotion.count << endl;
	cout << "�ص���		: " << m_antiPoison.count << endl;
	cout << "�ش�		: " << m_bandage.count <<endl;
	cout << "û��ȯ		: " << m_mentalCare.count << endl;
	cout << "�����ݾ�	: " << m_money << endl;
}

void Inventory::ShowShopItem()const
{
	cout << "����" << endl;
	cout << "���� ����	: " << m_redPotion.price << " Gold" << endl;
	cout << "�ص���		: " << m_antiPoison.price << " Gold" << endl;
	cout << "�ش�		: " << m_bandage.price << " Gold" << endl;
	cout << "û��ȯ		: " << m_mentalCare.price << " Gold" << endl;
	cout << "�����ݾ�	: " << m_money << " Gold" << endl;

}

void Inventory::AddMoney(int _money)
{
	m_money += _money;
}

int Inventory::GetMoney()
{
	return m_money;
}

bool Inventory::CompareMoney(int _item, int _pMoney)
{
	switch (_item)
	{
	case (int)ITEM::REDP:
		if (m_redPotion.price > _pMoney)
			return false;
		break;

	case (int)ITEM::ANTI:
		if (m_antiPoison.price > _pMoney)
			return false;
		break;

	case (int)ITEM::BAND:
		if (m_bandage.price > _pMoney)
			return false;
		break;

	case (int)ITEM::MENTAL:
		if (m_mentalCare.price > _pMoney)
			return false;
		break;

	default:
		break;
	}
	return true;
}

