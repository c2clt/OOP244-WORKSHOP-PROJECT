// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// Saiyan.cpp implementation of member functions
// OOP244 Workshop 4: Constructors_Lab 
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Saiyan.h"

using namespace std;

namespace sdds {
	Saiyan::Saiyan() {

		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {

		set(name, dob, power);
	}

	bool Saiyan::isSuper() const {

		return m_super;
	}

	bool Saiyan::isValid() const {

		return m_name[0] != '\0' && m_dob < MAX_DOB && m_power > 0;
	}

	void Saiyan::setEmpty() {

		m_name[0] = '\0';
		m_dob = MAX_DOB;
		m_power = 0;
		m_super = false;
	}

	void Saiyan::display() const {

		if (isValid()) {
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;

			if (isSuper()) {
				cout << "Super Saiyan Ability: Super Saiyan.\n" << endl;
			}
			else {
				cout << "Super Saiyan Ability: Not super Saiyan.\n" << endl;
			}
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		bool valid = name != nullptr && name[0] != '\0' && dob < MAX_DOB && power > 0;
		if (valid) {
			strncpy(m_name, name, MAX_NAME);
			m_name[MAX_NAME] = '\0';
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
		else {
			setEmpty();
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) const {
		return this->m_power < other.m_power;
	}

	Saiyan::~Saiyan() {

	}
}
