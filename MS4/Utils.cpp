#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>
#include "Utils.h"

namespace sdds {
	char* toUpper(char* str) {
		for (int i = 0; str[i] != '\0'; i++) {
			str[i] = toupper(str[i]);
		}

		return str;
	}

	bool strICmp(const char* str1, const char* str2) {
		bool res = false;

		int size1 = strlen(str1);
		int size2 = strlen(str2);
		if (size1 == size2) {
			char* tmp1 = new char[size1 + 1];
			strcpy(tmp1, str1);
			toUpper(tmp1);
			char* tmp2 = new char[size1 + 1];
			strcpy(tmp2, str2);
			toUpper(tmp2);
			if (strcmp(tmp1, tmp2) == 0) {
				res = true;
			}
			delete[] tmp1;
			tmp1 = nullptr;
			delete[] tmp2;
			tmp2 = nullptr;
		}
		
		return res;
	}
}