// https://open.kattis.com/problems/artichoke

#include <iostream>
#include <vector>
#include <cmath>



int main(void)
{
    double p, a, b, c, d;
    size_t n;
    std::cin >> p >> a >> b >> c >> d >> n;

    // calculate prices:
    std::vector<double> prices;
    for(size_t k=1; k<=n; k++){
        double thisPrice = (p * ( sin(a * (double)k + b) + cos(c * (double)k + d) + 2));
        prices.push_back(thisPrice);
    }

    // find largest decline
    double highestPrice = prices[0];
    double lowestPrice = prices[0];
    double largestDecline = 0;

    for(auto price : prices)
    {
        if(price < lowestPrice){
            lowestPrice = price;
            double thisDecline = highestPrice - lowestPrice;
            if(thisDecline > largestDecline){
                largestDecline = thisDecline;
            }
        }
        else if(price > highestPrice){
            highestPrice = price;
            lowestPrice = price;
        }
    }

    std::cout.precision(4+8);
    std::cout << largestDecline << std::endl;
    return EXIT_SUCCESS;
}
