/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  definition of the classes for Menu Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include "Utils.h"

const int MAX_NO_OF_ITEMS = 10;

namespace sdds {

	class MenuItem {
		char* Menuitem;

		MenuItem();
		MenuItem(const char* item);
		void setItem(const char* item);
		MenuItem(const MenuItem& itemSrc) = delete;
		MenuItem& operator=(const MenuItem& itemSrc) = delete;
		std::ostream& display() const;
		~MenuItem();
		friend class Menu;
	};

	class Menu {
		char* Title;
		MenuItem* MenuItems[MAX_NO_OF_ITEMS];
		int ItemNum;
		int Identation;
	public:
		Menu();
		Menu(const char* ttl, int identLev = 0);
		Menu(const Menu& menuSrc);
		Menu& operator=(const Menu& menuSrc);
		void setEmpty();
		void setTitle(const char* ttl);
		void setItems(MenuItem* const Items[], int num);
		void setIdentation(int identLev);
		operator bool() const;
		bool isEmpty() const;
		std::ostream& display() const;
		Menu& operator=(const char* ttl);
		void add(const char* newMenuItem);
		Menu& operator<<(const char* item);		
		int run() const;
		operator int() const;
		virtual ~Menu();
	};		
}
#endif