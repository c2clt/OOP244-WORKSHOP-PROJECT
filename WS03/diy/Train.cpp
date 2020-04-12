/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// email: jzhou175@myseneca.ca
// Train.cpp: implementation of functions decalred in header file Train.h
// OOP244 Workshop 3: DIY-Classes & Privacy
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#include "Train.h"

using namespace std;

namespace sdds {

	void Cargo::init(const char* cargo_desc, double cargo_weight) {

		setDescription(cargo_desc);
		setWeight(cargo_weight);
	}

	void Cargo::setDescription(const char* cargo_desc) {

		if (cargo_desc != nullptr && cargo_desc[0] != '\0') {
			strncpy(description, cargo_desc, MAX_DESC);
			description[MAX_DESC] = '\0';
		}
		else {
			description[0] = '\0';
		}
	}

	void Cargo::setWeight(const double cargo_weight) {
		
		if (cargo_weight >= MIN_WEIGHT && cargo_weight <= MAX_WEIGHT) {

			weight = cargo_weight;
		}
		else {

			weight = MIN_WEIGHT;
		}
	}

	char* Cargo::getDescription() {

		return description;
	}

	double Cargo::getWeight() {

		return weight;
	}
 
	void Train::setTrain(const char* train_name, int train_id) {

		bool valid = train_name != nullptr && train_name[0] != '\0' && train_id >= 1;

		if (valid) {
			strncpy(name, train_name, MAX_NAME);
			name[MAX_NAME] = '\0';
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
		if (name[0] == '\0' || id == 0) {

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

				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Cargo: " << cargo->getDescription()
					 << " Weight: " << cargo->getWeight() << endl;
			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}

	}

	bool Train::swapCargo(Train& trainB) {

		bool res = false;
		if (trainB.cargo != nullptr) {

			Cargo* tmp;
			tmp = trainB.cargo;
			trainB.cargo = this->cargo;
			this->cargo = tmp;

			res = true;
		}

		return res;
	}

	bool Train::increaseCargo(double cargo_weight) {

		bool res = false;
		if (cargo != nullptr) {
			if (cargo->getWeight() < MAX_WEIGHT) {
				res = true;
				if (cargo->getWeight() + cargo_weight >= MAX_WEIGHT) {
					cargo->setWeight(MAX_WEIGHT);
				}
				else {
					cargo->setWeight(cargo->getWeight() + cargo_weight);
				}
			}
		}

		return res;
	}

	bool Train::decreaseCargo(double cargo_weight) {

		bool res = false;
		if (cargo != nullptr) {
			if (cargo->getWeight() > MIN_WEIGHT) {
				res = true;
				cargo->setWeight(cargo->getWeight() - cargo_weight);
			}
		}

		return res;
	}

	void Train::loadCargo(Cargo train_cargo) {

		cargo = new Cargo;
		strncpy(cargo->getDescription(), train_cargo.getDescription(), MAX_DESC);
		cargo->setWeight(train_cargo.getWeight());
		cargo->getWeight();
	}

	void Train::unloadCargo() {

		delete cargo;
		cargo = nullptr;
	}
}