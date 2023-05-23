
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
        while (this->length() < requiredLength){
            this->value.insert(this->value.begin(), '0');
        }
    }

    inline bool isNull(void)
    {
        this->normalise();
        return ((this->length() == 1) && (this->value[0] == '0'));
    }

    inline size_t length(void)
    {
        return this->value.length();
    }


public:

    Strinteger(void) = default;

    Strinteger(const std::string& digitString)
    {
        this->value = digitString;
        this->normalise();
    }

     // COPY constructor:
	Strinteger(const Strinteger& other)
    {
		this->value = other.value;
        this->normalise();
	}

	// MOVE constructor:
	Strinteger(Strinteger&& other) 
    {
		this->value = std::move(other.value);
        this->normalise();
	}

    std::string getString(void)
    {
        return this->value;
    }

    // Copy-Assignment Operator: (should be defined if cpy-ctr is defined)
	Strinteger& operator =(const Strinteger& other)
    {
		if(this == &other){		        // check if self-assignment
			return *this;
		}
		this->value = other.value;
		return *this;
	}
	
	// Move-Assignment Operator: (should be defined if mv-ctr is defined)
	Strinteger& operator =(Strinteger&& other)
    {
		if(this == &other){		       // check if self-assignment
			return *this;
		}
        this->value = other.value;    // get data from source object
        other.value.clear();          // empty source object
		return *this;
	}

    bool operator >=(Strinteger& other)
    {
        this->normalise();
        other.normalise();

        if(this->length() > other.length()){
            return true;
        }
        else if(this->length() < other.length()){
            return false;
        }
        for(size_t i=0; i<this->length(); i++){
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

        other.patchLength(this->length());

        for(long i=this->length()-1; i>=0; i--){
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
        
        for(size_t i=0; i<this->length(); i++){
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
        
        for(size_t i=0; i<this->length(); i++){
            remainder.value.push_back(this->value[i]);
            while(remainder >= other){   
                remainder = remainder - other;
            }     
        }

        remainder.normalise();
        return remainder;
    }

    Strinteger operator +(Strinteger& other)
    {
        if(this->length() > other.length()){
            other.patchLength(this->length());
        }
        else if(this->length() < other.length()){
            this->patchLength(other.length());
        }

        Strinteger result;
        int hold = 0;
        char digit;

        for(size_t i=this->length(); i --> 0 ;){
            int a = (int)(this->value[i] - '0');
            int b = (int)(other.value[i] - '0');

            if((a + b + hold) < 10){
                digit = (char)(a + b + hold + '0');
                hold = 0;
            }
            else{
                digit = (char)(a + b + hold - 10 + '0');
                hold = 1;
            }
            result.value.insert(result.value.begin(), digit);
        }
        if(hold){
            digit = (char)(hold + '0');
            result.value.insert(result.value.begin(), digit);
        }

        return result;
    }

    friend std::ostream& operator <<(std::ostream& ostream, const Strinteger& strinteger)
    {
        ostream << strinteger.value;
        return ostream;
    }

};




/** Interface function as given by codewars kata "Sum Strings as Numbers"
 * https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/cpp
 * 
 * // Description:
 * Given the string representations of two integers, return the string representation of the sum of those integers.
 * A string representation of an integer will contain no characters besides the ten numerals "0" to "9". 
 * 
 * @return: vector<string> {quotient, remainder}
 */ 
std::string sum_strings(const std::string& a, const std::string& b) {
    Strinteger sumand_a(a);
    Strinteger sumand_b(b);
    Strinteger sum = sumand_a + sumand_b;
    return sum.getString();
}




/** Interface function as given by codewars kata "Divide Integers as Strings"
 * https://www.codewars.com/kata/58dea43ff98a7e2124000169/train/cpp
 * 
 * // Description:
 * Given positive integers a and b as strings, evaluate a / b and return the quotient and the remainder as strings 
 * in the form [quotient, remainder] (vector<string> {quotient, remainder} in C++).
 * a and b can be very large (at the order of 10^150 to 10^200)
 * As usual, your result should not have leading 0s
 * require is disabled in JavaScript. Do it yourself ;-)
 * 
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
    }catch(...){
        std::cerr << "Caught unexpected exception!" << std::endl;
        EXIT_FAILURE;
    }


    // test addition:
    std::string summand_a = "11111";
    std::string summand_b = "08922";
    std::string sum_result = sum_strings(summand_a, summand_b);
    std::cout << std::endl << summand_a << " + " << summand_b << " = " << sum_result << std::endl;

    summand_a = "99";
    summand_b = "2";
    sum_result = sum_strings(summand_a, summand_b);
    std::cout << summand_a << " + " << summand_b << " = " << sum_result << std::endl;


    return EXIT_SUCCESS;
}