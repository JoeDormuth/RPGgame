#include <iostream>
#include "CPlayer.h"

using namespace std;

CPlayer m_oPlayer;
CRollDie dice;

void GameMenu();
void NewGame();
void SaveGame();
void LoadGame();
void GameIntro();
void IntroMenu();
void Wild();
void Fountain();
void DarkLord();
void Fight(Creature*);
void Heal();
void ExploreHp();
void ExploreWild();
void FinalFight(Boss*);

void main()
{

	GameMenu();

}

void GameMenu()
{

	char opt = '1';

	while(opt != '0')
	{

		cout << "=======================" << endl;
		cout << "Choose an option below." << endl;
		cout << "1. New Game" << endl;
		cout << "2. Load Game" << endl;
		cout << "0. Quit" << endl;
		cout << "=======================" << endl;
		cin >> opt;

		switch(opt)
		{
		case '1':
			//New Game
			NewGame();
			break;

		case '2':
			//Load Game
			LoadGame();
			break;

		case '0':
			break;

		default:
			cout << "Not a valid option!" << endl;
			break;
		}

	}

}

void NewGame()
{

	char opt = '2';

	while(opt != '1')
	{

		cout << "\n";

		m_oPlayer.CreateNewCharacter();
		m_oPlayer.DisplayAttributes();

		cout << "\n====================================" << endl;
		cout << "Would you like to keep this player?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cout << "====================================" << endl;
		cin >> opt;

		switch(opt)
		{
			case '1':
				//Save the game
				SaveGame();
				//Continue to game
				GameIntro();
				IntroMenu();
				break;

			case '2':
				break;

			default:
				cout << "Not a valid option!" << endl;
				break;
		}
	}
}
void SaveGame()
{
	ofstream file ("character.char");

	file << m_oPlayer.GetStrength() << endl;
	file << m_oPlayer.GetAgility() << endl;
	file << m_oPlayer.GetWisdom() << endl;
	file << m_oPlayer.GetEndurance() << endl;
	file << m_oPlayer.GetHealth() << endl;
	file << m_oPlayer.GetXp() << endl;
	file << m_oPlayer.GetLevel() << endl;
	file << m_oPlayer.GetDamage() << endl;

	file.close();

	cout << "\nGame saved..." << endl;

}
void LoadGame()
{

	ifstream in ("character.char");

	int value;

	in >> value;
	m_oPlayer.SetStrength(value);

	in >> value;
	m_oPlayer.SetAgility(value);

	in >> value;
	m_oPlayer.SetWisdom(value);

	in >> value;
	m_oPlayer.SetEndurance(value);

	in >> value;
	m_oPlayer.SetHealth(value);

	in >> value;
	m_oPlayer.SetXp(value);

	in >> value;
	m_oPlayer.SetLevel(value);

	in >> value;
	m_oPlayer.SetDamage(value);

	in.close();

	cout << "\n";

	m_oPlayer.DisplayAttributes();
	cout << "Character loaded...\n" << endl;
	system("pause");
	IntroMenu();

}
void GameIntro()
{

	cout << "\n============================================================================" << endl;
	cout << "\nWelcome to a world of which has been forgotten." << endl;
	cout << "You may wonder where and when you are. to this i will tell you" << endl;
	cout << "Eveything may appear different but you are still on the planet earth" << endl;
	cout << "just one thousand years earlier than you were. Now to why you are" << endl;
	cout << "here. You have not been brought here by chance but because we" << endl;
	cout << "beleive that you can help us with the war that is arising. The" << endl;
	cout << "dark lord has taken control over most wildlife and is preparing to" << endl;
	cout << "use them to wipe humans from existance you are chosen to save mankind." << endl;
	cout << "Before we are sure of this we will need you to prove yourself worthy. You" << endl;
	cout << "must complete challenges that are thrown at you and most importantly survive" << endl;
	cout << "Now prepare yourself for the war to come and begin your journey.\n" << endl;
	cout << "============================================================================\n" << endl;
	system("pause");

}

void IntroMenu()
{

	char opt = '1';

	while (opt != '0')
	{

		cout << "\n==============================" << endl;
		cout << "current location - HOME" << endl;
		cout << "==============================" << endl;
		cout << "Please choose your destination\n" << endl;
		cout << "1. The Dark Wilderness" << endl;
		cout << "2. Fountain of Rejuvenation" << endl;
		cout << "3. Dark Lords Lair" << endl;
		cout << "0. Quit to Main Menu" << endl;
		cout << "==============================" << endl;
		cin >> opt;


	switch(opt)
		{
			case '1':
				Wild();
				break;

			case '2':
				Fountain();
				break;

			case '3':
				DarkLord();
				break;

			case '0':
				break;

			default:
				cout << "Not a valid option!" << endl;
				break;
		}

	}

}

void Wild()
{

	char opt = '1';

	while (opt != '0')
	{
		Creature C;

		cout << "\n==============================" << endl;
		cout << "current location - WILDERNESS" << endl;
		cout << "==============================" << endl;
		cout << "What would you like to do?\n" << endl;
		cout << "1. Battle" << endl;
		cout << "2. Explore" << endl;
		cout << "0. Home" << endl;
		cout << "==============================" << endl;
		cin >> opt;

		switch(opt)
		{

			case '1':
				Fight(&C);
				break;

			case '2':
				ExploreWild();
				break;
		
			case '0':
				break;

			default:
				cout << "Not a valid option!" << endl;
				break;

		}

	}

}

void Fountain()
{

	char opt = '1';

	while (opt != '0')
	{

		cout << "\n==============================" << endl;
		cout << "current location - FOUNTAIN" << endl;
		cout << "==============================" << endl;
		cout << "What would you like to do?" << endl;
		cout << "Your Health is: " << m_oPlayer.GetHealth()<< "\n" << endl;
		cout << "1. Rejuvenate" << endl;
		cout << "2. Explore" << endl;
		cout << "0. Home" << endl;
		cout << "==============================" << endl;
		cin >> opt;

		switch(opt)
		{

			case '1':
				Heal();
				break;

			case '2':
				ExploreHp();
				break;
		
			case '0':
				break;

			default:
				cout << "Not a valid option!" << endl;
				break;

		}

	}

}

void DarkLord()
{

char opt = '1';

	while (opt != '0')
	{
		Boss B;

		cout << "\n===================================" << endl;
		cout << "current location - DARK LORD'S LAIR" << endl;
		cout << "===================================" << endl;
		cout << "What would you like to do?\n" << endl;
		cout << "1. Battle" << endl;
		cout << "0. Turn Back" << endl;
		cout << "===================================" << endl;
		cin >> opt;

		switch(opt)
		{

			case '1':
				FinalFight(&B);
				break;
		
			case '0':
				break;

			default:
				cout << "Not a valid option!" << endl;
				break;

		}

	}	

}
void Fight(Creature *C)
{
	char opt = '1';

	while(opt != '2' && m_oPlayer.GetHealth() > 0 && C->GetHealth() >= 0)
	{
		
		cout << "\nYou have encountered a ";
		C->DisplayCreature();
		cout << "\n===================================" << endl;
		cout << "What would you like to do?" << endl;
		cout << "Your Health is: " << m_oPlayer.GetHealth() << "\n" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Run Away" << endl;
		cout << "===================================" << endl;
		cin >> opt;

		switch(opt)
		{

		case '1':

			if(dice.roll(1, 6) <= 3)
			{
				C->SetHealth(C->GetHealth() - m_oPlayer.GetDamage());
				//cout << "You inflicted " <<	m_oPlayer.GetDamage() << " Damage on the " << C->DisplayCreature() << endl;
			}
			else
			{
				cout << "Your attack has failed" << endl;
			}

			if(m_oPlayer.GetHealth() > 0 && C->GetHealth() <= 0)
			{
				m_oPlayer.SetXp(m_oPlayer.GetXp() + 5);
				cout << "You won the Battle and have gained 5 XP Points" << endl;
			}
			break;

		case '2':
			break;

		default:
			cout << "Not a valid option!" << endl;
			break;

		}

	}

}
void Heal()
{
	if(m_oPlayer.GetLevel() == 1)
		m_oPlayer.SetHealth(20);
	else
		m_oPlayer.SetHealth(40);

}
void ExploreHp()
{

	if(m_oPlayer.GetHealth() < 25 && m_oPlayer.GetLevel() == 1)
		m_oPlayer.SetHealth(m_oPlayer.GetHealth() + (rand() % 2));
	else if(m_oPlayer.GetHealth() < 50 && m_oPlayer.GetLevel() == 2)
		m_oPlayer.SetHealth(m_oPlayer.GetHealth() + (rand() % 2));
	else
		m_oPlayer.SetHealth(m_oPlayer.GetHealth() + 0);

	SaveGame();

}
void ExploreWild()
{

		int x = rand() % 5;

		switch(x)
			{
			case 0:
				if(m_oPlayer.GetAgility() < 20)
				{
					m_oPlayer.SetAgility(m_oPlayer.GetAgility() + 1);
					cout << "Your Agility went up! " << m_oPlayer.GetAgility() << endl;
					SaveGame();
				}
				else
				{
					m_oPlayer.SetAgility(m_oPlayer.GetAgility() + 0);
				}
				break;
			case 1:
				if(m_oPlayer.GetEndurance() < 20)
				{
					m_oPlayer.SetEndurance(m_oPlayer.GetEndurance() + 1);
					cout << "Your Endurance went up! " << m_oPlayer.GetEndurance() << endl;
					SaveGame();
				}
				else
				{
					m_oPlayer.SetEndurance(m_oPlayer.GetEndurance() + 0);
				}
				break;
			case 2:
				if(m_oPlayer.GetStrength() < 20)
				{
					m_oPlayer.SetStrength(m_oPlayer.GetStrength() + 1);
					cout << "Your Strength went up! " << m_oPlayer.GetStrength() << endl;
					SaveGame();
				}
				else
				{
					m_oPlayer.SetStrength(m_oPlayer.GetStrength() + 0);
				}
				break;
			case 3:
				if(m_oPlayer.GetWisdom() < 20)
				{
					m_oPlayer.SetWisdom(m_oPlayer.GetWisdom() + 1);
					cout << "Your Wisdom went up! " << m_oPlayer.GetWisdom() << endl;
					SaveGame();
				}
				else
				{
					m_oPlayer.SetWisdom(m_oPlayer.GetWisdom() + 0);
				}
				break;
			case 4:
				m_oPlayer.SetAgility(m_oPlayer.GetAgility() + 0);
				break;
			case 5:
				m_oPlayer.SetAgility(m_oPlayer.GetAgility() + 0);
				break;
			default:
				m_oPlayer.SetAgility(m_oPlayer.GetAgility() + 0);
				break;

	}

}
void FinalFight(Boss *B)
{

	char opt = '1';

	while(opt != '2' && m_oPlayer.GetHealth() > 0 && B->GetHealth() >= 0)
	{
		
		cout << "\nYou have challenged the DarkLord";
		cout << "\n===================================" << endl;
		cout << "What would you like to do?" << endl;
		cout << "Your Health is: " << m_oPlayer.GetHealth() << "\n" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Run Away" << endl;
		cout << "===================================" << endl;
		cin >> opt;

		switch(opt)
		{

		case '1':

			if(dice.roll(1, 6) <= 3)
			{
				B->SetHealth(B->GetHealth() - m_oPlayer.GetDamage());
				cout << "You inflicted " <<	m_oPlayer.GetDamage() << " Damage on the DarkLord!" << endl;
			}
			else
			{
				cout << "Your attack has failed" << endl;
			}

			if(m_oPlayer.GetHealth() > 0 && B->GetHealth() <= 0)
			{
				m_oPlayer.SetXp(m_oPlayer.GetXp() + 5);
				cout << "You won the final fight and have completed the game" << endl;
			}
			break;

		case '2':
			break;

		default:
			cout << "Not a valid option!" << endl;
			break;

		}

	}

}