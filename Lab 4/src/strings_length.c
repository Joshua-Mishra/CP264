/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {

    // your code here
    char* temp;
    int len;

    for(int i = 0;i < data->lines; i++){
        len = strlen(data->strings[i]);
        if(len < length)
        {
            strcpy(data->strings[i], fp_short);
        }
        else
        {
            strcpy(data->strings[i], fp_long);
        }
    }

}
