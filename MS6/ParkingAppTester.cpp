/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ParkingAppTester.cpp
Author: Jingmin Zhou (Jessica)
-----------------------------------------------------------
Date        Reason
2020/04/05  Tester of the Parking Application
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"

using namespace std;
using namespace sdds;

void ShowDatafile() {
   char ch;
   ifstream file("ParkingData.csv");
   cout << endl << "Content of ParkingData.csv after the program exits" << endl;
   cout << "-----------------------------------------------------------" << endl;
   while (file.get(ch)) {
      cout <<char(tolower(ch));
   }
   cout << "-----------------------------------------------------------" << endl; 
}

void pause() {
    cout << "Press Enter to Continue...";
    while (getchar() != '\n');
}

int main() {
   Parking P("ParkingData.csv", 11);
   cout << "Pass 1: ------->" << endl;   
   P.run();
   ShowDatafile();
   cout << "<------------------------" << endl;
   pause();
   cout << "Pass 2: ------->" << endl;
   P.run();
   ShowDatafile();
   cout << "<------------------------" << endl;
   pause();
   cout << "Pass 3: ------->" << endl;
   P.run();
   ShowDatafile();
   
   return 0;
}
