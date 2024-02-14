#include "Field.h"

Field::~Field()
{
	Release();
}

void Field::Initialize(Character* _player)
{
	m_player = _player;
}

void Field::Update()
{
	while (true)
	{
		system("cls");
		m_player->ShowInfo();
		int iInput = 0;

		cout << "사냥터" << endl;
		cout << "0. 인벤토리    1. 고블린 숲    2. 오크 부락    3. 오우거 산    4. 돌아가기 : ";
		cin >> iInput;

		switch (iInput)
		{
		case INVENTORY:
			static_cast<Player*>(m_player)->OpenInventory();
			break;

		case (int)FIELD::GOBLIN:
			m_fieldInfo = new GoblinForest;
			m_fieldInfo->Initialize(m_player);
			m_fieldInfo->Update();
			break;

		case (int)FIELD::ORC:
			m_fieldInfo = new OrcVillage;
			m_fieldInfo->Initialize(m_player);
			m_fieldInfo->Update();
			break;

		case (int)FIELD::ORGER:
			m_fieldInfo = new OrgerMountain;
			m_fieldInfo->Initialize(m_player);
			m_fieldInfo->Update();
			break;

		case (int)FIELD::BACK:
			Release();
			return;

		default:
			InErr;
		}


	}
}

void Field::Release()
{
	Safe_Delete(m_fieldInfo);
}
