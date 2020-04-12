/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// Email: jzhou175@myseneca.ca
// ID: 119766194
// Date: Jan. 22nd 2020
// DIY-OOP244 Workshop 2 (Dynamic Memory & Function Overloading)
***********************************************************************/

/* Gift.h:
	definition of the Gift structure with designed data members;
	declaration of the function prototypes;
	enhancing the concept of function overloads.
*/
#ifndef SDDS_GIFT_H__
#define SDDS_GIFT_H__

const int MAX_DESC = 15;
const double MAX_PRICE = 999.99;
const int MAXLEN_PATTERN = 20;

namespace sdds {

	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
		struct Wrapping* wrap;
		int wrap_layers;
	};

	struct Wrapping {
		char* pattern;
	};

	void gifting(char* g_description);

	void gifting(double& g_price);

	void gifting(int& g_units);

	void display(const Gift& gift);

	bool wrap(Gift& gift);

	bool unwrap(Gift& gift);

	void gifting(Gift& gift);

}
#endif