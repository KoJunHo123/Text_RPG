#include "Shop.h"

// ���� ������� ���� ���� ǰ�� �ҷ�����.

void Shop::Initialize(Player* _player)
{
	m_player = _player;
}

void Shop::Update()
{
	m_player->OpenShop();
	
	
}
