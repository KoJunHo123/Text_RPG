#include "OrcVillage.h"

void OrcVillage::Initialize(Character* _player)
{
	m_allow = GetRandomNum(1, 3);

	m_player = _player;


	for (int i = 0; i < m_allow; ++i)
	{
		m_monster.push_back(new Monster);
		dynamic_cast<Monster*>(m_monster[i])->Initialize("오크", 60, 6);
		dynamic_cast<Monster*>(m_monster[i])->SetReturnMoney(200);
	}

	m_monIter = m_monster.begin();

	m_debuff |= POISON;
	m_debuffPer = 30;

}

void OrcVillage::Update()
{

}

void OrcVillage::Release()
{

}





void OrcVillage::Debuff()
{
	// 상태 이상
	int ranNum = GetRandomNum(1, 100);
	if ((ranNum <= m_debuffPer) && (BLOODY != (m_player->GetState() & BLOODY)))
	{
		cout << "출혈에 걸렸습니다." << endl;
		m_player->AddState(BLOODY);
	}
}
