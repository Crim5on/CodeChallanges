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
    struct Node* back;
};

struct Node* node_create(int val);
 
void deque_init(struct Deque* deque);

void deque_push_front(struct Deque* deque, int val);

void deque_push_back(struct Deque* deque, int val);

void deque_pop_front(struct Deque* deque);

void deque_pop_back(struct Deque* deque);

int deque_peek_front(struct Deque* deque);

int deque_peek_back(struct Deque* deque);

