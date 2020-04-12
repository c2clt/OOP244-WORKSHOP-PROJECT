// OOP244 Workshop 7: Inheritance
// File: Vehicle.h
// Date: 03/10/2020
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// Email: jzhou175@myseneca.ca
// Description:
// This header file defines the Vehicle class
/////////////////////////////////////////////

#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

const int MIN_SPEED = 100;
const int MAX_SPEED = 140;

namespace sdds {
	class Vehicle {
		int m_speed;
		int m_noOfSeats;
	public:
		Vehicle();
		Vehicle(int speed, int noOfSeats);
		int getSpd() const;
		int getSeats() const;
		bool finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
		~Vehicle();
	};
	std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	std::istream& operator>>(std::istream& in, Vehicle& v);
}
#endif