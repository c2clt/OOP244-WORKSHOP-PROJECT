// OOP244 Workshop 5-Diy: Operator Overloading
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
const int TYPE_SIZE = 6;

namespace sdds {
	class Ship {
		char* type_ship;
		Engine* engs;		
		int num_engs;

	public:
		Ship();
		Ship(const char* type, Engine engsArr[], int len_engsArr);
		void setEmpty();
		void set(const char* type, Engine engsArr[], int len_engsArr);
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