// OOP244 Workshop 6: Class with a Resource
// File: BasketTester.cpp
// Date: 3/3/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file tests the Basket Module
/////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include"Basket.h"
#include"Basket.h" //intentional

using namespace std;
using namespace sdds;

int main(){

	cout << "---------------------------------------------" << endl;
	cout << "**** Basket default constructor ****" << endl;
	Basket b;
	cout << b;
	


	//checking input validity  3 argument constructor
	cout << "---------------------------------------------" << endl;
	cout << "**** Checking Input Validity (invalid) ****" << endl;

	Basket b1[] = { { "cherry", -2, 2.50 },
	{ "orange", 3, -5.50 },
	{ nullptr, 4, 6.50 }
	};

	for (int i = 0; i < 3; i++){

		cout << b1[i];
		
	}
	cout << "---------------------------------------------" << endl;

	cout << "**** Checking Input Validity (valid) ****" << endl;
	Basket b2("apple", 12, 20.50);
	Basket b3("banana", 14, 10.50);
	Basket b4("pears", 10, 12.50);
	cout << b2;
	cout << "---------------------------------------------" << endl;
	cout << b3;
    cout << "---------------------------------------------" << endl;
	cout << b4;
	cout << "---------------------------------------------" << endl;


	//copy constructor
	cout << "**** Validating copy constructor ****" << endl;
	Basket b5 = b3;
	cout << "A new basket of banana is created" << endl;
	cout << b5;
	cout << "---------------------------------------------" << endl;
	cout << b3;
	cout << "---------------------------------------------" << endl;
	
	//copy assignment operator
	cout << "**** Checking copy assignment operator ****" << endl;
	b2 = b4; 
	cout << b2;
	cout << "---------------------------------------------" << endl;
	cout << b4;
	cout << "---------------------------------------------" << endl;
	

	//checking identical 
    cout << "**** Basket comparing original and copy ****" << endl;
	if (b2 == b4) cout << "Both baskets are carrying the same fruits" << endl;
	else
		cout << "They are not same type of Baskets" << endl;
	cout << "---------------------------------------------" << endl;

	
	//Increasing the price of original
	cout << "Basket increasing the price of original" << endl;
	b4.addPrice(1.0);
	cout << b4;
	cout << "------------------------------------------------------------------" << endl;
	

	
	//After increasing price checking the identical again
	cout << "**** Basket comparing after increasing the price and quantity ****" << endl;

	if (b2 != b4) cout << "Baskets are not same" << endl;
	
	return 0;
}
