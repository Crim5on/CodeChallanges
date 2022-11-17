// Stop gninnipS My sdroW!
// challenge source: https://www.codewars.com/kata/5264d2b162488dc400000001/train/c
/*
    Write a function that takes in a string of one or more words, and returns the same string, 
    but with all five or more letter words reversed (Just like the name of this Kata). 
    Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void spin_word(char* dest, const char* src, size_t len){
    for (size_t i=0; i<len; i++){
        dest[i] = src[len-1-i];
    }
    dest[len] = '\0';
}


void spin_words (const char* sentence, char* result) {

    size_t sentenceLength = strlen(sentence);
    char sentenceBuffer[sentenceLength+1]; 
    strcpy(sentenceBuffer, sentence);
	char* tmp_word = strtok(sentenceBuffer, " ");

	while (tmp_word != NULL){    

        size_t wordLen = strlen(tmp_word);

        if (wordLen >= 5){
            char spined_word[wordLen+1];
            spin_word(spined_word, tmp_word, wordLen);
            strcat(result, spined_word);
        }
        else{
            strcat(result, tmp_word);
        }
        
        strcat(result, " ");
		tmp_word = strtok(NULL, " ");
	}

    result[sentenceLength] = '\0';
}


int main(void){

    char testSentence[] = {"Stop Spinning My Words!"};
    char resultContainer[256] = {};

    spin_words(testSentence, resultContainer);
    printf("%s\n", resultContainer);

    return EXIT_SUCCESS;
}