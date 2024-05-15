// CommissionEmployee class test program.
#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h" // CommissionEmployee class definition
#include "BasePlusCommissionEmployee.h" // CommissionEmployee class functions definition
#include "BasePlusCommissionEmployee2.h"
#include "CommissionEmployee.cpp" // CommissionEmployee class definition
#include "BasePlusCommissionEmployee.cpp" // CommissionEmployee class functions definition
#include "BasePlusCommissionEmployee2.cpp"
using namespace std;

int main() {
	// instantiate a CommissionEmployee object     
	CommissionEmployee employee{ "Soon", "Sue", "222-22-2222", 10000, .06 };
	BasePlusCommissionEmployee emplBase{ "Jimmy", "Cain", "000-00-0000", 20000, 0.06, 1000 };
	BasePlusCommissionEmployee2 emplBase2{ "Mark", "Rae", "999-99-9999", 20000, 0.06, 1000 };

	BasePlusCommissionEmployee* emplB;

	emplB = &emplBase;

	// get commission employee data
	cout << fixed << setprecision(2); // set floating-point formatting
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is "
		<< employee.getSocialSecurityNumber()

		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate() << endl;


	CommissionEmployee* complE;
	BasePlusCommissionEmployee basePEmpl{ "Jimmy", "Cain", "000-00-0000", 20000, 0.06, 1000 };

	cout << "===========================================\nUpcasting to CommissinEmployee:\n";
	complE = &basePEmpl;  //Upcasting the object basePEmpl;

	cout << endl << complE->earnings() << endl;

	employee.setGrossSales(8000); // set gross sales      
	employee.setCommissionRate(.1); // set commission rate
	cout << "\nUpdated employee information from function toString: \n\n"
//		<< employee.toString() ;
		<< emplBase.toString() << " and salary = " << emplBase.earnings() << endl;
/*
	//Reset the data in emplBase.

	emplB->setFirstName("King");
	emplB->setLastName("Kong");
	emplB->setBaseSalary(50000);
	emplB->setCommissionRate(0.8);
	emplB->setSocialSecurityNumber("111-11-1111");

	// display the employee's earnings
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;

	cout << setw(55) << "\n*******************************************************" << endl;
	cout << "Using inheritance from BasePlusCommissionEmployee: \n" << endl;
	cout << "The Base Salary of " << emplBase.getLastName() << " " << emplBase.getFirstName() << " is: "
		<< emplBase.getCommissionRate() * emplBase.getGrossSales() + emplBase.getBaseSalary() << endl;

	cout << "Attempt to access BasePlusCOmmission function using BaseEmloytee object: " <<
		employee.earnings() << " and BasePlusCOmmission object : " << emplBase.earnings() << endl;

	cout << "\n\nUsing 2 layer deep inheritance: " << endl;
	//	cout << "Employee name: " << emplBase2.getFirstName() << " " << emplBase2.getLastName() << endl;
	//	cout << "SSN: " << emplBase2.getSocialSecurityNumber() << endl;
	//	cout << "Base Salary: " << emplBase2.getBaseSalary() << endl;
	cout << "Gross Sales: " << emplBase2.toString() << endl;
	cout << "Eranings: " << emplBase2.getBaseSalary() << " + " << emplBase2.getCommissionRate() << " * "
		<< emplBase2.getGrossSales() << " = " << emplBase2.earnings() << endl;
	//	cout << "Base salary:" << emplBase2.getBaseSalary() << endl;
	*/

	complE = nullptr;
	emplB = nullptr;
	delete complE;
	delete emplB;

	return 0;
	}

