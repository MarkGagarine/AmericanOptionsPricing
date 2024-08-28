//
// Created by Mark Gagarine on 2024-08-19.
//

#ifndef AMERICANOPTIONSPRICING_OPTION_H
#define AMERICANOPTIONSPRICING_OPTION_H
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

class Option {
public:
    // Constructor
    Option(const std::string& sym, const double stockPr, const double DTE, const double vol);

    // Getters
    std::string getSymbol() const;
    double getStockPrice() const;
    double getDTE() const;
    double getVolatility() const;
    std::vector<std::vector<double>> getOptionChain() const;     // Return entire option chain as Straddle
    double getCallAtStrike(double strike) const;                  // Return call at specific strike
    double getPutAtStrike(double strike) const;                   // Return put at specific strike

private:
    const std::string symbol;
    const double stock_price;
    const double days_to_exp;
    const double volatility;
    std::vector<double> strikeChain;
    std::vector<double> callChain;
    std::vector<double> putChain;

    // Option chain management
    void addStrike(double strike);
    void addCall(double callPrice);
    void addPut(double putPrice);
    double setStrikeStep(double currStrike, int &chainLength, int &stepStart);
    void setStrikeChain();
    void setCallChain();
    void setPutChain();
    std::vector<double>& getStrikeChain();
    std::vector<double>& getCallChain();
    std::vector<double>& getPutChain();

    // Methods to compute option Greeks (to be implemented later)

    // float calculateDelta();
    // float calculateGamma();

    // ...
};


#endif //AMERICANOPTIONSPRICING_OPTION_H
