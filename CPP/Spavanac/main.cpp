// source: https://open.kattis.com/problems/spavanac

#include <iostream>
#include <ctime>


int main(void)
{   
    // INPUT:
    tm time = {0};  // initialise all values with 0
    std::cin >> time.tm_hour >> time.tm_min;

    // PROCESSING:
    time.tm_min = time.tm_min - 45;
    mktime(&time); // normalise the time

    // OUTUT:
    std::cout << time.tm_hour << " " << time.tm_min << std::endl;

    return EXIT_SUCCESS;
}
