#include "FieldInfo.h"


FieldInfo::~FieldInfo()
{
	Release();
}

// virtual
void FieldInfo::Initialize(Character* _player)
{
}

void FieldInfo::Update()
{
	while (true)
	{
		system("cls");
		m_player->ShowInfo();
		ShowMonsterArr();


		int iInput = 0;


		cout << "0. 昔坤塘軒    1. 因維    2. 亀爽 : ";
		cin >> iInput;

		Player* player = dynamic_cast<Player*>(m_player);

		switch (iInput)
		{
		case INVENTORY:
			player->OpenInventory();
			break;

		case (int)BATTLE::ATTACK:
			Fight();
			break;

		case (int)BATTLE::RUN:
			cout << "亀爽馬心柔艦陥!" << endl;
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
	cout << "因維 企雌: ";
	cin >> iAttack;

	--iAttack;	// 壕伸税 index 域至聖 是背 馬蟹 皐捜.

	// 脊径廃 葵戚 佼什斗研 企雌生稽 梅生悟, 背雁 企雌税 端径戚 糎仙拝 井酔.
	DamageCalculate(iAttack);
}

void FieldInfo::DamageCalculate(int _iAttack)
{
	Player* player = dynamic_cast<Player*>(m_player);
	Monster* monster = dynamic_cast<Monster*>(m_monster);
	// 脊径廃 葵戚 佼什斗研 企雌生稽 梅生悟, 背雁 企雌税 端径戚 糎仙拝 井酔.
	if (0 <= _iAttack && m_allow > _iAttack && monster[_iAttack].GetHp() > 0)
	{
		m_player->HpCalculate(monster[_iAttack].GetDamage() * m_alliveMonster);
		cout << "巴傾戚嬢亜 " << monster[_iAttack].GetDamage() * m_alliveMonster << "税 汽耕走研 閤紹柔艦陥." << endl;
		Debuff();
		if (player->DebuffEffect())	// 因匂 去税 巨獄覗 毒舛 -> false蟹神檎 叔鳶
		{
			monster[_iAttack].HpCalculate(m_player->GetDamage());
			cout << "巴傾戚嬢亜 " << m_player->GetDamage() << "税 汽耕走研 爽醸柔艦陥." << endl;
		}
		
		system("pause");
	}
	else
	{
		InErr;
	}

}


// 渋軒, 紫諺 毒舘
bool FieldInfo::Decision()
{
	// 奄糎 持糎廃 佼什斗 呪 煽舌
	int save = m_alliveMonster;
	m_alliveMonster = m_allow;

	Monster* monster = dynamic_cast<Monster*>(m_monster);
	// 穿端 拝雁 佼什斗拭辞 薄仙 宋精 佼什斗幻鏑 薦須
	for (int i = 0; i < m_allow; ++i)
	{
		if (0 >= monster[i].GetHp())
		{
			monster[i].RemoveAttack();
			--m_alliveMonster;
		}
	}

	Player* player = dynamic_cast<Player*>(m_player);
	// 奄糎拭 持糎廃 佼什斗左陥 薄仙 持糎廃 佼什斗 呪亜 旋聖 井酔 井蝿帖 装亜
	if (save > m_alliveMonster)
	{
		player->CalculateExp((save - m_alliveMonster) * monster->GetReturnExp());
		player->AddMoney(monster->GetReturnMoney());
		cout << monster->GetReturnMoney() << " Gold研 塙究梅柔艦陥." << endl;
		system("pause");
	}

	if (0 >= m_player->GetHp())
	{
		cout << "ばばばば紫諺ばばばば" << endl;
		m_player->InitHp();
		Release();
		system("pause");
		return true;
	}
	else if (0 == m_alliveMonster)
	{
		cout << "!!!!渋軒!!!!" << endl;
		Release();
		system("pause");
		return true;
	}

	
	return false;
	
	
}

// virtual
void FieldInfo::Debuff()
{
}