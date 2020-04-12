#ifndef SDDS_WORD_H__
#define SDDS_WORD_H__

#include "Tools.h"
const int MAX_WORD_LEN = 21;

namespace sdds {

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	void programTitle();

	void wordStats(bool logOn);	

	void addWord(Word words[], int* index, const char newWord[]);

	int searchWords(const Word words[], int num, const char word[]);

	void print(const Word* w, bool gotoNextLine);

	void sort(Word words[], int cnt);

	void report(const Word words[], int noOfWords, int longestWord);

	void swap(Word* p1, Word* p2);
}
#endif