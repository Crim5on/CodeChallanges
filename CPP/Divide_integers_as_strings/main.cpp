// kata source: https://www.codewars.com/kata/58dea43ff98a7e2124000169/train/cpp
/*
    Given positive integers a and b as strings, evaluate a / b and return the quotient and the remainder as strings 
    in the form [quotient, remainder] (vector<string> {quotient, remainder} in C++).
    a and b can be very large (at the order of 10^150 to 10^200)
    As usual, your result should not have leading 0s
    require is disabled in JavaScript. Do it yourself ;-)
*/


#include <iostream>
#include <string>
#include <vector>
#include <exception>



class Strinteger
{

private:

    std::string value;


protected:    // helpers

    inline void normalise(void)
    {
        while(value.length() > 1 && value[0] == '0'){
            value.erase(0, 1);
        }
    }

    inline void patchLength(size_t requiredLength)
    {
        while (this->value.length() < requiredLength){
            this->value.insert(this->value.begin(), '0');
        }
    }

    inline bool isNull(void)
    {
        this->normalise();
        return ((this->value.length() == 1) && (this->value[0] == '0'));
    }


public:

    Strinteger(void) = default;

    Strinteger(std::string digitString)
    {
        this->value = digitString;
        this->normalise();
    }

    Strinteger(const Strinteger& other)
    {
        this->value = other.value;
    }

    std::string getString(void)
    {
        return this->value;
    }

    void operator =(const Strinteger& other)
    {
        this->value = other.value;
        this->normalise();
    }

    bool operator >=(Strinteger& other)
    {
        this->normalise();
        other.normalise();

        if(this->value.length() > other.value.length()){
            return true;
        }
        else if(this->value.length() < other.value.length()){
            return false;
        }
        for(size_t i=0; i<this->value.length(); i++){
            // compare acii values
            if(this->value[i] > other.value[i]){
                return true;
            }
            else if(this->value[i] < other.value[i]){
                return false;
            }
            else{
                ;   // continue
            }
        }
        return true; // if equal            
    }

    Strinteger operator -(Strinteger& other)
    {
        char digit_char; 
        int digit_a, digit_b, digit_res;
        int hold = 0;
        Strinteger result;

        other.patchLength(this->value.length());

        for(long i=this->value.length()-1; i>=0; i--){
            digit_a = this->value[i] - '0';
            digit_b = other.value[i] - '0';
            if((digit_a > digit_b) || (digit_a == digit_b && !hold)){
                digit_res = digit_a - (digit_b + hold);
                hold = 0;
            }
            else{
                digit_res = 10 - (digit_b + hold) + digit_a;
                hold = 1;
            }
            digit_char = digit_res + '0';
            result.value.insert(result.value.begin(), digit_char);
        }
        return result;
    }

    Strinteger operator /(Strinteger& other)
    {
        if(other.isNull()){
            throw std::out_of_range("Div / 0 is undefined!");
        }

        Strinteger remainder, quotient;
        
        for(size_t i=0; i<this->value.length(); i++){
            size_t divCount = 0;
            remainder.value.push_back(this->value[i]);

            while(remainder >= other){   
                remainder = remainder - other;
                divCount++;
            }     
            quotient.value.push_back(divCount + '0');
        }

        quotient.normalise();
        return quotient;
    }

    Strinteger operator %(Strinteger& other)
    {
        if(other.isNull()){
            throw std::out_of_range("Div / 0 is undefined!");
        }

        Strinteger remainder;
        
        for(size_t i=0; i<this->value.length(); i++){
            remainder.value.push_back(this->value[i]);
            while(remainder >= other){   
                remainder = remainder - other;
            }     
        }

        remainder.normalise();
        return remainder;
    }
};



/** Interface function as given by codewars kata
 * @return: vector<string> {quotient, remainder}
 */ 
std::vector<std::string> divide_strings(std::string a, std::string b)
{
    // NOTE: very comfortable usage:
    Strinteger divident = Strinteger(a);
    Strinteger divisor = Strinteger(b);
    Strinteger quotient = divident / divisor;
    Strinteger remainder = divident % divisor;

    std::vector<std::string> results;
    results.push_back(quotient.getString());
    results.push_back(remainder.getString());
    return results;
}



/* TEST CODE IN MAIN */
int main(void)
{
    // test constructors
    Strinteger t1("0600");
    std::cout << "t1: " << t1.getString() << std::endl;

    Strinteger t2("2000");
    std::cout << "t2: " << t2.getString() << std::endl;

    // test >= operator
    std::cout << "t1 >= t2 : " << bool(t1 >= t2) << std::endl;
    std::cout << "t2 >= t1 : " << bool(t2 >= t1) << std::endl;

    // test - and = operator
    Strinteger t3 = t2 - t1;
    std::cout << "t2 - t1 : " << t3.getString() << std::endl;
    t2 = t2 - t1;
    std::cout << "t2 = t2 - t1 : " << t2.getString() << std::endl;
    t2 = t1;
    std::cout << "t2 = t1 : " << t2.getString() << std::endl;



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