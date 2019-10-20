// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <string>
#include "SBoard.h"
#include "WordList.h"

using namespace std;

int main() 
{
	int value;

	SBoard SB;
	SB.read();
	SB.print();

	WordList WL;

	system("CLS");

	value=SB.firstWord();
	SB.print();

	cout << endl << value;

	return 0;
}
