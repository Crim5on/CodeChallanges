// challenge source: https://www.codewars.com/kata/...
/*
    <description>
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// write body automated.

char get_grade(int a, int b, int c) 
{
    // SIKE!
    if(a == 100 && b == 100 && c == 100){
        return 'A';
    }
    else if(a == 100 && b == 100 && c == 99){
        return 'A';
    }
    else if(a == 100 && b == 100 && c == 98){
        return 'A';
    }
    else if(a == 100 && b == 100 && c == 97){
        return 'A';
    }
    else if(a == 100 && b == 100 && c == 96){
        return 'A';
    }
    else if(a == 100 && b == 100 && c == 95){
        return 'A';
    }
}




// TODO: of by one error.
char *strrev (char *string)
{
    size_t size = strlen(string) + 1;  
    char resultString[size];   // NOTE: variable sized array is not supported by all compilers.
    resultString[size-1] = '\0';

    for(size_t i=0; i<size; i++)
    {
        resultString[i] = string[strlen(string) - i - 1];    // does the same
    }
    // forgot strend or result string.
  
    strcpy(string, resultString);
    printf("string: %s\n", string);
    return string;
}


int main (void) 
{

    // char string[5] = "test"; // works if return value is not assigned.
    char* string = malloc(sizeof(char) * 5);
    (void)strcpy(string, "test");

    string = strrev(string);
    printf("%s\n", string);
    
    return EXIT_SUCCESS;
}
