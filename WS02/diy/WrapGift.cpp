/***********************************************************************
// Name: Jingmin Zhou (Jessica)
// Email: jzhou175@myseneca.ca
// ID: 119766194
// Date: Jan. 22nd 2020
// DIY-OOP244 Workshop 2 (Dynamic Memory & Function Overloading)
***********************************************************************/

/* WrapGift.cpp: 
    Tests Gift module
    which the main focuses are dynamic memory allocation
*/

#include <iostream>
#include "Gift.h"
#include "Gift.h" // intentional
using namespace std;
using namespace sdds;

void initWrap(Gift& g) {
  g.wrap = nullptr;
  g.wrap_layers = 0;
}

ostream& line(int len, char ch) {
	for (int i = 0; i < len; i++, cout << ch);
	return cout;
}
ostream& number(int num) {
	cout << num;
	for (int i = 0; i < 9; i++) {
		cout << " - " << num;
	}
	return cout;
}

int main() {

  Gift g1, g2; 

  cout << "Preparing an empty Gift to be wrapped and display it" << endl;
  line(64, '-') << endl; number(1) << endl;
  gifting(g1.g_description);
  gifting(g1.g_price);
  gifting(g1.g_units);
  initWrap(g1); cout << endl;
  display(g1);

  cout << "\nAttempting to wrap the previous Gift: " << g1.g_description << endl;
  line(64, '-') << endl; number(2) << endl;
  if (wrap(g1)) cout << "Success!" << endl; else cout << "Wrapping failure!" << endl;

  cout << "\nAttempting to rewrap the previous Gift: " << g1.g_description << endl;
  line(64, '-') << endl; number(3) << endl;
  if (!wrap(g1)) cout << "Success2!" << endl; else cout << "Already wrapped failure!" << endl;

  cout << "\nAttempting to unwrap the previous Gift: " << g1.g_description << endl;
  line(64, '-') << endl; number(4) << endl;
  if (unwrap(g1)) cout << "Success3!" << endl; else cout << "Unwrapping failure!" << endl;

  cout << "\nAttempting to un-unwrap the previous Gift: " << g1.g_description << endl;
  line(64, '-') << endl; number(5) << endl;
  if (!unwrap(g1)) cout << "Success4!" << endl; else cout << "Already unwrapped failure!" << endl;

  cout << "\nPrepare another empty Gift via the combined function and display it" << endl;
  line(64, '-') << endl; number(6) << endl;
  initWrap(g2);
  gifting(g2); cout << endl;
  display(g2);

  cout << "\nEnd of main" << endl;
  unwrap(g2); 
  return 0;
}
