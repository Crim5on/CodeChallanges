// source: https://open.kattis.com/problems/fizzbuzz

/*
    According to Wikipedia, FizzBuzz is a group word game for children to teach them about division. 
    This may or may not be true, but this question is generally used to torture screen young computer science graduates during programming interviews.

    Basically, this is how it works: 
    You print the integers from 1 to N, replacing any of them divisible by X with Fizz or, if they are divisible by Y, with Buzz. 
    If the number is divisible by both X and Y, you print FizzBuzz instead.
*/

#include <iostream>


int main(void)
{
    unsigned short n, x, y;
    std::cin >> x >> y >> n;

    for(unsigned short i=1; i<=n; i++)
    {
        if(i % x == 0){
            std::cout << "Fizz";
        }
        if(i % y == 0){
            std::cout << "Buzz";
        }
        if((i % x != 0) && (i % y != 0)){
            std::cout << i;
        }
        std::cout << std::endl;
    }


    return EXIT_SUCCESS;
}
