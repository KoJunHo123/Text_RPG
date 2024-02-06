#pragma once
enum PLAYER
{
	FIGHTER = 1,
	MAGITION,
	THIEF
};

enum CONTINUE
{
	CONTINUE = 1,
	RESTART
};

struct PlayerChar
{
	int job;
	int PlayerHP;
	int MaxHp;
	int PlayerDmg;
	wchar_t jobName[8];	// 주소가 바껴서는 안됨. 내부 값만 바껴야 함.
	int Exp;
	int MaxExp;
	int Level;
};

// 플레이어 초기화
void InitPlayer(PlayerChar* _pC, int _jC, int _continueChoice);
// 플레이어 상태 보기
void ShowPlayer(PlayerChar* _pC);
// 플레이어 정보 저장
void SavePlayerData(PlayerChar* _pC);
// 플레이어 정보 가져오기
void TakePlayerData(PlayerChar* _pC);
// 플레이어 레벨업
void PlayerLevelup(PlayerChar* _pC);