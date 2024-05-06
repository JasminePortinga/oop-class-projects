//Math 173 - Spring 2024
//Week 12 Lab - Group project 3 
//
//Comments: The exchange from US $ to other currency is incorrect. Did you
//			look at the output on Canvas?
//			Jasmine works look good. Good to check the vector after each initialization.
//			The addCoun() function is misplaced in your main. Did you check that after 
//			3 runs, it keeps adding Cuban and Phillipine into the private vector countries<>?
//			How can you fix that?
//Grade: 85/100		


#include <iostream>
#include <iomanip> // Enable setprecision()
#include <string>  // Enables string modification
#include <vector>
#include "Exchange-5.h"
#include "Exchange-7.cpp"

using namespace std;

int main()      // main program
{
	char ans{ 'y' };
	int method{ 0 }, choice;
	double amt{ 0 };

	vector <string> country{ "Argentina Peso", "Brazilian Real", "Canadian Dollar", "Chinese Yuan", "Euro",
					"Hong Kong Dollar", "Indian Rupee", "Japanese Yen", "Mexican Peso", "Russian Ruble" };

	vector<vector<float>> vec{
		{862.3, 0.00116},
		{5.06, 0.198},
		{1.36, 0.74},
		{7.23, 0.14},
		{0.92, 1.08},
		{7.83, 0.13},
		{83.25, 0.012},
		{151.8, 0.0066},
		{16.48, 0.061},
		{92.38, 0.011}
	};


	//Add a 2-dimensioanl vector pointer named vecPtr and initialize it to the vector vec<<>> above.
		// ......................


	//Add a 1-dimensinal vector of type string named countryPtr and initialize it to the vector country above.
		// ......................
		// string countryPtr* = &country;
		// vector<float> vecPtr* = vec;
	auto countryPtr = new vector<string>;
	auto vecPtr = new vector<vector<float>>;
	countryPtr = &country;
	vecPtr = &vec;
	bool addCurr{ false };

	Exchange exch;
	// exch.cntyInit(country);		//Test this function and the the next overloading function.		
	exch.cntyInit(countryPtr);
	//exch.vecInit(vec);		//Test this function and the the next overloading function.
	exch.vecInit(vecPtr);

	//
	//	Display the header as in the outpuy on Canvas
	//

	while (tolower(ans) == 'y') {

		cout << endl << setw(10) << "Enter 1 to convert from US $ to other currency." << endl;
		cout << setw(10) << "2 to convert from other currency to US $: ";
		cin >> choice;
		cout << endl << endl;

		if (choice == 1) {
			cout << "Enter the amount of dollars to be converted: ";
			cin >> amt;
			exch.US_Foreign(amt);
			//Call the function US_Foreign() to shows the coversion from US $ to foreign currencies.

		}
		else if (choice == 2) {
			cout << "Enter the amount of foreign currency to be converted: ";
			cin >> amt;
			exch.Foreign_US(amt);
			//exch.showCur();
			//exch.Display();
			//Call the function Foreign_US() to shows the conversion from foreign currency to US $.
		}

		vector<vector<float>> vecAdd{ {862.3, 0.00116},{ 56.54, 0.018 } };
		vector<string> cntyAdd{ "Cuban Peso" , "Philippine Peso" };

		//Call the function addCoun() to add the vector vecAdd<> to the PRIVATE vector exch<<>>.
		//Call the function addCurr() to add the vector cntyAdd to the PRIVATE vector countries<>.
		if (!addCurr) {
			exch.addCoun(cntyAdd);
			exch.addCurr(vecAdd);
		}


		cout << endl << endl << "Enter [y/Y] to continue, else enter anything : ";
		cin >> ans;
	}


	countryPtr = nullptr;
	vecPtr = nullptr;
	delete countryPtr;
	delete vecPtr;

	return 0;
}

