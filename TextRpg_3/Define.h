#pragma once

#ifndef ��ó����

#define InErr	{ cout << "�߸��� �Է��Դϴ�." << endl; system("pause"); }
#define Safe_Delete(p)	if(p) {delete p; p = nullptr;}
#define Safe_Delete_Arr(p)	if(p) {delete[] p; p = nullptr;}

#define POISON		0x001
#define BLOODY		0x002
#define FEAR		0x004

#define INVENTORY	0


#endif // !InErr

// ������ ���� ��������
extern int GetRandomNum(int _first, int _second);