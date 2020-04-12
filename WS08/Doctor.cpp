// OOP244 Workshop 8: Virtual Functions
// File: Doctor.cpp
// Date: 03/24/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implements the Doctor module
//////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Doctor.h"

namespace sdds {
	Doctor::Doctor() {
		m_type[0] = '\0';
		m_salary = 0.0;
		m_whours = 0;
		m_specialist = false;
	}

	Doctor::Doctor(const char* type, double salary, int whours, bool specialist) {
		if (salary > 0.0 && whours > 0) {
			if (type != nullptr && type[0] != '\0') {
				strncpy(m_type, type, MAX_CHAR);
				m_type[MAX_CHAR] = '\0';
			}			
			m_whours = whours;
			m_specialist = specialist;
			setSalary(salary);
		}
		else {
			m_type[0] = '\0';
			m_salary = 0.0;
			m_whours = 0;
			m_specialist = false;
		}
	}

	void Doctor::setSalary(double salary) {
		if (m_specialist) {
			m_salary = salary + 2000.0;
		}
		else {
			m_salary = salary;
		}
	}

	bool Doctor::workHours() {
		return m_whours >= MIN_W_HOURS;
	}

	void Doctor::bonus() {
		if (m_whours > MIN_W_HOURS) {
			m_salary += m_salary * 0.10;
		}
		else {
			m_salary += m_salary * 0.05;
		}
	}

	std::ostream& Doctor::display(std::ostream& os) const {
		if (m_salary > 0 && m_whours > 0) {
			os << "Doctor details" << std::endl;
			os << "Doctor Type: " << m_type << std::endl;
			os.setf(std::ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << std::endl;
			os.unsetf(std::ios::fixed);
			os.precision(6);
			os << "Working Hours: " << m_whours << std::endl;
		}
		else {
			os << "Doctor is not initiated yet" << std::endl;
		}

		return os;
	}
	Doctor::~Doctor() {
	}
}