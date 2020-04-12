/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/03/06  implementation of the Menu Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Utils.h"
#include "Menu.h"

using namespace std;

namespace sdds {

	MenuItem::MenuItem() {
		Menuitem = nullptr;
	}

	MenuItem::MenuItem(const char* item) {
		if (item != nullptr && item[0] != '\0') {
			int size = strlen(item) + 1;
			Menuitem = new char[size];
			strcpy(Menuitem, item);
		}
		else {
			Menuitem = nullptr;
		}
	}

	std::ostream& MenuItem::display() const {
		if (Menuitem != nullptr && Menuitem[0] != '\0') {
			cout << Menuitem << endl;
		}
		
		return cout;
	}

	MenuItem::~MenuItem() {
		delete[] Menuitem;
		Menuitem = nullptr;
	}

	Menu::Menu() {
		setEmpty();
	}

	Menu::Menu(const char* ttl, int identLev) {		
		if (ttl != nullptr && ttl[0] != '\0') {
			int size = strlen(ttl) + 1;
			Title = new char[size];
			strcpy(Title, ttl);
			Identation = identLev;
			MenuItems = nullptr;
			ItemNum = 0;
		}
		else {
			setEmpty();
		}
	}

	Menu::Menu(const Menu& menuSrc) {
		if (menuSrc.Title != nullptr && menuSrc.Title[0] != '\0') {
			int size = strlen(menuSrc.Title) + 1;
			Title = new char[size];
			strcpy(Title, menuSrc.Title);

			if (menuSrc.MenuItems != nullptr && menuSrc.ItemNum > 0) {
				ItemNum = menuSrc.ItemNum;
				MenuItems = new MenuItem[ItemNum];
				for (int i = 0; i < ItemNum; i++) {
					strcpy(MenuItems[i].Menuitem, menuSrc.MenuItems[i].Menuitem);
				}
			}

			Identation = menuSrc.Identation;
		}
		else {
			setEmpty();
		}
	}

	// menu deep assignment without items
	Menu& Menu::operator=(const Menu& menuSrc) {
		if (this != &menuSrc) {
			delete[] Title;
			if (menuSrc.Title != nullptr && menuSrc.Title[0] != '\0') {
				int size = strlen(menuSrc.Title) + 1;
				Title = new char[size];
				strcpy(Title, menuSrc.Title);
			}
			else {
				setEmpty();
			}
		}

		return *this;
	}

	void Menu::setEmpty() {
		Title = nullptr;
		MenuItems = nullptr;
		ItemNum = 0;
		Identation = 0;
	}

	Menu::operator bool() const {
		return !isEmpty();
	}

	bool Menu::isEmpty() const {
		return Title == nullptr;
	}

	std::ostream& Menu::display() const {
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			int space = Identation * 4;
			cout.width(space);
			cout << "";
			cout << Title << endl;
			if (MenuItems == nullptr) {
				cout << "No Items to display!" << endl;
			}
			else {
				for (int i = 0; i < ItemNum; i++) {
					cout.width(space);
					cout << "";
					cout << i + 1 << "- ";
					MenuItems[i].display();
				}
				cout.width(space);
				cout << "";
				cout << "> ";
			}
		}
		return cout;
	}

	Menu& Menu::operator=(const char* ttl) {
		delete[] Title;
		if (ttl != nullptr && ttl[0] != '\0') {
			int size = strlen(ttl) + 1;
			Title = new char[size];
			strcpy(Title, ttl);
		}
		else {
			setEmpty();
		}

		return *this;
	}	

	void Menu::add(const char* item) {
		if (!isEmpty()) {			
			if (item != nullptr && item[0] != '\0') {
				MenuItem addItem;
				int size = strlen(item) + 1;
				addItem.Menuitem = new char[size];
				strcpy(addItem.Menuitem, item);

				MenuItem* temp = new MenuItem[ItemNum + 1];

				for (int i = 0; i < ItemNum; i++) {
					temp[i].Menuitem = MenuItems[i].Menuitem;
				}
				temp[ItemNum].Menuitem = addItem.Menuitem;

				delete[] MenuItems;
				ItemNum++;
				MenuItems = new MenuItem[ItemNum];

				for (int i = 0; i < ItemNum; i++) {
					MenuItems[i].Menuitem = temp[i].Menuitem;
				}
					
				delete[] temp;
				}	
			else {
				setEmpty();
			}
		}				
	}

	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}

	int Menu::run() const {
		int selection = 0;
		display();
		if (MenuItems != nullptr) {
			char s[100];
			int invalid;
			do {
				invalid = 0;
				cin >> s;
				cin.ignore(1000, '\n');
				if (!isInt(s)) {
					cout << "Invalid Integer, try again: ";
					invalid = 1;
				}
				else {
					selection = atoi(s);
					if (selection < 1 || selection > ItemNum) {
						cout << "Invalid selection, try again: ";
						invalid = 1;
					}
				}
			} while (invalid);
		}

		return selection;
	}	

	Menu::operator int() const{
		return run();
	}

	Menu::~Menu() {
		delete[] Title;
		Title = nullptr;
		delete[] MenuItems;
		MenuItems = nullptr;
	}
}