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
#include "subfiles/exchange.h"
#include "subfiles/exchange.cpp"

using namespace std;
  
char ans1{'Y'};
void cont();
int main() {
    Exchange exchange;
    exchange.title();
    while (toupper(ans1) == 'Y'){
    exchange.window();
    cont();
    }
    return 0;
}

void cont() {
    std::cout << "Enter y/Y to continue, else enter anything: ";
    std::cin >> ans1;
}