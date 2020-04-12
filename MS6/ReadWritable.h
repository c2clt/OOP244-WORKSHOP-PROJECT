/* Citation and Sources...
Final Project Milestone 6
Module: an abstract class ReadWritable
Filename: ReadWritable.h
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  definition of the ReadWritable Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__
#include <iostream>

namespace sdds {
	class ReadWritable {
		bool commaSepFlag;
	public:
		ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual ~ReadWritable();
	};

	std::ostream& operator<<(std::ostream& os, const ReadWritable& RW);
	std::istream& operator>>(std::istream& is, ReadWritable& RW);
}
#endif