// OOP244 Workshop 7: Inheritance
// File: Car.cpp
// Date: 03/10/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implements the Car module
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car() {
		Vehicle();
		m_carType[0] = '\0';
		m_regYear = MIN_YEAR;
	}
	Car::Car(const char* type, int year, int spd, int seats) : Vehicle(spd, seats) {
		setCar(type, year);
	}
	void Car::setCar(const char* type, int year) {
		if (type != nullptr && type[0] != '\0' && year >= MIN_YEAR) {
			strncpy(m_carType, type, MAX_CHAR);
			m_carType[MAX_CHAR] = '\0';
			m_regYear = year;
		}
		else {
			m_carType[0] = '\0';
			m_regYear = MIN_YEAR - 1;
		}
	}
	void Car::finetune() {
		if (m_regYear < MIN_YEAR) {
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
		else {
			if (Vehicle::finetune()) {
				cout << "This car is finely tuned to default speed" << endl;
			}
		}
	}

	std::ostream& Car::display(std::ostream& os) const {
		bool valid = Vehicle::getSpd() >= MIN_SPEED 
			&& Vehicle::getSeats() > 0 
			&& m_carType[0] != '\0' 
			&& m_regYear >= MIN_YEAR;
		if (valid) {
			cout.width(20);
			cout.setf(ios::left);
			os << m_carType;
			cout.unsetf(ios::left);
			os << m_regYear;
			Vehicle::display(os);
		}
		else {
			os << "Car is not initiated yet" << endl;
		}

		return os;
	}

	std::istream& Car::input(std::istream& in) {
		char type[MAX_CHAR + 1];
		cout << "Enter the car type: ";
		in >> type;
		int year;
		cout << "Enter the car registration year: ";
		in >> year;
		setCar(type, year);
		Vehicle::input(in);

		return in;
	}

	Car::~Car() {

	}

	std::ostream& operator<<(std::ostream& os, const Car& C) {
		C.display(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, Car& C) {
		C.input(in);
		return in;
	}
}