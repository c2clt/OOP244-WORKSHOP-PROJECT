// OOP244 Workshop 6: Class with a Resource
// File: Basket.h
// Date: 3/3/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file define class Basket
// data members and member function prototypes
/////////////////////////////////////////////
#ifndef SDDS_BASKET_H__
#define SDDS_BASKET_H__

namespace sdds {
	class Basket {
		char* m_fruitName;
		int m_qty;
		double m_price;
	public:
		Basket();
		Basket(const char* name, int qty, double price);
		Basket(const Basket& bsk);
		Basket& operator=(const Basket& bsk);
		void setEmpty();
		void setName(const char* name);
		void setQty(int qty);
		void setPrice(double price);
		bool isEmpty() const;
		bool addPrice(double prc);
		std::ostream& display(std::ostream& os) const;
		bool operator==(const Basket& bsk);
		bool operator!=(const Basket& bsk);
		~Basket();
	};	
	std::ostream& operator<<(std::ostream& os, const Basket& bsk);
}

#endif