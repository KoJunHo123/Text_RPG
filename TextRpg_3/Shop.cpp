#include "Shop.h"

void Shop::Initialize(Player* _player)
{
	m_player = _player;
}

void Shop::Update()
{
	m_player->OpenShop();
	
	
}
