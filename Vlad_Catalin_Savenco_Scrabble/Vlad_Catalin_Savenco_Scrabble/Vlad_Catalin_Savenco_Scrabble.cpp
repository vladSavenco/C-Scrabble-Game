// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <fstream>

using namespace std;

ifstream File;

bool check(string word)
{
	for (std::string::size_type i = 0; i < word.size(); ++i)
	{
		if (strchr("abcdefghijklmnopqrstuvwxyz", word[i]) == 0)
		{
			return false;
		}
	}
	return true;
}

bool value(string word)
{
	return true;
}

int main() 
{
	int nr=0;
	string word;

	typedef vector< tuple<string, int> > my_tuple;
	my_tuple List0;

	File.open("words.txt");

	while (File >> word)
	{
		if (check(word) == true)
		{
			List0.push_back(tuple<string, int>(word, 15));
			nr++;
		}
	}

	for (my_tuple::const_iterator i = List0.begin(); i != List0.end(); ++i) 
	{
		cout << get<0>(*i) <<' ';
		cout << get<1>(*i) << endl;
	}

	cout << nr;

	return 0;
}
