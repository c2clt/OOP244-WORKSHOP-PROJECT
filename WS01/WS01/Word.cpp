#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Word.h"

using namespace std;

const int MAX_NO_OF_WORDS = 500;

namespace sdds {
    
    void programTitle() {
        cout <<
            "This program reads a text file from the standard input and analyzes and reports" << endl <<
            "the number of words and their occurrences in the text file." << endl;
    }

    void wordStats(bool logOn) {
        Word words[MAX_NO_OF_WORDS] = { {"",0} };
        char word[MAX_WORD_LEN];
        char lowerCaseWord[MAX_WORD_LEN];
        int NoOfWords = 0;
        int maxLen = 0;
        int foundIndex = 0;
        while (!cin.fail()) {
            cin >> word;
            toLowerCaseAndAlphabeticCopy(lowerCaseWord, word);
            if (lowerCaseWord[0] != 0) {
                if (maxLen < (int)strlen(lowerCaseWord)) {
                    maxLen = strlen(lowerCaseWord);
                }
                if (NoOfWords == 0) {
                    addWord(words, &NoOfWords, lowerCaseWord);
                }
                else {
                    foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
                    if (foundIndex < 0) { // word not found in list; so word is new and never read before
                        foundIndex = NoOfWords;
                        addWord(words, &NoOfWords, lowerCaseWord);
                    }
                    else {
                        words[foundIndex].count++;
                    }
                }
                if (logOn) {
                    print(&words[foundIndex], false);
                    cout << " read so far." << endl;
                }
            }
        }
        cout << "---------------------------------------------------" << endl << "End of data" << endl << "---------------------------------------------------" << endl;
        cout << "Sorting data " << endl;
        sort(words, NoOfWords);
        cout << "Sort ended" << endl;
        report(words, NoOfWords, maxLen);
    }

    void addWord(Word words[], int* index, const char newWord[]) {
        strcpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    int searchWords(const Word words[], int num, const char word[]) {
        int i;
        int foundIndex = -1;  // will be set to found index; if not found sould be less than 0
        for (i = 0; foundIndex == -1 && i < num; i++) { // while not found and i is less than number of words
            if (strcmp(words[i].letters, word) == 0) { // if word is already read and found in the list of previous words
                foundIndex = i;   // set the index to be returned.
            }
        }
        return foundIndex;
    }

    void print(const Word* w, bool gotoNextLine) {
        cout << w->letters << ": " << w->count;
        if (gotoNextLine) cout << endl;
    }

    void sort(Word words[], int cnt) {
        int i, j;
        for (i = 0; i < cnt - 1; i++) {
            for (j = 0; j < cnt - i - 1; j++) {
                if (strcmp(words[j].letters, words[j + 1].letters) > 0) {
                    swap(&words[j], &words[j + 1]);
                }
            }
        }
    }

    void report(const Word words[], int noOfWords, int longestWord) {
        int i;
        int total;
        title();
        for (total = 0, i = 0; i < noOfWords; i++) {
            print(&words[i], true);
            total += words[i].count;
        }
        endList();
        totalWordsStat(noOfWords, total, longestWord);
    }

    void swap(Word* p1, Word* p2) {
        Word w;
        w = *p1;
        *p1 = *p2;
        *p2 = w;
    }
}
