// OOP244 Workshop 8: Virtual Functions
// File: Doctor.h
// Date: 03/24/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file defines the Doctor module
//////////////////////////////////////

#ifndef SDDS_DOCTOR_H__
#define SDDS_DOCTOR_H__

#include <iostream>
#include "Employee.h"

const int MIN_W_HOURS = 6;
const int MAX_CHAR = 20;

namespace sdds {
	class Doctor : public Employee {
		char m_type[MAX_CHAR + 1];
		double m_salary;
		int m_whours;
		bool m_specialist;
	public:
		Doctor();
		Doctor(const char* type, double salary, int whours, bool specialist = false);
		void setSalary(double salary);
		bool workHours();
		void bonus();
		std::ostream& display(std::ostream& os) const;
		virtual ~Doctor();
	};
}
#endif // !SDDS_DOCTOR_H__