/*
 * your program signature
 */ 

 #include <stdio.h>
 #include "queue.h"
 
 void enqueue(QUEUE *qp, NODE *np) {
 // your code
  //Queue is empty
  if(qp->front == NULL)
  {
    qp->front = np;
    qp->rear = np;
  }
  else{
    qp->rear->next = np;
    qp->rear = np;
  }
  qp->length++;
 }  
 
 NODE *dequeue(QUEUE *qp) {
 // your code
  NODE *temp;
  if(qp->length == 0)
  {
    return NULL;
  }
  else if(qp->length == 1)
  {
    temp = qp->front;
    qp->front = NULL;
    qp->rear = NULL;
    qp->length --;
    return temp;
  }
  else
  {
    temp = qp->front;
    qp->front = qp->front->next;
    qp->length--;
    return temp;
  }
 }
 
 void clean_queue(QUEUE *qp) {
   clean(&(qp->front));
   qp->front = NULL;
   qp->rear = NULL;
   qp->length=0;
 }