// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <windows.h>

using namespace std;

bool check(string word)
{
	for (std::string::size_type i = 0; i < word.size(); ++i)
	{
		if (strchr("abcdefghijklmnopqrstuvwxyz", word[i]))
		{
		}
		else
			return false;
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

void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct cell
{
	char character='0';
	int colour=0;
	int multAmmount=1;
}cl;

ifstream File;
ifstream boardFile;

int main() 
{
	int nr=0,m=15;
	string word;

	struct cell cl[15][15];

	typedef vector< tuple<string, int> > my_tuple;
	my_tuple List0;

	File.open("words.txt");
	boardFile.open("BoardFile.txt");

	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j <=14; j++)
		{
			boardFile >> cl[i][j].colour;
			boardFile >> cl[i][j].multAmmount;
		}
	}


	for (int i = 0; i <=14; i++)
	{
		for (int j = 0; j <= 14; j++)
		{
			int col = cl[i][j].colour;
			Color(col);
			cout << cl[i][j].character<<' ';
		}
		cout << endl;
		Color(15);
	}

	/*for (int i = 0; i <= 14 ; i++)
	{
		for (int j = 0; j <= 14; j++)
		{
			cout << cl[i][j].colour<<' ';
			cout << cl[i][j].multAmmount<<"     ";
		}
		cout << endl;
	}*/

	/*while (File >> word)
	{
		if (check(word) == true)
		{
			List0.push_back(tuple<string, int>(word, value(word)));
			nr++;
		}
	}*/

	/*for (my_tuple::const_iterator i = List0.begin(); i != List0.end(); ++i) 
	{
		cout << get<0>(*i) <<' ';
		cout << get<1>(*i) << endl;
	}*/

	cout << nr;

	File.close();

	return 0;
}
