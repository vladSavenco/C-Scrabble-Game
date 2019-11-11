#include "LetterList.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime> 

using namespace std;

//letters available;

struct letters
{
	char letter='0';
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
	int ok = 0;

	for (int i = 0; i <= 26; i++)
	{
		if (Lt[i].number > 0)
			ok = 1;
	}
	return ok;
}

int LetterList::checkForLetters(string word)
{
	struct pLetters pLs[7];

	int ok,let=0,i,j;

	for (i = 0; i <= 6; i++)
	{
		pLs[i].letter = pLt[i].letter;
	}

	for (i = 0; i <= word.size() - 1; i++)
	{
		ok = 0;
		for (j = 0; j <= 6 && ok==0; j++)
		{
			if (word[i] == pLs[j].letter)
			{
				ok = 1;
				pLs[j].letter = '0';
				cout << "removing:" << word[i] << endl;
				word[i] = '0';
			}
		}
	}

	for (i = 0; i <= word.size() - 1; i++)
	{
		ok = 0;
		for (j = 0; j <= 6 && ok == 0; j++)
		{
			if (word[i] != '0' && pLs[j].letter == '#')
			{
				ok = 1;
				pLs[j].letter = '0';
				cout << "removing:" << word[i] << endl;
				word[i] = '0';
			}
		}
	}

	for (i = 0; i <= word.size() - 1; i++)
	{
		if (word[i] != '0')
			let = 1;
	}

	if (let == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

LetterList::LetterList()
{
	
}