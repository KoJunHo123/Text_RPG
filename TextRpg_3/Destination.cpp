#include "Destination.h"

Destination::~Destination()
{
	Release();
}

void Destination::Initialize(Character* _player)
{
	m_player = _player;
}

void Destination::Update()
{
	while (true)
	{
		int iInput;
		system("cls");

		m_player->ShowInfo();

		cout << "행선지" << endl;
		cout << "0. 인벤토리    1. 사냥터    2. 상점    3. 타이틀로 돌아가기 : ";
		cin >> iInput;

		Player* player = dynamic_cast<Player*>(m_player);

		switch (iInput)
		{
		case INVENTORY:
			player->OpenInventory();
			break;

		case (int)DEST::FIELD:
			m_field = new Field;
			m_field->Initialize(m_player);
			m_field->Update();
			m_iInput = iInput;	// 나중에 Release 용도
			break;

		case (int)DEST::SHOP:
			// cout << "상점 리모델링 중" << endl;
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
