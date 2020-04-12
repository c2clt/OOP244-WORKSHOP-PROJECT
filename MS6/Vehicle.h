/* Citation and Sources...
Final Project Milestone 6
Module: Vehicle
Filename: Vehicle.h
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  definition of the Vehicle Module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include "ReadWritable.h"
#include "Utils.h"

const int MAXLEN = 8;

namespace sdds {
	class Vehicle : public ReadWritable {
		char licensePlate[MAXLEN + 1];
		char* make_model;
		int parkSpotNum;
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate();
		const char* getMakeModel();
		void setMakeModel(const char* makeModel);
	public:
		Vehicle();
		Vehicle(const char* plate, const char* makeModel, int spotNum = 0);
		Vehicle(const Vehicle& vCopy) = delete;
		Vehicle& operator=(const Vehicle& vCopy) = delete;
		int getParkingSpot() const;
		void setParkingSpot(int spotNum);
		friend bool operator==(const Vehicle& v, const char* plate);
		friend bool operator==(const Vehicle& v1, const Vehicle& v2);
		virtual std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& write(std::ostream& ostr = std::cout) const;
		virtual ~Vehicle();
	};
	
}
#endif //!SDDS_VEHICLE_H__