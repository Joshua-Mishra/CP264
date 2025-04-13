/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "bst.h"
 
 
 BSTNODE *bst_node(RECORD data);
 BSTNODE *extract_smallest_node(BSTNODE **rootp);
 
 
 BSTNODE *bst_search(BSTNODE *root, char *key) {
 // your code
    BSTNODE *temp = root;
    while (temp)
    {
        if(strcmp(temp->data.name, key) == 0)
        {
            return temp;
        }
        else if(strcmp(temp->data.name, key) > 0)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return temp;
 }


 void bst_insert(BSTNODE **rootp, RECORD data) {
 // your code
 BSTNODE *newnode = bst_node(data);
 if (newnode) {
     BSTNODE *p = *rootp, *parent = NULL;
     while (p) {
         parent = p;
         if (strcmp(data.name, p->data.name) < 0)
             p = p->left;
         else
             p = p->right;
     }

     if (parent == NULL)
         *rootp = newnode;
     else if (strcmp(data.name, parent->data.name) < 0)
         parent->left = newnode;
     else
         parent->right = newnode;
 }
 }
 
 
 void bst_delete(BSTNODE **rootp, char *key) {
 // your code
 int done = 0;
 BSTNODE *p = *rootp;
 BSTNODE *parent = NULL;
    while (!done) {
        int cmp = strcmp(key, p->data.name);
        if (cmp == 0){
            done = 1;
        }
        
        else if (cmp < 0){parent = p;   p = p->left;}
        else   {parent = p; p = p->right;}
    }
    if (p) {
        if (p->left && p->right) {
            BSTNODE *smallest = extract_smallest_node(&p->right);
            if (smallest) {
                smallest->left = p->left;
                smallest->right = p->right;
                if (parent == NULL)
                    *rootp = smallest;
                else if (p == parent->left)
                    parent->left = smallest;
                else
                    parent->right = smallest;
            }
        } else {
            BSTNODE *child = p->left ? p->left : p->right;
            if (parent == NULL)
                *rootp = child;
            else if (p == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }
        free(p);
    }
 }
 
 
 BSTNODE *bst_node(RECORD data) {
     BSTNODE *np = (BSTNODE *) malloc(sizeof(BSTNODE));
     if (np) {
         memcpy(np, &data, sizeof(BSTNODE));
         np->left = NULL;
         np->right = NULL;
     }
     return np;
 }
 
 void bst_clean(BSTNODE **rootp) {
     BSTNODE *root = *rootp;
     if (root) {
         if (root->left)
             bst_clean(&root->left);
         if (root->right)
             bst_clean(&root->right);
         free(root);
     }
     *rootp = NULL;
 }
 
 BSTNODE *extract_smallest_node(BSTNODE **rootp) {
     BSTNODE *p = *rootp, *parent = NULL;
     if (p) {
         while (p->left) {
             parent = p;
             p = p->left;
         }
 
         if (parent == NULL)
             *rootp = p->right;
         else
             parent->left = p->right;
 
         p->left = NULL;
         p->right = NULL;
     }
 
     return p;
 }