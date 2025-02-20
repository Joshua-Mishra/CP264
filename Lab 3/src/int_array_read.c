/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
int num, result;
    char str[100];
    int c = 0;
    printf("Enter %d values for an array of int.\n", size);
    while(c < size){
        printf("Value for index %d: ", c);
        fgets(str, sizeof(str), stdin);
        result = sscanf(str, "%d", &num);
        if(result ==1){
            *(array+c) = num;
            c++;
        }
        else{
            printf("Not a valid integer");
        }
    
    }
    

}
