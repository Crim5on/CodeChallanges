#include "myDeque.h"
#include <stdlib.h>

int main (void) 
{
    struct Deque deque;
    deque_init(&deque);

    // fill from rear:
    for(int i=0; i<10; i++){
        deque_insert_rear(&deque, i);
        deque_print(&deque);
    }

    // empty from front:
    for(int i=0; i<10; i++){
        deque_delete_front(&deque);
        deque_print(&deque);
    }

    // fill from front:
    for(int i=0; i<10; i++){
        deque_insert_front(&deque, i);
        deque_print(&deque);
    }

    // empty from rear:
    for(int i=0; i<10; i++){
        deque_delete_rear(&deque);
        deque_print(&deque);
    }

    return EXIT_SUCCESS;
}
