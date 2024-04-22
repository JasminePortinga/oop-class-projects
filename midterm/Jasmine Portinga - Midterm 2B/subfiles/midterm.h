//jasmine portinga midterm 2b

#ifndef midterm_project
#define midterm_project
#include <array>
#include <string>
#include <iomanip>
class UsCurrency {
public:
	UsCurrency(){}; //default constructor
	UsCurrency(std::array<double, 6>, std::array<double, 6>); //hard code them as 6 for now

	void billInit(std::array<double, 6>&);
	void coinInit(std::array<double, 6>&);
	void display();
	//void billChange();
	void coinsChange(double);
	int cr(double); //stands for 'coin rounder' bc i'm lazy; rounds the double values up for use of switch/case

private:
	std::array<double, 6>bills, coins; //2 arrays of size 6 named bills n coins
};

#endif //end header