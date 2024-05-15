// Fig. 11.11: BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
#include <sstream>
#include <stdexcept>
#include "CommissionEmployee.h" // CommissionEmployee class declaration
#include "BasePlusCommissionEmployee.h"
#include "BasePlusCommissionEmployee2.h"
using namespace std;

// constructor
BasePlusCommissionEmployee2::BasePlusCommissionEmployee2(const string& first, const string& last, 
	const string& ssn, double sales, double rate, double salary)
   // explicitly call base-class constructor                  
   : BasePlusCommissionEmployee(first, last, ssn, sales, rate, salary) {
	setBaseSalary2(salary); // validate and store base salary   
}

// set base salary
void BasePlusCommissionEmployee2::setBaseSalary2(double salary) {
   if (salary < 0.0) {
      throw invalid_argument("Salary must be >= 0.0");
   }

   baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee2::getBaseSalary2() const {
   return baseSalary;
}

// calculate earnings
double BasePlusCommissionEmployee2::earnings() const {
   // derived class cannot access the base class’s private data
   return baseSalary + (commissionRate * grossSales);
}

// returns string representation of BasePlusCommissionEmployee object
string BasePlusCommissionEmployee2::toString() const {
   ostringstream output;

   // derived class cannot access the base class’s private data          
   output << "This toString() function is from the Derived class BasePlusCommissionEmployee2."
	   << "\nBase-salaried commission employee: " << firstName << ' '
      << lastName << "\nsocial security number: " << socialSecurityNumber
      << "\ngross sales: " << grossSales
      << "\ncommission rate: " << commissionRate
      << "\nbase salary: " << baseSalary;
   return output.str();
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
