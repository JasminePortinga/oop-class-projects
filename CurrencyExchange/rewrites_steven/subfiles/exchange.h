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
    bool currenciesAdded{false};
    void vecInit();
    void cntyInit();
    
public:
    Exchange();
    Exchange(const std::string&, const std::vector<double>&);
    void title();
    void convertFromUSD(double);
    void convertToUSD (double, int);
    void countriesList();
    void addCurrencies();
    void window();
};

#endif  /* exchange_h */
