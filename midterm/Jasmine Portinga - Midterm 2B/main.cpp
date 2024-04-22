// object-oriented programming midterm 2b | Jasmine Portinga

#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include "subfiles/midterm.h"
#include "subfiles/midterm.cpp"
#include "subfiles/jkp_std.h"

using namespace std;

int main() {
	project midterm; //from my own header file to make titling solo projects easier
	midterm.title("Midterm 2B: Coin Exchange");

	array<double, 6>b = {1, 5, 10, 20, 50, 100};
	array<double, 6>c = {1, 0.5, 0.25, 0.1, 0.05, 0.01}; //reversed the order from the canvas output so that i can use loops in the coins change. could've used <algorithm> to copy this over and sort a copy of an array, but why bother using the extra memory
	//array<double, 6>c = {0.01, 0.05, 0.1, 0.25, 0.5, 1};

	UsCurrency exch(b, c); //create instance of the coin counter display
	exch.display();

	double amount{0.0}; //initialize to 0
	cout << "Enter the amount to convert to coins (Less than $5): ";
	cin >> amount;
	exch.coinsChange(amount);

	return 0;
}