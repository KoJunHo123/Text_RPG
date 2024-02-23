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
			Start();
			return true;

		case (int)TITLE::EXIT:
			SaveChoice();
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
			m_player = new Player;
			m_player->Initialize("����", 300, 10);
			return;

		case (int)JOB::MAGITION:
			m_player = new Player;
			m_player->Initialize("������", 100, 30);
			return;

		case (int)JOB::THIEF:
			m_player = new Player;
			m_player->Initialize("����", 200, 20);
			return;
		default:
			InErr;
			break;
		}
		
	}
	
}

void GameManager::Start()
{
	system("cls");
	int iLoad = 0;

	cout << "1. �̾��ϱ�    2. ó������ : ";
	cin >> iLoad;

	switch (iLoad)
	{
	case (int)START::CONTINUE:
		LoadFile();
		break;

	case (int)START::BEGIN:
		break;

	default:
		InErr;
		break;
	}
}

void GameManager::SaveChoice()
{
	if (nullptr != m_player)
	{
		system("cls");
		int iInput = 0;
		cout << "�����Ͻðڽ��ϱ�?" << endl;
		cout << "1. ����    2. �������� �ʰ� ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case (int)SAVE::SAVE:
			SaveFile();
			break;

		case (int)SAVE::NOTSAVE:
			break;
		}
	}


}

// ���� ����
void GameManager::SaveFile()
{
	ofstream outFile("Save/SaveData.dat", ios::binary);
	if (outFile.is_open())
	{
		Player* player = static_cast<Player*>(m_player);
		player->SavePlayer(outFile);
		outFile.close();
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}
}

// ���� �ҷ�����
void GameManager::LoadFile()
{
	m_player = new Player;
	
	ifstream inFile("Save/SaveData.dat", ios::binary);
	if (inFile.is_open())
	{
		inFile.close();
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}
}

GameManager::~GameManager()
{
	Release();
}

