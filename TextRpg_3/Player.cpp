#include "Player.h"

Player::Player(const char _name[], int _maxHp, int _damage)
	: Character(_name, _maxHp, _damage)
	, m_level(1)
	, m_exp(0)
	, m_maxExp(50)
	, m_inven{}
{
}



void Player::CalculateExp(int _getExp)
{
	m_exp += _getExp;
	if (m_exp >= m_maxExp)
	{
		cout << "������!!" << endl;
		++m_level;
		m_damage += 5;
		m_maxHp += 50;
		m_hp = m_maxHp;
		m_maxExp += 50;
		m_exp = 0;
		m_state = 0;
		system("pause");
	}
}

bool Player::DebuffEffect()
{
	bool attack_Success = true;
	if (POISON == (m_state & POISON))
	{
		cout << "�÷��̾ 1�� �� �������� �޾ҽ��ϴ�." << endl;
		m_hp -= 1;
	}
	if (BLOODY == (m_state & BLOODY))
	{
		cout << "�÷��̾ 3�� ���� �������� �޾ҽ��ϴ�." << endl;
		m_hp -= 3;
	}
	if (FEAR == (m_state & FEAR))
	{
		int ranNum = GetRandomNum(1, 100);
		if (30 > ranNum)
		{
			cout << "�÷��̾ ������ �ɷ� ���� ������ �� �����ϴ�." << endl;
			attack_Success = false;
		}
	}

	return attack_Success;
}

void Player::ShowInfo()const
{
	cout << "���� : " << m_name << endl;
	cout << "���� : " << m_level << endl;
	cout << "ü�� : " << m_hp << '/' << m_maxHp << endl;
	cout << "���ݷ� : " << m_damage << endl;
	cout << "����ġ : " << m_exp << '/' << m_maxExp << endl;
	cout << "���� : ";

	if (POISON == (m_state & POISON))
	{
		cout << "[�ߵ�]";
	}
	if (BLOODY == (m_state & BLOODY))
	{
		cout << "[����]";
	}
	if (FEAR == (m_state & FEAR))
	{
		cout << "[����]";
	}
	if(NULL == m_state)
	{
		cout << "[����]";
	}

	cout << endl <<"======================================" << endl;
}

void Player::OpenInventory()
{
	int useInventory = 1;
	while (useInventory)
	{
		system("cls");
		ShowInfo();
		m_inven.ShowInventory();

		int iInput = 0;
		cout << "1. ���� ����    2. �ص���    3. �ش�    4. û��ȯ    5. ���ư��� : ";
		cin >> iInput;

		useInventory = m_inven.UseItem(iInput);
		if(1 == useInventory)
			UseItemEffect(iInput);
		system("pause");
	}
}

void Player::OpenShop()
{
	bool useShop = true;

	while (useShop)
	{
		system("cls");
		m_inven.ShowShopItem();

		int iInput = 0;
		cout << "1. ���� ����    2. �ص���    3. �ش�    4. û��ȯ    5. ���ư��� : ";
		cin >> iInput;

		if (!(m_inven.CompareMoney(iInput, m_inven.GetMoney())))
		{
			cout << "�ݾ��� �����մϴ�." << endl;
			system("pause");
			continue;
		}

		useShop = m_inven.AddItem(iInput);
		system("pause");
	}
	
}

void Player::UseItemEffect(int _iInput)
{
	switch (_iInput)
	{
	case (int)ITEM::REDP:
		if (50 > (m_maxHp - m_hp))
		{
			cout << "�÷��̾��� ü���� " << m_maxHp - m_hp << " ȸ���Ǿ����ϴ�." << endl;
			m_hp = m_maxHp;
		}
		else if (m_hp > 0)
		{
			cout << "�÷��̾��� ü���� 50 ȸ���Ǿ����ϴ�." << endl;
			m_hp += 50;
		}
		break;

	case (int)ITEM::ANTI:
		if(POISON == (m_state & POISON))
		{
			cout << "�ߵ��� �����Ͽ����ϴ�." << endl;
			m_state &= ~POISON;
		}
		break;

	case (int)ITEM::BAND:
		if (BLOODY == (m_state & BLOODY))
		{
			cout << "������ �����Ͽ����ϴ�." << endl;
			m_state &= ~BLOODY;
		}
		break;

	case (int)ITEM::MENTAL:
		if (FEAR == (m_state & FEAR))
		{
			cout << "������ �����Ͽ����ϴ�." << endl;
			m_state &= ~FEAR;
		}
		break;

	case (int)ITEM::RETURN:
		return;

	default:
		InErr;
		break;
	}
	
}

void Player::AddMoney(int _money)
{
	m_inven.AddMoney(_money);
}

void Player::SavePlayer(ofstream& _file)
{
	_file.write(reinterpret_cast<const char*>(this), sizeof(Player));		// write�� const char*�� ���ڷ� ����.
}

void Player::LoadPlayer(ifstream& _file)
{
	_file.read(reinterpret_cast<char*>(this), sizeof(Player));		// read�� char*�� ���ڷ� ����.
}


