//
//  exchange.cpp
//  exchange
//
//  Created by Steven Yon on 4/8/24.
//

#include "./exchange.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

Exchange::Exchange() {
    vecInit();
    cntyInit();
}

Exchange::Exchange(const std::string& country, const std::vector<double>& rates){
    countries.push_back(country);
    exchangeRates.push_back(rates);
}

void Exchange::vecInit(){
    exchangeRates = {
        { 862.3, 0.00116 },
        { 5.06, 0.198 },
        { 1.36, 0.74 },
        { 7.23, 0.14 },
        { 0.92, 1.08 },
        { 7.83, 0.13 },
        { 83.25, 0.012 },
        { 151.8, 0.0066 },
        { 16.48, 0.061 },
        { 92.38, 0.011 }
    };
}

void Exchange::cntyInit(){
    countries = {"Argentina Peso", "Brazilian Real", "Canadian Dollar", "Chinese Yuan",
                 "Euro", "Hong Kong Dollar", "Indian Rupee", "Japanese Yen",
                 "Mexican Peso", "Russian Ruble"};
}

void Exchange::title() {
    std::string stars{"*************************************"};
    std::cout << std::setw(65) << stars << std::endl;
    std::cout << std::setw(60) << "*\tWelcome to Currency Exchange\t*" << std::endl;
    std::cout << std::setw(65) << stars << std::endl << std::endl;
}

void Exchange::convertFromUSD(double amount) {
    for (size_t i = 0; i < countries.size(); i++) {
       double converted = amount * exchangeRates[i][0];
        std::cout << std::setw(20) << countries[i] << std::setw(10) << exchangeRates[i][0] << std::setw(10) << converted << std::endl;
    }
}

void Exchange::convertToUSD (double amount, int j) {
    double converted = amount * exchangeRates[j-1][1];
    std::cout << "From USD to " << countries[j-1] << std::setw(10)<< "$1" << std::setw(10) << exchangeRates[j-1][0] << std::endl << std::endl;
    std::cout << "From " << countries[j-1] << " to USD" << std::setw(10) << amount << std::setw (10) << converted << std::endl << std::endl;
    }

void Exchange::countriesList() {
    for (size_t i = 0; i < countries.size(); i++)
        std::cout << std::setw(5) << i+1 << " " << countries[i] << std::endl;
}

void Exchange::addCurrencies() {
    if (!currenciesAdded){
        countries.push_back("Cuban Peso");
        countries.push_back("Philippine Peso");
        
        exchangeRates.push_back({ 24.01, 0.042 });
        exchangeRates.push_back({ 56.54, 0.018 });
        currenciesAdded = true;
    }
}

void Exchange::window() {
    int ans2{0};
    std::cout << "Enter 1 to convert from US dollar to other currency. 2 to convert from other currency to US dollar: ";
    std::cin >> ans2;
    std::cout << std::endl;
        double amount{0};
        
        if (ans2==1){
       std::cout << "Enter the amount in US Dollars: ";
       std::cin >> amount;
       std::cout << std::endl << std::setw(27) << "$1" << std::setw(9) << "$" << amount << std::endl;
       convertFromUSD(amount);
       std::cout << std::endl << std::endl;
            
        }
        
        else if (ans2==2){
            unsigned int j;
            Exchange::countriesList();
            std::cout << std::endl << "First choose a country: ";
            std::cin >> j;
            std:: cout << std::endl;
            std::cout << "Enter the amount in foreign currency: ";
            std::cin >> amount;
            std::cout << std::endl;
            Exchange::convertToUSD(amount,j);
        }
        
        else {
            std::cout << "Invalid input" << std::endl << std::endl;
        }
        Exchange::addCurrencies();
}