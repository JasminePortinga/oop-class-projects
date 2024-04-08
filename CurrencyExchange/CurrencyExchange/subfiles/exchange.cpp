//function file
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<locale>
#include <stdexcept>

using namespace std;

int vec_size{10}; //initialize to 10

vector<vector<double>> vecInit{ //vector vecInit with 10 items, initialized to the integers values
	{862.3, 0.00116}, //peso
	{ 5.06, 0.198 }, //brazilian real 
	{ 1.36, 0.74 }, //canadian dollar
	{ 7.23, 0.14 }, //cn yuan
	{ 0.92, 1.08 }, //euro
	{ 7.83, 0.13 }, //hk dollar
	{ 83.25, 0.012 }, //indian rupee
	{ 151.8, 0.0066 }, //jpy
	{ 16.48, 0.061 }, //mexican peso
	{ 92.38, 0.011 } //russian ruble
};
vector <string> cntyInit{ //vector cntyInit string, with 10 countries 
	"Argentina Peso", "Brazilian Real", "Canadian Dollar", "Chinese Yuan", "Euro", "Hong Kong Dollar", "Indian Rupee",
		"Japanese Yen", "Mexican Peso", "Russian Ruble"
};
void outputVector() { //output the countries with the currencies in form of list

    for (int i{0}; i<vec_size; i++) {
        cout << setw(35) << cntyInit[i] << setw(10) << vecInit[i][0] << endl;
    }
	/*for (double &currency : vecInit) { //for loop for showing the countries 
		//cout << country + 1 << "  ";
		//for (int currency : vecInit) { //output the currency values by side of the countries 
        for (std::string country : cntyInit) {
			//cout << currency + 1 << "  ";
		}
		cout << endl; //one line for each country with the currency
	}*/
	cout << endl;
}

class country {
    country(std::string name, double to_foreign, double rate);
    public:

    private:
};

int main() {

    outputVector();

    /*
	vector<vector<double>> vec{ //vector vecInit with 10 items, initialized to the integers values
		{ 862.3, 0.00116 },
		{ 5.06, 0.198 },
		{ 1.36, 0.74 },
		{ 7.23, 0.14 },
		{ 0.92, 1.08 },
		{ 7.83, 0.13 },
		{ 83.25, 0.012 },
		{ 151.8, 0.0066 },
		{ 16.48, 0.061 },
		{ 92.38, 0.011 }
	};*/


}