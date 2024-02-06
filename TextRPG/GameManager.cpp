#include <iostream>

#include "GameManager.h"

using namespace std;

void JobChoice(PlayerChar* _pC)
{
	system("cls");
	int jChoice = 0;
	cout << "���� ����" << endl;
	cout << "1. ����    2.������    3.����" << endl;
	cin >> jChoice;

	system("cls");
	int contChoice = 0;
	cout << "1. �̾��ϱ�		2. ó������" << endl;
	cin >> contChoice;
	

	InitPlayer(_pC, jChoice, contChoice);
}

// ����� / ������
int ActChoice(PlayerChar* _pC)
{
	system("cls");
	ShowPlayer(_pC);
	int choice = 0;
	cout << "1. �����    2. ����" << endl;
	cin >> choice;

	return choice;
}

void RankChoice(PlayerChar* _pC)
{
	while (true)
	{
		system("cls");
		ShowPlayer(_pC);
		int choice = 0;
		cout << "1. �ʱ�    2. �߱�    3. ���    4. �� �ܰ�" << endl;
		cin >> choice;


		// ���� ���� �Ҵ�
		MonsterChar* mc = nullptr;
		AllocateMonster(&mc, choice);

		switch (choice)
		{
		case EASY:
		case NORMAL:
		case HARD:
			Battle(_pC, mc);
			break;
		case BACK:
			return;
		}
	}
}

void Battle(PlayerChar* _pC, MonsterChar* _mC)
{
	bool back = false;
	while (!back)
	{
		system("cls");
		ShowPlayer(_pC);
		ShowMonster(_mC);

		int battle = 0;
		int att_num = 0;
		int deathMonster = 0;

		for (int i = 0; i < _mC->monsterCount; ++i)
		{
			if ((_mC + i)->MonsterHP <= 0)
			{
				++deathMonster;
			}
		}

		cout << "1. ����    2. ����" << endl;
		cin >> battle;

		switch (battle)
		{
		case ATTACK:
			cout << "��� ����" << endl;
			cin >> att_num;
			_pC->PlayerHP -= (_mC->MonsterDmg) * (_mC->monsterCount - deathMonster);
			(_mC + (att_num - 1))->MonsterHP -= _pC->PlayerDmg;
			KillDeath(_pC, _mC, &back, deathMonster);
			break;
		case RUN:
			//ReleaseMonster(_mC);
			return;
		}
	}
}


void KillDeath(PlayerChar* _pC, MonsterChar* _mC, bool* _back, int _deathMonster)
{
	int deathCount = 0;

	for (int i = 0; i < _mC->monsterCount; ++i)
	{
		if ((_mC + i)->MonsterHP <= 0)
		{
			++deathCount;
		}
	}
	
	if (_deathMonster != deathCount)
	{
		switch (_mC->MonsterRank)
		{
		case EASY:
			_pC->Exp += 10;
			break;
		case NORMAL:
			_pC->Exp += 20;
			break;
		case HARD:
			_pC->Exp += 30;
			break;
		}
		if (_pC->Exp >= _pC->MaxExp)
		{
			PlayerLevelup(_pC);
		}
	}


	if (_pC->PlayerHP <= 0)
	{
		cout << "���" << endl;
		_pC->PlayerHP = _pC->MaxHp;
		*_back = true;
		ReleaseMonster(_mC);
		system("pause");
		return;
	}
	else if (deathCount == _mC->monsterCount)
	{
		cout << "�¸�" << endl;
		*_back = true;
		ReleaseMonster(_mC);
		system("pause");
		return;
	}
}

