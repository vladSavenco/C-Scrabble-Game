#include "WordList.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>
#include <Windows.h>

using namespace std;

//creating a vector of structs that save in each one a string and an int.

struct line
{
	string word=" ";
	int value = 0;;
};

vector<line>ln;

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
		if (strchr("jx", word[i]))
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

//sorting algorithm ?.

/*void quickSort(vector<line>lm, int left, int right)
{
	if (left < right)
	{
		int m = (left + right) / 2;

		string aux1 = lm[left].word;
		int aux2 = lm[left].value;

		lm[left].word = lm[m].word;
		lm[left].value = lm[m].value;

		lm[m].word = aux1;
		lm[m].value = aux2;

		int i = left, j = right, d = 0;

		while (i < j)
		{
			if (lm[i].word > lm[j].word)
			{
				aux1 = lm[i].word;
				aux2 = lm[i].value;

				lm[i].word = lm[j].word;
				lm[i].value = lm[j].value;

				lm[j].word = aux1;
				lm[j].value = aux2;

				d = 1 - d;
			}
			i += d;
			j -= 1 - d;

		}
		quickSort(lm, left, i - 1);
		quickSort(lm, i + 1, right);
	}
}*/

//binary search algorith that checks if the 

bool binSearch(vector<line>lm,int l,int r,string word)
{
	if (r > l)
	{
		int mid = l + (r - l) / 2;
		if (lm[mid].word == word)
		{
			return true;
		}
		if (lm[mid].word > word)
		{
			return binSearch(lm, l, mid - 1, word);
		}
		return binSearch(lm, mid + 1, r, word);
	}

	return false;
}

bool WordList::checkWord(string word)
{
	return binSearch(ln, 0, ln.size() - 1, word);
}

WordList::WordList()
{
	int nr = 0, userScore = 0;
	string word;

	ifstream File;
	File.open("words.txt");

	int m = 0;

	while (File >> word)
	{
		if (check(word) == true)
		{
			ln.push_back(line());
			ln[m].word = word;
			ln[m].value = value(word);
			m++;
			nr++;
		}
	}

	/*for (int i=0;i<=ln.size()-1;i++)
	{
		cout << ln[i].word << " ";
		cout << ln[i].value << endl;
	}*/

	cout << nr;

	File.close();
}
