#include "Shop_2.h"

void Shop_2::Initialize(Character* _player)
{
	m_player = _player;

	// �ʱ� ����
	m_item[0][0].itemType = 0;
	strcpy_s(m_item[0][0].name, "�ʱ޹���");
	m_item[0][0].damage = 10;
	m_item[0][0].price = 100;

	// �ʱ� ����
	m_item[0][1].itemType = 1;
	strcpy_s(m_item[0][1].name, "�ʱް���");
	m_item[0][1].hp = 100;
	m_item[0][1].price = 100;

	// �߱� ����
	m_item[1][0].itemType = 0;
	strcpy_s(m_item[1][0].name, "�߱޹���");
	m_item[1][0].damage = 20;
	m_item[1][0].price = 200;

	// �߱� ����
	m_item[1][1].itemType = 1;
	strcpy_s(m_item[1][1].name, "�߱ް���");
	m_item[1][1].hp = 200;
	m_item[1][1].price = 200;

	// ��� ����
	m_item[2][0].itemType = 0;
	strcpy_s(m_item[2][0].name, "��޹���");
	m_item[2][0].damage = 30;
	m_item[2][0].price = 300;

	// ��� ����
	m_item[2][1].itemType = 1;
	strcpy_s(m_item[2][1].name, "��ް���");
	m_item[2][1].hp = 300;
	m_item[2][1].price = 300;

}

void Shop_2::Update()
{
	while (true)
	{
		system("cls");
		int num(0);
		int RankNum(0);
		int ItemChoice(0);
		cout << "1. ������ ����    2. ������ �Ǹ�    3. ���ư��� : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "1. �ʱ�    2. �߱�    3. ��� : ";
			cin >> RankNum;
			switch (RankNum)
			{
			case 1:
				cout << "1. �ʱ� ����    2. �ʱ� ���� : ";
				cin >> ItemChoice;
				switch (ItemChoice)
				{
				case 1:
					static_cast<Player*>(m_player)->BuyItem(m_item[0][0]);
					break;

				case 2:
					static_cast<Player*>(m_player)->BuyItem(m_item[0][1]);
					break;
				}
				break;

			case 2:
				cout << "1. �߱� ����    2. �߱� ���� : ";
				cin >> ItemChoice;
				switch (ItemChoice)
				{
				case 1:
					static_cast<Player*>(m_player)->BuyItem(m_item[1][0]);
					break;

				case 2:
					static_cast<Player*>(m_player)->BuyItem(m_item[1][1]);
					break;
				}
				break;

			case 3:
				cout << "1. ��� ����    2. ��� ���� : ";
				cin >> ItemChoice;
				switch (ItemChoice)
				{
				case 1:
					static_cast<Player*>(m_player)->BuyItem(m_item[2][0]);
					break;

				case 2:
					static_cast<Player*>(m_player)->BuyItem(m_item[2][1]);
					break;
				}
				break;
			}
			break;

		case 2:
			static_cast<Player*>(m_player)->SellItem();
			break;

		case 3:
			return;
		}
	}
	
}
