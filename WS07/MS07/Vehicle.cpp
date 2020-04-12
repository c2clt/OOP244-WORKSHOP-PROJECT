// OOP244 Workshop 7: Inheritance
// File: Vehicle.cpp
// Date: 03/10/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implements the Vehicle module
/////////////////////////////////////////////

#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds {
	Vehicle::Vehicle() {
		m_speed = MIN_SPEED;
		m_noOfSeats = 0;
	}

	Vehicle::Vehicle(int spd, int seats) {
		if (spd >= MIN_SPEED && seats > 0) {
			m_speed = spd;
			m_noOfSeats = seats;
		}
		else {
			m_speed = MIN_SPEED;
			m_noOfSeats = 0;
		}
	}

	int Vehicle::getSpd() const {
		return m_speed;
	}

	int Vehicle::getSeats() const {
		return m_noOfSeats;
	}

	bool Vehicle::finetune() {
		bool res;
		if (m_speed > MAX_SPEED) {
			m_speed = MIN_SPEED;
			res = true;
		}
		else {
			cout << "The car cannot be tuned" << endl;
			res = false;
		}

		return res;
	}

	std::ostream& Vehicle::display(std::ostream& os) const{
		if (m_speed >= MIN_SPEED && m_noOfSeats > 0) {
			os << "|" << m_speed << "|" << m_noOfSeats << endl;

			if (m_speed > MAX_SPEED) {
				os << "Car has to be fine tuned for speed limit" << endl;
			}
		}
		else {
			os << "This Car is not initiated" << endl;
		}

		return os;
	}

	std::istream& Vehicle::input(std::istream& in) {
		int spd;
		cout << "Enter the Vehicle`s speed: ";
		in >> spd;
		int seats;
		cout << "Enter no of seats: ";
		in >> seats;
		*this = Vehicle(spd, seats);

		return in;
	}

	Vehicle::~Vehicle() {

	}

	std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}

	std::istream& operator>>(std::istream& in, Vehicle& v) {
		v.input(in);
		return in;
	}
}