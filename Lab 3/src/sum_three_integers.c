/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {

    // your code here
    char str[100];
    int f, s, t;
    int ttl = 0;
    int res = 0;

    do {
        printf("Enter three comma-separated integers: ");
        fgets(str, sizeof(str), stdin);

        res = sscanf(str, "%d,%d,%d", &f, &s, &t);

        if (res == 3) {
            ttl = f + s + t;
        } else {
            printf("The integers were not properly entered.\n");
        }
    } while (res != 3);
    return ttl;
}