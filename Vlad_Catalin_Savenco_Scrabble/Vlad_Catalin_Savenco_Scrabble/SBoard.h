#ifndef SBoard_H
#define SBoard_H
#include <string>

class SBoard
{
	public:
		SBoard();
		void read();
		void print();
		int addWord(std::string word,int m,int n, std::string direction);
		int firstWord();
		int addWord();
};

#endif
