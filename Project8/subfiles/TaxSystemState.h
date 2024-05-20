//
//  TaxSystemState.h
//  TaxSystem
//
//  Created by Steven Yon on 5/15/24.
//

#ifndef TaxSystemState_h
#define TaxSystemState_h

#include "TaxSystem.h"
#include <iostream>
#include <iomanip>
#include <string>


class TaxSystemState : public TaxSystem{
   public:
        TaxSystemState();                 // Default constructor
        TaxSystemState(const std::string, const std::string, const std::string, const std::string, double inc);//Constructor with parameters
        virtual ~TaxSystemState() = default; // compiler generates virtual destructor

        void setStateTax(double tax);
        double getStateTax() const;

        TaxSystemState operator+=(double AddIncome);   //addition

        virtual double stateTx(std::string) override;  //virtual
        virtual std::string toString() const override; // virtual
    private:
        std::string stateTaxId{"999-99-9999"};
        double stateTax{ 0 };
};




#endif /* TaxSystemState_h */