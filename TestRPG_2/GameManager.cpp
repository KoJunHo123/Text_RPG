#include "GameManager.h"

void GameManager::StratGame()
{
	while (true)
	{
			system("cls");
			cout << "TEXT RPG" << endl;
			cout << "1. ���� ����    2. ���� : ";
			cin >> m_start;
			bool back = false;

			switch (m_start)
			{
			case (int)START::START:
				if (JobChoice())
				{
					break;
				}

				while (!back)
				{
					switch (ActChoice())
					{
					case (int)ACT::HUNT:
						HuntingGround();
						break;
					case (int)ACT::MARKET:
						break;
					case (int)ACT::EXIT:
						back = true;
						break;
					default:
						InErr;
						system("pause");
						break;
					}
				}
				
				break;

			case (int)START::EXIT:
				return;

			default:
				InErr;
				system("pause");
			break;
		}

	}
	

}

bool GameManager::JobChoice()
{
	system("cls");
	cout << "���� ����" << endl;
	cout << "1. ����    2. ������    3. ���� : ";
	cin >> m_jobChoice;
	
	if (1 == m_jobChoice || 2 == m_jobChoice || 3 == m_jobChoice)
	{
		m_player = PlayerInfo(m_jobChoice);
		return false;
	}
	else
	{
		InErr;
		system("pause");
		return true;
	}
}

int GameManager::ActChoice()
{
	system("cls");
	m_player.ShowPlayerInfo();
	cout << "�༱��" << endl;
	cout << "1. �����    2. ����    3.���۸޴��� ���ư��� : ";
	cin >> m_actChoice;

	return m_actChoice;
}

void GameManager::HuntingGround()
{
	bool exit = false;
	while (!exit)
	{
		system("cls");
		cout << "1. ��� ��    2. ��ũ �ζ�    3. ����� ��    4. ���ư��� : ";
		cin >> m_hunting;

		switch (m_hunting)
		{
		case (int)HUNT::GOBLIN:
		case (int)HUNT::ORC:
		case (int)HUNT::ORGER:
		{
			Battle();

		}
		case (int)HUNT::END:
			exit = true;
		break;
		default:
			InErr;
			break;
		}
	}
	
}

void GameManager::Battle()
{
	system("cls");
	srand(time(nullptr));

	m_allocNum = rand() % 3 + 1;

	m_monster = new MonsterInfo[m_allocNum];
	for (int i = 0; i < m_allocNum; ++i)
	{
		m_monster[i] = MonsterInfo(m_hunting);
	}
	bool run = false;

	while (!run)
	{
		system("cls");
		int attack;

		m_player.ShowPlayerInfo();
		for (int i = 0; i < m_allocNum; ++i)
		{
			m_monster[i].ShowMonsterInfo(i);
		}
		
		cout << "1. ����    2. ���� : ";
		cin >> attack;

		switch (attack)
		{
		case 1:
			DamageCalculate();
			run = WinOrLose();
			break;
		case 2:
			run = true;
			break;
		default:
			InErr;
			break;
		}

	}

	delete[] m_monster;
	m_monster = nullptr;
}

void GameManager::DamageCalculate()
{
	cout << "���� ��� : ";
	cin >> m_attack;

	int pDamage = m_player.Get_Damage();

	m_monster[m_attack-1].DamageCalculate(pDamage);

	for (int i = 0; i < m_allocNum; ++i)
	{
		m_player.DamageCalculate(m_monster[i].Get_Damage());
	}
}

bool GameManager::WinOrLose()
{

	if (0 >= m_player.Get_HP())
	{
		cout << "���" << endl;
		m_player.InitHP();
		system("pause");
		return true;
	}
	int deathCount = 0;
	for (int i = 0; i < m_allocNum; ++i)
	{
		if (0 >= m_monster[i].Get_HP())
		{
			++deathCount;
		}
	}
		
	if (m_allocNum == deathCount)
	{
		cout << "�¸�" << endl;
		system("pause");
		m_player.ExpUp(m_hunting * m_allocNum * 10);
		return true;
	}
	return false;
}
