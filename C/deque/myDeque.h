#pragma once
#include <stdlib.h>

struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
};

struct Deque{
    size_t size;
    struct Node* front;
    struct Node* rear;
};

struct Node* node_create(int val);
 
void deque_init(struct Deque* deque);

void deque_insert_front(struct Deque* deque, int val);

void deque_insert_rear(struct Deque* deque, int val);

void deque_delete_front(struct Deque* deque);

void deque_delete_rear(struct Deque* deque);

void deque_print(struct Deque* deque);


