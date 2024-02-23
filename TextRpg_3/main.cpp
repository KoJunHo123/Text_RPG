#include "GameManager.h"

#pragma region 메모리 누수 확인
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif
#pragma endregion 메크로

using namespace std;

// 꺄악 변태!
int main()
{
#pragma region 메모리 누수 확인
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#pragma endregion 함수

	GameManager gm;

	gm.Update();


	return 0;
}