/* Citation and Sources...
Final Project Milestone 4
Module: an abstract class ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/03/25  implementation of the ReadWritable Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "ReadWritable.h"

namespace sdds {
	ReadWritable::ReadWritable() {
		commaSepFlag = false;
	}

	bool ReadWritable::isCsv()const {
		return commaSepFlag;
	}

	void ReadWritable::setCsv(bool value) {
		commaSepFlag = value;
	}

	ReadWritable::~ReadWritable() {

	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& RW) {
		RW.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, ReadWritable& RW) {
		RW.read(is);
		return is;
	}
}