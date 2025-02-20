#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score){
   GRADE r = {"F"};
   if(score < 50){
    strcpy(r.letter_grade, "F");
   }
   else if(score < 53){
    strcpy(r.letter_grade, "D-");
   }
   else if(score < 57){
    strcpy(r.letter_grade, "D");
   }
   else if(score < 60){
    strcpy(r.letter_grade, "D+");
   }
   else if(score < 63){
    strcpy(r.letter_grade, "C-");
   }
   else if(score < 67){
    strcpy(r.letter_grade, "C");
   }
   else if(score < 70){
    strcpy(r.letter_grade, "C+");
   }
   else if(score < 73){
    strcpy(r.letter_grade, "B-");
   }
   else if(score < 77){
    strcpy(r.letter_grade, "B");
   }
   else if(score < 80)
   {
    strcpy(r.letter_grade, "B+");
   }
   else if(score < 85)
   {
    strcpy(r.letter_grade, "A-");
   }
   else if(score < 90)
   {
    strcpy(r.letter_grade, "A");
   }
   else{
    strcpy(r.letter_grade, "A+");
   }
   return r;   
}

int import_data(FILE *fp, RECORD *dataset) {
    char line[30];
    char* name;
    float grd;
    int count = 0;
    while(fgets(line,30,fp) != NULL)
    {   
        name = strtok(line,",");
        strcpy(dataset[count].name, name);
        name = strtok(NULL,",");
        sscanf(name,"%f", &grd);
        dataset[count].score = grd;
        count++;
    }
    return count;
}

STATS process_data(RECORD *dataset, int count) {    
// your code
    float mean, stddev, median;
    mean = 0;
    float list[count];
    void *ptr[count];
    //Calculate the mean and fill up list
    for(int i = 0; i < count;i++){
        mean += dataset[i].score;
        list[i] = dataset[i].score;
        ptr[i] = &list[i];
    }
    mean = mean/count;
    select_sort(ptr,0,count-1);
    
    if(count % 2 == 1)
    {
        median = *(float*)ptr[count/2];
    }    
    else
    {
        median = (*(float*)ptr[count/2] + *(float*)ptr[(count/2) -1])/2;
    }
    for(int i = 0; i < count; i++)
    {
        stddev += pow(list[i] - mean,2);
    }
    stddev = pow(stddev/count,0.5);
    STATS s = {count, mean, stddev, median};
    return s;

}


int report_data(FILE *fp, RECORD *dataset, STATS stats) {

    fprintf(fp, "stats:value\n");
    fprintf(fp, "count:%d\n", stats.count);
    fprintf(fp, "mean:%.1f\n", stats.mean);
    fprintf(fp, "stddev:%.1f\n", stats.stddev);
    fprintf(fp, "median:%.1f\n\n", stats.median);
    fprintf(fp, "name:score,grade\n");
    
    void *ptr[stats.count];
    for(int i = 0; i < stats.count; i++)
    {
        ptr[i] = &dataset[i];
    }
    my_sort(ptr,0,stats.count-1,cmp2);
    for (int i = 0; i < stats.count; i++) {
        RECORD r = *(RECORD*)ptr[i];
        float f = r.score;
        GRADE g = grade(f);
        fprintf(fp, "%s:%.1f,%s\n",r.name, f, g.letter_grade);
    }
    return 0;
}
int cmp2(void *x, void *y) {
    float b = ((RECORD*) x)->score;
    float a = ((RECORD*) y)->score; 
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}