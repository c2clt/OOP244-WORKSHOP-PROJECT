/* ------------------------------------------------------
Final Project Milestone 5
Module: Car and Motorcycle
Filename: ms5_CarMotorcycleTester.cpp
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date       Reason
2020/3/31  tester of Car and Motorcycle modules
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

/*comment out car or motorcycle include and functions to test
individually.
*/

#include <iostream>
#include "Car.h"
#include "Motorcycle.h"

using namespace std;
using namespace sdds;

void  MotorcycleTest(Vehicle*);
void  CarTest(Vehicle*);

int main() {
   cout << "Milestone 5, Car and Motorcycle: " << endl;
   CarTest(new Car);
   MotorcycleTest(new Motorcycle);
   return 0;
}

void  MotorcycleTest(Vehicle* V) {
   cout << "Motorcycle Test:" << endl << endl << "Invalid object printout: " <<endl;
   cout << *V << endl;
   cout << "Testing Console Entry, Enter the following: " << endl
      << "ab12<ENTER>" << endl
      << "Harley Davidson<ENTER>" << endl
      << "yes<ENTER>" << endl
      << "y<ENTER>" << endl;
   // test Motorcycle::read() with isCsv() == false
   cin >> *V;
   V->setCsv(true);
   // test Motorcycle::write() with isCsv() == ture
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   // test Motorcycle::write() with isCsv() == false and hasSidecar == true
   cout << "Console Printout: " << endl << *V << endl;
   cout << "Testing CSV Entry, Enter the following: " << endl
      << "12,AA22,Honda CD80,0<ENTER>" << endl;
   V->setCsv(true);
   // test Motorcycle::read() and write() with isCsv() == true
   cin >> *V;
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   // test Motorcycle::write() with isCsv() == false and hasSidecar == false
   cout << endl << "Console Printout: " << endl << *V << endl;
   delete V;
}

void  CarTest(Vehicle* V) {
    // test empty Car()
   cout << "Car Test:" << endl << endl << "Invalid object printout: " << endl;
   cout << *V << endl; 
   cout << "Testing Console Entry, Enter the following: " << endl
      << "abc123<ENTER>" << endl
      << "Chevy Volt<ENTER>" << endl
      << "yes<ENTER>" << endl
      << "y<ENTER>" << endl;
   // test Car::read() with isCsv() == false
   cin >> *V;
   V->setCsv(true);
   // test Car::write() with isCsv() == true
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   // test Car::write() with isCsv() == false and carWash == true
   cout << "Console Printout: " << endl << *V << endl;
   cout << "Testing CSV Entry, Enter the following: " << endl
      << "12,GVAA123,Nissan Leaf,0<ENTER>" << endl;
   V->setCsv(true);
   // test Car::read() with isCsv() == true
   cin >> *V;
   cout << endl << "Comma Separated Values: " << endl << *V << endl;
   V->setCsv(false);
   // test Car::write() with isCsv() == false and carWash == false
   cout << endl << "Console Printout: " << endl << *V << endl;
   delete V;
}