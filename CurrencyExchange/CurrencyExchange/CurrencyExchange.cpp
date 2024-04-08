// CurrencyExchange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include "subfiles/exchange.h"
#include "subfiles/exchange.cpp"

using namespace std;

void greeting();

int main()
{
    greeting();

    char ans1{'Y'};
    int ans2{0};
    
    while (toupper(ans1) == 'Y'){
    std::cout << "Enter 1 to convert from US dollar to other currency. 2 to convert from other currency to US dollar: ";
    std::cin >> ans2;
    
        double i{0}, amt{0};
        
        if (ans2==1){
            std::cout << "First choose a country: ";
            std::cin >> i;
            std::cout << std::endl;
            std::cout << "Enter the amount in US Dollars: ";
            std::cin >> amt;
            std::cout << std::endl;
            std::cout << "From US to " << /* Vector string */ "\t$" << amt << "\t" << amt /* Vector value */ << std::endl;
            
        }
        
        else if (ans2==2){
            
            std::cout << "First choose a country: ";
            std::cin >> i;
            std::cout << std::endl;
            std::cout << "Enter the amount in foreign currency: ";
            std::cin >> amt;
            std::cout << std::endl;
            std::cout << "From to US Dollars:\t" << amt << "\t$" << amt /*Vector value*/ << std::endl;
            
        }
        
        else {
            
        }
        
        std::cout << "Enter y/Y to continue, else enter anything: ";
        std::cin >> ans1;
    }
    

    
    return 0;

}

void greeting() {
    string stars{"**************************************"};
    cout << setw(50) << stars << endl;
    cout << setw(50) << "*\tWelcome to Currency Exchange\t*" << endl;
    cout << setw(50) << stars << endl;
}

