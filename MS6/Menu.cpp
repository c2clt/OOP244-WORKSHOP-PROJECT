/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.cpp
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  implementation of the Menu Module
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
		setItem(nullptr);
	}

	MenuItem::MenuItem(const char* item) {
		setItem(item);
	}

	void MenuItem::setItem(const char* item) {
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
		setTitle(ttl);
		setItems({nullptr}, 0);
		setIdentation(identLev);
	}

	Menu::Menu(const Menu& menuSrc) {
		setTitle(menuSrc.Title);
		setItems(menuSrc.MenuItems, menuSrc.ItemNum);
		setIdentation(menuSrc.Identation);
	}

	Menu& Menu::operator=(const Menu& menuSrc) {
		if (this != &menuSrc) {
			delete[] Title;
            for (int i = 0; i < ItemNum; i++) {
                delete MenuItems[i];
                MenuItems[i] = nullptr;
            }
			setTitle(menuSrc.Title);
			setItems(menuSrc.MenuItems, menuSrc.ItemNum);
			setIdentation(menuSrc.Identation);
		}

		return *this;
	}

	void Menu::setEmpty() {
		setTitle(nullptr);
		setItems({nullptr}, 0);
		setIdentation(0);
	}

	void Menu::setTitle(const char* ttl) {
		if (ttl != nullptr && ttl[0] != '\0') {
			int size = strlen(ttl) + 1;
			Title = new char[size];
			strcpy(Title, ttl);
		}
		else {
			Title = nullptr;
		}
	}

	void Menu::setItems(MenuItem* const Items[], int num) {
		if (num > 0) {
			ItemNum = num <= MAX_NO_OF_ITEMS ? num : MAX_NO_OF_ITEMS;
			for (int i = 0; i < ItemNum; i++) {
				MenuItems[i] = new MenuItem(Items[i]->Menuitem);
			}
		}
		else {
			for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
				MenuItems[i] = nullptr;
			}
			ItemNum = 0;
		}
	}

	void Menu::setIdentation(int identLev) {
		if (identLev > 0) {
			Identation = identLev;
		}
		else {
			Identation = 0;
		}
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
			if (MenuItems[0] == nullptr) {
				cout << "No Items to display!" << endl;
			}
			else {
				for (int i = 0; i < ItemNum; i++) {
					cout.width(space);
					cout << "";
					cout << i + 1 << "- ";
					MenuItems[i]->display();
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
		setTitle(ttl);

		return *this;
	}	

	void Menu::add(const char* item) {
		if (!isEmpty()) {
			if (ItemNum < MAX_NO_OF_ITEMS) {
				if (item != nullptr && item[0] != '\0') {
					MenuItems[ItemNum] = new MenuItem(item);
					ItemNum++;
				}
				else {
					delete[] Title;
					Title = nullptr;
					for (int i = 0; i < ItemNum; i++) {
						delete MenuItems[i];
						MenuItems[i] = nullptr;
					}
					setEmpty();
				}
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
		if (MenuItems[0] != nullptr) {
			int invalid;
			do {
				invalid = 0;
				cin >> selection;
				if (cin.fail()) {
					cout << "Invalid Integer, try again: ";
					invalid = 1;
				}
				else {
					if (selection < 1 || selection > ItemNum) {
						cout << "Invalid selection, try again: ";
						invalid = 1;
					}
				}
				cin.clear();
				cin.get();
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
		for (int i = 0; i < ItemNum; i++) {
			delete MenuItems[i];
			MenuItems[i] = nullptr;
		}
	}
}
