
#ifndef CREATURE_H
#define CREATURE_H

class Creature
{

	private:

		int m_iHp;
		int m_iDmg;

	public:

	Creature()
	{
		CRollDie dice;

		m_iHp = dice.roll(2, 6);
		m_iDmg = dice.roll(1, 8);

	}

	int GetHealth()
	{
		return m_iHp;
	}
	int GetDamage()
	{
		return m_iDmg;
	}


	void SetHealth(int h)
	{
		m_iHp = h;
	}
	void SetDamage(int d)
	{
		m_iDmg = d;
	}

	void DisplayCreature()
	{
		int x = rand() % 5;

		switch(x)
		{
		case 0:
			cout << "Possessed Parrot";
			break;
		case 1:
			cout << "Venomous Snake";
			break;
		case 2:
			cout << "Fire Ants";
			break;
		case 3:
			cout << "Rabit Hedgehog";
			break;
		case 4:
			cout << "Poisonous Arachnid";
			break;
		case 5:
			cout << "Frantic Beaver";
			break;
		default:
			cout << "Wild Wolf";
			break;

		}
	}

};
#endif