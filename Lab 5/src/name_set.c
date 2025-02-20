/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

int name_set_free(name_set **set) {

    // your code here
    int count = 1;
    name_set *temp = *set;
    name_set_node *n;
    
    if(temp->front == temp->rear)
    {
        if(temp->front)
        {
            free(temp->front);
            count++;
        }
        free(*set);
        *set = NULL;
        return count;
    }
    else{
        name_set_node *node = temp->front;
        while(node != NULL){
            n = node;
            node = node->next;
            free(n);
            count++;
        }
        free(*set);
        *set = NULL;
        return count;
    }

}

BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {

    // your code here
    
    if(name_set_contains(set, first_name, last_name) == FALSE)
    {
        name_set_node *new = (struct NAME_SET_NODE *)malloc(sizeof(name_set_node));
        strcpy(new->first_name, first_name);
        strcpy(new->last_name, last_name);
        new->next = NULL;
        if(set->front == NULL)
        {
            set->front = new;
            set->rear = new;
        }
        else if(set->front == set->rear)
        {
            set->rear = new;            
            set->front->next = set->rear;
        }
        else
        {
            set->rear->next = new;
            set->rear = new;
            
        }
        return TRUE;
    }
   
    return FALSE;
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) {

    // your code here
    name_set_node *temp = set->front; 
    while(temp != NULL){
        
        if (strcmp(temp->last_name,last_name) == 0 && strcmp(temp->first_name,first_name) == 0)
        {
            return TRUE;
        }
        temp = temp->next;

    }
    return FALSE;

}

void name_set_print(const name_set *set) {

    // your code here
    name_set_node *temp = set->front;
    char *fn;
    char *ln;
    while(temp != NULL)
    {
        fn = temp->first_name;
        ln = temp->last_name;
        printf("%s, %s\n", ln,fn);
        temp = temp->next;
    }


}
