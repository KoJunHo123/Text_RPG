#include "Player.h"

Player::Player(string _name, int _maxHp, int _damage)
	: Character(_name, _maxHp, _damage)
	, m_level(1)
	, m_exp(0)
	, m_maxExp(50)
	, m_inven{}

	//, m_inven_2{}
	//, m_money(0)
	//, m_armor{}
	//, m_weapon{}
{
}

void Player::Initialize(string _name, int _maxHp, int _damage)
{
	m_name = _name;
	m_hp = _maxHp;
	m_maxHp = _maxHp;
	m_damage = _damage;
	m_level = 1;
	m_exp = 0;
	m_maxExp = 50;
	m_inven = {};
	//m_inven_2.reserve(5);
	//m_money = 1000;
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
	system("cls");
	ShowInfo();
	int choice = 0;
	cout << "1. 소비창    2. 장비창     3. 돌아가기 : ";
	cin >> choice;

	if (1 == choice)
	{
		int iInput = 0;
		bool useInventory = true;
		while (5 != iInput)
		{
			system("cls");
			ShowInfo();
			m_inven.ShowInventory();

			cout << "1. 빨간 포션    2. 해독제    3. 붕대    4. 청심환    5. 돌아가기 : ";
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
			cout << "1. 무기 변경    2. 갑옷 변경    3. 돌아가기" << endl;
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
			cout << "플레이어의 체력이 " << m_maxHp - m_hp << " 회복되었습니다." << endl;
			m_hp = m_maxHp;
		}
		else if (m_hp > 0)
		{
			cout << "플레이어의 체력이 50 회복되었습니다." << endl;
			m_hp += 50;
		}
		break;

	case (int)CONSUMABLE::ANTI:
		if(POISON == (m_state & POISON))
		{
			cout << "중독을 해제하였습니다." << endl;
			m_state &= ~POISON;
		}
		else
		{
			cout << "아무일도 일어나지 않았습니다." << endl;
		}
		break;

	case (int)CONSUMABLE::BAND:
		if (BLOODY == (m_state & BLOODY))
		{
			cout << "출혈을 해제하였습니다." << endl;
			m_state &= ~BLOODY;
		}
		else
		{
			cout << "아무일도 일어나지 않았습니다." << endl;
		}
		break;

	case (int)CONSUMABLE::MENTAL:
		if (FEAR == (m_state & FEAR))
		{
			cout << "공포를 해제하였습니다." << endl;
			m_state &= ~FEAR;
		}
		else
		{
			cout << "아무일도 일어나지 않았습니다." << endl;
		}
		break;

	case (int)CONSUMABLE::RETURN:
		return;

	default:
		InErr;
		break;
	}
}

#pragma region 부랴부랴
//void Player::BuyItem(item _item)
//{
//	system("cls");
//	if (5 > m_inven_2.size())
//	{
//		m_money -= _item.price;
//		m_inven_2.push_back(_item);
//		cout << "구매 완료" << endl;
//	}
//	else
//		cout << "인벤토리에 공간이 없습니다." << endl;
//	system("pause");
//}
//
//void Player::SellItem()
//{
//	system("cls");
//	ShowInventory();
//
//	char name[32] = {};
//	cout << "판매할 아이템 : " << endl;
//	cin >> name;
//	for (vector<item>::iterator iter = m_inven_2.begin(); iter != m_inven_2.end(); )
//	{
//		if (!strcmp(name, (*iter).name))
//		{
//			m_money += (*iter).price;
//			iter = m_inven_2.erase(iter);
//			cout << "판매 완료" << endl;
//			system("pause");
//		}
//		else
//			++iter;
//	}
//}
//
//void Player::ShowInventory()
//{
//	cout << "소지금 : " << m_money << "원" << endl;
//	for (vector<item>::iterator iter = m_inven_2.begin(); iter != m_inven_2.end(); ++iter)
//	{
//		// 무기
//		if (0 == (*iter).itemType)
//		{
//			cout << "이름 : " << (*iter).name << endl;
//			cout << "공격력 : " << (*iter).damage << endl;
//			cout << "가격 : " << (*iter).price << endl;
//		}
//		// 갑빠
//		else
//		{
//			cout << "이름 : " << (*iter).name << endl;
//			cout << "추가 체력 : " << (*iter).hp << endl;
//			cout << "가격 : " << (*iter).price << endl;
//		}
//		cout << endl;
//	}
//}
//
//void Player::SetWeapon(item _weapon)
//{
//	if (m_weapon.damage == 0)
//	{
//		m_damage += _weapon.damage;
//		m_weapon = _weapon;
//	}
//	
//	else
//	{
//		m_damage -= m_weapon.damage;
//		m_damage += _weapon.damage;
//		m_weapon = _weapon;
//	}
//}
//
//void Player::SetArmor(item _armor)
//{
//	if (m_armor.hp == 0)
//	{
//		m_maxHp += _armor.hp;
//		m_armor = _armor;
//	}
//	else
//	{
//		m_maxHp -= m_armor.hp;
//		m_maxHp += _armor.hp;
//		m_armor = _armor;
//	}
//}
//
//void Player::SetItem()
//{
//	system("cls");
//	ShowInventory();
//
//	char name[32] = {};
//	cout << "장착할 아이템 : ";
//	cin >> name;
//
//	for (vector<item>::iterator iter = m_inven_2.begin(); iter != m_inven_2.end(); ++iter)
//	{
//		if (!strcmp(name, (*iter).name))
//		{
//			if (0 == (*iter).itemType)
//				SetWeapon(*iter);
//			else
//				SetArmor(*iter);
//
//		}
//	}
//}
#pragma endregion 만든 것들


void Player::SavePlayer(ofstream& _file)
{
	_file.write(reinterpret_cast<const char*>(this), sizeof(Player));		// write는 const char*를 인자로 받음.
}

void Player::LoadPlayer(ifstream& _file)
{
	_file.read(reinterpret_cast<char*>(this), sizeof(Player));		// read는 char*를 인자로 받음.
}

void Player::CopyPlayerData(Player* _player)
{
	m_name = _player->m_name;
	m_hp = _player->m_hp;
	m_maxHp = _player->m_maxHp;
	m_damage = _player->m_damage;
	m_state = _player->m_state;
	m_level = _player->m_level;
	m_exp = _player->m_exp;
	m_maxExp = _player->m_maxExp;
	m_inven = _player->m_inven;
}


