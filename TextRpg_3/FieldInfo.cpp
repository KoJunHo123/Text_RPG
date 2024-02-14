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
			Release();
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
	Safe_Delete_Arr(m_monster);
}

void FieldInfo::ShowMonsterArr()
{
	Monster* monster = dynamic_cast<Monster*>(m_monster);
	for (int i = 0; i < m_allow; ++i)
	{
		monster[i].ShowInfo(i);
	}
}

void FieldInfo::Fight()
{
	system("cls");
	m_player->ShowInfo();
	ShowMonsterArr();

	int iAttack = 0;
	cout << "공격 대상: ";
	cin >> iAttack;

	--iAttack;	// 배열의 index 계산을 위해 하나 빼줌.

	// 입력한 값이 몬스터를 대상으로 했으며, 해당 대상의 체력이 존재할 경우.
	DamageCalculate(iAttack);
}

void FieldInfo::DamageCalculate(int _iAttack)
{
	Player* player = static_cast<Player*>(m_player);
	Monster* monster = static_cast<Monster*>(m_monster);
	// 입력한 값이 몬스터를 대상으로 했으며, 해당 대상의 체력이 존재할 경우.
	if (0 <= _iAttack && m_allow > _iAttack && monster[_iAttack].GetHp() > 0)
	{
		m_player->HpCalculate(monster[_iAttack].GetDamage() * m_alliveMonster);
		cout << "플레이어가 " << monster[_iAttack].GetDamage() * m_alliveMonster << "의 데미지를 받았습니다." << endl;
		Debuff();
		if (player->DebuffEffect())	// 공포 등의 디버프 판정 -> false나오면 실패
		{
			monster[_iAttack].HpCalculate(m_player->GetDamage());
			cout << "플레이어가 " << m_player->GetDamage() << "의 데미지를 주었습니다." << endl;
		}
		
		system("pause");
	}
	else
	{
		InErr;
	}

}


// 승리, 사망 판단
bool FieldInfo::Decision()
{
	// 기존 생존한 몬스터 수 저장
	int save = m_alliveMonster;
	m_alliveMonster = m_allow;

	Monster* monster = static_cast<Monster*>(m_monster);
	// 전체 할당 몬스터에서 현재 죽은 몬스터만큼 제외
	for (int i = 0; i < m_allow; ++i)
	{
		if (0 >= monster[i].GetHp())
		{
			monster[i].RemoveAttack();
			--m_alliveMonster;
		}
	}

	Player* player = static_cast<Player*>(m_player);
	// 기존에 생존한 몬스터보다 현재 생존한 몬스터 수가 적을 경우 경험치 증가
	if (save > m_alliveMonster)
	{
		player->CalculateExp((save - m_alliveMonster) * monster->GetReturnExp());
		player->AddMoney(monster->GetReturnMoney());
		cout << monster->GetReturnMoney() << " Gold를 획득했습니다." << endl;
		system("pause");
	}

	if (0 >= m_player->GetHp())
	{
		cout << "ㅠㅠㅠㅠ사망ㅠㅠㅠㅠ" << endl;
		m_player->InitHp();
		Release();
		system("pause");
		return true;
	}
	else if (0 == m_alliveMonster)
	{
		cout << "!!!!승리!!!!" << endl;
		Release();
		system("pause");
		return true;
	}

	
	return false;
	
	
}
