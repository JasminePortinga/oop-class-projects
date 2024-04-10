//Currency Exchange Project
//  main.cpp
//  exchange
//
//  Created by Steven Yon on 4/8/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "exchange.h"

using namespace std;


int main() {
    Exchange exchange;
    exchange.title();
  
    char ans1{'Y'};
    int ans2{0};
    
    while (toupper(ans1) == 'Y'){
    cout << "Enter 1 to convert from US dollar to other currency. 2 to convert from other currency to US dollar: ";
    cin >> ans2;
    cout << endl;
    
        double amount{0};
        
        if (ans2==1){
            cout << "Enter the amount in US Dollars: ";
            cin >> amount;
            cout << endl << setw(27) << "$1" << setw(9) << "$" << amount << endl ;
            exchange.convertFromUSD(amount);
            cout << endl << endl;
            
        }
        
        else if (ans2==2){
            unsigned int j;
            exchange.countriesList();
            cout << endl << "First choose a country: ";
            cin >> j;
            cout << endl;
            cout << "Enter the amount in foreign currency: ";
            cin >> amount;
            cout << endl;
            exchange.convertToUSD(amount,j);
        }
        
        else {
            cout << "Invalid input" << endl << endl;
        }
        
        exchange.addCurrencies();
        
        std::cout << "Enter y/Y to continue, else enter anything: ";
        std::cin >> ans1;
    }
    return 0;
}
