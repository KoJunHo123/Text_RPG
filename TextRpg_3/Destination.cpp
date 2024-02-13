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

		cout << "�༱��" << endl;
		cout << "0. �κ��丮    1. �����    2. ����    3. Ÿ��Ʋ�� ���ư��� : ";
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
			m_iInput = iInput;	// ���߿� Release �뵵
			break;

		case (int)DEST::SHOP:
			// cout << "���� ���𵨸� ��" << endl;
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
