//
//  exchange.h
//  exchange
//
//  Created by Steven Yon on 4/8/24.
//

#ifndef exchange_h
#define exchange_h

#include <vector>
#include <string>


class Exchange {

private:
    std::vector<std::vector<double>> exchangeRates;
    std::vector<std::string> countries;
    bool currenciesAdded;
    void vecInit();
    void cntyInit();
    
public:
    Exchange();
    Exchange(const std::string& country, const std::vector<double>&rates);
    void title();
    void convertFromUSD(double amount);
    void convertToUSD (double amount, int j);
    void countriesList();
    void addCurrencies();
};

#endif  /* exchange_h */
