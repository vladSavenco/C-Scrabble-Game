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

//Function that takes a number as an input and changes the colour of the output text.

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

int checkValue(int m, int n, string word, string direction)
{
	int nr = 0, wordValue = 0, multiplier = 1, ok = 0;
	if (direction == "right")
	{
		for (int i = m; i <= 14 && ok == 0; i++)
		{
			for (int j = n; j <= 14 && ok == 0; j++)
			{
				if (nr == word.size() - 1)
					ok = 1;
				wordValue = wordValue + LValue(cl[i][j].character, cl[i][j].colour);
				nr++;
				if (cl[i][j].colour == 12)
					multiplier = multiplier * 3;
				if (cl[i][j].colour == 13)
					multiplier = multiplier * 2;
			}
		}
	}

	if (direction == "down")
	{
		for (int i = n; i <= 14 && ok == 0; i++)
		{
			for (int j = m; j <= 14 && ok == 0; j++)
			{
				if (nr == word.size() - 1)
					ok = 1;
				wordValue = wordValue + LValue(cl[j][i].character, cl[j][i].colour);
				nr++;
				if (cl[j][i].colour == 12)
					multiplier = multiplier * 3;
				if (cl[j][i].colour == 13)
					multiplier = multiplier * 2;
			}
		}
	}

	wordValue = wordValue * multiplier;
	return wordValue;
}

int findWords(int x,int y, string direction)
{
	string word;
	int nr=0,val=0;

	if (direction == "right")
	{
		int i = x-1;

		while (cl[i][y].character > 96 && cl[i][y].character < 123 && i!=0)
		{
			i = i - 1;
		}
		x = i+1;
		for (i; i <= 15; i++)
		{
			if (cl[i][y].character > 96 && cl[i][y].character < 123 && i != 0)
			{
				word = cl[i][y].character;
				nr++;
			}
		}

		//val=checkValue(x,y,word,direction);

	}

	if (direction == "down")
	{
		int i = y-1;

		while (cl[x][i].character > 96 && cl[x][i].character < 123 && i != 0)
		{
			i = i - 1;
		}
		y = i+1;
		for (i; i <= 15; i++)
		{
			if (cl[x][i].character > 96 && cl[x][i].character < 123 && i != 0)
			{
				word = cl[x][i].character;
				nr++;
			}
		}
		//val = checkValue(x, y, word, direction);
	}

	cout << endl<<"foud word" << word << endl;

	return val;

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
	int len = word.size(),ok=0;
	
	if (direction == "right")
	{
		for (int j = n; j <= n + len - 1; j++)
		{
			if (cl[m][j].character>96 && cl[m][j].character<123)
			{
				ok = 1;
				cout << "found it on";
			}

			if (cl[m-1][j].character > 96 && cl[m-1][j].character < 123 && m!=0)
			{
				ok = 1;
				cout << "found it above";
			}

			if (cl[m + 1][j].character > 96 && cl[m + 1][j].character < 123 && m!=14)
			{
				ok = 1;
				cout << "found it under";
			}
		}

		if (cl[m][n - 1].character>96 && cl[m][n - 1].character<123 && n != 0)
		{
			ok = 1;
			cout << "found it before or after spot";
		}
		if (cl[m][n+len].character > 96 && cl[m][n+len].character < 123 && n+len-1!=14)
		{
			ok = 1;
			cout << "found it before or after spot";
		}
	}


	if (direction == "down")
	{
		for (int j = m; j <= m + len - 1; j++)
		{
			if (cl[j][n].character > 96 && cl[j][n].character < 123)
			{
				ok = 1;
				cout << "found it on";
			}

			if (cl[j][n-1].character > 96 && cl[j][n-1].character < 123 && n != 0)
			{
				ok = 1;
				cout << "found it on the left";
			}

			if (cl[j][n+1].character > 96 && cl[j][n+1].character < 123 && n != 14)
			{
				ok = 1;
				cout << "found it on the right";
			}
		}

		if (cl[n-1][m].character > 96 && cl[n-1][m].character < 123 && m != 0)
		{
			ok = 1;
			cout << "found it before or after spot";
		}
		if (cl[n+len][m].character > 96 && cl[n+len][m].character < 123 && m + len - 1 != 14)
		{
			ok = 1;
			cout << "found it before or after spot";
		}
	}

	return ok;
}

//Function that adds a given word starting at given cooordinates, towards given direction.

int SBoard::addWord(string word, int m, int n, string direction)
{
	int nr = 0, ok = 0,val=0;
	if (direction == "right")
	{
		for (int i = m; i <= 14 && ok == 0; i++)
		{
			for (int j = n; j <= 14 && ok == 0; j++)
			{
				if (nr == word.size() - 1)
					ok = 1;
				cl[i][j].character = word[nr];
				LL.removeLetters(word[nr]);
				val = findWords(i, j, direction);
				nr++;
			}
		}
	}

	if (direction == "down")
	{
		for (int i = n; i <= 14 && ok == 0; i++)
		{
			for (int j = m; j <= 14 && ok == 0; j++)
			{
				if (nr == word.size() - 1)
					ok = 1;
				cl[j][i].character = word[nr];
				LL.removeLetters(word[nr]);
				val = findWords(i, j, direction);
				nr++;
			}
		}
	}

	return val;
}

//Function that asks player to input coordinates, then checks if there can be placed a word there,

int SBoard::inputCoordinates(string word, string direction)
{
	int x, y, value = 0,newVal=0;

	cout << "Please input the x axys:" << endl;
	cin >> x;
	cout << "Please input the y axis:" << endl;
	cin >> y;

	while (checkProximity(word, direction, x, y) == 0)
	{
		cout << "Please input other coordinates:" << endl;
		cout << "Please input the x axys:" << endl;
		cin >> x;
		cout << "Please input the y axis:" << endl;
		cin >> y;
	}

	newVal=addWord(word, x, y, direction);

	value = checkValue(x, y, word, direction);

	value = value + newVal;

	return value;
}

//Function that only asks for a word and direction from the player then places the word at the middle coordinates.

int SBoard::firstWord()
{
	int value=0;

	std::string word, direction;

	word = Pword();

	direction = rightDown();

	addWord(word, 7, 7, direction);

	value = checkValue(7, 7, word, direction);

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