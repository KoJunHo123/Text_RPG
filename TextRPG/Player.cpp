#include "Player.h"
#include <iostream>

using namespace std;

void InitPlayer(PlayerChar* _pC, int _jC, int _continueChoice)
{
	_pC->job = _jC;

	switch (_pC->job)
	{
	case FIGHTER:
		switch (_continueChoice)
		{
		case CONTINUE:
			TakePlayerData(_pC);
			break;

		case RESTART:wcsncpy_s(_pC->jobName, L"전사", 8);
			_pC->PlayerDmg = 10;
			_pC->PlayerHP = 300;
			_pC->MaxHp = 300;
			_pC->Exp = 0;
			_pC->MaxExp = 100;
			break;
		}
		break;
	case MAGITION:
		switch (_continueChoice)
		{
		case CONTINUE:
			TakePlayerData(_pC);
			break;

		case RESTART:
			wcsncpy_s(_pC->jobName, L"마법사", 8);
			_pC->PlayerDmg = 30;
			_pC->PlayerHP = 100;
			_pC->MaxHp = 100;
			_pC->Exp = 0;
			_pC->MaxExp = 100;
			break;
		}
		break;
	case THIEF:
		switch (_continueChoice)
		{
		case CONTINUE:
			TakePlayerData(_pC);
			break;

		case RESTART:
			wcsncpy_s(_pC->jobName, L"도적", 8);
			_pC->PlayerDmg = 20;
			_pC->PlayerHP = 200;
			_pC->MaxHp = 200;
			_pC->Exp = 0;
			_pC->MaxExp = 100;
			break;
		}
		break;
	}
}


void ShowPlayer(PlayerChar* _pC)
{
	cout << "직업 : ";
	wcout<< _pC->jobName << endl;
	cout << "체력 : " << _pC->PlayerHP << "/" << _pC->MaxHp << endl;;
	cout << "공격력 : " << _pC->PlayerDmg << endl;
	cout << "경험치: " << _pC->Exp << "/" << _pC->MaxExp << endl;
	cout << "======================================" << endl;

}

void SavePlayerData(PlayerChar* _pC)
{
	FILE* pData = nullptr;
	errno_t err = 0;


	switch (_pC->job)
	{
	case FIGHTER:
		err = fopen_s(&pData, "PlayerData/FPlayerState.txt", "wb");
		break;
	case MAGITION:
		err = fopen_s(&pData, "PlayerData/MPlayerState.txt", "wb");
		break;
	case THIEF:
		err = fopen_s(&pData, "PlayerData/TPlayerState.txt", "wb");
		break;
	}

	if (0 == err)
	{
		fwrite(_pC, sizeof(PlayerChar), 1, pData);
		fclose(pData);
	}
	else
	{
		cout << "파일을 불러오지 못했습니다." << endl;
		return;
	}
	
}

void TakePlayerData(PlayerChar* _pC)
{
	FILE* pData = nullptr;

	errno_t err = 0;

	switch (_pC->job)
	{
	case FIGHTER:
		err = fopen_s(&pData, "PlayerData/FPlayerState.txt", "rb");
		break;
	case MAGITION:
		err = fopen_s(&pData, "PlayerData/MPlayerState.txt", "rb");
		break;
	case THIEF:
		err = fopen_s(&pData, "PlayerData/TPlayerState.txt", "rb");
		break;
	}

	if (0 == err)
	{
		fread(_pC, sizeof(PlayerChar), 1, pData);
		fclose(pData);
	}
	else
	{
		cout << "파일을 찾지 못했습니다." << endl;
		return;
	}
}

void PlayerLevelup(PlayerChar* _pC)
{
	_pC->MaxHp += 100;
	_pC->PlayerDmg += 10;
	_pC->MaxExp += 50;
	_pC->PlayerHP = _pC->MaxHp;
	_pC->Exp = 0;
}
