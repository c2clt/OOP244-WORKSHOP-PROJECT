// OOP244 Workshop 5-Lab: Operator Overloading
// File: Ship.cpp
// Date: 2/11/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implementates the member functions in Ship.h
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Ship.h"

namespace sdds {
	Ship::Ship() {
		setEmpty();
	}

	Ship::Ship(const char* type, Engine engines[], int len_engs) {
		set(type, engines, len_engs);
	}

	void Ship::setEmpty() {
		type_ship[0] = '\0';
		for (int i = 0; i < MAX_ENGS; i++) {
			engs[i] = Engine();
		}		
		num_engs = 0;
	}

	void Ship::set(const char* type, Engine engines[], int len_engs) {
		bool valid = type != nullptr && strlen(type) > 0 && strlen(type) <= 6 && len_engs > 0;
		if (valid) {
			strcpy(type_ship, type);
			num_engs = len_engs < MAX_ENGS ? len_engs : MAX_ENGS;
			for (int i = 0; i < num_engs; i++) {
				engs[i] = engines[i];
			}
		}
		else {
			setEmpty();
		}
	}

	bool Ship::empty() const {
		return type_ship[0] == '\0';
	}

	float Ship::calculatePower() const {
		float sumOfPower = 0;
		for (int i = 0; i < num_engs; i++) {
			sumOfPower += 5 * engs[i].get();
		}
		return sumOfPower;
	}
	 
	void Ship::display() const {
		if (!empty()) {
			cout << type_ship << "-";
			cout.setf(ios::fixed);
			cout.width(6);
			cout.precision(2);
			cout << calculatePower() << endl;
			for (int i = 0; i < num_engs; i++) {
				engs[i].display();
			}
		}
		else {
			cout << "No available data" << endl;
		}
	}

	Ship& Ship::operator+=(Engine e) {
		if (!empty() && num_engs < MAX_ENGS) {
			engs[num_engs] = e;
			num_engs++;
		}
		else {
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}

		return *this;
	}

	bool operator==(const Ship& ship1, const Ship& ship2) {
		return ship1.calculatePower() == ship2.calculatePower();
	}

	bool operator<(const Ship& ship, double power) {
		return ship.calculatePower() < power;
	}

	Ship::~Ship() {

	}
}