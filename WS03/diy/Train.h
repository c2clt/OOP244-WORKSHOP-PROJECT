/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// ID: 119766194
// email: jzhou175@myseneca.ca
// Train.h: defining the date members and function prototypes for module Train
// OOP244 Workshop 3: DIY-Classes & Privacy
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TRAIN_H__
#define SDDS_TRAIN_H__

const int MAX_NAME = 30;
const int MAX_DESC = 20;
const double MAX_WEIGHT = 700.555;
const double MIN_WEIGHT = 40.444;

namespace sdds {

	class Cargo {

		char description[MAX_DESC + 1];
		double weight;

	public:

		void init(const char* cargo_desc, double cargo_weight);

		void setDescription(const char* cargo_desc);

		void setWeight(const double cargo_weight);
		
		char* getDescription();

		double getWeight();	
	};

	class Train {

		char name[MAX_NAME + 1];
		int id;
		Cargo* cargo;

	public:
		void setTrain(const char* train_name, int train_id);

		bool isEmpty() const;

		void display() const;

		bool swapCargo(Train& train);

		bool increaseCargo(double cargo_weight);

		bool decreaseCargo(double cargo_weight);

		void loadCargo(Cargo train_cargo);

		void unloadCargo();
	};
}
#endif 