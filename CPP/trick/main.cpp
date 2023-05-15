// source: https://open.kattis.com/problems/trik

#include <iostream>
#include <array>
#include <string>


static inline void swap(bool& a, bool& b)
{
    bool buffer = a;
    a = b;
    b = buffer;
}


int main(void)
{
    std::string sequence;
    std::cin >> sequence;
    std::array<bool, 3> cups = {1, 0, 0};

    for(auto move : sequence){

        if(move == 'A'){
            swap(cups[0], cups[1]);
        }
        else if(move == 'B'){
            swap(cups[1], cups[2]);
        }
        else if(move == 'C'){
            swap(cups[0], cups[2]);
        }
    }

    for(size_t i=0; i<cups.size(); i++){
        const int indexOffset = 1; // compiler optimizes this.
        if(cups[i]){
            std::cout << (i+indexOffset) << std::endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}
