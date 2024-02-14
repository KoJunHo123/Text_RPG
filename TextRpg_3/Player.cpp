#include "Player.h"

Player::Player(const char _name[], int _maxHp, int _damage)
	: Character(_name, _maxHp, _damage)
	, m_level(1)
	, m_exp(0)
	, m_maxExp(50)
	, m_inven{}
{
}



void Player::Initialize(const char _name[], int _maxHp, int _damage)
{
	strcpy_s(m_name, sizeof(m_name), _name);
	m_hp = _maxHp;
	m_maxHp = _maxHp;
	m_damage = _damage;
	m_level = 1;
	m_exp = 0;
	m_maxExp = 50;
	m_inven = {};
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
	system("cls");
	ShowInfo();
	int choice = 0;
	cout << "1. �Һ�â    2. ���â     3. ���ư��� : ";
	cin >> choice;

	if (1 == choice)
	{
		bool useInventory = true;
		while (useInventory)
		{
			system("cls");
			ShowInfo();
			m_inven.ShowInventory();

			int iInput = 0;
			cout << "1. ���� ����    2. �ص���    3. �ش�    4. û��ȯ    5. ���ư��� : ";
			cin >> iInput;
			if (5 == iInput)
				return;
			useInventory = m_inven.UseItem(iInput);
			if (true == useInventory)
				UseItemEffect(iInput);
			system("pause");
		}
	}
	else if (2 == choice)
	{
		while (true)
		{
			system("cls");
			ShowInfo();
			m_inven.ShowEquip();

			int addStat = 0;

			int iInput = 0;
			cout << "1. ���� ����    2. ���� ����    3. ���ư���" << endl;
			cin >> iInput;

			switch (iInput)
			{
			case (int)EQUIP::WEAPON:
				m_damage += m_inven.ChangeWeapon();
				break;

			case (int)EQUIP::ARMOR:
				m_maxHp += m_inven.ChangeArmor();
				break;

			case (int)EQUIP::BACK:
				return;
			}
		}
	}
	
}



void Player::UseItemEffect(int _iInput)
{
	switch (_iInput)
	{
	case (int)CONSUMABLE::REDP:
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

	case (int)CONSUMABLE::ANTI:
		if(POISON == (m_state & POISON))
		{
			cout << "�ߵ��� �����Ͽ����ϴ�." << endl;
			m_state &= ~POISON;
		}
		else
		{
			cout << "�ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�." << endl;
		}
		break;

	case (int)CONSUMABLE::BAND:
		if (BLOODY == (m_state & BLOODY))
		{
			cout << "������ �����Ͽ����ϴ�." << endl;
			m_state &= ~BLOODY;
		}
		break;

	case (int)CONSUMABLE::MENTAL:
		if (FEAR == (m_state & FEAR))
		{
			cout << "������ �����Ͽ����ϴ�." << endl;
			m_state &= ~FEAR;
		}
		break;

	case (int)CONSUMABLE::RETURN:
		return;

	default:
		InErr;
		break;
	}
	
}
void Player::EquipItemEffect()
{

}
//
//void Player::SavePlayer(ofstream& _file)
//{
//	_file.write(reinterpret_cast<const char*>(this), sizeof(Player));		// write�� const char*�� ���ڷ� ����.
//}
//
//void Player::LoadPlayer(ifstream& _file)
//{
//	_file.read(reinterpret_cast<char*>(this), sizeof(Player));		// read�� char*�� ���ڷ� ����.
//}


