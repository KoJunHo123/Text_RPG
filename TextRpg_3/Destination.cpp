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

		cout << "행선지" << endl;
		cout << "0. 인벤토리    1. 사냥터    2. 상점    3. 미궁    4. 타이틀로 돌아가기 : ";
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
			// cout << "상점 리모델링 중" << endl;
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
