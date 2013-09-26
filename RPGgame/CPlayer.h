#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "CRollDie.h"
#include "Creature.h"
#include "Boss.h"
#include <fstream>

using namespace std;

class CPlayer
{

private:

	int m_iXp;
	int m_iStr;
	int m_iAgi;
	int m_iWis;
	int m_iEnd;
	int m_iDmg;
	int m_iHp;
	int m_iLev;

public:

	CPlayer();

	//New Character
	void CreateNewCharacter();

	void DisplayAttributes();

	void SaveGame();

	int GetStrength();
	int GetAgility();
	int GetWisdom();
	int GetEndurance();
	int GetHealth();
	int GetDamage();
	int GetXp();
	int GetLevel();

	void SetStrength(int s);
	void SetAgility(int a);
	void SetWisdom(int w);
	void SetEndurance(int e);
	void SetHealth(int h);
	void SetDamage(int d);
	void SetXp(int x);
	void SetLevel(int l);

};

#endif 
