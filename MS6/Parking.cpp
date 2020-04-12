/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05   implementation of the Parking Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Parking.h"

using namespace std;

namespace sdds {
	Parking::Parking() {
		this->setEmpty();
	}
	
	Parking::Parking(const char* datafile, int noOfSpots) {
		this->setEmpty();
		setFileName(datafile);	
		if (noOfSpots >= 10 && noOfSpots <= MAXSPOTS) {
			numOfSpots = noOfSpots;
		}
		else {
			numOfSpots = 0;
		}

		if (loadFile()) {
			parkingMenu = Menu("Parking Menu, select an action:", 0);
			parkingMenu << "Park Vehicle"
				<< "Return Vehicle"
				<< "List Parked Vehicles"
				<< "Close Parking (End of day)"
				<< "Exit Program";
			vehicleMenu = Menu("Select type of the vehicle:", 1);
			vehicleMenu << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			cout << "Error in data file" << endl;
			this->setEmpty();
		}		
	}

	void Parking::setFileName(const char* datafile) {
		if (datafile != nullptr && datafile[0] != '\0') {
			int size = strlen(datafile) + 1;
			fileName = new char[size];
			strcpy(fileName, datafile);
		}
		else {
			fileName = nullptr;
		}
	}

	void Parking::setEmpty() {
		setFileName(nullptr);
		parkingMenu = Menu();
		vehicleMenu = Menu();
		numOfSpots = 0;
		for (int i = 0; i < MAXSPOTS; i++) {
			spots[i] = nullptr;
		}
		numOfParkedVeh = 0;
	}

	bool Parking::isEmpty() const {
		return fileName == nullptr;
	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << numOfSpots - numOfParkedVeh << " *****" << endl;
		cout.unsetf(ios::left);
	}

	void Parking::parkVehicle() {
		if (numOfSpots == numOfParkedVeh) {
			cout << "Parking is full" << endl;
		}
		else {
			int selection = vehicleMenu.run();
			if (selection == 3) {
				cout << "Parking cancelled" << endl;
			}
			else {
				Vehicle* vp = nullptr;
				if (selection == 1) {
					vp = new Car();
				}
				else if (selection == 2) {
					vp = new Motorcycle();
				}

				vp->setCsv(false);
				cin >> *vp;
	
				bool valid = true;
				for (int i = 0; i < numOfSpots && valid; i++) {
					if (spots[i] != nullptr && *spots[i] == *vp) {
						cout << "\nCan not park; license plate already in the system!" << endl;
						cout << *vp;
						cout << endl;
						valid = false;
					}
				}
				if (valid && numOfParkedVeh < numOfSpots) {
					for (int i = 0; i < numOfSpots && valid; i++) {
						if (spots[i] == nullptr) {
							spots[i] = vp;
							spots[i]->setParkingSpot(i + 1);
							cout << "\nParking Ticket" << endl;
							cout << *spots[i]; 
							cout << endl;
							numOfParkedVeh++;
							valid = false;
						}
					}
				}
			}
		}		
	}

	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		char plate[MAXLEN + 1] = { '\0' };
		bool invalid;
		cout << "Enter Licence Plate Number: ";
		do {
			invalid = false;
			cin >> plate;
			cin.ignore();
			if (strlen(plate) < 1 || strlen(plate) > 8) {
				cout << "Invalid Licence Plate, try again: ";
				invalid = true;
			}
		} while (invalid);
		toUpper(plate);

		bool flag = true;
		for (int i = 0; i < numOfSpots && flag; i++) {
			if (spots[i] != nullptr && *spots[i] == plate) {
				cout << "\nReturning: " << endl;
				spots[i]->setCsv(false);
				cout << *spots[i];
				cout << endl;
				delete spots[i];
				spots[i] = nullptr;
				numOfParkedVeh--;
				flag = false;
			}
		}

		if (flag) {
			cout << "\nLicense plate " << plate << " Not found\n" << endl;
		}
	}

	void Parking::vehicleList() const {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numOfSpots; i++) {
			if (spots[i] != nullptr) {
				spots[i]->setCsv(false);
				cout << *spots[i];
				cout << "-------------------------------" << endl;
			}
		}
	}
	
	bool Parking::parkingClose() {
		bool close = false;
		if (numOfParkedVeh == 0) {
			cout << "Closing Parking" << endl;
			close = true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			if (yes()) {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < numOfSpots; i++) {
					if (spots[i] != nullptr) {
						cout << endl << "Towing request" << endl;
						cout << "*********************" << endl;
						cout << *spots[i];
						delete spots[i];
						spots[i] = nullptr;
						numOfParkedVeh--;
					}
				}
				saveFile();
				close = true;
			}
			else {
				cout << "Aborted!" << endl;
				close = false;
			}
		}

		return close;
	}

	bool Parking::exitApp() const {		
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		bool res = yes();
		if (res) {
			saveFile();
		}

		return res;
	}

	bool Parking::loadFile() {
		bool state = true;
		ifstream filein;
		if (!isEmpty()) {
			filein.open(fileName);
		}

		char vType;
		Vehicle* vp;
		numOfParkedVeh = 0;

		while (numOfParkedVeh < numOfSpots && state && filein) {
			vType = 'x';
			vp = nullptr;
			filein >> vType;
			filein.ignore();
			if (vType == 'C') {
				vp = new Car();
			}
			else if (vType == 'M') {
				vp = new Motorcycle();
			}

			if (vp) {
				vp->setCsv(true);
				filein >> *vp;
				if (filein) {
					spots[vp->getParkingSpot() - 1] = vp;
					numOfParkedVeh++;
				}			
				else {
					delete vp;
					vp = nullptr;
					state = false;
				}
			}
		}

		return state;
	}

	void Parking::saveFile() const {
		if (!isEmpty()) {
			ofstream fileout(fileName);
			if (fileout) {
				for (int i = 0; i < numOfSpots; i++) {
					if (spots[i] != nullptr) {
						spots[i]->setCsv(true);
						fileout << *spots[i];
					}
				}
			}
		}
	}

	int Parking::run() {
		int res = 1;
		if (!isEmpty()) {	
			res = 0;
			int option, flag;
			do
			{
				parkingStatus();
				flag = 1;
				option = parkingMenu.run();
				
				switch (option)
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					vehicleList();
					break;
				case 4:
					if (parkingClose()) {
						flag = 0;
					}
					break;
				default:
					if (exitApp()) {
						cout << "Exiting program!" << endl;
						flag = 0;
					}
					break;
				}
			} while (flag);
		}

		return res;
	}

	Parking::~Parking() {
		saveFile();
		delete[] fileName;
		fileName = nullptr;

		// delete spots[i]
		for (int i = 0; i < MAXSPOTS; i++) {
			delete spots[i];
			spots[i] = nullptr;
		}
	}
}