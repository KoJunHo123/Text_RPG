#include "ItemList.h"

tItem ItemList::GetConsumableItem(int _input)
{
    switch (_input)
    {
    case (int)CONSUMABLE::REDP:
        return m_redPotion;

    case (int)CONSUMABLE::ANTI:
        return m_antiPoison;
        
    case (int)CONSUMABLE::BAND:
        return m_bandage;

    case (int)CONSUMABLE::MENTAL:
        return m_mentalCare;

    case (int)CONSUMABLE::RETURN:
        return tItem();

    default:
        InErr;
        break;
    }
}

void ItemList::AddConsumableItem(int _input)
{
    switch (_input)
    {
    case (int)CONSUMABLE::REDP:
        ++m_redPotion.count;
        break;

    case (int)CONSUMABLE::ANTI:
        ++m_antiPoison.count;
        break;

    case (int)CONSUMABLE::BAND:
        ++m_bandage.count;
        break;

    case (int)CONSUMABLE::MENTAL:
        ++m_mentalCare.count;
        break;

    }
    return;
}

bool ItemList::UseConsumableItem(int _input)
{
    switch (_input)
    {
    case (int)CONSUMABLE::REDP:
        if (0 < m_redPotion.count)
            --m_redPotion.count;
        else
        {
            cout << "������ �������� �����ϴ�." << endl;
            return false;
        }
        break;

    case (int)CONSUMABLE::ANTI:
        if (0 < m_antiPoison.count)
            --m_antiPoison.count;
        else
        {
            cout << "������ �������� �����ϴ�." << endl;
            return false;
        }
        break;

    case (int)CONSUMABLE::BAND:
        if (0 < m_bandage.count)
            --m_bandage.count;
        else
        {
            cout << "������ �������� �����ϴ�." << endl;
            return false;
        }
        break;

    case (int)CONSUMABLE::MENTAL:
        if (0 < m_mentalCare.count)
            --m_mentalCare.count;
        else
        {
            cout << "������ �������� �����ϴ�." << endl;
            return false;
        }
        break;
    }
    return true;
}

void ItemList::AddEquipmentItem(int _iInput, int _iInputWA)
{
    switch (_iInput)
    {
    case (int)EQUIPRANK::OLD:
        ChoiceWeaponOrArmor(m_oldWeapon, m_oldArmor, _iInputWA);
        break;

    case (int)EQUIPRANK::NEW:
        ChoiceWeaponOrArmor(m_newWeapon, m_newArmor, _iInputWA);
        break;

    case (int)EQUIPRANK::HARD:
        ChoiceWeaponOrArmor(m_hardWeapon, m_hardArmor, _iInputWA);
        break;

    case (int)EQUIPRANK::BACK:
        return;

    default:
        InErr;
        break;
    }
    return;
}

// _itemType: ��� Ÿ��(1: �Һ�  2: ���)     _input: ��� ����       _wa: ����/��(�Һ�: 0)
int ItemList::GetPrice(int _itemType, int _input, int _wa)
{
    switch (_itemType)
    {
        // �Һ������
    case 1:
        switch (_input)
        {
        case (int)CONSUMABLE::REDP:
            return m_redPotion.price;

        case (int)CONSUMABLE::ANTI:
            return m_antiPoison.price;

        case (int)CONSUMABLE::BAND:
            return m_bandage.price;

        case (int)CONSUMABLE::MENTAL:
            return m_mentalCare.price;
        }
        break;

        // ��� ������
    case 2:
        switch (_input)
        {
        case (int)EQUIPRANK::OLD:
            switch (_wa)
            {
            case (int)EQUIP::WEAPON:
                return m_oldWeapon.price;
                
            case (int)EQUIP::ARMOR:
                return m_oldArmor.price;
            }
            break;

        case (int)EQUIPRANK::NEW:
            switch (_wa)
            {
            case (int)EQUIP::WEAPON:
                return m_newWeapon.price;
                
            case (int)EQUIP::ARMOR:
                return m_newArmor.price;
                
            }
            break;

        case (int)EQUIPRANK::HARD:
            switch (_wa)
            {
            case (int)EQUIP::WEAPON:
                return m_hardWeapon.price;

            case (int)EQUIP::ARMOR:
                return m_hardArmor.price;

            }
            break;
        }
        break;
    }

}

void ItemList::ChoiceWeaponOrArmor(tWeapon& _weapon, tArmor& _armor, int _iInputWA)
{
    switch (_iInputWA)
    {
    case (int)EQUIP::WEAPON:
        if (false == _weapon.own)
        {
            _weapon.own = true;
            cout << "�����Ͽ����ϴ�." << endl;
        }
        else
        {
            cout << "�̹� �������Դϴ�." << endl;
        }
        break;

    case (int)EQUIP::ARMOR:
        if (false == _armor.own)
        {
            _armor.own = true;
            cout << "�����Ͽ����ϴ�." << endl;
        }
        else
        {
            cout << "�̹� �������Դϴ�." << endl;
        }
        break;

    case (int)EQUIP::BACK:
        return;
    }
}

void ItemList::ShowConsumableItem() const
{
    cout << "���� ����	: " << m_redPotion.count << endl;
    cout << "�ص���		: " << m_antiPoison.count << endl;
    cout << "�ش�		: " << m_bandage.count << endl;
    cout << "û��ȯ		: " << m_mentalCare.count << endl;
}

void ItemList::ShowConsumableItemPrice() const
{
    cout << "���� ����	: " << m_redPotion.price << " Gold" << endl;
    cout << "�ص���		: " << m_antiPoison.price << " Gold" << endl;
    cout << "�ش�		: " << m_bandage.price << " Gold" << endl;
    cout << "û��ȯ		: " << m_mentalCare.price << " Gold" << endl;
}

tWeapon ItemList::GetEquipWeapon(int _input)
{
    switch (_input)
    {
    case (int)EQUIPRANK::OLD:
        return m_oldWeapon;

    case (int)EQUIPRANK::NEW:
        return m_newWeapon;

    case (int)EQUIPRANK::HARD:
        return m_hardWeapon;
    }
     
}

tArmor ItemList::GetEquipArmor(int _input)
{
    switch (_input)
    {
    case (int)EQUIPRANK::OLD:
        return m_oldArmor;

    case (int)EQUIPRANK::NEW:
        return m_newArmor;

    case (int)EQUIPRANK::HARD:
        return m_hardArmor;
    }
}

bool ItemList::CheckWeapon(int _input)
{
    switch (_input)
    {
    case (int)EQUIPRANK::OLD:
        return m_oldWeapon.own;

    case (int)EQUIPRANK::NEW:
        return m_newWeapon.own;

    case (int)EQUIPRANK::HARD:
        return m_hardWeapon.own;

    }
}

bool ItemList::CheckArmor(int _input)
{
    switch (_input)
    {
    case (int)EQUIPRANK::OLD:
        return m_oldArmor.own;

    case (int)EQUIPRANK::NEW:
        return m_newArmor.own;

    case (int)EQUIPRANK::HARD:
        return m_hardArmor.own;
    }
}

void ItemList::ShowEquipmentItem() const
{
    cout << m_oldWeapon.name << " : ";
    if (m_oldWeapon.own)
        cout << "������" << endl;
    else
        cout << "�̼�����" << endl;

    cout << m_oldArmor.name << " : ";
    if (m_oldArmor.own)
        cout << "������" << endl;
    else
        cout << "�̼�����" << endl;

    cout << m_newWeapon.name << " : ";
    if (m_newWeapon.own)
        cout << "������" << endl;
    else
        cout << "�̼�����" << endl;

    cout << m_newArmor.name << " : ";
    if (m_newArmor.own)
        cout << "������" << endl;
    else
        cout << "�̼�����" << endl;
    
    cout << m_hardWeapon.name << " : ";
    if (m_hardWeapon.own)
        cout << "������" << endl;
    else
        cout << "�̼�����" << endl;

    cout << m_hardArmor.name << " : ";
    if (m_hardArmor.own)
        cout << "������" << endl;
    else
        cout << "�̼�����" << endl;
}

void ItemList::ShowEquipmentItemPrice(int _iInput) const
{
    switch (_iInput)
    {
    case (int)EQUIPRANK::OLD:
        cout << m_oldWeapon.name << " : " << m_oldWeapon.price << " Gold" << endl;
        cout << m_oldArmor.name << " : " << m_oldArmor.price << " Gold" << endl;
        break;

    case (int)EQUIPRANK::NEW:
        cout << m_newWeapon.name << " : " << m_newWeapon.price << " Gold" << endl;
        cout << m_newArmor.name << " : " << m_newArmor.price << " Gold" << endl;
        break;

    case (int)EQUIPRANK::HARD:
        cout << m_hardWeapon.name << " : " << m_hardWeapon.price << " Gold" << endl;
        cout << m_hardArmor.name << " : " << m_hardArmor.price << " Gold" << endl;
        break;
    }
}




