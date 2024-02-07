#include "Shop.h"

// 파일 입출력을 통한 상점 품목 불러오기.

void Shop::Initialize(Player* _player)
{
	m_player = _player;
}

void Shop::Update()
{
	m_player->OpenShop();
	
	
}
