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
#include <deque>

void printDeque(const std::deque<unsigned short>& digits){
    for(auto i : digits){
        std::cout << i;
    }
    std::cout << std::endl;
}

static std::deque<unsigned short> digitStringToDeque(const std::string& digitString){
    std::deque<unsigned short> digitDeque;
    for(auto c : digitString){
        digitDeque.push_back((unsigned short)(c - '0'));
    }
    return digitDeque;
}


static std::string digitDequeToString(std::deque<unsigned short>& digitDeque){
    std::string digitString;
    while(!digitDeque.empty()){
        digitString.append(1, (char)(digitDeque.front() + '0'));
        digitDeque.pop_front();
    }
    return digitString;
}


static void removeLeadingZeros(std::deque<unsigned short>& digits){
    while((digits.front() == 0) && (digits.size() > 1)){
        digits.pop_front();
    }
}


static bool isLower(const std::deque<unsigned short>& a, const std::deque<unsigned short>& b)
{
    if(a.size() < b.size()){
        return true;
    }
    else if(a.size() > b.size()){
        return false;
    } 
    else if(a.size() == b.size()){
        if(a == b){
            return false;
        }
        for(size_t i=0; i<a.size(); i++){
            if(a[i] > b[i]){
                return false;
            }
            else if(a[i] < b[i]){
                return true;
            }
            else{
                ; // proceed.
            }
        }
    }
    return false;
}


static std::deque<unsigned short> minus(const std::deque<unsigned short>& minuend, const std::deque<unsigned short>& subtrahend)
{
    std::deque<unsigned short> difference;
    int i = minuend.size() - 1;
    int j = subtrahend.size() - 1;
    unsigned short ubertrag = 0;
    unsigned short digit;
    unsigned short subtrahend_digit;

    while(i >= 0)
    {
        if(j >= 0){
            subtrahend_digit = subtrahend[j] + ubertrag;
            ubertrag = 0;
            if(minuend[i] >= subtrahend_digit){
                digit = minuend[i] - subtrahend_digit;
            }
            else{
                digit = (minuend[i] + 10) - subtrahend_digit;
                ubertrag = 1;
            }
            j--;
        }
        else{
            digit = minuend[i] - ubertrag;
            ubertrag = 0;
        }
        difference.push_front(digit);
        i--;
    }
    removeLeadingZeros(difference); // can we remove this?
    return difference;
}


std::vector<std::string> divide_strings(std::string a, std::string b){
    int div_count = 0;
    std::deque<unsigned short> remainder = digitStringToDeque(a);
    std::deque<unsigned short> divisor = digitStringToDeque(b);

    while (!isLower(remainder, divisor)){
        remainder = minus(remainder, divisor);
        div_count++;
    }
    
    std::vector<std::string> results;
    results.push_back(std::to_string(div_count));
    results.push_back(digitDequeToString(remainder));
    return results;
}


int main(void)
{
    std::vector<std::string> results = divide_strings("60", "5");
    std::cout << "quotient: " << results[0] << std::endl;
    std::cout << "remainder: " << results[1] << std::endl;

    return EXIT_SUCCESS;
}