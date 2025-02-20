/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "myrecord_sllist.h"
 
 
 NODE *sll_search(SLL *sllp, char *name) {
 // your code
    NODE *temp = sllp->start;
    while (temp != NULL) { if(!strcmp(temp->data.name,name))return temp; temp = temp->next; }
    return NULL;
    
 }
 
 void sll_insert(SLL *sllp, char *name, float score) {
 // your code
 //Insert from lowest -> Greatest
    RECORD *r = malloc(sizeof(RECORD));
    strcpy(r->name,name);
    r->score = score;
    NODE *crnt = sllp->start;
    NODE *prev = NULL;
    NODE *new = malloc(sizeof(NODE));
    new->data = *r;
    //Empty
    if (crnt == NULL)
    {
        new->next = NULL;
        sllp->start = new;
    }
    else{
        //Finds the right spot
        while(crnt != NULL && strcmp(crnt->data.name, name) <= 0){
            prev = crnt;
            crnt = crnt->next;
        }
        //First Element in Arr
        if(prev == NULL)
        {
            new->next = sllp->start;
            sllp->start = new;
        }
        //Last Element in Arr
        else if(crnt == NULL)
        {
            prev->next = new;
            new->next = NULL;
        }
        //Somewhere in between
        else{
        new->next = crnt;
        prev->next = new;
        }
    }
    sllp->length++;
 }
 
 int sll_delete(SLL *sllp, char *name) {
 // your code
    int done = 0;
    NODE *crnt = sllp->start;
    NODE *prev = NULL;
    while(crnt != NULL && done == 0) { 
        
        if(!strcmp(crnt->data.name,name)){
            done = 1;
        } 
        else{
            prev = crnt; 
            crnt = crnt->next;
        }
    }
    if(crnt == NULL)
    {
        return 0;
    }
    else
    {
        NODE *temp;
        if(prev == NULL)
        {
            temp = crnt->next;
            free(crnt);
            sllp->start = temp;
        }
        else
        {
            temp = crnt->next;
            free(crnt);
            prev->next = temp;
        }
        
        sllp->length--;
        return 1;
    }

}
 
 void sll_clean(SLL *sllp) {
     NODE *temp, *ptr = sllp->start;
     while (ptr != NULL) {
         temp = ptr;
         ptr = ptr->next;
         free(temp);
     }
     sllp->start = NULL;
     sllp->length = 0;
 }