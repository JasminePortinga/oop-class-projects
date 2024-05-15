// Fig. 11.10: BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee class derived from class 
// CommissionEmployee.
#ifndef BASEPLUSCOMMISSIONEMPLOYEE2_H
#define BASEPLUSCOMMISSIONEMPLOYEE2_H

#include <string> // C++ standard string class
#include "CommissionEmployee.h" // CommissionEmployee class declaration
#include "BasePlusCommissionEmployee.h" // CommissionEmployee class declaration

class BasePlusCommissionEmployee2 : public BasePlusCommissionEmployee {
public:
   BasePlusCommissionEmployee2(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0.0, double = 0.0);

   void setBaseSalary2(double); // set base salary
   double getBaseSalary2() const; // return base salary

   double earnings() const; // calculate earnings
   std::string toString() const; // create string representation
private:
   double baseSalary; // base salary
};

#endif

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
