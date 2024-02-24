#include "Labyrinth.h"

void Labyrinth::Initialize(Character* _player)
{
	m_player = _player;
}

void Labyrinth::Update()
{
	MakeMaze();
	MakeMaze();
	ShowMaze();
	bool escape = true;
	bool playerEscape = true;
	while (escape && playerEscape)
	{
		playerEscape = playerMove();
		ShowMaze();

		escape = Success();
	}
}

void Labyrinth::MakeMaze()
{
	for (int i = 1; i < 11; ++i)
	{
		for (int j = 1; j < 11; ++j)
		{
			int num(0);
			num = CheckMaze(i, j);

			if (!m_maze.t_route[i][j]) // 0�� ���¿���
			{
				if (1 == CheckMaze(i, j) && 8 > GetRandomNum(1, 10))
				{
					m_maze.t_route[i][j] = 1;
				}
			}
		}
	}
}

void Labyrinth::ShowMaze()
{
	system("cls");
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (i == m_location[0] && j == m_location[1])
			{
				cout << '@' << " ";
				continue;
			}

			if (1 == m_maze.t_route[i][j])
				cout << ' ' << " ";
			else
				cout << '*' << " ";
		}
		cout << endl;
	}
}

int Labyrinth::CheckMaze(int _first, int _second)
{
	// �� 1�� ����
	int oneCount = 0;
	if (_first != 1 && m_maze.t_route[_first - 1][_second])
	{
		++oneCount;
	}
	if (_first != 10 && m_maze.t_route[_first + 1][_second])
	{
		++oneCount;
	}
	if (_second != 1 && m_maze.t_route[_first][_second - 1])
	{
		++oneCount;
	}
	if (_second != 10 && m_maze.t_route[_first][_second + 1])
	{
		++oneCount;
	}
	return oneCount;
}

bool Labyrinth::playerMove()
{
	int playerMove;

	cout << "2. �Ʒ�    4. ����    6. ������    8. ��    5. Ż�� : ";

	cin >> playerMove;
	switch (playerMove)
	{
	case 2:
		if (0 == m_maze.t_route[m_location[0] + 1][m_location[1]])
			break;
		++m_location[0];
		break;
	case 4:
		if (0 == m_maze.t_route[m_location[0]][m_location[1] - 1])
			break;
		--m_location[1];
		break;
	case 5:
		return false;
	case 6:
		if (0 == m_maze.t_route[m_location[0]][m_location[1] + 1])
			break;
		++m_location[1];
		break;
	case 8:
		if (0 == m_maze.t_route[m_location[0] - 1][m_location[1]])
			break;
		--m_location[0];
		break;
	}
	return true;
}


bool Labyrinth::Success()
{
	if (11 == m_location[0] && 10 == m_location[1])
	{
		cout << "Ż��!" << endl;
		cout << "1000�� ȹ��" << endl;
		static_cast<Player*>(m_player)->AddMoney(1000);
		system("pause");
		return false;
	}
	return true;
}
