// Fig. 10.16: fig10_16.cpp
// Complex class test program.
#include <iostream>
#include "Complex.h"
#include "Complex.cpp"
//#include "complexType.h"
//#include "complexType.cpp"
using namespace std;

int main() {
    Complex x;
    Complex y{ 4, 8 };   // y = 4 + 8i
    Complex z{ 3, -1 };  // z = 3 - i

    //    complexType num1(21, 18);                       //Line 6
    //    complexType num2;                               //Line 7
    //    complexType num3;                               //Line 8

//    cout << "num1 = " << x << endl;      //Line 9
//    cout << "num2 = " << y << endl;     //Line 10

    cout << "Enter a complex number in the form a+b: ";                 //Line 11
    cin >> y;                                    //Line 12
    cout << endl;                                    //Line 13
    cout << "Your complex number is: " << y << endl << endl;
    x = y + z;
    cout << "Let x = y + z, then x = (" << y << ") + (" << z << ") = " << x << endl;

    //    cout << "x: " << x.toString() << "\ny: " << y.toString()
    cout << "x: " << x << "\ny: " << y
        << "\nz: " << z;

    x = y + z;
    //    cout << "\n\nx = y + z:\n" << x.toString() << " = " << y.toString() << " + " << z.toString();
    cout << "\n\nx = y + z:\n" << x << " = (" << y << ")" << " + " /*((z.getImagine() < 0 )? " - " : " + (")*/ << "(" << z << ")"  << endl;
    x = y - z;
    //    cout << "\n\nx = y - z:\n" << x.toString() << " = " << y.toString()
    cout << "\n\nx = y - z:\n" << x << " = (" << y << ")" <<  " - " /*((z.getImagine() < 0 )? " - " : " + ")*/ << "(" << z << ")" << endl;

    x = y * z;
    //    cout << "\n\nx = y - z:\n" << x.toString() << " = (" << y.toString() << ") * (" << z.toString() << ")" << endl;
    cout << "\n\nx = y * z:\n" << x << " = (" << y << ") * (" << z << ")" << endl;

}


