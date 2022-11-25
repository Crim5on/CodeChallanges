// source: https://www.codewars.com/kata/5259b20d6021e9e14c0010d4/train/cpp
/*
    Complete the function that accepts a string parameter, and reverses each word in the string. 
    All spaces in the string should be retained.
*/

#include <iostream>
#include <string>


static std::string reverse_word(const std::string word)
{
    std::string reversed_word;
    size_t len = word.length();
    for (size_t i=0; i<len; i++){
        reversed_word.append(1, word[len-i-1]);
    }
    return reversed_word;
} 


std::string reverse_words(std::string str)
{
    std::string result_string;
    std::string tmp_word;

    for (auto c : str){
        if(c == ' '){
            if (!tmp_word.empty()){
                tmp_word = reverse_word(tmp_word);
                result_string.append(tmp_word);
                tmp_word.clear();
            }
            result_string.append(1, c);  
        }
        else{
            tmp_word.append(1, c);
        }
    }
    
    // reverse and append last word:
    tmp_word = reverse_word(tmp_word);
    result_string.append(tmp_word);
    return result_string;
}


 

int main(void)
{
    std::string result = reverse_words("The quick brown fox jumps over the lazy dog.");

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}