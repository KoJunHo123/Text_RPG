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

		cout << "�����" << endl;
		cout << "0. �κ��丮    1. ��� ��    2. ��ũ �ζ�    3. ����� ��    4. ���ư��� : ";
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
