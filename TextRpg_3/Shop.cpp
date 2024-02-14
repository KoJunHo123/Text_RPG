#include "Shop.h"

// 파일 입출력을 통한 상점 품목 불러오기.

void Shop::Initialize(Character* _player)
{
	m_player = _player;
}

void Shop::Update()
{
	while (true)
	{
		system("cls");
		cout << "아이템 목록" << endl;
		int iInput = 0;
		cout << "1. 소비 아이템    2. 장비 아이템    3. 돌아가기 : ";
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
	cout << "소비 아이템" << endl;
	cout << "=====================" << endl;
	m_item.ShowConsumableItemPrice();

	int iInput = 0;
	cout << "1. 빨간 포션    2. 해독제    3. 붕대    4. 청심환    5. 돌아가기 : ";
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
			cout << "소지금이 부족합니다" << endl;
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
	cout << "1. 초급 장비    2. 중급 장비    3. 고급 장비    4. 돌아가기 : ";
	cin >> iInput;
	
	if (4 == iInput)
		return;

	// 여기서부터 반복문
	while (true)
	{
		system("cls");
		m_item.ShowEquipmentItemPrice(iInput);

		int purchase;
		cout << endl << "1. 무기 구매    2. 갑옷 구매    3. 돌아가기 : ";
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
				cout << "소지금이 부족합니다" << endl;
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
