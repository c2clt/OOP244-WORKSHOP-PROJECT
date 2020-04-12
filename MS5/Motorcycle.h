/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle module
Filename: Motorcycle.h
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/03/31  definition of the Motorcycle Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__

#include "Vehicle.h"

namespace sdds {
	class Motorcycle : public Vehicle {
		bool hasSidecar;
	public:
		Motorcycle();
		Motorcycle(const char* plate, const char* makeModel, int spotNum = 0, bool flag = false);
		Motorcycle(const Motorcycle& mCopy) = delete;
		Motorcycle& operator=(const Motorcycle& mCopy) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout) const;
		virtual ~Motorcycle();
	};
}
#endif