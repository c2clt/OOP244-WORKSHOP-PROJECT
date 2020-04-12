/* Citation and Sources...
Final Project Milestone 4
Module: an abstract class ReadWritable
Filename: Vehicle.cpp
Version 1.0
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/03/25  implementation of the Vehicle Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Vehicle.h"

namespace sdds {
	void Vehicle::setEmpty() {
		licensePlate[0] = '\0';
		make_model = nullptr;
		parkSpotNum = 0;
	}

	bool Vehicle::isEmpty() const {
		return licensePlate[0] == '\0' || make_model == nullptr;
	}
	// toBeFixed
	const char* Vehicle::getLicensePlate() {
		return licensePlate;
	}

	const char* Vehicle::getMakeModel() {
		return make_model;
	}

	void Vehicle::setMakeModel(const char* makeModel) {
		if (makeModel != nullptr && makeModel[0] != '\0' && strlen(makeModel) >= 2) {
			int size = strlen(makeModel) + 1;
			delete[] make_model;
			make_model = new char[size];
			strcpy(make_model, makeModel);
		}
		else {
			delete[] make_model;
			setEmpty();
		}
	}

	Vehicle::Vehicle() : ReadWritable() {
		setEmpty();
	}

	Vehicle::Vehicle(const char* plate, const char* makeModel, int spotNum) : ReadWritable() {
		setEmpty();
		if (plate != nullptr && plate[0] != '\0' && strlen(plate) <= MAXLEN) {
			strncpy(licensePlate, plate, MAXLEN);
			licensePlate[MAXLEN] = '\0';
			toUpper(licensePlate);
		}
		else {
			licensePlate[0] = '\0';
		}
		setMakeModel(makeModel);
		setParkingSpot(spotNum);
	}
	
	int Vehicle::getParkingSpot() const {
		return parkSpotNum;
	}

	void Vehicle::setParkingSpot(int spotNum) {
		if (spotNum >= 0) {
			parkSpotNum = spotNum;
		}
		else {
			delete[] make_model;
			setEmpty();
		}
	}

	bool operator==(const Vehicle& v, const char* plate) {
		bool identical = false;
		if (!v.isEmpty()) {
			if (plate != nullptr && plate[0] != '\0' 
				&& strlen(plate) <= MAXLEN) {
				if (strICmp(v.licensePlate, plate)) {
					identical = true;
				}
			}
		}

		return identical;
	}

	bool operator==(const Vehicle& v1, const Vehicle& v2) {
		bool identical = false;
		if (!v1.isEmpty() && !v2.isEmpty()) {
			if (strICmp(v1.licensePlate, v2.licensePlate)) {
				identical = true;
			}
		}
		
		return identical;
	}

	std::istream& Vehicle::read(std::istream& istr) {
		if (isCsv()) {
			istr >> parkSpotNum;
			istr.ignore();
			istr.getline(licensePlate, MAXLEN + 1, ',');
			toUpper(licensePlate);			
			char temp[60 + 1] = { '\0' };
			istr.getline(temp, 60 + 1, ',');
			setMakeModel(temp);
		}
		else {
			std::cout << "Enter Licence Plate Number: ";
			int invalid;
			do {
				invalid = 0;
				istr >> licensePlate;
				istr.ignore();
				if (strlen(licensePlate) > 8) {
					invalid = 1;
					std::cout << "Invalid Licence Plate, try again: ";
				}
			} while (invalid);
			toUpper(licensePlate);

			std::cout << "Enter Make and Model: ";
			char temp[60 + 1] = { '\0' };
			do {
				invalid = 0;				
				istr.getline(temp, 60 + 1);
				if (strlen(temp) < 2 || strlen(temp) > 60) {
					invalid = 1;
					std::cout << "Invalid Make and model, try again: ";
				}				
			} while (invalid);
			setMakeModel(temp);

			parkSpotNum = 0;
		}

		if (istr.fail()) {
			istr.clear();
			setEmpty();
		}
		
		return istr;
	}

	std::ostream& Vehicle::write(std::ostream& ostr) const {
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << std::endl;
		}
		else {
			if (isCsv()) {
				ostr << parkSpotNum << "," << licensePlate << "," << make_model << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (parkSpotNum > 0) {
					ostr << parkSpotNum << std::endl;
				}
				else {
					ostr << "N/A" << std::endl;
				}
				ostr << "Licence Plate: " << licensePlate << std::endl;
				ostr << "Make and Model: " << make_model << std::endl;
			}
		}

		return ostr;
	}

	Vehicle::~Vehicle() {
		delete[] make_model;
		make_model = nullptr;
	}
}