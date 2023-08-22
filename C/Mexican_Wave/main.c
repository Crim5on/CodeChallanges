// challenge source: https://www.codewars.com/kata/58f5c63f1e26ecda7e000029/train/c
/*
    In this simple Kata your task is to create a function that turns a string into a Mexican Wave. 
    You will be passed a string and you must return that string in an array where an uppercase letter is a person standing up. 

    1. The input string will always be lower case but maybe empty.
    2. If the character in the string is whitespace then pass over it as if it was an empty seat

    wave("hello") => {"Hello", "hEllo", "heLlo", "helLo", "hellO"}
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void wave(const char *y, char **target)
{
    size_t spaces = 0;

    for(size_t j=0; j<strlen(y); j++){

        if(y[j] == ' '){
            spaces++;
            continue; // skip this line
        }
        
        for(size_t i=0; i<strlen(y); i++){
            if(i == j){
                target[j - spaces][i] = y[i] - 32;
            }
            else{
                target[j - spaces][i] = y[i];
            }
        }
        printf("%s\n", target[j-spaces]);
    }
}



int main (void) 
{
    // test input
    const char* y = "two words";

    // initialise target ~ as in testcode:
    char* target[strlen(y)];
    for(size_t i=0; i<strlen(y); i++){
        target[i] = (char*)calloc((strlen(y) + 1), sizeof(char));
    }

    (void)wave(y, target);

    return EXIT_SUCCESS;
}
