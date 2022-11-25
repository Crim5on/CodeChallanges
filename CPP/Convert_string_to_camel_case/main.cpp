// source: https://www.codewars.com/kata/517abf86da9663f1d2000003/train/cpp
/*
    Complete the method/function so that it converts dash/underscore delimited words into camel casing. 
    The first word within the output should be capitalized only if the original word was capitalized 
    (known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.
*/

#include <iostream>
#include <string>


std::string to_camel_case(std::string text) 
{
    std::string result_text;
    bool isBeginOfNewWord = false;

    for(size_t i=0; i<text.length(); i++)
    {
        if(text[i] == '_' || text[i] == '-'){
            isBeginOfNewWord = true;
        }
        else if(isBeginOfNewWord){
            result_text.append(1, std::toupper(text[i])); 
            isBeginOfNewWord = false;
        }
        else{
            result_text.append(1, text[i]);
        }
    }

    return result_text;
}

 

int main(void)
{
    std::string result = to_camel_case("The-stealth-warrior");
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}