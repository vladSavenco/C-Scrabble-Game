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

//sorting algorithm.

void merge(int l, int m, int r)
{
	int i, j, k,size,halfSize;
	int n1 = m - l + 1;
	int n2 = r - m;

	// creating temporarry arrays.

	size = ln.size();
	halfSize = size/2;

	vector<line> L(ln.begin(), ln.begin() + halfSize);
	vector<line> R(ln.begin() + halfSize, ln.end());

	i = 0;
	j = 0;
	k = 0;

	while (i < n1 && j < n2)
	{
		if (L[i].word <= R[j].word)
		{
			ln[k].word = L[i].word;
			ln[k].value = L[i].value;
			i++;
		}
		else
		{
			ln[k].word = R[j].word;
			ln[k].value = R[j].value;
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		ln[k].word = L[i].word;
		ln[k].value = L[i].value;
		i++;
		k++;
	}

	while (j < n2)
	{
		ln[k].word = R[j].word;
		ln[k].value = R[j].value;
		j++;
		k++;
	}
}

void mergeSort(int l, int r)
{
	if (l < r)
	{

		int m = l + (r - 1) / 2;

		cout << m << " " << r<<endl;

		mergeSort(l, m);
		mergeSort(m + 1, r);

		merge(l, m, r);
	}
}

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

	mergeSort(0,ln.size()-1);

	/*for (int i=0;i<=ln.size()-1;i++)
	{
		cout << ln[i].word << " ";
		cout << ln[i].value << endl;
	}*/

	cout << nr<<endl;

	File.close();
}
