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
		cout << "1. 게임 시작    2. 종료 : ";

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
		cout << "직업을 선택하시오." << endl;
		cout << "1. 전사    2. 마법사    3. 도적 : ";
		cin >> iInput;

		switch (iInput)
		{
		case (int)JOB::FIGHTER:
			m_player = new Player;
			m_player->Initialize("전사", 300, 10);
			return;

		case (int)JOB::MAGITION:
			m_player = new Player;
			m_player->Initialize("마법사", 100, 30);
			return;

		case (int)JOB::THIEF:
			m_player = new Player;
			m_player->Initialize("도적", 200, 20);
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

	cout << "1. 이어하기    2. 처음부터 : ";
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
		cout << "저장하시겠습니까?" << endl;
		cout << "1. 저장    2. 저장하지 않고 종료 : ";
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

// 파일 저장
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
		cout << "파일 열기 실패" << endl;
	}
}

// 파일 불러오기
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
		cout << "파일 열기 실패" << endl;
	}
}

GameManager::~GameManager()
{
	Release();
}

