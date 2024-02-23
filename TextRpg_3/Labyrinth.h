#pragma once
#include <iostream>
#include "Player.h"
#include "Define.h"

struct maze
{
	int t_route[12][12];

	maze()
		: t_route{}
	{}

	maze(int _num)
		: t_route{}
	{
		// 1¹ø ¹Ì·Î
		switch (_num)
		{
		case 1:
			t_route[0][1] = 1;
			t_route[1][1] = 1;

			t_route[2][1] = 1;

			t_route[3][1] = 1;

			t_route[4][1] = 1;
			t_route[4][8] = 1;
			t_route[4][9] = 1;
			t_route[4][10] = 1;

			t_route[5][1] = 1;
			t_route[5][8] = 1;
			t_route[5][10] = 1;

			t_route[6][1] = 1;
			t_route[6][8] = 1;
			t_route[6][10] = 1;

			t_route[7][1] = 1;
			t_route[7][5] = 1;
			t_route[7][6] = 1;
			t_route[7][7] = 1;
			t_route[7][8] = 1;
			t_route[7][10] = 1;

			t_route[8][1] = 1;
			t_route[8][5] = 1;
			t_route[8][10] = 1;

			t_route[9][1] = 1;
			t_route[9][5] = 1;
			t_route[9][10] = 1;

			t_route[10][1] = 1;
			t_route[10][2] = 1;
			t_route[10][3] = 1;
			t_route[10][4] = 1;
			t_route[10][5] = 1;
			t_route[10][10] = 1;

			t_route[11][10] = 1;
			break;

		case 2:
			t_route[0][1] = 1;

			t_route[1][1] = 1;
			t_route[1][2] = 1;
			t_route[1][3] = 1;
			t_route[1][4] = 1;
			t_route[1][5] = 1;
			
			t_route[2][5] = 1;

			t_route[3][5] = 1;

			t_route[4][5] = 1;

			t_route[5][5] = 1;
			t_route[5][6] = 1;
			t_route[5][7] = 1;
			t_route[5][8] = 1;
			t_route[5][9] = 1;

			t_route[6][9] = 1;
			t_route[7][6] = 1;
			t_route[7][7] = 1;
			t_route[7][8] = 1;
			t_route[7][9] = 1;

			t_route[8][6] = 1;

			t_route[9][6] = 1;

			t_route[10][6] = 1;
			t_route[10][7] = 1;
			t_route[10][8] = 1;
			t_route[10][9] = 1;
			t_route[10][10] = 1;
			t_route[11][10] = 1;
			break;
		case 3:
			t_route[0][1] = 1;

			t_route[1][1] = 1;
			t_route[1][2] = 1;
			t_route[1][3] = 1;
			t_route[1][4] = 1;
			
			t_route[2][4] = 1;
			
			t_route[3][4] = 1;
			
			t_route[4][2] = 1;
			t_route[4][3] = 1;
			t_route[4][4] = 1;
			
			t_route[5][2] = 1;
			
			t_route[6][2] = 1;
			t_route[6][3] = 1;
			t_route[6][4] = 1;
			t_route[6][5] = 1;
			t_route[6][7] = 1;
			t_route[6][8] = 1;
			t_route[6][9] = 1;
			
			t_route[7][5] = 1;
			t_route[7][7] = 1;
			t_route[7][9] = 1;
			
			t_route[8][5] = 1;
			t_route[8][7] = 1;
			t_route[8][9] = 1;
			
			t_route[9][5] = 1;
			t_route[9][7] = 1;
			t_route[9][9] = 1;
			
			t_route[10][5] = 1;
			t_route[10][6] = 1;
			t_route[10][7] = 1;
			t_route[10][9] = 1;
			t_route[10][10] = 1;

			t_route[11][10] = 1;
			break;
		}
		

	}

	~maze()
	{}
};



class Labyrinth
{
private:
	int m_location[2];
	maze m_maze;
	Character* m_player;

public:
	Labyrinth()
		: m_location{ 0, 1 }
		, m_maze(1)
		, m_player(nullptr)
	{
	}

	Labyrinth(int _num)
		: m_location{ 0, 1 }
		, m_maze(_num)
		, m_player(nullptr)
	{
	}

	~Labyrinth()
	{}

public:
	void Initialize(Character* _player);
	void Update();

private:
	void MakeMaze();
	void ShowMaze();
	int CheckMaze(int _first, int _second);
	bool playerMove();
	bool Success();
};

