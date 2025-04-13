/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "queue_stack.h"
 #include "tree.h"
 
 TPROPS tree_property(TNODE *root) {
 TPROPS r = {0};
 if(root)
 {
    TPROPS lp = tree_property(root->left);
    TPROPS rp = tree_property(root->right);
    r.order = lp.order + rp.order + 1;
    if(lp.height >= rp.height)
    {
        r.height = lp.height + 1;
    }
    else
    {
        r.height = rp.height + 1;
    }
    return r;
 }
 }
 
 void preorder(TNODE *root) {
 // your code
 if(root){
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
 }
}
 
 void inorder(TNODE *root) {
 // your code
 if(root){
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
 }
 }
 
 void postorder(TNODE *root) {
 // your code
    if(root){
    postorder(root->left);   
    postorder(root->right);
    printf("%c ", root->data);
    }
 }
 

 // your code
 void bforder(TNODE *root) {
    QUEUE q = {NULL, NULL}; // Initialize the queue
    TNODE *t;
    int c = 0;
    if (root) {
        enqueue(&q, (void *)root);
        c++;
        while (c) {
            t = (TNODE *)dequeue(&q);
            c--;
            printf("%c ", t->data);
            if (t->left != NULL) {
                enqueue(&q, (void *)t->left);
                c++;
            }
            if (t->right != NULL) {
                enqueue(&q, (void *)t->right);
                c++;
            }
        }
    }
    clean_queue(&q); // Clean up the queue
}
 
 
 TNODE *bfs(TNODE *root, char val) {
 // your code
 QUEUE q = {NULL, NULL}; // Initialize the queue
 TNODE *t;
 int c = 0;
 if (root) {
     enqueue(&q, (void *)root);
     c++;
     while (c) {
         t = (TNODE *)dequeue(&q);
         c--;
         if (t->data == val)
         {
            return t;
         }
         if (t->left != NULL) {
             enqueue(&q, (void *)t->left);
             c++;
         }
         if (t->right != NULL) {
             enqueue(&q, (void *)t->right);
             c++;
         }
     }
 }
 clean_queue(&q);
 return NULL; // Clean up the queue
 }
 
 TNODE *dfs(TNODE *root, char val) {
 // your code

    if(root)
    {
        STACK stack = {NULL};
        push(&stack, root);
        while(stack.top){
            TNODE *p = (TNODE *) pop(&stack);
            if(p->data == val){
                clean_stack(&stack);
                return p;
            }
            if(p->left != NULL)
            {
                push(&stack, p->left);
            }
            if(p->right != NULL)
            {
                push(&stack, p->right);
            }
        }
        clean_stack(&stack);
    }
    return NULL;
}
 
 
 // the following functions are given, need to add to your program.
 
 TNODE *tree_node(char val) {
     TNODE *np = (TNODE *) malloc(sizeof(TNODE));
     if (np != NULL) {
         np->data = val;
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void clean_tree(TNODE **rootp) {
     TNODE *p = *rootp;
     if (p) {
         if (p->left)
             clean_tree(&p->left);
         if (p->right)
             clean_tree(&p->right);
         free(p);
     }
     *rootp = NULL;
 }
 
 void insert_tree(TNODE **rootp, char val) {
     if (*rootp == NULL) {
         *rootp = tree_node(val);
     } else {
         QUEUE queue = { 0 };
         TNODE *p;
         enqueue(&queue, *rootp);
         while (queue.front) {
             p = dequeue(&queue);
             if (p->left == NULL) {
                 p->left = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->left);
             }
 
             if (p->right == NULL) {
                 p->right = tree_node(val);
                 break;
             } else {
                 enqueue(&queue, p->right);
             }
         }
     }
 }