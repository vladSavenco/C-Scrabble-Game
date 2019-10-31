// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <string>
#include "SBoard.h"
#include "WordList.h"
#include "LetterList.h"

using namespace std;

int main() 
{
	int value,pValue=0;

	SBoard SB;
	SB.read();
	SB.print();

	WordList WL;
	LetterList LL;

	LL.readLetters();
	LL.checkLetters();
	LL.printLetters();

	value = SB.firstWord();

	system("CLS");

	SB.print();

	pValue = pValue + value;

	cout << endl<<"Your score:" << pValue<<endl;

	while (LL.checkPool() > 0)
	{
		LL.readLetters();
		LL.checkLetters();
		LL.printLetters();

		value = SB.pAddWord();

		system("CLS");

		SB.print();

		pValue = pValue + value;

		cout << endl<<"Your Score:" << pValue<< endl;
	}

	return 0;
}
