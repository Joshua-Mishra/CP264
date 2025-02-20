#include "mysort.h"
void swap(void **x, void **y) {
     void *temp = *y;
     *y = *x;
     *x = temp;
}

// a compare floating values pointed by void pointers. 
int cmp(void *x, void *y) {
   float a = *(float*)x;
   float b = *(float*)y; 
     if (a > b) return 1;
     else if (a < b) return -1;
     else return 0;
}  
/**
 * @param *a[] - array of void pointers.
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void select_sort(void *a[], int left, int right){
     int mindex;
     for(int i = left; i <= right; i++){
          mindex = i;
          for(int j = i + 1; j <= right; j++){
               if (cmp(a[mindex], a[j]) == 1){
                    mindex = j;
               }
          }

          if (mindex != i)
          {
               swap(&a[mindex],&a[i]);
          }
     }
}

/**
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void quick_sort(void *a[], int left, int right){
     if(left < right){
          void *pivot = a[right];
          int temp = left - 1;
          for (int i = left; i <= right; i++)
          {
               
               if (cmp(pivot,a[i]) == 1)
               {
                    temp++;
                    swap( &a[i], &a[temp]);
               }
          }
          swap(&a[temp + 1], &a[right]);

          quick_sort(a, left, temp);
          quick_sort(a, temp + 2, right);
     }
}
/**
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) ){
     int mindex;
     for(int i = left; i <= right; i++){
          mindex = i;
          for(int j = i + 1; j <= right; j++){
               if ((*cmp)(a[mindex], a[j]) >0){
                    mindex = j;
               }
          }

          if (mindex != i)
          {
               swap(&a[mindex],&a[i]);
          }
     }
}