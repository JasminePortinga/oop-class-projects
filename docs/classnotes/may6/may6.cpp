#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// using namespace std;

// today we are learning about. subclasses i think
// let's say we have a class called Geometry2D w/instances obj1, obj2
// Geometry2D obj3 = obj1.area() + obj2.area(); // can we do that? lol no
// Geometry2d obj4 = obj1.perim() + obj2.perim(); // this should actually be done as like. obj4.width = obj1.with() + obj2.width() & obj4.length = obj1.length() + obj2.length();
//  this is pretty much what function overloading is for
//  unrelated. but function overloading Is smth i wish js had.

// keyword Explicit allows for user-defined constructors or something
//  say you have a class called Complex. you can also overwrite the basic i/o operators like
//  Complex operator+(const Complex&) const; //addition
//  Complex operator-(const Complex&) const; //subtraction
//  Complex operator*(const Complex&) const;
//  Complex operator/(const Complex&& operand2) const;

class Complex
{
public:
	// friend functions aren't part of the class, but they need to access stuff inside, hence why they're defined inside it
	friend std::ostream &operator<<(std::ostream &osObject, const Complex &complex) {
		osObject << complex.real;
		osObject << " + ";
		osObject << complex.imaginary;
		osObject << "i";
		return osObject;
	};
	friend std::istream &operator>>(std::istream & isObject, Complex &complex) {
		char ch;
		// isObject >> ch; //step a
		isObject >> complex.real; //step b
		// isObject >> ch; //step c
		isObject >> complex.imaginary; //step d
		// isObject >> ch; //step e

		// user input MUST be as (a,b) unless you want to do try/catch. which is my beloved
		return isObject; //return the istream obj
	};

	~Complex()
	{
		// intPtr = nullptr;
		// delete intPtr;
		std::cout << "\nCalling complex Destructor.\n"; // default constructor
	};

	explicit Complex(double r= 0.0, double i= 0.0) {
		real = r;
		imaginary = i;
	}; // user-defined constructor

	// notice how the data type parameters for all these operator overloaders are the class itself. we can overload more than just these four, but Watch Out
	Complex operator+(const Complex &operand2) const { // these have to be constant so that we're not changing whatever the original value is, since we're passing them by address
	return Complex{real + operand2.real, imaginary + operand2.imaginary};
	};	  // addition
	Complex operator-(const Complex &operand2) const {
		return Complex{real - operand2.real, imaginary - operand2.imaginary};
	};	  // subtraction
	Complex operator*(const Complex &operand2) const {
		Complex tmp;
		tmp.real = real * operand2.real + (-1) * imaginary * operand2.imaginary; // real * real - imaginary * imaginary, then
		tmp.imaginary = real * operand2.imaginary + imaginary * operand2.real; // real * imaginary foiling
		return tmp;
	};
	Complex operator/(const Complex & operand2) const {
		Complex tmp;

		return tmp;
	};
	std::string toString() const;

private:
	double real; //real part
	double imaginary; //imaginary part
	// double* intPtr;

};

using namespace std;

int main()
{
	Complex x;
	Complex y{4, 8}; //y = 4+8i
	Complex z{3, -1}; //z = 3 - i

	cout << "Enter a complex number in the form a+b: ";
	cin >> y;
	cout << "Your complex number is: " << y << endl << endl;
	x = y + z;
	cout << "Let x = y + z: " << endl;
	cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl << endl;
	return 0;
}