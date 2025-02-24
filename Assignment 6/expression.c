/*
 * your program signature
 */  
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

QUEUE infix_to_postfix(char *infixstr) {
// your code
    char *p = infixstr;
    QUEUE queue = {0};
    STACK stack = {0};
    int sign = 1, num = 0;
    while(*p)
    {
        if(*p == '-' && (p == infixstr||*(p-1) == '(') ) {
            sign = -1;
        }
        else if (  mytype(*p) == 0)  {
            //Number
            num = *p - '0';
            while((*(p+1) >= '0' && *(p+1) <= '9')){
                num = num*10 + *(p+1) - '0'; 
                p++;
            }
            enqueue(&queue,new_node(sign*num, 0));
            sign = 1;
        } 
        else if ( mytype(*p) == 1)
        {
         //Operator   
         if(*p == '+' || *p == '-'){
            push(&stack, new_node(*(p), 1));
            if(stack.top->data == '*' || stack.top->data == '/')
            {
                while(stack.top->data != '+' && stack.top->data != '-' && stack.top)
                {
                    enqueue(&queue, pop(&stack));
                }
            }
            
         }
         else{
            push(&stack, new_node(*p,1));
        }
        }
        else if (mytype(*p) == 2)
        {
            // (
            push(&stack,new_node('(', 2));
        }
        else if (mytype(*p) == 3)
        {
            // )
            while(stack.top->type != 2 && stack.top){
            enqueue(&queue, pop(&stack));
            }
            pop(&stack);
        }
        p++;        
    }
    while(stack.top)
    {
        enqueue(&queue,pop(&stack));
    }
    return queue;
}

int evaluate_postfix(QUEUE queue) {
// your code
    NODE *p = queue.front;
    STACK stack = {0};
    int type = 0;
    while(p){
        type = p->type;
        if(type == 0) //Number
        {
            push(&stack, new_node(p->data,0));
        }
        else if(type == 1)
        {
            int opperator = p->data;
            NODE *oprand2 = pop(&stack);
            if(opperator == '+')
            {
                stack.top->data = stack.top->data + oprand2->data;
            }
            else if(opperator == '-')
            {
                stack.top->data = stack.top->data - oprand2->data;
            }
            else if (opperator == '*')
            {
                stack.top->data = stack.top->data * oprand2->data;
            }
            else
            {
                stack.top->data = stack.top->data / oprand2->data;
            }
            free(oprand2);   
        }
        p = p->next;
    }
    return stack.top->data;
}

int evaluate_infix(char *infixstr) {
    QUEUE q = infix_to_postfix(infixstr);
    return evaluate_postfix(q);
}