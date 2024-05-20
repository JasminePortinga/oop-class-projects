// Jasmine Portinga, Thiago Santiago, Steven Yon

#include <iostream>
#include <iomanip>
#include <string>
#include "subfiles/TaxSystem.h"
#include "subfiles/TaxSystem.cpp"
#include "subfiles/TaxSystemState.h"
#include "subfiles/TaxSystemState.cpp"

using namespace std;

int main()
{
	// TaxSystemState a;
	// cout << fixed << setprecision(2); // fix the precision display

	TaxSystem tax1{"John", "Doe", "999-99-9999", 72000};
	TaxSystem tax2{"Marie", "Kolosovich", "999-99-9998", 12500}; // these work fine when not extending the class to state
	TaxSystemState statTax1("Jim", "Chen", "999-99-9997", "123456789", 52350.25);
	string name{"first name"};
	// TaxSystemState stTax{name, othervar, otherstring, double};
	tax1.setDependent(1); // 1 dependent
	cout << tax1.toString() << endl; //prints the information

	tax1.stateTx("NY"); // sets the state tax to 0.05

	// cout << tax1.getTaxID();

	tax2.setDependent(3);

	tax2.stateTx("CA"); // sets state tax to 0.06
	cout << tax2.toString() << endl;

	// TaxSystemState* st; // pointer to the state tax
	TaxSystemState* st(&statTax1);
	// st = &statTax1;
	// auto st = new TaxSystem(statTax1);
	// cout << (*st).toString();
	// // st -> statTax1;
	// cout << "Testing the pointer += overloading:\n";
	// st += 28000;
	cout << (*st).toString() << endl;
	st = nullptr;
	delete st;

	return 0;
}