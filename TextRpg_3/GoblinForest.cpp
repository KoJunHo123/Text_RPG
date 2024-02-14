#include "GoblinForest.h"


void GoblinForest::Initialize(Character* _player)
{
	
	m_allow = GetRandomNum(1, 3);

	m_monster = new Monster[m_allow];
	m_player = _player;


	Monster* monster = static_cast<Monster*>(m_monster);
	for (int i = 0; i < m_allow; ++i)
	{
		monster[i].Initialize("���", 30, 3);	// monster�� character ����ŭ �ּҿ��� �Ϸ� �ϸ� ����
	}

	m_debuff |= POISON;
	m_debuffPer = 30;

	m_alliveMonster = m_allow;


	monster->SetReturnMoney(100);
}

void GoblinForest::Update()
{

}

void GoblinForest::Release()
{
	Safe_Delete_Arr(m_monster);
}





void GoblinForest::Debuff()
{
	// ���� �̻�
	int ranNum = GetRandomNum(1, 100);
	if ((ranNum <= m_debuffPer) && (POISON != (m_player->GetState() & POISON)))
	{
		cout << "���� �ߵ��Ǿ����ϴ�." << endl;
		m_player->AddState(POISON);
	}
}
