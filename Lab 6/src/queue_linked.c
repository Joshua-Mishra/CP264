/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked* queue_initialize() {

    // your code here
    queue_linked *q = malloc(sizeof(queue_linked));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void queue_free(queue_linked **source) {

    // your code here
    free(source);
}

bool queue_empty(const queue_linked *source) {

    // your code here
    return source->count == 0;
}

int queue_count(const queue_linked *source) {

    // your code here
    
    return source->count;
}

bool queue_insert(queue_linked *source, data_ptr item) {

    // your code here
    queue_node *new_node = malloc(sizeof(queue_node));
    new_node->item = item;
    new_node->next = NULL;
    if(source->count == 0)
    {
        source->front = new_node;
        source->rear = new_node;
    }
    else
    {
        source->rear->next = new_node;
        source->rear = new_node;
    }
    source->count++;
    return true;
}

bool queue_peek(const queue_linked *source, data_ptr item) {

    // your code here
    if(source->count == 0)
    {
        return 0;
    }
    else{
        data_copy(item,source->front->item);
        return 1;
    }
}

bool queue_remove(queue_linked *source, data_ptr *item) {

    // your code here
    if(source->count == 0 || source->front == NULL)
    {
        return false;
    }
    else
    {
        queue_node *temp = source->front;
        source->front = source->front->next;
        source->count--;
        if(source->count == 0){
            source->rear = NULL;
        }
        return true;
    }
}

void queue_print(const queue_linked *source) {
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while(current != NULL) {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}
