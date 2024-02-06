#include "Destination.h"

Destination::~Destination()
{
	Release();
}

void Destination::Initialize(Player* _player)
{
	m_player = _player;
}

void Destination::Update()
{
	while (true)
	{
		int iInput;
		system("cls");

		m_player->ShowPlayer();

		cout << "행선지" << endl;
		cout << "0. 인벤토리    1. 사냥터    2. 상점    3. 타이틀로 돌아가기 : ";
		cin >> iInput;


		switch (iInput)
		{
		case INVENTORY:
			m_player->OpenInventory();
			break;

		case (int)DEST::FIELD:
			m_field = new Field;
			m_field->Initialize(m_player);
			m_field->Update();
			m_iInput = iInput;
			break;

		case (int)DEST::SHOP:
			m_shop = new Shop;
			m_shop->Initialize(m_player);
			m_shop->Update();
			m_iInput = iInput;
			break;

		case (int)DEST::BACK:
			return;

		default:
			InErr;
		}
	}
}

void Destination::Release()
{
	switch (m_iInput)
	{
	case (int)DEST::FIELD:
		Safe_Delete(m_field);
		break;

	case (int)DEST::SHOP:
		Safe_Delete(m_shop);
		break;

	default:
		break;
	}
}
