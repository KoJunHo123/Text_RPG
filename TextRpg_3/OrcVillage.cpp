#include "OrcVillage.h"

void OrcVillage::Initialize(Character* _player)
{
	m_allow = GetRandomNum(1, 2);

	m_monster = new Monster[m_allow];
	m_player = _player;

	Monster* monster = static_cast<Monster*>(m_monster);
	for (int i = 0; i < m_allow; ++i)
	{
		monster[i].Initialize("��ũ", 60, 6);
	}

	m_debuff |= BLOODY;

	m_debuffPer = 20;

	m_alliveMonster = m_allow;

	monster->SetReturnMoney(200);
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
	// ���� �̻�
	int ranNum = GetRandomNum(1, 100);
	if ((ranNum <= m_debuffPer) && (BLOODY != (m_player->GetState() & BLOODY)))
	{
		cout << "������ �ɷȽ��ϴ�." << endl;
		m_player->AddState(BLOODY);
	}
}
