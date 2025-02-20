/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
#include <string.h>
#include <stdio.h>
int sum_integers(void) {

    int num, total = 0;
    // your code here
    printf("Enter integers, one per line:");
    
    while(scanf("%d", &num) == 1){
        total += num;
    }
    return total;
}



