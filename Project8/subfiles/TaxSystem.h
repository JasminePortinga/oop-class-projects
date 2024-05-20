#ifndef TAXSYSTEM_H
#define TAXSYSTEM_H


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class TaxSystem {
protected:
    string firstName;
    string lastName;
    string taxID;
    double income{ 0 };
    double netIncome;
    double fedTax;
    double stateTax;
    int dependent{0};
public:
    TaxSystem();
    TaxSystem(const string& fName, string& lName, const string& ID, double wage);
    TaxSystem(const string fName, string lName, const string ID, double wage);
    
    void setFirstName(const string& fName);
    string getFirstName() const;
    void setLastName(const string& lName);
    string getLastName() const;
    void setTaxID(const string& ID);
    string getTaxID() const;
    void setIncome(double wage);

    double getIncome() const;
    void setNetIncome(double totalWage);

    double getNetIncome() const;

    double NetIncome();

    void setDependent(int leech);
    double getDependent() const;
    string printDependent(const TaxSystem& X);
    TaxSystem operator+(const TaxSystem& operand2) const;
    virtual double stateTx(string) { return 0; };
    virtual string toString() const;
};


#endif /* Tax_System_h */