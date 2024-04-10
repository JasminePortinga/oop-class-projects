// main function

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <iomanip>
#include "subfiles/exchange.h"
#include "subfiles/exchange.cpp"

//global var done outside of the class bc i don't want to bother with the get/set f'ns of the exchange instance
char ans{'n'}; //for the continuation loop
void cont();

int main()
{
	//int i{0}; //for the index of the country whose currency is being examined
	exchange exchange;
	//exchange.cntyInit(); //initialize
	exchange.greeting();
	//add the two countries after the first time
	exchange.addCtry("Cuba", "Cuban Peso", 24.01, 0.042);
	exchange.addCtry("Philippines", "Philippine Peso", 56.54, 0.018);
	cont();
	while(toupper(char(ans))=='Y') {
		exchange.window();
		cont();
	}
	return 0;
}

void cont() {
	std::cout << "Would you like to continue? Enter Y/y to continue: ";
	std::cin >> ans;
	std::cout << std::endl;
}