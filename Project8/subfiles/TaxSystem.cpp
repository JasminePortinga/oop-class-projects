#include "TaxSystem.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

TaxSystem::TaxSystem() {};
TaxSystem::TaxSystem(const string& fName, string& lName, const string& ID, double wage) {
        firstName = fName;
        lastName = lName;
        taxID = ID;
        setIncome(wage);
    }
TaxSystem::TaxSystem(const string fName, string lName, const string ID, double wage) {
        firstName = fName;
        lastName = lName;
        taxID = ID;
        setIncome(wage);
    }
  
    void TaxSystem::setFirstName(const string& fName) {
        firstName = fName;
    }
    string TaxSystem::getFirstName() const { return firstName; }
    void TaxSystem::setLastName(const string& lName) {
        lastName = lName;
    }
    string TaxSystem::getLastName() const { return lastName; }
    void TaxSystem::setTaxID(const string& ID) {
        taxID = ID;
    }
    string TaxSystem::getTaxID() const {
        return taxID;
    }
    void TaxSystem::setIncome(double wage) {
        if (wage < 0.0) {
            throw invalid_argument("You are broke go get a job and start over!  ;)");
        }

        income = wage;
    }

    double TaxSystem::getIncome() const { return income; }
    void TaxSystem::setNetIncome(double totalWage) {
        if (totalWage < 0.0) {
            throw invalid_argument("I told you. You are broke go get a job and start over!  ;)");
        }

        netIncome = totalWage;
    }

    double TaxSystem::getNetIncome() const { return netIncome; }

    double TaxSystem::NetIncome() {
        return income - income*fedTax - income*stateTax;
    }

    void TaxSystem::setDependent(int leech) {
       
        dependent = leech;
    }
    double TaxSystem::getDependent() const { return dependent; }
    string TaxSystem::printDependent(const TaxSystem& X) {
        return "The number of dependents is: " + std::to_string(X.dependent);
    }
    TaxSystem TaxSystem::operator+(const TaxSystem& operand2) const {
        return TaxSystem{firstName,lastName, taxID, income + operand2.income};
    }
// double TaxSystem::stateTx(string state){
//     if (state == "NY"){return 0.05;}
// else if (state == "CA"){return 0.06;}
// else {return 0.0;}
    
// }
     string TaxSystem::toString() const {
        ostringstream output;
        output << "Tax payer information: " << firstName << " " << lastName
            << "\ntax id: " << taxID
            << "\nNumber of dependents: " << dependent
            << "\nIncome: " << income
            << "\nFed. Tax: " << fedTax;
        return output.str();
    }

