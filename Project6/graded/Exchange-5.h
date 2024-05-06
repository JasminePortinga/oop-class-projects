//File Name: Exchange.h

#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <iostream>
#include <string>  // Enables string modification
#include <vector> 

class Exchange
{
	private:
		std::vector<std::string> countries;
		std::string country;
		std::vector<std::vector<float>> exch;
		int conversionChoice;
		int count{ 0 };

	public:
		Exchange();
		Exchange(std::string cnty, std::vector<float>& currency);

		void vecInit(std::vector<std::vector<float>>);	
		void vecInit(std::vector<std::vector<float>>*);
	// ==>	void vecInit(Add a 2-dimensional vector pointer of type float as a parameter);
	//void checkVec();

//		void cntyInit(std::vector<std::string>&);
		void cntyInit(std::vector<std::string>);
		void cntyInit(std::vector<std::string>*);
	// ==>	void cntyInit(Add a string vector pointer as a parameter);

		void addCoun(std::vector<std::string>);
	// ==>	void addCoun(Add a string vector as parameter);

		void addCurr(std::vector<std::vector<float>>);
	// ==>	void addCurr(Add a 2-dimensional vector as a paramter);

		void US_Foreign(double);
	// ==>	void US_Foreign(Add a parameter of type double as an amount to be converted);

		void Foreign_US(double);
	// ==>	void Foreign_US(Add a parameter of type double as an amount to be converted);

		void Display(int);
		void showCur(double);
};

#endif 