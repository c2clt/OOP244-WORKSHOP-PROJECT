// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// Saiyan.h(header file) define the class with data members and member functions
// OOP244 Workshop 4: Constructors_DIY 
/////////////////////////////////////////////


#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__

const int MAX_NAME = 30;
const int MAX_DOB = 2020;

namespace sdds {

	class Saiyan {

		char* m_name;
		int m_dob;
		int m_power;
		int m_level;
		bool m_super;

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup();
		~Saiyan();
	};
}
#endif