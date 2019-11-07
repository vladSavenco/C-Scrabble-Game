#include "SBoard.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "wordList.h"
#include "LetterList.h"

using namespace std;

LetterList LL;

void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct cell
{
	char character = 254;
	int colour = 0;
	int multAmmount = 1;
};

struct cell cl[15][15];

SBoard::SBoard()
{
}

//Function that asks the player to input either down or right and checks if the player gave the correct value.

string rightDown()
{
	string direction;
	cout << "Please input the direction you wish your word to go: Right or Down" << endl;
	cin >> direction;
	
	while ((direction != "right") && (direction != "down"))
	{
		cout << "Please try again, thank you:";
		cin >> direction;
		cout << endl;
	}

	return direction;
}

//Function that reads the collour and multiplier ammount of each tile from file.

void SBoard::read()
{
	std::ifstream boardFile;
	boardFile.open("BoardFile.txt");

	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j <= 14; j++)
		{
			boardFile >> cl[i][j].colour;
			boardFile >> cl[i][j].multAmmount;
			//std::cout << cl[i][j].colour << ' ';
			//std::cout << cl[i][j].multAmmount << std::endl;
		}
	}
}

//Function that prints the scrabble board.

void SBoard::print()
{
	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j <= 14; j++)
		{
			int col = cl[i][j].colour;
			Color(col);
			std::cout << cl[i][j].character << ' ';
		}
		std::cout << std::endl;
		Color(15);
	}
}

//Function that returns the value of each letter.

int LValue(char l, int val)
{
	int value=0;

	if (strchr("aeioulnstr", l))
	{
		value = 1;
	}
	if (strchr("dg", l))
	{
		value = 2;
	}
	if (strchr("bcmp",l))
	{
		value = 3;
	}
	if (strchr("fhvwy", l))
	{
		value = 4;
	}
	if (strchr("k", l))
	{
		value = 5;
	}
	if (strchr("jx", l))
	{
		value = 8;
	}
	if (strchr("qz", l))
	{
		value = 10;
	}

	if (val == 11)
		value = value * 2;
	if (val == 9)
		value = value * 3;

	return value;

}

string Pword()
{
	string word;

	cout << "Please input your word, thank you:";

	cin >> word;

	while (LL.checkForLetters(word) == false)
	{
		cout << "You do not have the letters to make this word, please choose another word:";
		cin >> word;
	}
	return word;
}

int checkProximity(string word, string direction, int m, int n)
{
	int len = word.length(),ok=0;
	if (direction == "right")
	{
			for (int j = n; j <= n+len; j++)
			{
				if (cl[m][j].character != 254 )
				{
					ok = 1;
					cout << "found right on top" << endl;
				}
				if (cl[m - 1][j].character != 254)
					{
						ok = 1;
						cout << "found right above" << endl;
					}
				if (cl[m + 1][j].character != 254)
						{
							ok = 1;
							cout << "found right under" << endl;
						}
			}
		if (cl[m][n - 1].character != 254 || cl[m][n + len-1].character != 254)
		{
			ok = 1;
			cout << "found right 2" << endl;
		}
	}
	if (direction == "down")
	{
		for (int i = n; i <= n; i++)
		{
			for (int j = m; j <= m+len; j++)
			{
				if (cl[j][i].character != 254 || cl[j - 1][i].character != 254 || cl[j + 1][i].character != 254)
				{
					ok = 1;
					cout << "found left 1" << endl;
				}
				else
				{
					cout << "nothing found" << endl;
				}
			}
		}
		if (cl[m-1][n].character != 254 || cl[m + len-1][n].character != 254)
		{
			ok = 1;
			cout << "found left 2" << endl;
		}
	}

	return ok;
}

//Function that asks player to input coordinates, then checks if there can be placed a word there,

int SBoard::inputCoordinates(string word, string direction)
{
	int x, y, value = 0;

	cout << "Please input the x axys:" << endl;
	cin >> x;
	cout << "Please input the y axis:" << endl;
	cin >> y;

	if (checkProximity(word, direction, x, y) != 1)
	{
		cout << "Please input other coordinates:" << endl;

		inputCoordinates(word, direction);
	}
	else
	{
		value = addWord(word, x, y, direction);
	}

	return value;
}

//Function that adds a given word starting at given cooordinates, towards given direction.

int SBoard::addWord(string word, int m, int n, string direction)
{
	int nr = 0, wordValue=0, multiplier=1,ok=0;
	if (direction == "right")
	{
		if (15 - (n) >= word.size())
		{
			for (int i = m; i <= 14 && ok == 0; i++)
			{
				for (int j = n; j <= 14 && ok==0; j++)
				{
					if (nr == word.size()-1)
						ok = 1;
					cl[i][j].character = word[nr];
					wordValue = wordValue + LValue(cl[i][j].character, cl[i][j].colour);
					LL.removeLetters(word[nr]);
					nr++;
					if (cl[i][j].colour == 12)
						multiplier = multiplier * 3;
					if (cl[i][j].colour == 13)
						multiplier = multiplier * 2;
				}
			}
		}
	}

	if (direction == "down")
	{
		if (15 - (m) >= word.size())
		{
			for (int i = n; i <= 14 && ok == 0; i++)
			{
				for (int j = m; j <= 14 && ok == 0; j++)
				{
					if (nr == word.size()-1)
						ok = 1;
					cl[j][i].character = word[nr];
					wordValue = wordValue + LValue(cl[j][i].character, cl[j][i].colour);
					LL.removeLetters(word[nr]);
					nr++;
					if (cl[j][i].colour == 12)
						multiplier = multiplier * 3;
					if (cl[j][i].colour == 13)
						multiplier = multiplier * 2;
				}
			}
		}
	}

	wordValue = wordValue * multiplier;
	return wordValue;
}

//Function that only asks for a word and direction from the player then places the word at the middle coordinates.

int SBoard::firstWord()
{
	int value=0;

	std::string word, direction;

	word = Pword();

	direction = rightDown();

	value=addWord(word, 7, 7, direction);

	return value;
}

//Function that asks for a word, direction and coordinates from the player then places the word.

int SBoard::pAddWord()
{
	int value = 0;

	std::string word, direction;

	word = Pword();

	direction = rightDown();

	value=inputCoordinates(word, direction);

	return value;
}