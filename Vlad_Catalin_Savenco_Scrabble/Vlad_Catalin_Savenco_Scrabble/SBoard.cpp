#include "SBoard.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "wordList.h"

using namespace std;

void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct cell
{
	char character = '0';
	int colour = 0;
	int multAmmount = 1;
};

struct cell cl[15][15];

SBoard::SBoard()
{

}

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

int SBoard::addWord(std::string word, int m, int n, std::string direction)
{
	int nr = 0, wordValue=0, multiplier=1,ok=0;
	if (direction == "right")
	{
		if (15 - (n + 1) >= word.size())
		{
			for (int i = m; i <= 14 && ok == 0; i++)
			{
				for (int j = n; j <= 14 && ok==0; j++)
				{
					if (nr == word.size()-1)
						ok = 1;
					cl[i][j].character = word[nr];
					wordValue = wordValue + LValue(cl[i][j].character, cl[i][j].colour);
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
		if (15 - (m + 1) >= word.size())
		{
			for (int j = m; j <= 14 && ok==0; j++)
			{
				for (int i = n; i <= 14 && ok==0; i++)
				{
					if (nr == word.size()-1)
						ok = 1;
					cl[i][j].character = word[nr];
					wordValue = wordValue + LValue(cl[i][j].character, cl[i][j].colour);
					nr++;
					if (cl[i][j].colour == 12)
						multiplier = multiplier * 3;
					if (cl[i][j].colour == 13)
						multiplier = multiplier * 2;
				}
			}
		}
	}
	wordValue = wordValue * multiplier;
	return wordValue;
}

int SBoard::firstWord()
{
	int value=0;

	std::string word, direction;
	cout << "write your word" << endl;
	cin >> word;
	cout << "down or right?" << endl;
	cin >> direction;

	value=addWord(word, 7, 7, direction);

	return value;
}