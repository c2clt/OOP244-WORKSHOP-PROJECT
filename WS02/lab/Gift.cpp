/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading
// Name: Jingmin Zhou (Jessica)
// Email: jzhou175@myseneca.ca
// ID: 119766194
// Date: Jan. 22nd 2020
***********************************************************************/

/* Gift.cpp:
	definition of the gifting functions declared in Gift.h
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

	}

	// get gift's price
	void gifting(double& g_price) {

		int invalid;
		do {
			invalid = 0;
			cout << "Enter gift price: ";
			cin >> g_price;

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
	
	}

}