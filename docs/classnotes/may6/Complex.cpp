// Fig. 10.15: Complex.cpp
// Complex class member-function definitions.
#include <string>
#include <iostream>
#include <cmath>
#include "Complex.h" // Complex class definition
using namespace std;

// Complex::Complex() {}; // Default constructor

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
    : real{realPart}, imaginary{imaginaryPart} {}

ostream &operator<<(ostream &osObject, const Complex &complex)
{
    //    osObject << "(";                    //Step a
    osObject << complex.real; // Step b
    bool img0{(complex.imaginary == 0)};
    if (!(complex.imaginary == 0)) { //if the imaginary component is not 0
        osObject << ((complex.imaginary < 0) ? " - " : " + ");
        if ((abs(complex.imaginary) != 1.0)) { //if it's not just 1
            osObject << abs(complex.imaginary);
        }
        osObject << "i";
    }
    // osObject << ((complex.imaginary < 0) ? " - " : " + "); // Step c
    // osObject << complex.imaginary;  //Step d
    // osObject << ((complex.imaginary == 1) ? "" : ((complex.imaginary < 0) ? complex.imaginary * -1 : complex.imaginary));
    //osObject << "i"; // Step e
    //    osObject << ")";                    //Step f

    return osObject; // return the ostream object
}

istream &operator>>(istream &isObject, Complex &complex)
{
    char ch;

    //    isObject >> ch;                     //Step a
    isObject >> complex.real; // Step b
    //    isObject >> ch;                     //Step c
    isObject >> complex.imaginary; // Step d
    //    isObject >> ch;                     //Step e

    return isObject; // return the istream object
}

// addition operator
Complex Complex::operator+(const Complex &operand2) const
{
    return Complex{real + operand2.real, imaginary + operand2.imaginary};
}

// subtraction operator
Complex Complex::operator-(const Complex &operand2) const
{
    return Complex{real - operand2.real, imaginary - operand2.imaginary};
}

Complex Complex::operator*(const Complex &operand2) const
{
    Complex tmp;
    tmp.real = real * operand2.real + (-1) * imaginary * operand2.imaginary;
    tmp.imaginary = real * operand2.imaginary + imaginary * operand2.real;
    return tmp;
}

Complex Complex::operator/(const Complex &operand2) const
{
    Complex tmp;
    Complex conjugate; //declare an instance for the conjugate
    conjugate.imaginary = operand2.imaginary * -1; // set the imaginary aspect to the 2nd operand's imaginary component
    // tmp.real = real*denom.imaginary;
    // tmp.imaginary = imaginary * 
    // tmp = this * conjugate;
    return tmp;
}

double Complex::getReal() {return real;}
double Complex::getImagine() {return imaginary;}

// return string representation of a Complex object in the form: (a, b)
string Complex::toString() const
{
    return to_string(real) + " + " + to_string(imaginary) + "i";
}

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
