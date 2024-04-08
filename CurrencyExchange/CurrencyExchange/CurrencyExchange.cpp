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

int main() {
   exchange title;
    
    
    char ans1{'Y'};
    int ans2{0};
    
    do{
    std::cout << "Enter y/Y to continue, else enter anything: ";
    std::cin >> ans1;
    std::cout << std::endl;
    std::cout << "Enter 1 to convert from US dollar to other currency. 2 to convert from other currency to US dollar: ";
    std::cin >> ans2;
    
        if (ans2==1){
            
        }
        
        else{
            
        }
    }
    while (toupper(ans1) == 'Y');
    
    return 0;
}

/*
int main()
{
    greeting();

    exchange::exchange exch();
    return 0;
}
*/

void greeting() {
    string stars{"**************************************"};
    cout << setw(50) << stars << endl;
    cout << setw(50) << "*\tWelcome to Currency Exchange\t*" << endl;
    cout << setw(50) << stars << endl;
}