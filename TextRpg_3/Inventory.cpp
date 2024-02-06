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
			cout << "소지한 아이템이 없습니다." << endl;
			return -1;
		}
		break;

	case (int)ITEM::ANTI:
		if (0 < m_antiPoison.count)
			--m_antiPoison.count;
		else
		{
			cout << "소지한 아이템이 없습니다." << endl;
			return -1;
		}
		break;

	case (int)ITEM::BAND:
		if (0 < m_bandage.count)
			--m_bandage.count;
		else
		{
			cout << "소지한 아이템이 없습니다." << endl;
			return -1;
		}
		break;

	case (int)ITEM::MENTAL:
		if (0 < m_mentalCare.count)
			--m_mentalCare.count;
		else
		{
			cout << "소지한 아이템이 없습니다." << endl;
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
		cout << "붉은 포션 구매" << endl;
		++m_redPotion.count;
		m_money -= m_redPotion.price;
		break;

	case (int)ITEM::ANTI:
		cout << "해독제 구매" << endl;
		++m_antiPoison.count;
		m_money -= m_antiPoison.price;
		break;

	case (int)ITEM::BAND:
		cout << "붕대 구매" << endl;
		++m_bandage.count;
		m_money -= m_bandage.price;
		break;

	case (int)ITEM::MENTAL:
		cout << "청심환 구매" << endl;
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
	cout << "인벤토리" << endl;
	cout << "붉은 포션	: " << m_redPotion.count << endl;
	cout << "해독제		: " << m_antiPoison.count << endl;
	cout << "붕대		: " << m_bandage.count <<endl;
	cout << "청심환		: " << m_mentalCare.count << endl;
	cout << "소지금액	: " << m_money << endl;
}

void Inventory::ShowShopItem()const
{
	cout << "상점" << endl;
	cout << "붉은 포션	: " << m_redPotion.price << " Gold" << endl;
	cout << "해독제		: " << m_antiPoison.price << " Gold" << endl;
	cout << "붕대		: " << m_bandage.price << " Gold" << endl;
	cout << "청심환		: " << m_mentalCare.price << " Gold" << endl;
	cout << "소지금액	: " << m_money << " Gold" << endl;

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

