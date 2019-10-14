#include "WordList.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <Windows.h>

using namespace std;

//creating a vector of tuples that save in each one a string and an int.

typedef vector< tuple<string, int> > my_tuple;
my_tuple List0;

//check if the word is legal by checking if the ascii code of each letter in the word is larger or equal with 97 and smaller or equal to 122 which are the ascii code of a and z.

bool check(std::string word)
{
	for (std::string::size_type i = 0; i < word.size(); ++i)
	{
		if (word[i] < 96 || word[i]>123)
		{
			return false;
		}
	}
	return true;
}

//gets the word value by adding up the value of each letter in the word.

int value(std::string word)
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

/*bool InterpolateSearch(my_tuple List0, string word)
{

}*/

WordList::WordList()
{
	int nr = 0, userScore = 0;
	string word;

	ifstream File;
	File.open("words.txt");

	while (File >> word)
	{
		if (check(word) == true)
		{
			List0.push_back(tuple<string, int>(word, value(word)));
			nr++;
		}
	}

	/*for (const auto& i : List0)
	{
		cout << get<0>(i) << " ";
		cout << get<1>(i) << endl;
	}*/

	cout << nr;

	File.close();
}
