//
// Created by Mark Gagarine on 2024-08-19.
//

#include "Stock.h"
#include <string>

using namespace std;


Stock::Stock(const string& sym, double pr, double vol)
    : symbol(sym), price(pr), volatility(vol){
    // Constructor initialization list is used to initialize const members
}

string Stock::getSymbol() const {
    return symbol;
}

double Stock::getPrice() const {
    return price;
}

double Stock::getVolatility() const {
    return volatility;
}

void Stock::setPrice(double pr) {
    price = pr;
}

void Stock::setVolatility(double vol) {
    volatility = vol;
}
