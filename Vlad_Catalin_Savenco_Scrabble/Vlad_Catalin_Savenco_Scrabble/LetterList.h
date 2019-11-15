#ifndef LetterList_H
#define LetterList_H
#include <string>

using namespace std;

class LetterList
{
	public:
		LetterList();
		void checkLetters();
		void printLetters();
		void removeLetters(char Let);
		void readLetters();
		int checkPool();
		int checkForLetters(string word, string LetList);
		void resetHand();
};
#endif
