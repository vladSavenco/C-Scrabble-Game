// Vlad_Catalin_Savenco_Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int main() {
	typedef vector< tuple<string, int> > my_tuple;
	my_tuple List0;
	List0.push_back(tuple<string, int>("John", 25));
	List0.push_back(tuple<string, int>("Ann", 25));
	List0.push_back(tuple<string, int>("Bob", 25));

	for (my_tuple::const_iterator i = List0.begin(); i != List0.end(); ++i) 
	{
		cout << get<0>(*i) <<' ';
		cout << get<1>(*i) << endl;
	}

	return 0;
}
