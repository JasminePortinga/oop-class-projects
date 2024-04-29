// Function definition file (Employee.cpp)

// Fig. 9.29: Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "Employee.h" // Employee class definition 
using namespace std;

// define and initialize static data member at global namespace scope
unsigned int Employee::count{0}; // cannot include keyword static

// define static member function that returns number of         
// Employee objects instantiated (declared static in Employee.h)
unsigned int Employee::getCount() { return count; }

void Employee::display() {
    cout << " The value of the variable count is : " << getCount() << endl;    
}

// constructor initializes non-static data members and 
// increments static data member count
Employee::Employee(const string& first, const string& last)
   : firstName(first), lastName(last) {
   ++count; // increment static count of employees
   cout << "Employee constructor for " << firstName
      << ' ' << lastName << " called." << endl;
}

// destructor decrements the count
/*
Employee::~Employee() {
   cout << "~Employee() called for " << firstName
      << ' ' << lastName << endl;
   --count; // decrement static count of employees
}
*/

// return first name of employee
string Employee::getFirstName() const { 
	return firstName; 
	return this -> firstName; // "this" is a pointer, so you can do this sort of thing as well
	//return *this.lastName;
	}

// return last name of employee
string Employee::getLastName() const { return lastName; }

string getName() {
    return  "\nN/A\n";
}

void Employee::getPtr(Employee* emp) {
    cout << "Employee name: " << emp->getFirstName() << " " << emp->getLastName() << endl;
}