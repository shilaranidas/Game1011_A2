// Game1011_A2_Das.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int userInput = 0;
int playerLocaaiton = 0;
int ReadAndPrint(const char* filename);
void Game();
void chooseClass();
void Intro();
void gameStart();
void Game();
void gameOver();
void story();
void quest();
int main()
{
	ReadAndPrint("GameStory.txt");
	system("pause");
	system("cls");
	Game();
}
int ReadAndPrint(const char* filename)
{
	ifstream myFileStream;
	myFileStream.open(filename);

	if (!myFileStream.is_open())
	{
		char errorMessage[256];
		strerror_s(errorMessage, errno);
		cerr << "Failed to open file: " << filename << ": " << errorMessage;
		return -1;
	}

	const int MAX_CHARS_PER_LINE = 256;
	while (!myFileStream.eof())
	{
		char lineContents[MAX_CHARS_PER_LINE];
		myFileStream.getline(lineContents, MAX_CHARS_PER_LINE);

		if (myFileStream.fail())
		{
			cerr << "Error: something went wrong reading line by line in file: " << filename;
			return -2;
		}

		cout << lineContents << endl;
	}

	return 0;
}
void chooseClass()//user input for class they want to be
{
	int classChoice = 0;
	cout << "What is your playstyle?\n\n";
	cout << "1 Warrior -balanced/higher damage\n";
	cout << "2 wizard -magic specialist\n";
	cout << "3 mage -support\n";
	cout << "\n>\t";
	while (!(cin >> classChoice) || classChoice < 1 || classChoice>3)
	{
		cout << "Invalid variable. must be in range of asked choice\n";
		cin.clear();
		cin.ignore(100, '\n');
	}
	switch (classChoice)
	{
	case 1:
		cout << "the warrior is born not made, he knows that his soul purpose in life is to serve and fight.\n";
		break;
	case 2:
		cout << "wizard. beware of this magic as it could be dangerous if not trained properly\n";
		break;
	case 3:
		cout << "a mage specialise inn magic of healin and curing\n";
		break;
	default:
		cout << "you are doing wrong! press either 1 or 2 or 3\n";
		break;
	}
	system("pause");
	system("cls");
	story();
}
void Intro()//user input name
{
	system("color 3");
	cout << "Enter your last name\n";
	string name;
	cin >> name;
	chooseClass();
}
void gameStart()
{
	cout << "*************************************************************\n";
	cout << "**********The eternal dream to hell**************************\n";
	cout << "*************************************************************\n";

	system("pause");
	system("cls");
	Intro();
}
void Game()//main menu in game
{
	cout << "**********************************************\n";
	cout << "*********WELCOME TO THE GAME******************\n";
	cout << "**********1 PLAY**************************\n";
	cout << "**********2 END**************************\n";
	cout << "**********************************************\n";
	cout << "**********************************************\n";
	cout << "\n\n>\t";
	while (!(cin >> userInput) || userInput < 1 || userInput>3)
	{
		cout << "Invalid variable. must be in range of asked choice\n";
		cin.clear();
		cin.ignore(100, '\n');
	}
	if (userInput == 1)
	{
		//create a new game
		system("cls");
		gameStart();
	}
	else
	{
		system("cls");
		gameOver();
	}
}
void story()
{
	cout << "you are awake from your dream in hospital bed in a big city\n";
	cout << "as you walk out the door there are 2 routes you encounter\n";
	cout << "**********************************\n";
	cout << "1 go east\n";
	cout << "2 go west(recommended not to go this way) voice shouted by someone from the hospital.\n";
	cout << "3 you feeling sick, you decide to go back to hospital.\n";
	cout << "**********************************\n";
	cout << "\n>\t";
	int playerLocation = 0;
	while (!(cin >> playerLocation) || playerLocation < 1 || playerLocation>3)
	{
		cout << "Invalid variable. must be in range of asked choice\n";
		cin.clear();
		cin.ignore(100, '\n');
	}
	if (playerLocation == 1)//east
	{
		system("cls");
		cout << "You go East and find yourself looking into long distance and see a car parked.\n";
		cout << "the car parked has keys hanging around and you are not in  the mood to walk\n";
		cout << "**********************************\n";
		cout << "1 pick up keys\n";
		cout << "2 ignore the scene and keep heading east.\n";
		cout << "**********************************\n";
		cout << "\n>\t";
		while (!(cin >> userInput) || userInput < 1 || userInput>3)
		{
			cout << "Invalid variable. must be in range of asked choice\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (userInput == 1)
		{
			cout << "you pick up keys.\n";
			cout << "you drive towards the end of the road where you fight a monster and uncover the truth and find out  you are in a dream and if you wake up you may die in reality.\n";
			cout << "if you finish your quest you reach the end goal.\n";
			cout << "you will live and will be returned back to your real world..\n";
			system("pause");
			system("cls");
			cout << "your quest begins here\n\n";
			quest();
		}
		else
		{
			cout << "1: you keep walking and exaust yourself and end up back to the hospital.\n";
			story();
		}
	}
	else if (playerLocation == 2) //west
	{
		system("cls");
		cout << "you go into the city and buy yourself some food \n as you are hungry. you buy fast food and eat 10 full meal\n";
		cout << "\n you have spend your life not knowing the truth and after a while you have died off in your old age \n at the hospital.";
		system("pause");
		system("cls");
		cout << "YOU have failed to fulfill you destiny and let the real world  to chaos as if was connected to dream \n with you\n";
		system("pause");
		system("cls");
		gameOver();
	}
	else if (playerLocation == 3) //bak hospital
	{
		system("cls");
		cout << "you go back in the hospital and take your time thinking and going over memories but are unable to picture the reality\n";

		cout << "YOU have chosen to go back to think about future steps\n";
		system("pause");
		system("cls");
		cout << "you are thinking about every moment of you life \n please  wait a moment as you think carefully what you plan ahead.\n";
		system("pause");
		system("cls");
		story();
	}
	else
	{
		cout << "you are doing it wrong! press either 1 or 2 or 3.";
	}
}
void quest()//quest for the user to input options and end of first ch
{
	system("cls");
	cout << "You reach a valley with giant gate with the guard guarding the gate.\n";
	cout << "what would you like to do ?\n";
	cout << "*****************************************************\n";
	cout << "1 Get the directions to find another route through the valley.\n";
	cout << "2 pay him to let you through these gates through the valley to find your own way to uncover mystries.\n";
	cout << "*****************************************************\n";
	cout << "Enter your choice: ";
	cout << "\n>\t";
	int path = 0;
	while (!(cin >> path) || path < 1 || path>3)
	{
		cout << "Invalid variable. must be in range of asked choice\n";
		cin.clear();
		cin.ignore(100, '\n');
	}
	if (path == 1)
	{
		system("cls");
		cout << "\n You: what way to the next city?\n";
		cout << "Guard: just follow the valley to the left. but beware of the monsters\n";
		cout << "you go and follow the valley and end up being attacked by several monsters and decide to fight back but your are\n";
		cout << "wounded and unconcious and the guard petrolling in the area find you and send you back to the hospital.\n";
		cout << "You end up back in hospital.\n";
	}
	else if (path == 2)
	{
		system("cls");
		cout << "You: \t I am going to find a way out!\n";
		cout << "Guard:\t you are insane. you will get killed out there.\n";
		cout << "You: \t I have my secrets and I know my way out. I want to know the truth and I will do whatever it takes to find out about this world.\n";
		cout << ">>You pay the guard some gold";
		cout << ">>The guard is distracted by the gold and start counting them\n";
		cout << ">>Meanwhile some where far away\n";
		cout << ">>Big explosion happens and guards go take a look leaving the gate opened.\n";
		cout << ">>You without thinking go through the gate across the valley\n";
		cout << ">>You are amazed as you find a new city with rich people and rich atmosphere.\n";
		cout << ">>A city you never imagined to ever see in a dream.";
		cout << ">>You entered the city and have ended your  first chapter. and are going into a whole new world.\n";
		system("pause");
		system("cls");
		cout << "TO BE CONTINUED\n\n";
		system("color e");
		cout << "*****************************************************\n";
		cout << "*************End of chapter one the eternal dream of hell****************************************\n";
		cout << "*****************************************************\n";

	}
}

void gameOver()
{
	system("color e");
	cout << "*****************************************************\n";
	cout << "***********************Game over******************************\n";
	cout << "*****************************************************\n";
	system("pause");
	system("cls");
	Game();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
