// function file
#include "./exchange.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

/* country class */
// constructor w/country name n two exchange rates
country::country(std::string n, std::string c, double t_f, double t_u)
{
	this->setName(n);
	this->setCurrency(c);
	this->setForeignRate(t_f);
	this->setUSDRate(t_u);
}

// set functions
void country::setForeignRate(double t_f)
{
}
void country::setUSDRate(double t_u) {}
void country::setName(std::string n) {}
void country::setCurrency(std::string c) {}

// get functions
double country::getFR() {}
double country::getUSR() {}
std::string country::getName() {}
std::string country::getCurrency() {}

/* exchange class */
exchange::exchange() {
	this->cntyInit();
}
// put all the cities into a vector. hard-coded is okay
void exchange::cntyInit()
{
	addCtry("Argentina","Argentinian Peso", 862.3, 0.0016);
	addCtry("Brazil", "Brazilian Real", 5.06, 0.198);
	//etc
}
// made a function for adding countries to the vector it bc i'm lazy and also it will be necessary for later
void exchange::addCtry(std::string n, std::string c, double t_f, double t_u)
{										// adding object instances into a vector: https://stackoverflow.com/questions/15802006/how-can-i-create-objects-while-adding-them-into-a-vector
	ctries.push_back(country(n, c, t_f, t_u)); 
}
//bc the looped version of the conversion display is different from the initial one, greeting() should include the unique conversion display
void exchange::greeting() {}
//y'know, like a bank teller window lol
void exchange::window() {
	//first ask whether the user would like to convert to foreign currency or to usd. save this as a variable
	//then, ask how much they'd like to convert. this number should be either a float or a double, unless you want to specify "whole dollars only"
	//then, display all the available countries n their conversion rates in their neat three columns. make sure they're numbered for the user to call on them! this should be a loop going through the ctries vector for the relevant info
	//then ask the user which country they'd like to convert the currency to, input as an integer. if they enter a number greater than 12, return an error and ask them to reenter a number
	//take that integer and use it to locate that country's object instance in the vector
	//call upon the relevant function for conversion 
	//no need to ask if they'd like to continue, as that's in the main loop
}
//these conversion functions take integers bc those integers will be the index of the country we're referencing in the vector
//bc they are void f'ns, they should also have a cout to display the final numbers
void exchange::convForeign(int i) {}
void exchange::convUSD(int i) {}