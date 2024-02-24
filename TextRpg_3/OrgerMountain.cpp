#include "OrgerMountain.h"

void OrgerMountain::Initialize(Character* _player)
{
	m_allow = GetRandomNum(1, 3);

	m_player = _player;


	for (int i = 0; i < m_allow; ++i)
	{
		m_monster.push_back(new Monster);
		dynamic_cast<Monster*>(m_monster[i])->Initialize("오우거", 90, 9);
		dynamic_cast<Monster*>(m_monster[i])->SetReturnMoney(300);
	}

	m_monIter = m_monster.begin();

	m_debuff |= POISON;
	m_debuffPer = 30;

}

void OrgerMountain::Update()
{

}

void OrgerMountain::Release()
{

}





void OrgerMountain::Debuff()
{
	// 상태 이상
	int ranNum = GetRandomNum(1, 100);
	if ((ranNum <= m_debuffPer) && (FEAR != (m_player->GetState() & FEAR)))
	{
		cout << "공포에 걸렸습니다." << endl;
		m_player->AddState(FEAR);
	}
}
