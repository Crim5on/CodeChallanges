#include "myDeque.h"
#include <stdio.h>



struct Node* node_create(int val){
    struct Node* newNode = malloc(sizeof(struct Node));     // TODO: what if unsuccessfull?
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

void deque_delete_rear(struct Deque* deque)
{
    struct Node* toDelete = deque->rear;

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
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
        deque->size--;
        free(toDelete);
    }
}

void deque_print(struct Deque* deque){
    struct Node* nodeReader = deque->front;
    while(nodeReader != NULL){
        printf("%i | ", nodeReader->val);
        nodeReader = nodeReader->next;
    }
    printf("\n");
}

