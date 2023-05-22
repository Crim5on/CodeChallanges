// kata source: https://www.codewars.com/kata/58dea43ff98a7e2124000169/train/cpp
/*
    Given positive integers a and b as strings, evaluate a / b and return the quotient and the remainder as strings 
    in the form [quotient, remainder] (vector<string> {quotient, remainder} in C++).
    a and b can be very large (at the order of 10^150 to 10^200)
    As usual, your result should not have leading 0s
    require is disabled in JavaScript. Do it yourself ;-)
*/

// TODO: aproach problem by doing "long division".
// TODO: Google long division

#include <iostream>
#include <string>
#include <vector>
#include <exception>


/* HELPER FUNCTIONS START */

static inline void normalise(std::string& string)
{
    while(string[0] == '0' && string.length() > 1){
        string.erase(0, 1);
    }
}

static inline void patchLength(std::string& string, size_t requiredLength)
{
    while (string.length() < requiredLength)
    {
        string.insert(string.begin(), '0');
    }
}


static inline bool isGreaterOrEqual(std::string& a, std::string&b)
{
    normalise(a);
    normalise(b);

    if(a.length() > b.length()){
        return true;
    }
    else if(a.length() < b.length()){
        return false;
    }
    for(size_t i=0; i<a.length(); i++){
        // compare acii values
        if(a[i] > b[i]){
            return true;
        }
        else if(a[i] < b[i]){
            return false;
        }
        else{
            ;   // continue
        }
    }
    return true; // if equal
}


static inline void nullCheck(std::string& number)
{
    normalise(number);
    if(number.length() == 1 && number[0] == '0'){
        throw std::out_of_range("Div / 0 is undefined!");
    }
}



static inline std::string minus(std::string a, std::string b)
{
    char digit_char; 
    int digit_a, digit_b, digit_res, hold;
    hold = 0;
    std::string result;
    patchLength(b, a.length());

    for(long i=a.length()-1; i>=0; i--){
        digit_a = a[i] - '0';
        digit_b = b[i] - '0';
        if((digit_a > digit_b) || (digit_a == digit_b && !hold)){
            digit_res = digit_a - (digit_b + hold);
            hold = 0;
        }
        else{
            digit_res = 10 - (digit_b + hold) + digit_a;
            hold = 1;
        }
        digit_char = digit_res + '0';
        result.insert(result.begin(), digit_char);
    }
    return result;
}



/* LOGIC IMPLEMENTATON START */

std::vector<std::string> divide_strings(std::string a, std::string b)
{
    nullCheck(b);
    std::string remainder = "";
    std::string quotient = "";
    
    for(size_t i=0; i<a.length(); i++){
        size_t divCount = 0;
        remainder.push_back(a[i]);

        while(isGreaterOrEqual(remainder, b)){   
            remainder = minus(remainder, b);
            divCount++;
        }     
        quotient.push_back(divCount + '0');
    }

    normalise(quotient);
    // vector<string> {quotient, remainder}

    std::vector<std::string> results;
    results.push_back(quotient);
    results.push_back(remainder);
    return results;
}




/* TEST CODE IMPLEMENTATION START */

int main(void)
{
    //std::vector<std::string> results = divide_strings("60", "5");
    //std::cout << "quotient: " << results[0] << std::endl;
    //std::cout << "remainder: " << results[1] << std::endl;

    // define test strings:
    std::string l5_v8 = "80000";
    std::string l5_v4 = "40000";
    std::string l6_v04 = "000400";
    std::string l3_v8 = "800";

    // testing normalise function:
    std::string normNumber = "000";
    std::cout << normNumber << " -> ";
    normalise(normNumber);
    std::cout << normNumber << std::endl;

    normNumber = "0910";
    std::cout << normNumber << " -> ";
    normalise(normNumber);
    std::cout << normNumber << std::endl;

    normNumber = "03";
    std::cout << normNumber << " -> ";
    normalise(normNumber);
    std::cout << normNumber << std::endl;


    // testing greater equal than function:
    std::cout << "80000 >= 40000: " << isGreaterOrEqual(l5_v8, l5_v4) << std::endl;
    std::cout << "40000 >= 80000: " << isGreaterOrEqual(l5_v4, l5_v8) << std::endl;
    std::cout << "80000 >= 80000: " << isGreaterOrEqual(l5_v8, l5_v8) << std::endl;
    std::cout << "80000 >= 000400: " << isGreaterOrEqual(l5_v8, l6_v04) << std::endl;
    std::cout << "80000 >= 800: " << isGreaterOrEqual(l5_v8, l3_v8) << std::endl;
    std::cout << "800 >= 80000: " << isGreaterOrEqual(l3_v8, l5_v8) << std::endl;

    // testing minus function:
    std::string minuend = "1000";
    std::string subtrahend = "333";
    std::cout << minuend << " - " << subtrahend << " = " << minus(minuend, subtrahend) << std::endl;

    // testing division;
    std::cout << std::endl;
    std::string divident = "199996";
    std::string divisor = "33";
    std::vector<std::string> results = divide_strings(divident, divisor);
    std::cout << divident << " / " << divisor << " = " <<  results[0] << " \tR: " << results[1] << std::endl;

    divident = "100";
    divisor = "5";
    results = divide_strings(divident, divisor);
    std::cout << divident << " / " << divisor << " = " <<  results[0] << " \tR: " << results[1] << std::endl;

    divident = "5";
    divisor = "101";
    results = divide_strings(divident, divisor);
    std::cout << divident << " / " << divisor << " = " <<  results[0] << " \tR: " << results[1] << std::endl;

    divident = "0";
    divisor = "1";
    results = divide_strings(divident, divisor);
    std::cout << divident << " / " << divisor << " = " <<  results[0] << " \tR: " << results[1] << std::endl;

    divident = "1";
    divisor = "0";
    try{
        results = divide_strings(divident, divisor);
        std::cout << divident << " / " << divisor << " = " <<  results[0] << " \tR: " << results[1] << std::endl;
    }catch(std::out_of_range exception){
        std::cout << "Caught division by 0 exception successfully!" << std::endl;
    }

    return EXIT_SUCCESS;
}