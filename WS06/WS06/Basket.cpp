// OOP244 Workshop 6: Class with a Resource
// File: Basket.cpp
// Date: 3/3/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implements the member functions
///////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Basket.h"

using namespace std;

namespace sdds {
	Basket::Basket() {
		setEmpty();
	}

	Basket::Basket(const char* name, int qty, double price) {
		setName(name);
		setQty(qty);
		setPrice(price);
	}

	Basket::Basket(const Basket& bcopy) {
		setName(bcopy.m_fruitName);
		setQty(bcopy.m_qty);
		setPrice(bcopy.m_price);
	}

	Basket& Basket::operator=(const Basket& bsk) {
		if (this != &bsk) {
			setQty(bsk.m_qty);
			setPrice(bsk.m_price);
			delete[] m_fruitName;
			setName(bsk.m_fruitName);			
		}
		return *this;
	}

	void Basket::setEmpty() {
		setName(nullptr);
		setQty(0);
		setPrice(0.0);
	}

	void Basket::setName(const char* name) {
		if (name != nullptr && name[0] != '\0') {
			int size = strlen(name) + 1;
			m_fruitName = new char[size];
			strncpy(m_fruitName, name, size);
		}
		else {
			m_fruitName = nullptr;
		}
	}

	void Basket::setQty(int qty) {
		if (qty > 0) {
			m_qty = qty;
		}
		else {
			m_qty = 0;
		}
	}

	void Basket::setPrice(double price) {
		if (price > 0.0) {
			m_price = price;
		}
		else {
			m_price = 0.0;
		}
	}

	bool Basket::isEmpty() const {
		return m_fruitName == nullptr || m_qty == 0 || m_price == 0.0;
	}

	bool Basket::addPrice(double prc) {
		bool res = false;
		if (prc > 0.0) {
			m_price += prc;
			res = true;
		}
		return res;
	}

	std::ostream& Basket::display(std::ostream& os) const {
		if (isEmpty()) {
			cout << "The Basket has not yet been filled" << endl;
		}
		else {
			os << "Basket Details" << endl;
			os << "Name: " << m_fruitName << endl;
			os << "Quantity: " << m_qty << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Price: " << m_price << endl;
			os.unsetf(ios::fixed);
			os.precision(6);
		}
		return os;
	}

	bool Basket::operator==(const Basket& bsk) {
		return (strcmp(m_fruitName, bsk.m_fruitName) == 0) && m_qty == bsk.m_qty && m_price == bsk.m_price;
	}

	bool Basket::operator!=(const Basket& bsk) {
		return !(*this == bsk);
	}

	std::ostream& operator<<(ostream& os, const Basket& bsk) {
		bsk.display(os);
		return os;
	}

	Basket::~Basket() {
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}
}