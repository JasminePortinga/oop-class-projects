//function file
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<locale>

using namespace std;
	
vector <int> vecInit(10) { //vector vecInit with 10 items, initialized to the integers values
		{862.3, 0.00116
	},
	{ 5.06, 0.198 },
	{ 1.36, 0.74 },
	{ 7.23, 0.14 },
	{ 0.92, 1.08 },
	{ 7.83, 0.13 },
	{ 83.25, 0.012 },
	{ 151.8, 0.0066 },
	{ 16.48, 0.061 },
	{ 92.38, 0.011 }
};
vector <string> cntyInit(10) { //vector cntyInit string, with 10 countries 
	Argentina Peso, Brazilian Real, Canadian Dollar, Chinese Yuan, Euro, Hong Kong Dollar, Indian Rupee,
		Japanese Yen, Mexican Peso, Russian Ruble
};
void outputVector() { //output the countries with the currencies in form of list
	for (int country : cntyInit) { //for loop for showing the countries 
		cout << country + 1  << "  ";
		for (int currency : vecInit) { //output the currency values by side of the countries 
			cout << currency + 1 << "  ";
		}
		endl; //one line for each country with the currency
	}
	cout << endl;
}

	double convertion
int main() {

}