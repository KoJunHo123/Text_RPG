#include "Shop.h"

// ���� ������� ���� ���� ǰ�� �ҷ�����.

void Shop::Initialize(Character* _player)
{
	m_player = _player;
}

void Shop::Update()
{
	Player* player = dynamic_cast<Player*>(m_player);
	player->OpenShop();
	
	
}
