//
// Created by Mark Gagarine on 2024-08-19.
//

#ifndef AMERICANOPTIONSPRICING_PRICE_AMERICAN_PSOR_H
#define AMERICANOPTIONSPRICING_PRICE_AMERICAN_PSOR_H


#include <Eigen/Eigen>
#include <cmath>
#include <algorithm>

double priceAmericanPSOR(const double S, const double T, const double sig, const double K, const double r, const bool type);

#endif //AMERICANOPTIONSPRICING_PRICE_AMERICAN_PSOR_H

