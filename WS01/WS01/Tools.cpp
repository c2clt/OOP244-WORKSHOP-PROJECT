#include <iostream>
#include <cctype>
#include "Tools.h"

using namespace std;

namespace sdds {
    void toLowerCaseAndAlphabeticCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        char lower;
        for (; source[i] != 0; i++) {
            lower = tolower(source[i]);
            if (lower >= 'a' && lower <= 'z') {
                des[j++] = tolower(source[i]);
            }
        }
        des[j] = 0;
    }

    void title() {
        cout << "Text word stats: " << endl;
        cout << "Word: No of  occurrences." << endl << "------------------------------------------------" << endl;
    }

    void endList() {
        cout << "------------------------------------------------" << endl;
    }

    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord) {
        cout << "Total number of words used: " << totNoWrds << endl;
        cout << "Total number of words overall: " << totalOverAll << endl;
        cout << "Longest word used had " << longestWord << " characters." << endl;
    }
}
