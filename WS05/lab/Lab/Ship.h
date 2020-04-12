// OOP244 Workshop 5-Lab: Operator Overloading
// File: Ship.h
// Date: 2/11/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file define class Ship
// data members and member function prototypes
/////////////////////////////////////////////

#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__

#include "Engine.h"
using namespace std;
const int MAX_ENGS = 10;
const int TYPE_SIZE = 6;

namespace sdds {
	class Ship {
		char type_ship[TYPE_SIZE + 1];
		Engine engs[MAX_ENGS];		
		int num_engs;

	public:
		Ship();
		Ship(const char* type, Engine engines[], int size_engines);
		void setEmpty();
		void set(const char* type, Engine engines[], int size_engines);
		bool empty() const;
		float calculatePower() const;
		void display() const;
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship& ship1, const Ship& ship2);
		~Ship();
	};
	bool operator<(const Ship& ship, double power);
	
}
#endif