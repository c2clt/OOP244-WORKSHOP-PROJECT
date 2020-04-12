// OOP244 Workshop 5-Diy: Operator Overloading
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

	Ship::Ship(const char* type, Engine engsArr[], int len_engsArr) {
		setEmpty();
        set(type, engsArr, len_engsArr);
	}

	void Ship::setEmpty() {
		type_ship = nullptr;
		engs = nullptr;
		num_engs = 0;
	}

	void Ship::set(const char* type, Engine engsArr[], int len_engsArr) {
		if (type_ship == nullptr) {
			type_ship = new char[TYPE_SIZE + 1];
		}

		bool valid = type != nullptr && strlen(type) > 0 && strlen(type) <= 6 && len_engsArr > 0;
		if (valid) {
			strcpy(type_ship, type);
			num_engs = len_engsArr;
			delete[] engs;
			engs = new Engine[num_engs];

			for (int i = 0; i < num_engs; i++) {
				engs[i] = engsArr[i];
			}
		}
		else {
            delete[] type_ship;
            setEmpty();
		}
	}

	bool Ship::empty() const {
		return type_ship == nullptr;
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
		if (!empty()) {
			Engine* temp = new Engine[num_engs + 1];
			for (int i = 0; i < num_engs; i++) {
				temp[i] = engs[i];
			}
			temp[num_engs] = e;
			delete[] engs;
			num_engs++;
			engs = new Engine[num_engs];
			for (int i = 0; i < num_engs; i++) {
				engs[i] = temp[i];
			}
			delete[] temp;
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
		delete[] type_ship;
		type_ship = nullptr;
		delete[] engs;
		engs = nullptr;
	}
}
