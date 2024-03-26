#include "./Fraction.h"
#include <string>
#include <cmath>

Fraction::Fraction(){}; // default
Fraction::Fraction(int a, int b, int c, int d)
{
	this->setn1(a);
	this->setd1(b);
	this->setn2(c);
	this->setd2(d);
	this->numParam(4);
}; // simple addition
Fraction::Fraction(int a, int b, int c, int d, int e, int f, int g, int h)
{
	this->setn1(a);
	this->setd1(b);
	this->setn2(c);
	this->setd2(d);
	this->setn3(e);
	this->setd3(f);
	this->setn4(g);
	this->setd4(h);
	this->numParam(8);
	this->isComplexFrac();
}; // complex addition

// setting props (only really used in the constructors rn)
void Fraction::setn1(int n) { num1 = n; }
void Fraction::setd1(int d) { den1 = d; }
void Fraction::setn2(int n) { num2 = n; }
void Fraction::setd2(int d) { den2 = d; }
void Fraction::setn3(int n) { num3 = n; }
void Fraction::setd3(int d) { den3 = d; }
void Fraction::setn4(int n) { num4 = n; }
void Fraction::setd4(int d) { den4 = d; }
// fetching private vars
int Fraction::n1() { return num1; }
int Fraction::n2() { return num2; }
int Fraction::n3() { return num3; }
int Fraction::n4() { return num4; }
int Fraction::d1() { return den1; }
int Fraction::d2() { return den2; }
int Fraction::d3() { return den3; }
int Fraction::d4() { return den4; }

// set as complex fraction
void Fraction::isComplexFrac() { complex_fraction = true; }
void Fraction::numParam(int a) { num_params = a; }
// strings
std::string Fraction::condFrac(fr_unit a)
{
	return "(" + std::to_string(abs(a.n())) + "/" + std::to_string(abs(a.d())) + ")";
}
std::string Fraction::sign(fr_unit a)
{
	return ((double(a.n()) / a.d() >= 0) ? " + " : " - "); // if the signs cancel out, then it's +, otherwise it's -. also have to make sure that we're using a double in one of the numbers, or else we end up with false positives
}
std::string Fraction::posneg(fr_unit a) {
	//bool isneg{(double(a.n())/a.d() >= 0)};
	return ((double(a.n())/a.d() >= 0) ? " " : "-"); //adds a negative sign if necessary
}
// basic function for adding two fraction units together
double Fraction::add_frac(fr_unit a, fr_unit b)
{
	if (a.d() == 0 || b.d() == 0)
	{ // if either fraction has 0 as a denominator
		std::cout << "\nNice try, professor. I know you can't have a fraction with a denominator of 0. Exiting program.\n";
		exit(0); // leave
	}
	int new_num = a.n() + b.n(); // by default, new numerator is the two numerators added together
	int new_denom = b.d();		 // if the fractions have the same denominator, it doesn't matter which one is picked
	if (a.d() != b.d())
	{												 // otherwise, if they're different, redeclare
		new_num = (a.n() * b.d()) + (b.n() * a.d()); // cross-multiply
		new_denom = (a.d() * b.d());				 // mult denominators together
	}
	//return (new_num%new_denom == 0) ? int(new_num/new_denom) : (double(new_num) / new_denom); // have to specify double on the numerator or else we'll end up w/the wrong answer somewhere
	return double(new_num)/new_denom;
}
// function for the result
double Fraction::add()
{
	fr_unit f1(num1, den1), f2(num2, den2); // will need at least two anyway
	if (complex_fraction)
	{
		fr_unit f3(num3, den3), f4(num4, den4);
		double num = add_frac(f1, f2);
		double den = add_frac(f3, f4);
		result = num / den;
	}
	else
	{
		result = add_frac(f1, f2);
	}
	return result;
}

// functions for showing the addition of two fractions
std::string Fraction::show_num(fr_unit a, fr_unit b) {
	std::string gap{" "};
	for(int i = -1; i <= (a.nw() + b.nw()); i++) {gap += " ";}
	return "\t" + posneg(a) + std::to_string(abs(a.n())) + gap + std::to_string(abs(b.n())) + "\n"; //numerator line
}
std::string Fraction::show_den(fr_unit a, fr_unit b) {
	std::string gap{" "};
	for(int i = -1; i <= (a.dw() + b.dw()); i++) {gap += " ";}
	return "\t " + std::to_string(abs(a.d())) + gap + std::to_string(abs(b.d())) + "\n"; //denominator line
}
std::string Fraction::show_line(fr_unit a, fr_unit b) {
	std::string sn{sign(b)};

	return  "\t" + line.substr(0, a.w()) + sign(b) + line.substr(0,b.w()) + (complex_fraction ? "" : " = " + std::to_string(add())) /* if it's not a complex fraction, then show the = sign and answer */ + "\n"; //dividing line
}
std::string Fraction::show_add(fr_unit a, fr_unit b)
{
	std::string str{""};
	str += show_num(a, b);
	str += show_line(a, b);
	str += show_den(a, b);
	return str;
}
std::string Fraction::show_add(fr_unit a, fr_unit b, fr_unit c, fr_unit d) {
	line += line; //double the available length of the line lol
	std::string str{""};
	std::string num = show_line(a, b); //the big middle line
	str += show_add(a,b) + "\t" + line.substr(0, num.length()) + " = " + std::to_string(add()) + "\n" + show_add(c, d) + "\n";
	return str;
}

// function for the display
void Fraction::display()
{
	fr_unit f1(num1, den1), f2(num2, den2);
	if(complex_fraction) {
		fr_unit f3(num3, den3), f4(num4, den4);
		std::cout << "\nEvaluation of a complex fraction:\n" << show_add(f1, f2, f3, f4);
	} else {
		std::cout << "\nSimple addition of fractions:\n" + show_add(f1, f2);
	}
}