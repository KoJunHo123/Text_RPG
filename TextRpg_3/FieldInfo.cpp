#include "FieldInfo.h"


FieldInfo::~FieldInfo()
{
	Release();
}


void FieldInfo::Update()
{
	while (true)
	{
		system("cls");
		m_player->ShowInfo();
		ShowMonsterArr();


		int iInput = 0;


		cout << "0. 인벤토리    1. 공격    2. 도주 : ";
		cin >> iInput;

		Player* player = static_cast<Player*>(m_player);

		switch (iInput)
		{
		case INVENTORY:
			player->OpenInventory();
			break;

		case (int)BATTLE::ATTACK:
			Fight();
			break;

		case (int)BATTLE::RUN:
			cout << "도주하였습니다!" << endl;
			for (m_monIter = m_monster.begin(); m_monIter != m_monster.end(); ++m_monIter)
				Safe_Delete(*m_monIter);
			system("pause");
 			return;

		default:
			InErr;
			break;
		}

		if (Decision())
		{
			Release();
			return;
		}

	}
}

void FieldInfo::Release()
{
	// Safe_Delete_Arr(m_monster);
}

void FieldInfo::ShowMonsterArr()
{
	int i(0);
	for (m_monIter = m_monster.begin(); m_monIter != m_monster.end(); ++m_monIter, ++i)
	{
		dynamic_cast<Monster*>(*m_monIter)->ShowInfo(i);
	}
}

void FieldInfo::Fight()
{
	system("cls");
	m_player->ShowInfo();
	ShowMonsterArr();

	int iAttack(0);
	cout << "공격 대상: ";
	cin >> iAttack;

	--iAttack;	// 배열의 index 계산을 위해 하나 빼줌.


	DamageCalculate(iAttack);
}

void FieldInfo::DamageCalculate(int _iAttack)
{
	// 입력한 값이 몬스터를 대상으로 했으며, 해당 대상의 체력이 존재할 경우.
	if (0 <= _iAttack && m_monster.size() > _iAttack)
	{
		Player* player = static_cast<Player*>(m_player);
		m_monIter = m_monster.begin() + _iAttack;
		Monster* monster = static_cast<Monster*>(*m_monIter);
		//m_player->HpCalculate(monster->GetDamage() * m_monster.size());
		for_each(m_monster.begin(), m_monster.end(), *player);
		cout << "플레이어가 " << monster->GetDamage() * m_monster.size() << "의 데미지를 받았습니다." << endl;
		Debuff();
		if (player->DebuffEffect())	// 공포 등의 디버프 판정 -> false나오면 실패
		{
			monster->HpCalculate(m_player->GetDamage());
			cout << "플레이어가 " << m_player->GetDamage() << "의 데미지를 주었습니다." << endl;
		}
		system("pause");
	}
	else
	{
		InErr;
		return;
	}

}


// 승리, 사망 판단
bool FieldInfo::Decision()
{
	Player* player = static_cast<Player*>(m_player);
	for (m_monIter = m_monster.begin(); m_monIter != m_monster.end();)
	{
		Monster* monster = dynamic_cast<Monster*>(*m_monIter);
		if ((*m_monIter)->GetHp() <= 0)
		{
			player->CalculateExp(monster->GetReturnExp());
			player->AddMoney(monster->GetReturnMoney());
			cout << monster->GetReturnMoney() << " Gold를 획득했습니다." << endl;
			Safe_Delete(*m_monIter);
			m_monIter = m_monster.erase(m_monIter);
			system("pause");
		}
		else
		{
			++m_monIter;
		}
	}

	if (0 >= m_player->GetHp())
	{
		cout << "ㅠㅠㅠㅠ사망ㅠㅠㅠㅠ" << endl;
		m_player->InitHp();
		Release();
		system("pause");
		return true;
	}
	else if (m_monster.begin() == m_monster.end())
	{
		cout << "!!!!승리!!!!" << endl;
		Release();
		system("pause");
		return true;
	}

	return false;
}
