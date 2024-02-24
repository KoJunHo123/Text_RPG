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


		cout << "0. 昔坤塘軒    1. 因維    2. 亀爽 : ";
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
			cout << "亀爽馬心柔艦陥!" << endl;
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
	cout << "因維 企雌: ";
	cin >> iAttack;

	--iAttack;	// 壕伸税 index 域至聖 是背 馬蟹 皐捜.


	DamageCalculate(iAttack);
}

void FieldInfo::DamageCalculate(int _iAttack)
{
	Player* player = static_cast<Player*>(m_player);
	m_monIter = m_monster.begin() + _iAttack;
	Monster* monster = static_cast<Monster*>(*m_monIter);


	// 脊径廃 葵戚 佼什斗研 企雌生稽 梅生悟, 背雁 企雌税 端径戚 糎仙拝 井酔.
	if (0 <= _iAttack && m_allow > _iAttack && monster->GetHp() > 0)
	{
		m_player->HpCalculate(monster->GetDamage() * m_monster.size());
		cout << "巴傾戚嬢亜 " << monster->GetDamage() * m_monster.size() << "税 汽耕走研 閤紹柔艦陥." << endl;
		Debuff();
		if (player->DebuffEffect())	// 因匂 去税 巨獄覗 毒舛 -> false蟹神檎 叔鳶
		{
			monster->HpCalculate(m_player->GetDamage());
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
	Player* player = static_cast<Player*>(m_player);
	for (m_monIter = m_monster.begin(); m_monIter != m_monster.end();)
	{
		Monster* monster = dynamic_cast<Monster*>(*m_monIter);
		if ((*m_monIter)->GetHp() <= 0)
		{
			player->CalculateExp(monster->GetReturnExp());
			player->AddMoney(monster->GetReturnMoney());
			cout << monster->GetReturnMoney() << " Gold研 塙究梅柔艦陥." << endl;
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
		cout << "ばばばば紫諺ばばばば" << endl;
		m_player->InitHp();
		Release();
		system("pause");
		return true;
	}
	else if (m_monster.begin() == m_monster.end())
	{
		cout << "!!!!渋軒!!!!" << endl;
		Release();
		system("pause");
		return true;
	}

	return false;
}
