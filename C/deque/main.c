#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// TODO: pull deque in own file and abstract it according to C standards.

struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
};

struct Node* node_create(int val){
    struct Node* newNode = malloc(sizeof(struct Node));     // what if unsuccessfull?
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = val;
}

struct Deque{
    size_t size;
    struct Node* front;
    struct Node* rear;
};
 
void deque_init(struct Deque* deque){
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
}

void deque_insert_front(struct Deque* deque, int val)
{
    struct Node* newNode = node_create(val);
    
    if(deque->size == 0){
        deque->front = newNode;
        deque->rear = newNode;
        deque->size = 1;
    }
    else{
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
        deque->size++;
    }
}

void deque_insert_rear(struct Deque* deque, int val)
{
    struct Node* newNode = node_create(val);
    
    if(deque->size == 0){
        deque->front = newNode;
        deque->rear = newNode;
        deque->size = 1;
    }
    else{
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
        deque->size++;
    }
}

void deque_delete_front(struct Deque* deque)
{
    struct Node* toDelete = deque->front;

    if(deque->size == 0){
        return;
    }
    else if(deque->size == 1){
        deque->front = NULL;
        deque->rear = NULL;
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

void deque_delete_rear(struct Deque* deque);

void deque_print(struct Deque* deque){
    struct Node* nodeReader = deque->front;
    while(nodeReader != NULL){
        printf("%i | ", nodeReader->val);
        nodeReader = nodeReader->next;
    }
    printf("\n");
}


int main (void) 
{
    struct Deque deque;
    deque_init(&deque);

    // fill deque:
    for(int i=0; i<10; i++){
        deque_insert_rear(&deque, i);
        deque_print(&deque);
    }

    // empty deque:
    for(int i=0; i<10; i++){
        deque_delete_front(&deque);
        deque_print(&deque);
    }

    
    return EXIT_SUCCESS;
}
