// OOP244 Workshop 8: Virtual Functions
// File: Engineer.cpp
// Date: 03/24/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implements the Engineer module
////////////////////////////////////////////

#include <iostream>
#include "Engineer.h"

namespace sdds {
	Engineer::Engineer() {
		m_esalary = 0.0;
		m_ewhours = 0;
		m_level = 0;
	}

	Engineer::Engineer(double esalary, int ewhours, int level) {
		bool valid = esalary > 0.0 && ewhours > 0 && 
					 level > 0 && level <= MAX_LEVEL;
		if (valid) {
			m_level = level;
			m_ewhours = ewhours;			
			setSalary(esalary);
		}
		else {
			m_esalary = 0.0;
			m_ewhours = 0;
			m_level = 0;
		}
	}

	void Engineer::setSalary(double esalary) {
		if (m_level == MAX_LEVEL) {
			m_esalary = esalary + 3000.0;
		}
		else {
			m_esalary = esalary;
		}
	}

	bool Engineer::workHours() {
		return m_ewhours >= MIN_HOURS;
	}

	void Engineer::bonus() {
		if (m_ewhours > MIN_HOURS && m_level == MAX_LEVEL) {
			m_esalary += m_esalary * 0.10;
		}
		else {
			m_esalary += m_esalary * 0.05;
		}
	}

	std::ostream& Engineer::display(std::ostream& os) const {
		if (m_esalary > 0.0 && m_ewhours > 0) {
			os << "Engineer details" << std::endl;
			os << "level: " << m_level << std::endl;
			os.setf(std::ios::fixed);
			os.precision(2);
			os << "Salary: "<< m_esalary << std::endl;
			os.unsetf(std::ios::fixed);
			os.precision(6);
			os << "Working hours: " << m_ewhours << std::endl;
		}
		else {
			os << "Engineer is not initiated yet" << std::endl;
		}

		return os;
	}

	Engineer::~Engineer() {

	}
}