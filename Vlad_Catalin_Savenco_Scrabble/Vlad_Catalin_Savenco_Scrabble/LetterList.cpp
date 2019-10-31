#include "LetterList.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime> 
#include <random>

using namespace std;

//letters available;

struct letters
{
	char letter;
	int number=0;
};

struct letters Lt[27];

//letters in player's hand;

struct pLetters
{
	char letter='0';
};

struct pLetters pLt[7];

//get a random number;

int random()
{

	int rNum;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 26);

	rNum = dist(rng);

	if (Lt[rNum].number == 0)
	{
		return random();
	}
	else
	{

		return rNum;
	}
}

//add letters to player hand;

void LetterList::checkLetters()
{
	for (int i = 0; i <= 6; i++)
	{
		if (pLt[i].letter == '0')
		{
			int val;
			val = random();
			pLt[i].letter = Lt[val].letter;
			Lt[val].number = Lt[val].number - 1;
		}
	}
}

void LetterList::printLetters()
{
	cout << "Available letters: ";
	for (int i = 0; i <= 6; i++)
		cout << pLt[i].letter << " ";
	cout << endl;
}

void LetterList::removeLetters(char Let)
{
	int ok = 0;

		for (int j = 0; j <= 6; j++)
		{
			if (pLt[j].letter ==Let)
			{
				pLt[j].letter = '0';
				ok = 1;
			}
		}

		if (ok == 0)
		{
			for (int j = 0; j <= 6; j++)
			{
				if (pLt[j].letter == '#')
				{
					pLt[j].letter = '0';
				}
			}
		}

}

void LetterList::readLetters()
{
	std::ifstream lFile;
	lFile.open("LetterList.txt");

	for (int i = 0; i <= 26; i++)
	{
		lFile >> Lt[i].letter;
		lFile >> Lt[i].number;
	}
}

int LetterList::checkPool()
{
	for (int i = 0; i <= 26; i++)
	{
		int ok = 0;
		if (Lt[i].number > 0)
			ok = 1;
		return ok;
	}
}

int LetterList::checkForLetters(string word)
{
	/*int ok = 0,j,i;

	for (j = 0; j <= 6; j++)
	{
		for (i = 0; i <= word.size() - 1; i++)
		{
			if (word[i] == pLt[j].letter)
			{
				ok++;
				j++;
			}
		}
	}
	if (ok == word.length())
	{
		return 0;
	}
	else
	{
		return 1;
	}*/

	if (word.length() == 0)
		return 0;
	for (unsigned int i = 0; i < 7 - (word.length() - 1); ++i)
		if (pLt[i].letter == word[0])
		{
			bool matches = true;
			for (unsigned int j = 1; j < word.length(); ++j)
				if (pLt[i + j].letter != word[j])
				{
					matches = false;
					break;
				}
			if (matches)
				return 0;
		}

}

LetterList::LetterList()
{
	
}