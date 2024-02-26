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


		cout << "0. �κ��丮    1. ����    2. ���� : ";
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
			cout << "�����Ͽ����ϴ�!" << endl;
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
	cout << "���� ���: ";
	cin >> iAttack;

	--iAttack;	// �迭�� index ����� ���� �ϳ� ����.


	DamageCalculate(iAttack);
}

void FieldInfo::DamageCalculate(int _iAttack)
{
	// �Է��� ���� ���͸� ������� ������, �ش� ����� ü���� ������ ���.
	if (0 <= _iAttack && m_monster.size() > _iAttack)
	{
		Player* player = static_cast<Player*>(m_player);
		m_monIter = m_monster.begin() + _iAttack;
		Monster* monster = static_cast<Monster*>(*m_monIter);
		//m_player->HpCalculate(monster->GetDamage() * m_monster.size());
		for_each(m_monster.begin(), m_monster.end(), *player);
		cout << "�÷��̾ " << monster->GetDamage() * m_monster.size() << "�� �������� �޾ҽ��ϴ�." << endl;
		Debuff();
		if (player->DebuffEffect())	// ���� ���� ����� ���� -> false������ ����
		{
			monster->HpCalculate(m_player->GetDamage());
			cout << "�÷��̾ " << m_player->GetDamage() << "�� �������� �־����ϴ�." << endl;
		}
		system("pause");
	}
	else
	{
		InErr;
		return;
	}

}


// �¸�, ��� �Ǵ�
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
			cout << monster->GetReturnMoney() << " Gold�� ȹ���߽��ϴ�." << endl;
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
		cout << "�ФФФл���ФФФ�" << endl;
		m_player->InitHp();
		Release();
		system("pause");
		return true;
	}
	else if (m_monster.begin() == m_monster.end())
	{
		cout << "!!!!�¸�!!!!" << endl;
		Release();
		system("pause");
		return true;
	}

	return false;
}
