#include <iostream>
#include "RunGame.h"
#include "SBoard.h"
#include "WordList.h"
#include "LetterList.h"

using namespace std;

int value=0, pValue = 0;


WordList WL1;
LetterList lL;
SBoard SB;

RunGame::RunGame()
{

}

//Function that builds the list of legal words.

void RunGame::RunG()
{
	WL1.Run();
}

//Function that gives the player his first turn.

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

//Function that handles the player's the other turns.

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

void RunGame::score()
{
	cout << pValue;
}