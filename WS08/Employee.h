// OOP244 Workshop 8: Virtual Functions
// File: Employee.h
// Date: 03/24/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file defines the Employee module as the interface
///////////////////////////////////////////////////////////////

#ifndef SDDS_EMPLOYEE_H__
#define SDDS_EMPLOYEE_H__

#include <iostream>

namespace sdds {
	class Employee {
	public:
		virtual void setSalary(double salary) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
		virtual ~Employee() {
		}
	};
}
#endif // !SDDS_EMPLOYEE_H__