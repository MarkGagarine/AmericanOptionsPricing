//
// Created by Mark Gagarine on 2024-08-19.
//

#ifndef AMERICANOPTIONSPRICING_STOCK_H
#define AMERICANOPTIONSPRICING_STOCK_H
#include <string>
#include <vector>
#include "Option.h"  // Include the Option class

class Stock {
public:
    // Constructor
    Stock(const std::string& sym, double pr, double vol);

    // Getters
    std::string getSymbol() const;
    double getPrice() const;
    double getVolatility() const;

    // Setters
    void setPrice(double pr);
    void setVolatility(double vol);

private:
    const std::string symbol;
    double price;
    double volatility;
};

#endif //AMERICANOPTIONSPRICING_STOCK_H