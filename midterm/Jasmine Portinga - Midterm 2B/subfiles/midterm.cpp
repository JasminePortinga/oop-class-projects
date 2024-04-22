//jasmine porting midterm 2b | functions file
#include <array>
#include <string>
#include <iomanip>
UsCurrency::UsCurrency(std::array<double, 6>b, std::array<double, 6>c) {
	billInit(b);
	coinInit(c);
};
void UsCurrency::billInit(std::array<double, 6>&b) { 
	bills = b;
};
void UsCurrency::coinInit(std::array<double, 6>&c) {
	coins = c;
};

void UsCurrency::display() {
	std::cout << std::fixed << std::setprecision(0) << "US Currency in bills:\n";
	for (int i{0}; i < bills.size(); i++) {
		std::cout << std::setw(15) << bills[i];
	}
	std::cout << std::setprecision(2); //change precision for coins
	std::cout << "\n\nUS Currency in coins:\n";
	for (int i{0}; i < coins.size(); i++) {
		std::cout << std::setw(15) << coins[i]; //display the various coin values
	}
	std::cout << "\n\n";
}

void UsCurrency::coinsChange(double a) {
	for (int i{0}; i < coins.size(); i++) {
		//std::cout << std::setw(20) << names[i] << " -> ";// << (cr(a) % cr(coins[i])) << std::endl;
		//int mod = cr(a)%cr(coins[i]);
		if (a >= coins[i]) { //if the current amt is greater than the coin value
			std::string n = ""; //init coin name to nothing
			//these got hard-coded bc otherwise there would have to be an array of strings for names, which would then also have to get initialized
			switch(cr(coins[i])) {
				case 1: n = "Penny"; break;
				case 5: n = "Nickel"; break;
				case 10: n = "Dime"; break;
				case 25: n = "Quarter"; break;
				case 50: n = "Half-Dollar"; break;
				case 100: n = "Dollar"; break;
			};
			int num = floor(cr(a)/cr(coins[i])); //find the number of coins; must use coin rounder f'n or else pennies don't work properly, probably bc of floating point nonsense
			//std::cout << "cr(coins[i]) = " << cr(coins[i]) << std::endl;
			std::cout << std::setw(20) << n << " -> " << num << std::endl; // display it
			a = a - (coins[i]*num); //and subtract it from a for the next loop
			//std::cout << std::endl;
			//std::cout << " (subtracted " << (coins[i]) << " * " << num << " = " << (coins[i]*num) << " for " << a << " left)" << std::endl;
		}
	}
	//std::cout << "Half-Dollar -> " << (a%coins[5]);
}

int UsCurrency::cr(double a) {
	return round(a*100);
}