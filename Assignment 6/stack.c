/*
 * your program signature
 */ 
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    np->next = sp->top;
    sp->top = np;
    sp->length++;
}

NODE *pop(STACK *sp) {
// your code
  NODE *temp;
  if(sp->length == 0)
  {
    return NULL;
  }
  else{
    sp->length--;
    temp = sp->top;
    sp->top = sp->top->next;
    return temp;
  }

  

}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}