/* Citation and Sources...
Final Project Milestone 6
Module: Utils module
Filename: Vehicle.cpp
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  implementation of the Vehicle Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
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

	bool yes() {
		std::string option;
		bool res, valid;
		do {
			valid = true;
			std::cin >> option;
			std::cin.ignore(1000, '\n');

			if (option == "Y" || option == "y") {
				res = true;
			}
			else if (option == "N" || option == "n") {
				res = false;
			}
			else {
				std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				valid = false;
				std::cin.clear();
			}
		} while (!valid);

		return res;
	}
}