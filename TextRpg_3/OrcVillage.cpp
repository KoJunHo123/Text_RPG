#include "OrcVillage.h"

void OrcVillage::Initialize(Player* _player)
{
	m_allow = GetRandomNum(1, 2);

	m_monster = new Monster[m_allow];
	m_player = _player;

	for (int i = 0; i < m_allow; ++i)
	{
		m_monster[i].Initialize("오크", 60, 6, 20);
	}

	m_debuff |= BLOODY;

	m_debuffPer = 20;

	m_alliveMonster = m_allow;

	m_monster->SetReturnMoney(200);
}

void OrcVillage::Update()
{

}

void OrcVillage::Release()
{
	Safe_Delete_Arr(m_monster);
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
