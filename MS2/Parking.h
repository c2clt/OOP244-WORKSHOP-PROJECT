/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.h
Version 1.0
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/03/14  definition of the Parking Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include "Menu.h"

namespace sdds {
	class Parking : public Menu {
	private:
		char* fileName;
		Menu parkingMenu;
		Menu vehicleMenu;

		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle() const;
		void returnVehicle() const;
		void vehicleList() const;
		bool parkingClose() const;
		bool exitApp() const;
		bool loadFile() const;
		void saveFile() const;
	public:
		using Menu::Menu;

		Parking();
		Parking(const char* fName);
		Parking(const Parking& pCopy) = delete;
		Parking& operator=(const Parking& pCopy) = delete;
		void setFileName(const char* fName);
		int run(); 
		~Parking();		
	};
}
#endif