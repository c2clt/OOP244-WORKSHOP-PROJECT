// OOP244 Workshop 5-Lab: Operator Overloading
// File: Engine.h
// Date: 2/11/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file defines class Engine with 
// data members and member function prototypes
/////////////////////////////////////////////

#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__

const int MAXSTYLE_ENG = 30;

namespace sdds {

	class Engine {

		char style_engine[MAXSTYLE_ENG + 1];
		double size_engine;		

	public:
		Engine();
		Engine(const char* style, double size);
		void setEmpty();
		void set(const char* style, double size);
		double get() const;
		void display() const;
		~Engine();
	};
}
#endif
