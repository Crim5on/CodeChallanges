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



class BigInteger 
{
    private:

        std::string digits;

        BigInteger(){
            ; // 
        }

        void removeLeadingZeros(){
            while(*digits.begin() == '0'){
                digits.erase(digits.begin());
            }
        }

        bool isLower(const std::string& a, const std::string& b)
        {
            if(a.length() < b.length()){
                return true;
            }
            else if(a.length() == b.length()){

                for(size_t i=0; i<a.length(); i++){

                    int a_i = (int)(a[i] - '0');
                    int b_i = (int)(b[i] - '0');

                    if(a_i > b_i){
                        return false;
                    }
                    else if(a_i < b_i){
                        return true;
                    }
                    else{
                        ; // proceed.
                    }
                }
            }
            return false;
        }

        bool isLarger(const std::string& a, const std::string& b)
        {
            if(a.length() > b.length()){
                return true;
            }
            else if(a.length() == b.length()){

                for(size_t i=0; i<a.length(); i++){

                    int a_i = (int)(a[i] - '0');
                    int b_i = (int)(b[i] - '0');

                    if(a_i > b_i){
                        return true;
                    }
                    else if(a_i < b_i){
                        return false;
                    }
                    else{
                        ; // proceed.
                    }
                }
            }
            return false;
        }


        bool isEqual(const std::string& a, const std::string& b)
        {
            if(a.length() == b.length()){

                for(size_t i=0; i<a.length(); i++){

                    int a_i = (int)(a[i] - '0');
                    int b_i = (int)(b[i] - '0');

                    if(a_i != b_i){
                        return false;
                    }
                }
                return true;
            }
            else{
                return false;
            }    
        }


        std::string minus(const std::string& a, const std::string& b)
        {
            std::string result;
            int digit = 0;
            int ubertrag = 0;
            long long i = a.length() - 1;
            long long j = b.length() - 1;

            while(i >= 0)
            {
                if(j >= 0){
                    int a_i = (int)(a[i] - '0');
                    int b_j = (int)(b[j] - '0');
                    // actual calculation:
                    b_j = b_j + ubertrag;
                    ubertrag = 0;
                    if(a_i >= b_j){
                        digit = a_i - b_j;
                    }
                    else{
                        digit = (a_i + 10) - b_j;
                        ubertrag = 1;
                    }
                    j--;
                }
                else{
                    digit = (int)(a[i] - '0') - ubertrag;
                    ubertrag = 0;
                }
                result.insert(0, 1, (char)(digit + '0'));
                i--;
            }
            return result;
        }


    public:

        BigInteger(const std::string number){
            this->digits = number;
        }

        BigInteger(const BigInteger& other){
            this->digits = other.digits;
        }

        std::string getString(){
            return this->digits;
        }

        void print(){
            std::cout << this->digits << std::endl;
        }

        bool operator< (BigInteger const& other){
            return isLower(this->digits, other.digits);
        }

        bool operator> (BigInteger const& other){
            return isLarger(this->digits, other.digits);
        }
        
        bool operator== (BigInteger const& other){
            return isEqual(this->digits, other.digits);
        }

        bool operator<= (BigInteger const& other){
            return isLower(this->digits, other.digits) || isEqual(this->digits, other.digits);
        }

        bool operator>= (BigInteger const& other){
            return isLarger(this->digits, other.digits) || isEqual(this->digits, other.digits);;
        }

        BigInteger operator- (BigInteger const &other){
            BigInteger result;

            if(! (*this < other)){
                result.digits = minus(this->digits, other.digits);
                result.removeLeadingZeros();
            }
            else {
                result.digits = std::string("0");
            }
            
            return result;
        }

        void operator= (BigInteger const &other){
            this->digits = other.digits;
        }

        BigInteger operator/ (BigInteger const &other){
            size_t div_count = 0;
            BigInteger remainder = *this;
            while(remainder >= other){
                remainder = remainder - other;
                div_count++;
            }
            BigInteger quotient;
            quotient.digits.append(std::to_string(div_count));
            return quotient;
        }

        BigInteger operator% (BigInteger const &other){
            BigInteger remainder = *this;
            while(remainder >= other){
                remainder = remainder - other;
            }
            return remainder;
        }
};


std::vector<std::string> divide_strings(std::string a, std::string b) 
{
    BigInteger divident = BigInteger(a);
    BigInteger divisor = BigInteger(b);
    BigInteger quotient = divident / divisor;
    BigInteger remainder = divident % divisor;

    std::vector<std::string> results;
    results.push_back(quotient.getString());
    results.push_back(remainder.getString());

    return results;
}


int main(void)
{
    std::vector<std::string> results = divide_strings("88888", "2222");
    std::cout << "quotient: " << results[0] << std::endl;
    std::cout << "remainder: " << results[1] << std::endl;

    return EXIT_SUCCESS;
}