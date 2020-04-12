// OOP244 Workshop 5-Diy: Operator Overloading
// File: Engine.cpp
// Date: 2/11/2020
// Name: Jingmin Zhou
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This file implementates the member functions in Engine.h
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Engine.h"

using namespace std;

namespace sdds {

	Engine::Engine() {
		setEmpty();
	}

	Engine::Engine(const char* style, double size) {
		set(style,size);
	}

	void Engine::setEmpty() {
		style_engine[0] = '\0'; 
		size_engine = 0.0;		
	}

	void Engine::set(const char* style, double size) {
		if (style != nullptr && style[0] != '\0' && size > 0) {
			size_engine = size;
			strncpy(style_engine, style, MAXSTYLE_ENG);
			style_engine[MAXSTYLE_ENG] = '\0';
		}
		else {
			setEmpty();
		}
	}

	double Engine::get() const {
		return size_engine;
	}

	void Engine::display() const {
		if (size_engine > 0) {
			cout << get() << " liters - " << style_engine << endl;
		}
	}

	Engine::~Engine() {

	}
}
