// OOP244 Workshop 8: Virtual Functions
// File: Engineer.h
// Date: 03/24/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file defines the Engineer module
////////////////////////////////////////
#ifndef SDDS_ENGINEER_H__
#define SDDS_ENGINEER_H__

#include "Employee.h"

const int MIN_HOURS = 5;
const int MAX_LEVEL = 4;

namespace sdds {
	class Engineer : public Employee {
		double m_esalary;
		int m_ewhours;
		int m_level;
	public:
		Engineer();
		Engineer(double esalary, int ewhours, int level);
		void setSalary(double esalary);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
		virtual ~Engineer();
	};
	
}
#endif // !SDDS_ENGINEER_H__