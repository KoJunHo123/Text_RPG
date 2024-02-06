#include "FieldInfo.h"


FieldInfo::~FieldInfo()
{
	Release();
}

// virtual
void FieldInfo::Initialize(Player* _player)
{
}

void FieldInfo::Update()
{
	while (true)
	{
		system("cls");
		m_player->ShowPlayer();
		ShowMonsterArr();


		int iInput = 0;


		cout << "0. �κ��丮    1. ����    2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case INVENTORY:
			m_player->OpenInventory();
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
	for (int i = 0; i < m_allow; ++i)
	{
		m_monster[i].ShowMonster(i);
	}
}

void FieldInfo::Fight()
{
	system("cls");
	m_player->ShowPlayer();
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
	// �Է��� ���� ���͸� ������� ������, �ش� ����� ü���� ������ ���.
	if (0 <= _iAttack && m_allow > _iAttack && m_monster[_iAttack].GetHp() > 0)
	{
		m_player->HpCalculate(m_monster[_iAttack].GetDamage() * m_alliveMonster);
		cout << "�÷��̾ " << m_monster[_iAttack].GetDamage() * m_alliveMonster << "�� �������� �޾ҽ��ϴ�." << endl;
		Debuff();
		if (m_player->DebuffEffect())	// ���� ���� ����� ���� -> false������ ����
		{
			m_monster[_iAttack].HpCalculate(m_player->GetDamage());
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

	// ��ü �Ҵ� ���Ϳ��� ���� ���� ���͸�ŭ ����
	for (int i = 0; i < m_allow; ++i)
	{
		if (0 >= m_monster[i].GetHp())
		{
			m_monster[i].RemoveAttack();
			--m_alliveMonster;
		}
	}

	// ������ ������ ���ͺ��� ���� ������ ���� ���� ���� ��� ����ġ ����
	if (save > m_alliveMonster)
	{
		m_player->CalculateExp((save - m_alliveMonster) * m_monster->GetReturnExp());
		m_player->AddMoney(m_monster->GetReturnMoney());
		cout << m_monster->GetReturnMoney() << " Gold�� ȹ���߽��ϴ�." << endl;
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

// virtual
void FieldInfo::Debuff()
{
}