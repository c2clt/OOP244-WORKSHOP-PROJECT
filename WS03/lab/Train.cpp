/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// email: jzhou175@myseneca.ca
// Train.cpp: implementation of functions decalred in header file Train.h
// OOP244 Workshop 3: Classes & Privacy
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#include "Train.h"

using namespace std;

namespace sdds {

	void Train::setTrain(const char* train_name, int train_id) {

		bool valid = train_name != nullptr && train_name[0] != '\0' && train_id >= 1;

		if (valid) {
			strncpy(name, train_name, MAX_NAME);
			id = train_id;
		}
		else {
			name[0] = '\0';
			id = 0;
		}

		cargo = nullptr;
	}

	bool Train::isEmpty() const {

		bool res;
		if (name == nullptr || name[0] == '\0' || id == 0) {

			res = true;
		}
		else {

			res = false;
		}
		
		return res;
	}

	void Train::display() const {

		cout << "***Train Summary***" << endl;
		
		if (isEmpty()) {

			cout << "This is an empty train." << endl;
		}
		else {

			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo != nullptr) {

				cout << "Cargo: " << cargo->description 
					 << " Weight: " << cargo->weight << endl;
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}

	}

	void Train::loadCargo(Cargo train_cargo) {

		cargo = new Cargo;
		strncpy(cargo->description, train_cargo.description, MAX_DESC);
		cargo->weight = train_cargo.weight;
	}

	void Train::unloadCargo() {

		delete cargo;
		cargo = nullptr;
	}
}