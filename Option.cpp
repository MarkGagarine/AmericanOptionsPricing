//
// Created by Mark Gagarine on 2024-08-19.
//

#include "Option.h"
#include "Price_American_PSOR.h"

using namespace std;

Option::Option(const string& sym, const double stockPr, const double DTE, const double vol, bool computeGreeks = false)
    : symbol(sym), stock_price(stockPr), days_to_exp(DTE), volatility(vol){
    // Constructor initialization list is used to initialize const members
    setStrikeChain();
    setCallChain();
    setPutChain();
    if(computeGreeks){
        setDelta();
        setGamma();
    }
}

/**
 * Stores call and put chains as straddle (call, strike, put)
 * @return 3 dimensional vector containing call, strike, and put chain
 */
vector<vector<double>> Option::getOptionChain() const{
    std::vector<std::vector<double>> straddleChain;
    // Iterate through all chains and construct the straddle for each strike price
    for (size_t i = 0; i < strikeChain.size(); ++i) {
        std::vector<double> straddleAtK;
        // Get the strike price, call price, and put price for the current index
        double put_price = putChain[i];
        double strike = strikeChain[i];
        double call_price = callChain[i];
        // Add the strike, call price, and put price to the straddle vector
        straddleAtK.push_back(put_price);
        straddleAtK.push_back(strike);
        straddleAtK.push_back(call_price);
        // Add the straddle vector to the straddle_chain
        straddleChain.push_back(straddleAtK);
    }
    // Return the complete straddle chain
    return straddleChain;
}

string Option::getSymbol() const {
    return symbol;
}

double Option::getStockPrice() const {
    return stock_price;
}

double Option::getDTE() const {
    return days_to_exp;
}

double Option::getVolatility() const {
    return volatility;
}

void Option::addStrike(double strike) {
    strikeChain.push_back(strike);
}

void Option::addCall(double callPrice) {
    callChain.push_back(callPrice);
}

void Option::addPut(double putPrice) {
    putChain.push_back(putPrice);
}

vector<double> &Option::getStrikeChain() {
    return strikeChain;
}

vector<double> &Option::getCallChain() {
    return callChain;
}

vector<double> &Option::getPutChain() {
    return putChain;
}

double Option::setStrikeStep(double currStrike, int &chainLength, int &stepStart) {
    // Set minimum strike price and strike step sizes
    const double minStrike = 5.0;
    const double minStep = 0.5;
    // Dynamically set option chain length
    if ((currStrike - 130) >= minStrike) {
        return 5.;
    } else if ((currStrike - 67.5) >= minStrike) {
        return 2.5;
    } else if ((currStrike - 30) >= minStrike) {
        return 1.;
    } else {
        float strikeStep = minStep;
        // Adjust chain length to fit minimum strike price
        if (currStrike <= 17.5) {
            while (currStrike + (stepStart * strikeStep) - int((chainLength / 2) * strikeStep) < 5) {
                stepStart++;
                chainLength--;
            }
        }
        return strikeStep;
   }
}

void Option::setStrikeChain() {
    double currStrike = double(nearbyint(stock_price));
    int chainLength = 51;
    int stepStart = 1;
    double strikeStep = setStrikeStep(currStrike, chainLength, stepStart);

    // Generate strike chain
    for (int i = stepStart; i <= chainLength ; i++){
        addStrike(currStrike + (i * strikeStep) - int((chainLength / 2) * strikeStep));
    }
}

void Option::setCallChain(){
    for(auto K: getStrikeChain()) addCall(priceAmericanPSOR(stock_price, days_to_exp, volatility, K, 0.05, 1));
}

void Option::setPutChain(){
    for(auto K: getStrikeChain()) addPut(priceAmericanPSOR(stock_price, days_to_exp, volatility, K, 0.05, 0));
}

double Option::getCallAtStrike(double strike) const {
    for(int i = 0; i < strikeChain.size(); i++){
        if (strikeChain[i] == strike){
            return callChain[i];
        }
    }
    cout << "Strike " << strike << " not in list\n";
    return -1;
}
double Option::getPutAtStrike(double strike) const {
    for(int i = 0; i < strikeChain.size(); i++){
        if (strikeChain[i] == strike){
            return putChain[i];
        }
    }
    cout << "Strike " << strike << " not in list\n";
    return -1;
}

/**
 * Computes and returns vector with respective delta of option chain (call, put)
 */
void Option::setDelta() {
    // Compute
    double epsilon = pow(10, -2);
    double dS = stock_price + epsilon;
    Option dO = Option(symbol, dS, days_to_exp, volatility);
    // result vector
    vector<double> dC = dO.getCallChain();
    vector<double> dP = dO.getPutChain();
    for(int i = 0; i < strikeChain.size(); i++){
        double callDelta = (dC[i] - callChain[i]) / dS;
        double putDelta = (dP[i] - putChain[i]) / dS;
        vector<double> currDelta = {callDelta, putDelta};
        delta.push_back(currDelta);
    }
}

/**
 * Computes and returns vector with respective gamma of option chain (call, put)
 * Requires: delta vector must be already calculated
 */
void Option::setGamma() {
    // Compute
    double epsilon = pow(10, -2);
    double dS = stock_price - epsilon;
    Option dO = Option(symbol, dS, days_to_exp, volatility);
    // result vector
    vector<double> dC = dO.getCallChain();
    vector<double> dP = dO.getPutChain();
    for(int i = 0; i < strikeChain.size(); i++){
        vector<double> currDelta = delta[i];
        double callGamma = (((dC[i] + callChain[i]) / dS) + currDelta[0]) / dS;
        double putGamma = (((dP[i] - putChain[i]) / dS) + currDelta[1]) / dS;
        vector<double> currGamma = {callGamma, putGamma};
        gamma.push_back(currGamma);
    }
}

vector<std::vector<double>> &Option::getDelta() {
    return delta;
}

vector<std::vector<double>> &Option::getGamma() {
    return delta;
}