#ifndef ROLLDIE_H
#define ROLLDIE_H

#include <iostream>
#include <ctime>
using namespace std;

// Class created to roll multiple dice based on DND rules
// Syntax is roll(Number of Rolls, Number of Sides)
// If result is -1 then you used an incorrect number of sides

class CRollDie
{

public:

	CRollDie()
	{
		srand(time(0));
	}

	int roll(int number, int sides)
	{
		int total = 0;

		switch(sides)
		{
			case 4:
			case 6:
			case 8:
			case 10:
			case 12:
			case 20:
				total = rollNumberDie(number, sides);
				break;
			case 100:
				total = rollNumberDie100(number);
				break;
			default:
				total = -1;
		}

		return total;

	}


private:

	int rollNumberDie(int number, int sides)
	{
		int total = 0;
		for (int i = 0; i < number; i++)
		{
			total += rollSingleDie(sides);
		}
		return total;
	}

	int rollNumberDie100(int number)
	{
		int total = 0;
		for (int i = 0; i < number; i++)
		{
			total += rollDie100();
		}
		return total;
	}

	int rollDie100()
	{
		int total = 0;
		int number1 = rollSingleDie(10);
		int number2 = rollSingleDie(10);

		if (number1 == 10 && number2 == 10)
		{
			total = 100;
		}
		else
		{
			if (number2 == 10)
			{
				total = number1 * 10;
			}
			else
			{
				if (number1 == 10)
				{
					total = number2;
				}
				else
				{
					total = (number1 * 10) + number2;
				}
			}
		}
		return total;
	}

	int rollSingleDie(int sides)
	{
		return 1 + rand() % sides;
	}
};

#endif