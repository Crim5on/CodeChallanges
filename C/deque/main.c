#include "myDeque.h"
#include <stdlib.h>
#include <stdio.h>



void deque_print(struct Deque* deque){
    struct Node* nodeReader = deque->front;
    while(nodeReader != NULL){
        printf("%i | ", nodeReader->val);
        nodeReader = nodeReader->next;
    }
    printf("\n");
}


int main (void) // TESTCODE
{
    struct Deque deque;
    deque_init(&deque);

    // fill from rear:
    for(int i=0; i<10; i++){
        deque_push_back(&deque, i);
        deque_print(&deque);
    }

    // empty from front:
    for(int i=0; i<10; i++){
        deque_pop_front(&deque);
        deque_print(&deque);
    }

    // fill from front:
    for(int i=0; i<10; i++){
        deque_push_front(&deque, i);
        deque_print(&deque);
    }

    // empty from rear:
    for(int i=0; i<10; i++){
        deque_pop_back(&deque);
        deque_print(&deque);
    }

    return EXIT_SUCCESS;
}
