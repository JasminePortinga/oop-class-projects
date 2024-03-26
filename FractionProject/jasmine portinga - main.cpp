#include "subfiles/Fraction.h"
#include "subfiles/Fraction.cpp"

int main() {
	Fraction frac1(-12, 15, 3, 15);
	Fraction frac2(1, 4, 2, 7, 13, -2, 5, 2);
	Fraction frac3(0, 3, 2, 7, -18, 2, -3, -4);
	Fraction frac4(1, 2, -3, 4);
	Fraction frac5(2, 5, 3, -8, 1, 3, -2, 15);
	frac1.display();
	frac2.display();
	frac3.display();
	frac4.display();
	frac5.display();
	return 0;
}