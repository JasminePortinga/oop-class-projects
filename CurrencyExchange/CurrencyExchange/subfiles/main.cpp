//
//  main.cpp
//  exchange
//
//  Created by Steven Yon on 4/8/24.
//

#include <iostream>
#include "exchange.h"


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
