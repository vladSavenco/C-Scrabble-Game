#ifndef WordList_H
#define WordList_H
#include <string>

class WordList
{
	public:
		WordList();
		bool checkWord(std::string word);
		void Run();
		bool LSearch(std::string word);
};
#endif
