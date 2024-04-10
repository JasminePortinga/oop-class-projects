//header file
#ifndef CURRENCY_EXCHANGE
#define CURRENCY_EXCHANGE

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class country
{
public:
	country(){}; // default constructor
	country(std::string, std::string, double, double);
	 // constructor w/country name n the two exchange rates
	void setForeignRate(double), setUSDRate(double), setName(std::string), setCurrency(std::string);
	double getFR(), getUSR(); //shorthanded these fn names bc they will probably be used a fair bit in the exchange class for the actual exchange rate
	std::string getName();
	std::string getCurrency();

private:
	double to_foreign, to_usd; // vars for the exchange rates to the foreign currency n to usd
	std::string name, currency;		   // country & currency name
};

class exchange
{
public:
	exchange(); //default constructor
	void cntyInit();
	void addCtry(std::string, std::string, double, double);
	void greeting();
	void window();
	void convForeign(int);
	void convUSD(int);

private:
	// make the vector of exchanges out of country objects
	std::vector<country> ctries{};
};
#endif