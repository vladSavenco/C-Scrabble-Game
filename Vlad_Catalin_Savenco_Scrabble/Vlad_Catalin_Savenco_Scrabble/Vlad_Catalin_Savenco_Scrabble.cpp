// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <string>
#include "SBoard.h"
#include "WordList.h"

using namespace std;

int main() 
{

	SBoard SB;
	SB.read();
	SB.print();

	WordList WL;

	string word;
	cin >> word;
	if (WL.checkWord(word) == true)
	{
		cout << "Found IT!";
	}
	else cout << "Not A Legal Word!!";

	//system("CLS");

	return 0;
}
