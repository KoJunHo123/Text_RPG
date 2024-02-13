#include "OrgerMountain.h"

void OrgerMountain::Initialize(Character* _player)
{
	m_allow = GetRandomNum(1, 1);

	m_monster = new Monster[m_allow];
	m_player = _player;

	Monster* monster = dynamic_cast<Monster*>(m_monster);
	for (int i = 0; i < m_allow; ++i)
	{
		monster[i].Initialize("�����", 90, 9, 30);
	}

	m_debuff |= FEAR;

	m_debuffPer = 20;

	m_alliveMonster = m_allow;

	monster->SetReturnMoney(300);

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
