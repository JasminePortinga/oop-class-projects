//function file
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<locale>
#include <stdexcept>

using namespace std;
vector<vector<double>> vecInit{ //vector vecInit with 10 items, initialized to the integers values
	{862.3, 0.00116},
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
vector <string> cntyInit{ //vector cntyInit string, with 10 countries 
	"Argentina Peso", "Brazilian Real", "Canadian Dollar", "Chinese Yuan", "Euro", "Hong Kong Dollar", "Indian Rupee",
		"Japanese Yen", "Mexican Peso", "Russian Ruble"
};

int main() {
	//showing the coutries with the currency database
	for (int country; country <= cntyInit.size(); country++)
	{
		country = cntyInit[country + 1];
		cout << country << "  ";
		for (int currency; currency <= vecInit.size(); currency++) {
			currency = vecInit[currency +1];
			cout << currency << " ";
		}
		cout << endl;
	}
}