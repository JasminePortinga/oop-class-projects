//
//  TaxSystemState.cpp
//  TaxSystem
//
//  Created by Steven Yon on 5/15/24.
//

#include "TaxSystem.h"
#include "TaxSystemState.h"

#include <iostream>
#include <iomanip>
#include <string>



TaxSystemState::TaxSystemState(){
}

TaxSystemState::TaxSystemState(const std::string fname, const std::string lname, const std::string id, const std::string stID, double inc){
    TaxSystem(fname, lname, id, inc);
    stateTaxId = stID;
    stateTax = 0;
}

void TaxSystemState::setStateTax(double tax){
    stateTax = tax;
}

double TaxSystemState::getStateTax() const{
    return stateTax;
}


double TaxSystemState::stateTx(std::string state){
    if (state == "NY"){return 0.05;}
    else if (state == "CA"){return 0.06;}
    else {return 0.0;}
}

std::string TaxSystemState::toString() const{
    std::string result = TaxSystem::toString();
    result += "\tState Tax: " + std::to_string(TaxSystemState::stateTax);
    return result;
    
}

TaxSystemState TaxSystemState::operator+=( double AddIncome){
    TaxSystemState tmp;
    tmp.income = income + AddIncome;
    return tmp;
    // return TaxSystemState{firstName,lastName,taxID,stateTaxId,income};
}

