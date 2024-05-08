// Fig. 10.15: Linear.cpp
// Linear class member-function definitions.
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Linear.h" // Linear class definition
using namespace std;

// Linear::Linear() {}; // Default constructor

// Constructor
Linear::Linear(double linearPart, double constantPart)
    : linear{linearPart}, constant{constantPart} {}

ostream &operator<<(ostream &osObject, const Linear &Linear)
{
    //    osObject << "(";                    //Step a
    bool quad{Linear.quadratic != 0}, lin{Linear.linear != 0}, cons{(Linear.constant != 0)}; //bools for the presence of a particular 
    if (!quad && !lin && !cons) { //if none of the components exist, then just print 0
        osObject << 0;
        return osObject;
    }
    if (quad) { //first check if
        if ((abs(Linear.quadratic) != 1)) {
            osObject << (Linear.quadratic);
        }
        osObject << "x^2"; //no matter what, if there's a quadratic element, print out the x^2
        if (lin || cons) {
            osObject << ((Linear.linear < 0) ? " - " : " + ");
        }
    }
    if (lin) {
        if ((abs(Linear.linear) != 1.0)) { //if it's not just 1
            if (quad) {
                osObject << abs(Linear.linear); //if there's a quadratic element, then don't print the +/- sign, bc that got programmed into the
            } else {
                osObject << (Linear.linear);
            }
        }
        osObject << "x";
    }
    if (Linear.linear == 0 && Linear.constant == 0) {
        osObject << 0; // if they're both 0, then print only 0
    } else {
        osObject << ((Linear.constant < 0) ? " - " : " + ");
        if ((abs(Linear.constant) != 1.0)) { //if it's not just 1
            osObject << abs(Linear.constant);
        }
    }
        // osObject << ((abs(Linear.constant) != 1) ? Linear.linear : "") << "x"; // if the x-factor exists, then print it
    


    // osObject << Linear.linear; // Step b
    // bool img0{(Linear.constant == 0)};
    // if (!(Linear.constant == 0)) { //if the constant component is not 0
    //     osObject << ((Linear.constant < 0) ? " - " : " + ");
    //     if ((abs(Linear.constant) != 1.0)) { //if it's not just 1
    //         osObject << abs(Linear.constant);
    //     }
    //     osObject << "i";
    // }
    // osObject << ((Linear.constant < 0) ? " - " : " + "); // Step c
    // osObject << Linear.constant;  //Step d
    // osObject << ((Linear.constant == 1) ? "" : ((Linear.constant < 0) ? Linear.constant * -1 : Linear.constant));
    //osObject << "i"; // Step e
    //    osObject << ")";                    //Step f

    return osObject; // return the ostream object
}

istream &operator>>(istream &isObject, Linear &Linear)
{
    char ch;

    //    isObject >> ch;                     //Step a
    isObject >> Linear.linear; // Step b
    //    isObject >> ch;                     //Step c
    isObject >> Linear.constant; // Step d
    //    isObject >> ch;                     //Step e

    return isObject; // return the istream object
}

// addition operator
Linear Linear::operator+(const Linear &operand2) const
{
    return Linear{linear + operand2.linear, constant + operand2.constant};
}

// subtraction operator
Linear Linear::operator-(const Linear &operand2) const
{
    return Linear{linear - operand2.linear, constant - operand2.constant};
}

// Linear Linear::operator*(const Linear &operand2) const
// {
//     Linear tmp;
//     // in (ax + b) * (cx + d), we should end up with: 
//     tmp.quadratic = (linear * operand2.linear); // (a * c)x^2
//     tmp.linear = (constant * operand2.linear) + (linear * operand2.constant); // (bc + ad)x
//     tmp.constant = (constant * operand2.constant); // (b * d) 
//     return tmp;
// }

void Linear::mult(const Linear &operand2) const {
    // string res{""}; //init to nothing
    double quad{(linear * operand2.linear)}, lin{((constant * operand2.linear) + (linear * operand2.constant))}, cons{(constant * operand2.constant)};
    // cout << "\constant: " << cons << endl;
    bool hasQ{quad != 0}, hasL{lin != 0}, hasC{cons !=0};
    cout << setprecision(2); 
    if (!hasQ && !hasL && !hasC) {
        // res = "0";
        cout << 0;
    } else {
        if (hasQ) { //first check if there is a quadratic component
            if (abs(quad) != 1) { // then make sure that it's not just 1 before printing
                // res += to_string(quad);
                cout << quad;
            }
            // res += "x^2"; //regardless of its coefficient, print out the x^2
            cout << "x^2";

            //then check to see if there are components to follow: 
            if (hasL || hasC) {
                if (hasL) { // if the linear exists
                    // res += ((lin > 0) ? " + " : " - ");
                    cout << ((lin > 0) ? " + " : " - ");
                } else { // otherwise the only other option is that the constant must exist
                    // res += ((cons > 0) ? " + " : " - ");
                    cout << ((cons > 0) ? " + " : " - ");
                }
            }
        }
        if (hasL) {
            double coeff{(hasQ ? abs(lin) : lin)}; //the coefficient keeping its +/- sign depends on whether a term came before it
            if (lin != 1) {
                // res += to_string(coeff); // if the coefficient isn't 1, then print it
                cout << coeff;
            }
            // res += "x"; //like the quadratic, regardless of the coefficient, the x must be printed if the linear component exists
            cout << "x";
            if (hasC) {
                // res += ((cons > 0) ? " + " : " - ");
                cout << ((cons > 0) ? " + " : " - ");
            }
        }

        if (hasC) {
            // double coeff{ (hasQ || hasL) ? abs(lin) : lin};
            // res += ((hasQ || hasL) ? to_string(abs(cons)) : to_string(cons));
            cout << ((hasQ || hasL) ? abs(cons) : cons);
        }
    }
    // return res;
};

Linear Linear::operator/(const Linear &operand2) const
{
    Linear tmp;
    // Linear conjugate; //declare an instance for the conjugate
    // conjugate.constant = operand2.constant * -1; // set the constant aspect to the 2nd operand's constant component
    // tmp.linear = linear*denom.constant;
    // tmp.constant = constant * 
    // tmp = this * conjugate;
    tmp.linear = ((linear * operand2.linear) + (constant + operand2.constant))/(pow(operand2.constant, 2) + pow(operand2.linear, 2));
    // tmp.constant = (constant * operand2.linear - )
    return tmp;
}

double Linear::getLinear() {return linear;}
double Linear::getConstant() {return constant;}

// return string representation of a Linear object in the form: (a, b)
string Linear::toString() const
{
    return to_string(linear) + " + " + to_string(constant) + "i";
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
