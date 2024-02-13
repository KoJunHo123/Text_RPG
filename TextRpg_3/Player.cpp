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
		cout << "레벨업!!" << endl;
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
		cout << "플레이어가 1의 독 데미지를 받았습니다." << endl;
		m_hp -= 1;
	}
	if (BLOODY == (m_state & BLOODY))
	{
		cout << "플레이어가 3의 출혈 데미지를 받았습니다." << endl;
		m_hp -= 3;
	}
	if (FEAR == (m_state & FEAR))
	{
		int ranNum = GetRandomNum(1, 100);
		if (30 > ranNum)
		{
			cout << "플레이어가 공포에 걸려 몸을 움직일 수 없습니다." << endl;
			attack_Success = false;
		}
	}

	return attack_Success;
}

void Player::ShowInfo()const
{
	cout << "직업 : " << m_name << endl;
	cout << "레벨 : " << m_level << endl;
	cout << "체력 : " << m_hp << '/' << m_maxHp << endl;
	cout << "공격력 : " << m_damage << endl;
	cout << "경험치 : " << m_exp << '/' << m_maxExp << endl;
	cout << "상태 : ";

	if (POISON == (m_state & POISON))
	{
		cout << "[중독]";
	}
	if (BLOODY == (m_state & BLOODY))
	{
		cout << "[출혈]";
	}
	if (FEAR == (m_state & FEAR))
	{
		cout << "[공포]";
	}
	if(NULL == m_state)
	{
		cout << "[정상]";
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
		cout << "1. 빨간 포션    2. 해독제    3. 붕대    4. 청심환    5. 돌아가기 : ";
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
		cout << "1. 빨간 포션    2. 해독제    3. 붕대    4. 청심환    5. 돌아가기 : ";
		cin >> iInput;

		if (!(m_inven.CompareMoney(iInput, m_inven.GetMoney())))
		{
			cout << "금액이 부족합니다." << endl;
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
			cout << "플레이어의 체력이 " << m_maxHp - m_hp << " 회복되었습니다." << endl;
			m_hp = m_maxHp;
		}
		else if (m_hp > 0)
		{
			cout << "플레이어의 체력이 50 회복되었습니다." << endl;
			m_hp += 50;
		}
		break;

	case (int)ITEM::ANTI:
		if(POISON == (m_state & POISON))
		{
			cout << "중독을 해제하였습니다." << endl;
			m_state &= ~POISON;
		}
		break;

	case (int)ITEM::BAND:
		if (BLOODY == (m_state & BLOODY))
		{
			cout << "출혈을 해제하였습니다." << endl;
			m_state &= ~BLOODY;
		}
		break;

	case (int)ITEM::MENTAL:
		if (FEAR == (m_state & FEAR))
		{
			cout << "공포를 해제하였습니다." << endl;
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
	_file.write(reinterpret_cast<const char*>(this), sizeof(Player));		// write는 const char*를 인자로 받음.
}

void Player::LoadPlayer(ifstream& _file)
{
	_file.read(reinterpret_cast<char*>(this), sizeof(Player));		// read는 char*를 인자로 받음.
}


