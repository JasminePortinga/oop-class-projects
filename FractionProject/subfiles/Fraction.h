#pragma once
#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

class Fraction {
	public:

	class fr_unit{ //individual fraction instances
		public:
		fr_unit(int n, int d) {
			this->setn(n);
			this->setd(d);
			this->setww();
		}

		//setting and getting numerator and denominator
		void setn(int n) {num=n;}
		int n() {return num;} //get num
		void setd(int d) {den = d;}
		int d() {return den;} //get den

		void setww() {
			std::string n = std::to_string(num);
			std::string d = std::to_string(abs(den));
			if (n.length() >= d.length()) { //if the numerator is longer than the denominator
				W += n.length(); //sets the width
				NW = ceil((W-1)/2);
				DW = ceil((W - d.length())/2);
			} else {
				W += d.length();
				NW = ceil((W - n.length())/2);
				DW = ceil((W-1)/2);
			}
		}
		int w() {return W;}
		int nw() {return NW;}
		int dw() {return DW;}
		private:
		int W{2}, NW{0}, DW{0}, num{0}, den{1}; //width, numerator width, denominator width, numerator, denominator
	}; //END of fraction unit class

	Fraction(); //default
	Fraction(int, int, int, int); //simple addition
	Fraction(int, int, int, int, int, int, int, int); //complex addition

	//setting props (only really used in the constructors rn)
	void setn1(int), setd1(int), setn2(int), setd2(int), setn3(int), setd3(int), setn4(int), setd4(int);
	//fetching private vars
	int n1(), n2(), n3(), n4(), d1(), d2(), d3(), d4();

	//set as complex fraction, num params
	void isComplexFrac(), numParam(int);
	//strings
	std::string condFrac(fr_unit), sign(fr_unit), posneg(fr_unit);
	//basic function for adding two fraction units together
	double add_frac(fr_unit, fr_unit);
	//function for the result
	double add();

	//functions for showing the addition of two fractions
	std::string show_num(fr_unit, fr_unit);
	std::string show_den(fr_unit, fr_unit);
	std::string show_line(fr_unit, fr_unit);
	std::string show_add(fr_unit, fr_unit);
	std::string show_add(fr_unit, fr_unit, fr_unit, fr_unit); //overloading for the complex ver

	//function for the display
	void display();

	private:
	int num1{0}, den1{1}, num2{0}, den2{ 1 }, num3{0}, den3{ 1 }, num4{0}, den4{ 1 }, num_params{0}; //init numerators to 0 and denominators to 1 so that no 0/0 errors
	double result{ 0 }; //this is used in the version that forces you to do this.add() in the main function. to only have to do this.display() in main, you'd change the display function to cout add() at some point
	bool complex_fraction{ false }; //a var for us to know if this particular instance is a complex fraction
	std::string line{ "----------------" }; //used for drawing the lines of fractions and whatnot
};

#endif //end if FRACTIONS_H