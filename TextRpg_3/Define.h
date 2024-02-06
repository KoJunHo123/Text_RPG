#pragma once

#ifndef 전처리기

#define InErr	{ cout << "잘못된 입력입니다." << endl; system("pause"); }
#define Safe_Delete(p)	if(p) {delete p; p = nullptr;}
#define Safe_Delete_Arr(p)	if(p) {delete[] p; p = nullptr;}

#define POISON		0x001
#define BLOODY		0x002
#define FEAR		0x004

#define INVENTORY	0


#endif // !InErr

// 랜덤한 숫자 가져오기
extern int GetRandomNum(int _first, int _second);