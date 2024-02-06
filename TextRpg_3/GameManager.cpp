#include "GameManager.h"

void GameManager::Initialize()
{
	
}

void GameManager::Update()
{
	while (Title())
	{
		if (nullptr == m_player)
		{
			JobChoice();
		}
		
		m_destination.Initialize(m_player);
		m_destination.Update();

	}
}

void GameManager::Release()
{
	Safe_Delete(m_player);
}

bool GameManager::Title()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		cout << "TEXT RPG" << endl;
		cout << "1. ���� ����    2. ���� : ";

		cin >> iInput;
		switch (iInput)
		{
		case (int)TITLE::START:
			return true;

		case (int)TITLE::EXIT:
			return false;

		default:
			InErr;
			break;
		}
	}
	
}

void GameManager::JobChoice()
{
	while (true)
	{
		system("cls");
		int iInput = 0;
		cout << "������ �����Ͻÿ�." << endl;
		cout << "1. ����    2. ������    3. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case (int)JOB::FIGHTER:
			m_player = new Player("����", 300, 10);
			return;

		case (int)JOB::MAGITION:
			m_player = new Player("������", 100, 30);
			return;

		case (int)JOB::THIEF:
			m_player = new Player("����", 200, 20);
			return;
		default:
			InErr;
			break;
		}
		
	}
	
}




GameManager::~GameManager()
{
	Release();
}

