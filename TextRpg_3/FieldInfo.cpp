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
	cout << "���� ���: ";
	cin >> iAttack;

	--iAttack;	// �迭�� index ����� ���� �ϳ� ����.

	// �Է��� ���� ���͸� ������� ������, �ش� ����� ü���� ������ ���.
	DamageCalculate(iAttack);
}

void FieldInfo::DamageCalculate(int _iAttack)
{
	Player* player = static_cast<Player*>(m_player);
	Monster* monster = static_cast<Monster*>(m_monster);
	// �Է��� ���� ���͸� ������� ������, �ش� ����� ü���� ������ ���.
	if (0 <= _iAttack && m_allow > _iAttack && monster[_iAttack].GetHp() > 0)
	{
		m_player->HpCalculate(monster[_iAttack].GetDamage() * m_alliveMonster);
		cout << "�÷��̾ " << monster[_iAttack].GetDamage() * m_alliveMonster << "�� �������� �޾ҽ��ϴ�." << endl;
		Debuff();
		if (player->DebuffEffect())	// ���� ���� ����� ���� -> false������ ����
		{
			monster[_iAttack].HpCalculate(m_player->GetDamage());
			cout << "�÷��̾ " << m_player->GetDamage() << "�� �������� �־����ϴ�." << endl;
		}
		
		system("pause");
	}
	else
	{
		InErr;
	}

}


// �¸�, ��� �Ǵ�
bool FieldInfo::Decision()
{
	// ���� ������ ���� �� ����
	int save = m_alliveMonster;
	m_alliveMonster = m_allow;

	Monster* monster = static_cast<Monster*>(m_monster);
	// ��ü �Ҵ� ���Ϳ��� ���� ���� ���͸�ŭ ����
	for (int i = 0; i < m_allow; ++i)
	{
		if (0 >= monster[i].GetHp())
		{
			monster[i].RemoveAttack();
			--m_alliveMonster;
		}
	}

	Player* player = static_cast<Player*>(m_player);
	// ������ ������ ���ͺ��� ���� ������ ���� ���� ���� ��� ����ġ ����
	if (save > m_alliveMonster)
	{
		player->CalculateExp((save - m_alliveMonster) * monster->GetReturnExp());
		player->AddMoney(monster->GetReturnMoney());
		cout << monster->GetReturnMoney() << " Gold�� ȹ���߽��ϴ�." << endl;
		system("pause");
	}

	if (0 >= m_player->GetHp())
	{
		cout << "�ФФФл���ФФФ�" << endl;
		m_player->InitHp();
		Release();
		system("pause");
		return true;
	}
	else if (0 == m_alliveMonster)
	{
		cout << "!!!!�¸�!!!!" << endl;
		Release();
		system("pause");
		return true;
	}

	
	return false;
	
	
}
