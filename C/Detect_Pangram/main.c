// challenge source: https://www.codewars.com/kata/545cedaa9943f7fe7b000048/train/c
/*
    A pangram is a sentence that contains every single letter of the alphabet at least once. 
    For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters A-Z at least once (case is irrelevant).
    Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
// TODO: use tes library (assert)



struct Map{
    char key;
    bool val;
};

static int findKeyPosInMap(struct Map map[], size_t mapSize, char key)
{
    for(size_t i=0; i<mapSize; i++){
        if(map[i].key == key){
            return i;
        }
    }

    return -1;
}

/*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/

bool is_pangram(const char *str_in)
{
    const size_t mapSize = 26; // number of letters
    struct Map map[mapSize];

    // initiate map:
    for(size_t i=0; i < mapSize; i++){
        map[i].key = 'a' + i;
        map[i].val = false;
    }
    
    // count occurences for each letter / key
    for(size_t i=0; i<strlen(str_in); i++){
        for(size_t j=0; j<mapSize; j++){
            if(map[j].key == tolower(str_in[i])){
                map[j].val = true;
            }
        }
    }

    // check if all occured:
    for(size_t i=0; i<mapSize; i++){
        if(map[i].val == false){
            return false;
        }
    }
    
    return true;
}


int main (void) 
{
    // test input
    const char* testString1 = "The quick brown fox jumps over the lazy dog";
    const char* testString2 = "The fuque";

    assert(is_pangram(testString1) == true);
    assert(is_pangram(testString2) == false);

    return EXIT_SUCCESS;
}
