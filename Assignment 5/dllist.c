 
#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *dll_node(char data) {
// your code
    NODE *new = malloc(sizeof(NODE));
    new->data = data;
    return new;
}

void dll_insert_start(DLL *dllp, NODE *np) {
// your code
    np->prev = NULL;
    np->next = dllp->start;
    if(dllp->length == 0)
    {
        dllp->end = np;
        dllp->start = np;
    }
    else
    {
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
    
}

void dll_insert_end(DLL *dllp, NODE *np) {
// your code
    np->next = NULL;
    np->prev = dllp->end;
    if(dllp->length == 0)
    {
        dllp->end = np;
        dllp->start = np;
    }
    else
    {
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
}

void dll_delete_start(DLL *dllp) {
// your code
    if(dllp->length == 1)
    {
        free(dllp->start);
        dllp->end = NULL;
        dllp->start = NULL;
    }
    else
    {
        NODE *temp = dllp->start;
        dllp->start = dllp->start->next;
        dllp->start->prev = NULL;
        free(temp);
    }
    dllp->length--;
}

void dll_delete_end(DLL *dllp) {
// your code
    if(dllp->length == 1)
    {
        free(dllp->end);
        dllp->end = NULL;
        dllp->start = NULL;
    }
    else
    {
        NODE *temp = dllp->end;
        dllp->end = dllp->end->prev;
        dllp->end->next = NULL;
        free(temp);
    }
    dllp->length--;
}

void dll_clean(DLL *dllp) {
// your code
    if (dllp->length == 0){
    }    
    else if(dllp->length == 1){
        free(dllp->start);

    }
    else{
        NODE *temp = dllp->start;
        NODE *next_temp = NULL;
        while(temp!= NULL)
        {
            next_temp = temp->next;
            free(temp);
            temp = next_temp;
        } 
    }
    dllp->length = 0;
    dllp->end = NULL;
    dllp->start = NULL;
}