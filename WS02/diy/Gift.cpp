/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// Email: jzhou175@myseneca.ca
// ID: 119766194
// Date: Jan. 22nd 2020
// DIY-OOP244 Workshop 2 (Dynamic Memory & Function Overloading)
***********************************************************************/

/* Gift.cpp:
	definition of the functions declared in Gift.h
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#include "Gift.h"

using namespace std;

namespace sdds {
	
	//get gift's description
	void gifting(char* g_description) {

		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> g_description;
		cin.ignore(2000, '\n');
	}

	// get gift's price
	void gifting(double& g_price) {

		int invalid;
		do {
			invalid = 0;
			cout << "Enter gift price: ";
			cin >> g_price;
			cin.ignore(2000, '\n');

			if (g_price < 0 || g_price > MAX_PRICE) {
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
				invalid = 1;
			}
		} while (invalid == 1);

	}

	// get gift's units
	void gifting(int& g_units) {

		int invalid;
		do {
			invalid = 0;
			cout << "Enter gift units: ";
			cin >> g_units;
			cin.ignore(2000, '\n');

			if (g_units < 1) {
				cout << "Gift units must be at least 1" << endl;
				invalid = 1;
			}
		} while (invalid == 1);

	}

	// display a given gift's details
	void display(const Gift& gift) {

		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.g_description << endl;
		cout << "Price: " << gift.g_price << endl;
		cout << "Units: " << gift.g_units << endl;
		if (gift.wrap == nullptr) {
			cout << "Unwrapped" << endl;
		}
		else {
			cout << "Wrap Layers: " << gift.wrap_layers << endl;

			for (int i = 0; i < gift.wrap_layers; i++) {
				cout << "Wrap #" << i + 1 << ": " << gift.wrap[i].pattern << endl;
			}
		}

	}

	// check if the wrapping of a given gift is successful or not.
	bool wrap(Gift& gift) {

		bool res;

		if (gift.wrap != nullptr) {

			cout << "Gift is already wrapped!" << endl;
			res = false;
		}
		else {
			cout << "Wrapping gifts..." << endl;
			int invalid;
			do {
				invalid = 0;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gift.wrap_layers;
				cin.ignore(2000, '\n');
				if (gift.wrap_layers < 1) {
					cout << "Layers at minimum must be 1, try again." << endl;
					invalid = 1;
				}			
			} while (invalid == 1);

			gift.wrap = new Wrapping[gift.wrap_layers];
			
			for (int i = 0; i < gift.wrap_layers; i++) {
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				gift.wrap[i].pattern = new char[MAXLEN_PATTERN + 1];
				cin >> gift.wrap[i].pattern;
				cin.ignore(2000, '\n');
			}

			res =  true;
		}

		return res;
	}

	// check if the unwrapping of a given gift is successful or not.
	bool unwrap(Gift& gift) {

		bool res;

		if (gift.wrap == nullptr) {

			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			res = false;
		}
		else {
			cout << "Gift being unwrapped." << endl;
			
			for (int i = 0; i < gift.wrap_layers; i++) {
				delete[] gift.wrap[i].pattern;
				gift.wrap[i].pattern = nullptr;
			}
			
			delete[] gift.wrap;
			gift.wrap = nullptr;
			gift.wrap_layers = 0;

			res = true;
		}

		return res;
	}

	// combine the previous gifting functions to set the gift’s description, price and units then attempt to wrap the gift.
	// calling this function to set all inforamtion of gift will make code clean and more readable.
	void gifting(Gift& gift) {
		cout << "Preparing a gift..." << endl;
		gifting(gift.g_description);
		gifting(gift.g_price);
		gifting(gift.g_units);
		wrap(gift);
	}

}