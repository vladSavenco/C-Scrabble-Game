// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include "SBoard.h"

using namespace std;

bool check(string word)
{
	for (std::string::size_type i = 0; i < word.size(); ++i)
	{
		if (word[i]<96 || word[i]>123)
		{
			return false;
		}
	}
	return true;
}

int value(string word)
{
	int value = 0;
	for (std::string::size_type i = 0; i < word.size(); ++i)
	{
		if (strchr("aeioulnstr", word[i]))
		{
			value = value + 1;
		}
		if (strchr("dg", word[i]))
		{
			value = value + 2;
		}
		if (strchr("bcmp", word[i]))
		{
			value = value + 3;
		}
		if (strchr("fhvwy", word[i]))
		{
			value = value + 4;
		}
		if (strchr("k", word[i]))
		{
			value = value + 5;
		}
		if (strchr("ix", word[i]))
		{
			value = value + 8;
		}
		if (strchr("qz", word[i]))
		{
			value = value + 10;
		}
	}
	return value;
}


int main() 
{
	int nr = 0, userScore = 0;
	string word,InputWord;

	typedef vector< tuple<string, int> > my_tuple;
	my_tuple List0;

	ifstream File;
	File.open("words.txt");

	SBoard SB;
	SB.read();
	SB.print();

	while (File >> word)
	{
		if (check(word) == true)
		{
			List0.push_back(tuple<string, int>(word, value(word)));
			nr++;
		}
	}
	cout << nr;

	//system("CLS");

	File.close();
	return 0;
}
