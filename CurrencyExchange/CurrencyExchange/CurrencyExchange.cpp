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

    exchange::exchange exch();
    return 0;
}

void greeting() {
    string stars{"**************************************"};
    cout << setw(50) << stars << endl;
    cout << setw(50) << "*\tWelcome to Currency Exchange\t*" << endl;
    cout << setw(50) << stars << endl;
}