#include "GameManager.h"

#pragma region �޸� ���� Ȯ��
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif
#pragma endregion ��ũ��

using namespace std;

// ���� ����!
int main()
{
#pragma region �޸� ���� Ȯ��
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#pragma endregion �Լ�

	GameManager gm;

	gm.Update();


	return 0;
}