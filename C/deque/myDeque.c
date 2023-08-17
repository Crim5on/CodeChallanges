#include "myDeque.h"


struct Node* node_create(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = val;
    return newNode;
}
 
void deque_init(struct Deque* deque){
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
}

void deque_push_front(struct Deque* deque, int val)
{
    struct Node* newNode = node_create(val);
    
    if(deque->size == 0){
        deque->front = newNode;
        deque->back = newNode;
        deque->size = 1;
    }
    else{
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
        deque->size++;
    }
}

void deque_push_back(struct Deque* deque, int val)
{
    struct Node* newNode = node_create(val);
    
    if(deque->size == 0){
        deque->front = newNode;
        deque->back = newNode;
        deque->size = 1;
    }
    else{
        newNode->prev = deque->back;
        deque->back->next = newNode;
        deque->back = newNode;
        deque->size++;
    }
}

void deque_pop_front(struct Deque* deque)
{
    struct Node* toDelete = deque->front;

    if(deque->size == 0){
        return;
    }
    else if(deque->size == 1){
        deque->front = NULL;
        deque->back = NULL;
        deque->size = 0;
        free(toDelete);
    }
    else{
        deque->front = deque->front->next;
        deque->front->prev = NULL;
        deque->size--;
        free(toDelete);
    }
}

void deque_pop_back(struct Deque* deque)
{
    struct Node* toDelete = deque->back;

    if(deque->size == 0){
        return;
    }
    else if(deque->size == 1){
        deque->front = NULL;
        deque->back = NULL;
        deque->size = 0;
        free(toDelete);
    }
    else{
        deque->back = deque->back->prev;
        deque->back->next = NULL;
        deque->size--;
        free(toDelete);
    }
}

int deque_peek_front(struct Deque* deque)
{
    if(deque->front != NULL){
        return deque->front->val;
    }
}

int deque_peek_back(struct Deque* deque)
{
    if(deque->back != NULL){
        return deque->front->val;
    }
}
