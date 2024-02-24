#include "GoblinForest.h"


void GoblinForest::Initialize(Character* _player)
{
	
	m_allow = GetRandomNum(1, 3);

	m_player = _player;


	for (int i = 0; i < m_allow; ++i)
	{
		m_monster.push_back(new Monster);
		dynamic_cast<Monster*>(m_monster[i])->Initialize("고블린", 30, 3);
		dynamic_cast<Monster*>(m_monster[i])->SetReturnMoney(100);
	}

	m_monIter = m_monster.begin();

	m_debuff |= POISON;
	m_debuffPer = 30;

}

void GoblinForest::Update()
{

}

void GoblinForest::Release()
{
}





void GoblinForest::Debuff()
{
	// 상태 이상
	int ranNum = GetRandomNum(1, 100);
	if ((ranNum <= m_debuffPer) && (POISON != (m_player->GetState() & POISON)))
	{
		cout << "독에 중독되었습니다." << endl;
		m_player->AddState(POISON);
	}
}
