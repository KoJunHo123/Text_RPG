#include "Shop.h"

// ���� ������� ���� ���� ǰ�� �ҷ�����.

void Shop::Initialize(Character* _player)
{
	m_player = _player;
}

void Shop::Update()
{
	while (true)
	{
		system("cls");
		cout << "������ ���" << endl;
		int iInput = 0;
		cout << "1. �Һ� ������    2. ��� ������    3. ���ư��� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			SellConsumable();
			break;

		case 2:
			SellEquipment();
			break;

		case 3:
			return;

		default:
			InErr;
			break;
		}
	}
	
	return;
}

void Shop::SellConsumable()
{
	system("cls");
	cout << "=====================" << endl;
	cout << "�Һ� ������" << endl;
	cout << "=====================" << endl;
	m_item.ShowConsumableItemPrice();

	int iInput = 0;
	cout << "1. ���� ����    2. �ص���    3. �ش�    4. û��ȯ    5. ���ư��� : ";
	cin >> iInput;

	Player* player = static_cast<Player*>(m_player);

	int itemPrice = m_item.GetPrice(1, iInput, 0);

	switch (iInput)
	{
	case (int)CONSUMABLE::REDP:
	case (int)CONSUMABLE::ANTI:
	case (int)CONSUMABLE::BAND:
	case (int)CONSUMABLE::MENTAL:
		if (player->GetMoney() >= itemPrice)
		{
			player->UseMoney(itemPrice);
			player->AddItem(iInput);
		}
		else
		{
			cout << "�������� �����մϴ�" << endl;
			system("pause");
		}
		break;
	case (int)CONSUMABLE::RETURN:
		return;
	default:
		InErr;
		break;
	}
}

void Shop::SellEquipment()
{
	system("cls");
	int iInput = 0;
	cout << "1. �ʱ� ���    2. �߱� ���    3. ��� ���    4. ���ư��� : ";
	cin >> iInput;
	
	if (4 == iInput)
		return;

	// ���⼭���� �ݺ���
	while (true)
	{
		system("cls");
		m_item.ShowEquipmentItemPrice(iInput);

		int purchase;
		cout << endl << "1. ���� ����    2. ���� ����    3. ���ư��� : ";
		cin >> purchase;
		
		Player* player = static_cast<Player*>(m_player);

		int itemPrice = m_item.GetPrice(2, iInput, purchase);

		switch (purchase)
		{
		case (int)EQUIP::WEAPON:
		case (int)EQUIP::ARMOR:
			if (player->GetMoney() >= itemPrice)
			{
				player->UseMoney(itemPrice);
				player->AddEquipItem(iInput, purchase);
			}
			else
			{
				cout << "�������� �����մϴ�" << endl;
				system("pause");
			}
			break;

		case (int)EQUIP::BACK:
			return;

		default:
			InErr;
			break;
		}
	}
	
}
