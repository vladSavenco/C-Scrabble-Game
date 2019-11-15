// Vlad_Catalin_Savenco_Scrabble

#include <iostream>
#include <string>
#include "SBoard.h"
#include "WordList.h"
#include "LetterList.h"
#include "RunGame.h"

using namespace std;

int main() 
{
	RunGame RG;
	LetterList LL;

	RG.RunG();

	RG.PlayerFirstMove();

	while (LL.checkPool() > 0)
	{
		RG.PlayerTurn();
	}

	cout << endl << "The End " << endl;
	cout << "Final Score:";
	RG.score();

	/*int value,pValue=0;

	SBoard SB;
	SB.read();
	SB.print();

	WordList WL;
	WL.Run();

	LetterList LL;

	LL.readLetters();
	LL.checkLetters();
	LL.printLetters();

	value = SB.firstWord();

	//system("CLS");

	SB.print();

	pValue = pValue + value;

	cout << endl<<"Your score:" << pValue<<endl;

	while (LL.checkPool() > 0)
	{
		LL.readLetters();
		LL.checkLetters();
		LL.printLetters();

		value = SB.pAddWord();

		SB.print();

		pValue = pValue + value;

		cout << endl<<"Your Score:" << pValue<< endl;
	}

	return 0;*/
}
