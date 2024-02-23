#include "Destination.h"

Destination::~Destination()
{
	Release(m_field);
	Release(m_shop);
	Release(m_labyrinth);
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
		cout << "0. �κ��丮    1. �����    2. ����    3. �̱�    4. Ÿ��Ʋ�� ���ư��� : ";
		cin >> iInput;

		switch (iInput)
		{
		case INVENTORY:
			static_cast<Player*>(m_player)->OpenInventory();
			//static_cast<Player*>(m_player)->SetItem();
			break;

		case (int)DEST::FIELD:
			m_field = new Field;
			m_field->Initialize(m_player);
			m_field->Update();
			Release(m_field);
			break;

		case (int)DEST::SHOP:
			// cout << "���� ���𵨸� ��" << endl;
			m_shop = new Shop;
			m_shop->Initialize(m_player);
			m_shop->Update();
			Release(m_shop);
			/*m_shop_2 = new Shop_2;
			m_shop_2->Initialize(m_player);
			m_shop_2->Update();*/
			break;

		case (int)DEST::LABYRINTH:
			m_labyrinth = new Labyrinth(GetRandomNum(1, 3));
			m_labyrinth->Initialize(m_player);
			m_labyrinth->Update();
			Release(m_labyrinth);
			break;

		case (int)DEST::BACK:
			return;

		default:
			InErr;
		}
	}
}

template<typename T>
void Destination::Release(T& _release)
{
	Safe_Delete(_release);
	// Safe_Delete(m_shop_2);
}
