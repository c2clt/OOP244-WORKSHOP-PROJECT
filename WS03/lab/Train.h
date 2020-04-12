/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// email: jzhou175@myseneca.ca
// Train.h: defining the date members and function prototypes for module Train
// OOP244 Workshop 3: Classes & Privacy
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TRAIN_H__
#define SDDS_TRAIN_H__

const int MAX_NAME = 30;
const int MAX_DESC = 20;

namespace sdds {

	struct Cargo {

		char description[MAX_DESC + 1];
		double weight;

	};

	class Train {

		char name[MAX_NAME + 1];
		int id;
		Cargo* cargo;

	public:
		void setTrain(const char* train_name, int train_id);

		bool isEmpty() const;

		void display() const;

		void loadCargo(Cargo train_cargo);

		void unloadCargo();
	};
}
#endif 