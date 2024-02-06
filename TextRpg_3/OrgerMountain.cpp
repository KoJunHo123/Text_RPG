#include "OrgerMountain.h"

void OrgerMountain::Initialize(Player* _player)
{
	m_allow = GetRandomNum(1, 1);

	m_monster = new Monster[m_allow];
	m_player = _player;

	for (int i = 0; i < m_allow; ++i)
	{
		m_monster[i].Initialize("�����", 90, 9, 30);
	}

	m_debuff |= FEAR;

	m_debuffPer = 20;

	m_alliveMonster = m_allow;

	m_monster->SetReturnMoney(300);

}

void OrgerMountain::Update()
{

}

void OrgerMountain::Release()
{
	Safe_Delete_Arr(m_monster);
}





void OrgerMountain::Debuff()
{
	// ���� �̻�
	int ranNum = GetRandomNum(1, 100);
	if ((ranNum <= m_debuffPer) && (FEAR != (m_player->GetState() & FEAR)))
	{
		cout << "������ �ɷȽ��ϴ�." << endl;
		m_player->AddState(FEAR);
	}
}
