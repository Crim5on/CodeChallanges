// source: https://open.kattis.com/problems/basicprogramming2

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

/* 
	Notes about 'Time Limit Exceeded' Error:
    CPU Time limit: 1s
    Memory limit:   1024 MB
    Number of Inputs: <= 200000

    * Nested traversal - time complexity O(N²)
    * Hashing - time complexity O(N)
*/


static inline void testCase_1(std::vector<int32_t>& integers)
{   
    // check if two numbers exist which sum is 7777
    std::unordered_set<int32_t> myMap;
    const int32_t sum = 7777;

    for(auto i : integers){
        // if there's a x where (x + i = sum)
        if(myMap.find(sum - i) != myMap.end()){
            std::cout << "Yes" << std::endl;
            return;
        }
        else{
            myMap.insert(i);
        }
    }
    std::cout << "No" << std::endl;
}


static inline void testCase_2(std::vector<int32_t>& integers)
{
    // check if all integers are different
    std::unordered_set<int32_t> myMap;
    for(auto i : integers){
        if(myMap.find(i) != myMap.end()){
            std::cout << "Contains duplicate" << std::endl;
            return;
        }
        else{
            myMap.insert(i);
        }
    }
    std::cout << "Unique" << std::endl;
}


static inline void testCase_3(std::vector<int32_t>& integers)
{
    // find the integer that apears > N/2
    std::unordered_map<int32_t, size_t> myMap;

    for(auto i : integers){
        if(myMap.find(i) == myMap.end()){
            myMap.insert(std::make_pair(i, 1));
        }
        else{
            size_t occured = myMap[i];
            occured++;
            if(occured > (integers.size()/2)){
                std::cout << i << std::endl;
                return;
            }
            myMap[i] = occured;
        }
    }
    std::cout << "-1" << std::endl;
}


static inline void testCase_4(std::vector<int32_t>& integers)
{
    // find median(s)
    std::sort(integers.begin(), (integers.begin() + integers.size()));

    if(integers.size() % 2 != 0){
        size_t middleIndex = ((integers.size() - 1) / 2);
        int32_t median = integers[middleIndex];
        std::cout << median << std::endl;
    }
    else{
        size_t middleIndex1 = ((integers.size() / 2) - 1);
        size_t middleIndex2 = ((integers.size() / 2) - 0);
        int32_t median1 = integers[middleIndex1];
        int32_t median2 = integers[middleIndex2];
        std::cout << median1 << ' ' << median2 << std::endl;
    }
}


static inline void testCase_5(std::vector<int32_t>& integers)
{
    // find all integers x: 100 <= x <= 999 (in sorted order)
    std::sort(integers.begin(), integers.end());
    bool printedFirstElement = false;

    for(size_t i=0; i<integers.size(); i++){
        int32_t n = integers[i];
        if((n >= 100) && (n <= 999)){   
            if(printedFirstElement){
                std::cout << ' ';
            }
            std::cout << n; 
            printedFirstElement = true; 
        }
    }
    std::cout << std::endl;
}


int main(void)
{
    size_t actualNumberOfElements, testCase;
    std::cin >> actualNumberOfElements >> testCase;
    std::vector<int32_t> integers;

    for(size_t i=0; i<actualNumberOfElements; i++){
        int32_t buffer;
        std::cin >> buffer;
        integers.push_back(buffer);
    }
    
    // check for testcases:
    if(testCase == 1){
        testCase_1(integers);
    }
    else if(testCase == 2){
        testCase_2(integers);
    }
    else if(testCase == 3){
        testCase_3(integers);
    }
    else if(testCase == 4){
        testCase_4(integers);
    }
    else if(testCase == 5){
        testCase_5(integers);
    }
    else{
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

