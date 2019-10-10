#ifndef SBoard_H
#define SBoard_H
#include <string>

class SBoard
{
	public:
		SBoard();
		void read();
		void print();
		void addWord(std::string word,int m,int n, std::string direction);
};

#endif
