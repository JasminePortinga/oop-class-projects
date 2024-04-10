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

using namespace std;

class Exchange {
private:
    vector<vector<double>> exchangeRates;
    vector<string> countries;
    bool currenciesAdded;
    
public:
    Exchange(){
        vecInit();
        cntyInit();
    }
    
    Exchange(const string& country, const vector<double>&rates){
        countries.push_back(country);
        exchangeRates.push_back(rates);
    }
    
    void vecInit(){
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
    
    void cntyInit(){
        countries = {"Argentina Peso", "Brazilian Real", "Canadian Dollar", "Chinese Yuan",
                     "Euro", "Hong Kong Dollar", "Indian Rupee", "Japanese Yen",
                     "Mexican Peso", "Russian Ruble"};
    }
    
    void title() {
        string stars{"*************************************"};
            cout << setw(65) << stars << endl;
            cout << setw(60) << "*\tWelcome to Currency Exchange\t*" << endl;
            cout << setw(65) << stars << endl << endl;
    }
    
    void convertFromUSD(double amount) {
        for (size_t i = 0; i < countries.size(); i++) {
           double converted = amount * exchangeRates[i][0];
            cout << setw(20) << countries[i] << setw(10) << exchangeRates[i][0] << setw(10) << converted << endl;
        }
    }
    
    void convertToUSD (double amount, int j) {
        double converted = amount * exchangeRates[j-1][1];
        cout << "From USD to " << countries[j-1] << setw(10)<< "$1" << setw(10) << exchangeRates[j-1][0] << endl << endl;
        cout << "From " << countries[j-1] << " to USD" << setw(10) << amount << setw (10) << converted << endl << endl;
        
        }
    
    
    void countriesList() {
        for (size_t i = 0; i < countries.size(); i++)
            cout << setw(5) << i+1 << " " << countries[i] << endl;
    }
    
    void addCurrencies() {
        if (!currenciesAdded){
            countries.push_back("Cuban Peso");
            countries.push_back("Philippine Peso");
            
            exchangeRates.push_back({ 24.01, 0.042 });
            exchangeRates.push_back({ 56.54, 0.018 });
            
            currenciesAdded = true;
        }
    }

};

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
            cout << "Invalid output" << endl << endl;
        }
        
        exchange.addCurrencies();
        
        std::cout << "Enter y/Y to continue, else enter anything: ";
        std::cin >> ans1;
    }
    return 0;
}
