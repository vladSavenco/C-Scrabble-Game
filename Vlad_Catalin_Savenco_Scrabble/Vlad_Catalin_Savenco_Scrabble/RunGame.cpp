#include <iostream>
#include "RunGame.h"
#include "SBoard.h"
#include "WordList.h"
#include "LetterList.h"

using namespace std;

int value=0, pValue = 0;

RunGame::RunGame()
{

}

WordList WL;
LetterList lL;
SBoard SB;

void RunGame::PlayerTurn()
{
	lL.readLetters();
	lL.checkLetters();
	lL.printLetters();

	value = SB.pAddWord();

	SB.print();

	pValue = pValue + value;

	cout << endl << "Your Score:" << pValue << endl;
}

void RunGame::PlayerFirstMove()
{
	SB.read();
	SB.print();

	lL.readLetters();
	lL.checkLetters();
	lL.printLetters();

	value = SB.firstWord();

	system("CLS");

	SB.print();

	pValue = pValue + value;

	cout << endl << "Your score:" << pValue << endl;
}