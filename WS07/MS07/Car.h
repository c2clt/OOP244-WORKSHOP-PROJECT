// OOP244 Workshop 7: Inheritance
// File: Car.h
// Date: 03/10/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This header file defines the Car class
/////////////////////////////////////////////

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include "Vehicle.h"

const int MAX_CHAR = 20;
const int MIN_YEAR = 2000;

namespace sdds {
	class Car : public Vehicle {
		char m_carType[MAX_CHAR + 1];
		int m_regYear;
	public:
		Car();
		Car(const char* type, int year, int spd, int seats);
		void setCar(const char* type, int year);
		void finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
		~Car();
	};

	std::ostream& operator<<(std::ostream& os, const Car& C);
	std::istream& operator>>(std::istream& in, Car& C);
}

#endif