/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory & Function Overloading 
// Name: Jingmin Zhou (Jessica)
// Email: jzhou175@myseneca.ca
// ID: 119766194
// Date: Jan. 22nd 2020
***********************************************************************/

/* GiftMain.cpp:
    utilizing the Gift structure and gifting functions;
    dymamic memory allocation and deallocation for defined Gift array.
*/
#include <iostream>
#include "Gift.h"
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {

    int numberOfGifts = 0; 

    Gift* giftArr = nullptr;
  
    cout << "Enter number of Gifts to allocate: ";
    cin >> numberOfGifts;

    if (numberOfGifts < 1) {

        return 1;

    }
    giftArr = new Gift[numberOfGifts];
  
    for (int i = 0; i < numberOfGifts; ++i) {

        cout << "Gift #" << i + 1 << ": " << endl;
        gifting(giftArr[i].g_description);
	
        cin.ignore(2000,'\n'); 

        gifting(giftArr[i].g_price);
	
        cin.ignore(2000,'\n'); 

        gifting(giftArr[i].g_units);

	    cin.ignore(2000, '\n');

        cout << endl;

    }

    for (int i = 0; i < numberOfGifts; i++) {

        cout << "Gift #" << i + 1 << ": " << endl;
        display(giftArr[i]);
        cout << endl;

    }
  
    delete[] giftArr;
    giftArr = nullptr;

    return 0;

}