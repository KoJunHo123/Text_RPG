#include "Shop_2.h"

void Shop_2::Initialize(Character* _player)
{
	m_player = _player;

	// 초급 무기
	m_item[0][0].itemType = 0;
	strcpy_s(m_item[0][0].name, "초급무기");
	m_item[0][0].damage = 10;
	m_item[0][0].price = 100;

	// 초급 갑빠
	m_item[0][1].itemType = 1;
	strcpy_s(m_item[0][1].name, "초급갑빠");
	m_item[0][1].hp = 100;
	m_item[0][1].price = 100;

	// 중급 무기
	m_item[1][0].itemType = 0;
	strcpy_s(m_item[1][0].name, "중급무기");
	m_item[1][0].damage = 20;
	m_item[1][0].price = 200;

	// 중급 갑빠
	m_item[1][1].itemType = 1;
	strcpy_s(m_item[1][1].name, "중급갑빠");
	m_item[1][1].hp = 200;
	m_item[1][1].price = 200;

	// 고급 무기
	m_item[2][0].itemType = 0;
	strcpy_s(m_item[2][0].name, "고급무기");
	m_item[2][0].damage = 30;
	m_item[2][0].price = 300;

	// 고급 갑빠
	m_item[2][1].itemType = 1;
	strcpy_s(m_item[2][1].name, "고급갑빠");
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
		cout << "1. 아이템 구매    2. 아이템 판매    3. 돌아가기 : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "1. 초급    2. 중급    3. 고급 : ";
			cin >> RankNum;
			switch (RankNum)
			{
			case 1:
				cout << "1. 초급 무기    2. 초급 갑빠 : ";
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
				cout << "1. 중급 무기    2. 중급 갑빠 : ";
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
				cout << "1. 고급 무기    2. 고급 갑빠 : ";
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
