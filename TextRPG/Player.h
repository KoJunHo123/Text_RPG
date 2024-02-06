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
	wchar_t jobName[8];	// �ּҰ� �ٲ����� �ȵ�. ���� ���� �ٲ��� ��.
	int Exp;
	int MaxExp;
	int Level;
};

// �÷��̾� �ʱ�ȭ
void InitPlayer(PlayerChar* _pC, int _jC, int _continueChoice);
// �÷��̾� ���� ����
void ShowPlayer(PlayerChar* _pC);
// �÷��̾� ���� ����
void SavePlayerData(PlayerChar* _pC);
// �÷��̾� ���� ��������
void TakePlayerData(PlayerChar* _pC);
// �÷��̾� ������
void PlayerLevelup(PlayerChar* _pC);