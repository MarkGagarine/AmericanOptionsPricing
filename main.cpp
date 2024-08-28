#include <iostream>
#include "Stock.h"
#include "Option.h"


using namespace std;


int main() {
    Stock AAPL = Stock("AAPL", 199., 0.21);
    cout << AAPL.getSymbol() << "\n";
    cout << AAPL.getPrice() << "\n";
    cout << AAPL.getVolatility() << "\n";
    AAPL.setPrice(50.);
    AAPL.setVolatility(.20);
    Option opAAPL = Option(AAPL.getSymbol(), AAPL.getPrice(), 1., AAPL.getVolatility());
    cout << "___OPTION___\n";
    cout << opAAPL.getSymbol() << "\n";
    cout << opAAPL.getStockPrice() << "\n";
    cout << opAAPL.getDTE() << "\n";
    cout << opAAPL.getVolatility() << "\n";
    return 0;
}
