#include "CPlayer.h"

CPlayer::CPlayer()
{
	CreateNewCharacter();
}

void CPlayer::CreateNewCharacter()
{

	CRollDie dice;

	m_iAgi = dice.roll(3, 6);
	m_iEnd = dice.roll(3, 6);
	m_iHp = 20;
	m_iStr = dice.roll(3, 6);
	m_iWis = dice.roll(3, 6);
	m_iDmg = (m_iAgi + m_iEnd + m_iStr + m_iWis)/5;
	m_iXp = 50;
	m_iLev = m_iXp / 50;

}

void CPlayer::DisplayAttributes()
{

	cout << "=====================" << endl;
	cout << "     Agility: " << m_iAgi << endl;
	cout << "   Endurance: " << m_iEnd << endl;
	cout << "    Strength: " << m_iStr << endl;
	cout << "      Wisdom: " << m_iWis << endl;
	cout << "      Health: " << m_iHp << endl;
	cout << "\n       Level: " << m_iLev << endl;
	cout << "          Xp: " << m_iXp << endl;
	cout << "=====================" << endl;

}

//getters
int CPlayer::GetAgility()
{
	return m_iAgi;
}
int CPlayer::GetEndurance()
{
	return m_iEnd;
}
int CPlayer::GetHealth()
{
	return m_iHp;
}
int CPlayer::GetStrength()
{
	return m_iStr;
}
int CPlayer::GetWisdom()
{
	return m_iWis;
}
int CPlayer::GetDamage()
{
	return m_iDmg;
}
int CPlayer::GetXp()
{
	return m_iXp;
}
int CPlayer::GetLevel()
{
	return m_iLev;
}

//setters
void CPlayer::SetAgility(int a)
{
	m_iAgi = a;
}
void CPlayer::SetEndurance(int e)
{
	m_iEnd = e;
}
void CPlayer::SetHealth(int h)
{
	m_iHp = h;
}
void CPlayer::SetStrength(int s)
{
	m_iStr = s;
}
void CPlayer::SetWisdom(int w)
{
	m_iWis = w;
}
void CPlayer::SetDamage(int d)
{
	m_iDmg = d;
}
void CPlayer::SetXp(int x)
{
	m_iXp = x;
}
void CPlayer::SetLevel(int l)
{
	m_iLev = l;
}
