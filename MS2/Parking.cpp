/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
Version 1.0
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/03/14  implementation of the Parking Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Parking.h"

using namespace std;

namespace sdds {
	Parking::Parking() {
		setFileName(nullptr);
		parkingMenu = Menu();
		vehicleMenu = Menu();
	}

	Parking::Parking(const char* fName) {
		setFileName(fName);		
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
			parkingMenu = Menu();
			vehicleMenu = Menu();
		}		
	}

	void Parking::setFileName(const char* fName) {
		if (fName != nullptr && fName[0] != '\0') {
			int size = strlen(fName) + 1;
			fileName = new char[size];
			strcpy(fileName, fName);
		}
		else {
			fileName = nullptr;
		}
	}

	bool Parking::isEmpty() const {
		return fileName == nullptr;
	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() const {
		int selection = vehicleMenu.run();
		if (selection == 1) {
			cout << "Parking Car" << endl;
		}
		else if (selection == 2) {
			cout << "Parking Motorcycle" << endl;
		}
		else {
			cout << "Cancelled parking" << endl;
		}
	}

	void Parking::returnVehicle() const {
		cout << "Returning Vehicle" << endl;
	}

	void Parking::vehicleList() const {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::parkingClose() const {
		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitApp() const {		
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		string option;
		bool res, valid;
		do {
			valid = true;
			cin >> option;
			cin.ignore(1000, '\n');
			
			if (option == "Y" || option == "y") {
				res = true;
			}
			else if (option == "N" || option == "n") {
				res = false;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				valid = false;
			}
		} while (!valid);

		return res;
	}

	bool Parking::loadFile() const {
		bool res = false;
		if (!isEmpty()) {
			cout << "loading data from " << fileName << endl;
			res = true;
		}

		return res;
	}

	void Parking::saveFile() const {
		if (!isEmpty()) {
			cout << "Saving data into " << fileName << endl;			
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
	}
}