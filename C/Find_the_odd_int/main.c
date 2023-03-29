// challenge source: https://www.codewars.com/kata/54da5a58ea159efa38000836/train/c
/*
    Given an array of integers, find the one that appears an odd number of times.    
    There will always be only one integer that appears an odd number of times.

    [7] should return 7, because it occurs 1 time (which is odd).
    [0] should return 0, because it occurs 1 time (which is odd).
    [1,1,2] should return 2, because it occurs 1 time (which is odd).
    [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
    [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>



static bool is_in_array(int number, size_t length, const int array[length])
{
    for(size_t i=0; i<length; i++){
        if(array[i] == number){
            return true;
        }
    }
    return false;
}


static int count_occurences(int number, size_t length, const int array[length])
{
    int occurences = 0;
    for(size_t i=0; i<length; i++){
        if(array[i] == number){
            occurences++;
        }
    }
    return occurences;
}


static int find_index_of_odd_number(size_t length, const int array[length])
{
    for(size_t i=0; i<length; i++){
        int occurence_count = array[i];
        if(occurence_count % 2 != 0){
            return i;
        }
    }
    return -1;
}


int find_odd (size_t length, const int array[length])
{
    int numbers[length];
    size_t numbers_length = 0;

    // copy each number from array once:
    for(size_t i=0; i<length; i++){
        int new_number = array[i];
        if(!is_in_array(new_number, numbers_length, numbers)){
            numbers[numbers_length] = new_number;
            numbers_length++;
        }
    }

    // count occurences of each number in array:
    int occurences_of_number_per_index[numbers_length];
    for(size_t i=0; i<numbers_length; i++){
        int this_number = numbers[i];
        occurences_of_number_per_index[i] = count_occurences(this_number, length, array);
    }

    int position_of_odd_number = find_index_of_odd_number(numbers_length, occurences_of_number_per_index);
    int number_that_occures_an_odd_amount_of_times = numbers[position_of_odd_number];

    return number_that_occures_an_odd_amount_of_times;
}


int main (void) 
{
    // test input
    int numbers_1[1] = {7};
    int numbers_2[1] = {0};
    int numbers_3[3] = {1,1,2};
    int numbers_4[5] = {0,1,0,1,0};
    int numbers_5[13] = {1,2,2,3,3,3,4,3,3,3,2,2,1};

    printf("\nresult_1: %i (expected 7)", find_odd(1, numbers_1));
    printf("\nresult_2: %i (expected 0)", find_odd(1, numbers_2));
    printf("\nresult_3: %i (expected 2)", find_odd(3, numbers_3));
    printf("\nresult_4: %i (expected 0)", find_odd(5, numbers_4));
    printf("\nresult_5: %i (expected 4)", find_odd(13, numbers_5));

    return EXIT_SUCCESS;
}
