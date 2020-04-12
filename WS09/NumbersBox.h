/***********************************************************************
// OOP244 Workshop 9: Templates
// File: NumbersBox.h
// Date: 2020/3/30
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description
// define and implemment the Calculator template NumbersBox
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_NUMBERSBOX_H__
#define SDDS_NUMBERSBOX_H__

#include <iostream>
#include <cstring>

const int MAXLEN = 15;
namespace sdds {
	template <class T>
	class NumbersBox {
		char name[MAXLEN + 1];
		int size;
		T* items;
	public:
		NumbersBox();
		NumbersBox(int sz, const char* nm);
		T& operator[](int i);
		NumbersBox<T>& operator*=(const NumbersBox<T>& other);
		NumbersBox<T>& operator+=(T num);
		std::ostream& display(std::ostream& os) const;
		virtual ~NumbersBox();
	};

	template <class T>
	NumbersBox<T>::NumbersBox() {
		name[0] = '\0';
		size = 0;
		items = nullptr;
	}

	template <class T>
	NumbersBox<T>::NumbersBox(int sz, const char* nm) {
		bool valid = sz >= 1 && nm != nullptr && nm[0] != '\0';
		if (valid) {
			strncpy(name, nm, MAXLEN);
			name[MAXLEN] = '\0';
			size = sz;
			items = new T[size];
		}
		else {
			name[0] = '\0';
			size = 0;
			items = nullptr;
		}
	}

	template <class T>
	T& NumbersBox<T>::operator[](int i) {
		return items[i];
	}

	template <class T>
	NumbersBox<T>& NumbersBox<T>::operator*=(const NumbersBox<T>& other) {
		if (other.size == this->size) {
			for (int i = 0; i < size; i++) {
				this->items[i] *= other.items[i];
			}
		}

		return *this;
	}

	template <class T>
	NumbersBox<T>& NumbersBox<T>::operator+=(T num) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = items[i];
		}
		delete[] items;
		size++;
		items = new T[size];
		for (int i = 0; i < size; i++) {
			items[i] = temp[i];
		}
		items[size - 1] = num;
		delete[] temp;		

		return *this;
	}

	template <class T>
	std::ostream& NumbersBox<T>::display(std::ostream& os) const {
		if (name[0] == '\0' || size == 0 || items == nullptr) {
			os << "Empty Box" << std::endl;
		}
		else {
			os << "Box name: " << name << std::endl;
			int i;
			for (i = 0; i < size - 1; i++) {
				os << items[i] << ", ";
			}
			os << items[i] << std::endl;
		}

		return os;
	}

	template <class T>
	std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box) {
		box.display(os);
		
		return os;
	}

	template <class T>
	NumbersBox<T>::~NumbersBox() {
		delete[] items;
		items = nullptr;
	}
}
#endif //!SDDS_NUMBERSBOX_H__