// Fig. 12.6: fig12_06.cpp
// Introducing polymorphism, virtual functions and dynamic binding.
#include <iostream>
#include <iomanip>
#include <array>
#include "Employee.h" // base classes
#include "Employee.cpp" // base classes
#include "CommissionEmployee.h" // base classes
#include "CommissionEmployee.cpp" // base classes
#include "BasePlusCommissionEmployee.h"  // child class
#include "BasePlusCommissionEmployee.cpp" // child class

// damn. professor snuffling real bad today.
// "be honest. how many of you play video games. almost all of you! shame on you!! i am ashamed of myself; if you go to calstate la open up the macbook you will see my name at the top score for tetris!!!"
// professor basically says if we have swag, we can walk into an office n go "i want a job. tell me what you want done n i'll get it done rn" and they'll give you smth to do, and if you can do that, you got a job.

// anyway pointers are runtime objects n functions, not compiled
// overwritten functions are DYNAMIC, executed during Runtime. this is an important distinction from function overloading, which is executed during compile time

using namespace std;

int main() {
	// create base-class object
	CommissionEmployee commissionEmployee{ "Sue", "Jones", "222-22-2222", 10000, .06 };

	// create derived-class object
	BasePlusCommissionEmployee basePlusCommissionEmployee{ "Bob", "Lewis", "333-33-3333", 5000, .04, 300 };

	cout << fixed << setprecision(2); // set floating-point formatting

	// output objects using static binding
	cout << "Invoking commissionEmployee.toString() function on base-class and derived-class "
		<< "\nobjects with static binding:"
		<< "\n\nCalling base class commissionEmployee.toString() function: \n"
		<< commissionEmployee.toString() // static binding
		<< "\n\nCalling derived class basePlusCommissionEmployee.toString() function: \n"
		<< basePlusCommissionEmployee.toString(); // static binding

	 // output objects using dynamic binding
	cout << "\n\nInvoking tostring() function on base-class commissionEmployee{} and "
		<< "\nderived-class BasePlusCommissionEmployee{} objects with dynamic binding";

	// natural: aim base-class pointer at base-class object        
	const CommissionEmployee* commissionEmployeePtr{ &commissionEmployee };

	cout << "\n\nCalling virtual function tostring() with base-class pointer commissionEmployeePtr*"
		<< "\nto base-class object invokes base-class: "
		<< "commissionEmployeePtr->toString() function:\n"
		<< commissionEmployeePtr->toString(); // base version

	 // natural: aim derived-class pointer at derived-class object
	const BasePlusCommissionEmployee* basePlusCommissionEmployeePtr{ &basePlusCommissionEmployee }; // natural                  

	cout << "\n\nCalling virtual function tostring() with derived-class pointer: basePlusCommissionEmployeePtr*"
		<< "\nto derived-class object invokes derived-class "
		<< "basePlusCommissionEmployeePtr->toString() function:\n"
		<< basePlusCommissionEmployeePtr->toString(); // derived version

	 // aim base-class pointer at derived-class object   
	commissionEmployeePtr = &basePlusCommissionEmployee;

	cout << "\n\nCalling virtual function tostring() with base-class pointer: commissionEmployeePtr*"
		<< "\nto derived-class object invokes derived-class "
		<< "\ncommissionEmployeePtr->toString() function:"
		<< "\n\tcommissionEmployeePtr = &basePlusCommissionEmployee;\n";

	// Polymorphism; invokes BasePlusCommissionEmployee's toString
	// via base-class pointer to derived-class object.
	// Virtual function binded at runtime.             
	cout << commissionEmployeePtr->toString() << endl;

	commissionEmployeePtr = nullptr;
	basePlusCommissionEmployeePtr = nullptr;
	delete commissionEmployeePtr;
	delete basePlusCommissionEmployeePtr;
}

