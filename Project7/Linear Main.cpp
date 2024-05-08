//Week 13 Project - Spring 2024
// Based on the example Complex.h and Complex.cpp, modify the Complex class 
//into a class Linear{} of the form ax + b.
// Your output should look like the one on Canvas. 
// Replace the * operator with the == operator to compare two linear equation.
//This operator overloading is of type bool.
//


// Linear class test program.
#include <iostream>
#include "Linear.h"
#include "Linear.cpp"

using namespace std;

int main() {
	Linear x;
	Linear y{ 4, 8 };
	Linear z{ 3, -10 };

	   cout << "x: " << x << "\ny: " << y << "\nz: " << z;

		x = y + z;
		cout << "\n\nx = y + z:\n" << x << " = " << y << " + " << z;

		x = y - z;
		cout << "\n\nx = y - z:\n" << x << " = " << y
			<< " - " << z << endl << endl;


	//Test your overloaded operator -- here.
		cout << "Comparing y & z:" << endl;
		cout << "x = y * z: " << endl;
		// cout << x * y;
		y.mult(z);
		cout << " == (" << y << ") * (" << z << ")";
	// .................
	// .................	

}


