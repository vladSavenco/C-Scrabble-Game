#include "SBoard.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>

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

void SBoard::addWord(std::string word, int m, int n, std::string direction)
{
	if (direction == "right")
	{
		for (int i = 0; i <= 14; i++)
		{
			for (int j = 0; j <= 14; j++)
			{
				if (i == m && j == n)
				{
					
				}
			}
		}
	}
}