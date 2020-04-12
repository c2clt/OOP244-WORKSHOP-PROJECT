/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.0
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  definition of the Parking Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"

const int MAXSPOTS = 100;

namespace sdds {
	class Parking : public Menu {
	private:
		char* fileName;
		Menu parkingMenu;
		Menu vehicleMenu;
		int numOfSpots;
		Vehicle* spots[MAXSPOTS];
		int numOfParkedVeh;

		void setEmpty();
		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void vehicleList() const;
		bool parkingClose();
		bool exitApp() const;
		bool loadFile();
		void saveFile() const;
	public:
		using Menu::Menu;

		Parking();
		Parking(const char* datafile, int noOfSpots);
		Parking(const Parking& pCopy) = delete;
		Parking& operator=(const Parking& pCopy) = delete;
		void setFileName(const char* fName);
		int run(); 
		~Parking();		
	};
}
#endif