/* Citation and Sources...
Final Project Milestone 6
Module: Car module
Filename: Car.h
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  definition of the Car Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		bool carWash;
	public:
		Car();
		Car(const char* plate, const char* makeModel, int spotNum = 0, bool flag = false);
		Car(const Car& cCopy) = delete;
		Car& operator=(const Car& cCopy) = delete;
		virtual std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;
		virtual ~Car();
	};
}
#endif