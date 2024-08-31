#include <iostream>
#include "Stock.h"
#include "Option.h"

using namespace std;

int main() {

    // Initialize stock data
    Stock AAPL = Stock("AAPL", 199., 0.21);
    cout << AAPL.getSymbol() << "\n";
    cout << AAPL.getPrice() << "\n";
    cout << AAPL.getVolatility() << "\n";
    // Check setters work
    AAPL.setPrice(49.99);
    AAPL.setVolatility(.20);
    // Compute option data
    Option opAAPL = Option(AAPL.getSymbol(), AAPL.getPrice(), 1., AAPL.getVolatility(), true);
    cout << "___OPTION___\n";
    // Check option getters
    cout << opAAPL.getSymbol() << "\n";
    cout << opAAPL.getStockPrice() << "\n";
    cout << opAAPL.getDTE() << "\n";
    cout << opAAPL.getVolatility() << "\n";
    // View current straddle data
    vector<vector<double>> straddle = opAAPL.getOptionChain();
    cout << "Call Strike Put\n";
    for(const auto& k: straddle){
        cout << k[0] << " " << k[1] << " " << k[2] << "\n";
    }
    // Check price of ITM call and puts
    double ITMCall =  opAAPL.getCallAtStrike(50.);
    double ITMPut = opAAPL.getPutAtStrike(50.);
    cout << "ITM calls are trading at $" << ITMCall << "\n";
    cout << "ITM puts are trading at $" << ITMPut << "\n";
    // Test edge cases
    double badITMCall =  opAAPL.getCallAtStrike(50.1);
    double badITMPut = opAAPL.getPutAtStrike(50.1);
    cout << "Bad ITM calls are not trading at $" << badITMCall << "\n";
    cout << "Bad ITM puts are not trading at $" << badITMPut << "\n";
    // Compute option greeks
    vector<vector<double>> delta = opAAPL.getDelta();
    vector<vector<double>> gamma = opAAPL.getGamma();
    cout << "Call Put\n ___Delta___";
    for(const auto& i: delta){
        cout << i[0] << " " << i[1] << "\n";
    }
    cout << "___Gamma___\n";
    for(const auto& i: gamma){
        cout << i[0] << " " << i[1] << "\n";
    }
    return 0;
}
