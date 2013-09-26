#ifndef BOSS_H
#define BOSS_H

class Boss
{

	private:

		int m_iHp;
		int m_iDmg;

	public:

	Boss()
	{
		CRollDie dice;

		m_iHp = dice.roll(4, 6);
		m_iDmg = dice.roll(2, 8);

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


};
#endif