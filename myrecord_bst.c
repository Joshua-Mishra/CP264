/*
 * your program signature
 */ 
 
 #include <stdio.h>
 #include <math.h>
 #include "bst.h"
 #include "myrecord_bst.h"
 
 /* Add a record data into the BSTDS and update its statistic fields 
  * using incremental/online algorithm.
  * @parame ds - pointer to the BSTDS.
  * @parama record - RECORD data to be added.
  */
 void add_record(BSTDS *ds, RECORD record) {
     BSTNODE *node = bst_search(ds->root, record.name);
     if (node == NULL) {
         bst_insert(&ds->root, record);
         ds->count++;

         double delta = record.score - ds->mean;
         ds->mean += delta / ds->count;
         
         double delta2 = record.score - ds->mean;
         ds->stddev = sqrt(((ds->count - 1) * pow(ds->stddev, 2) + delta * delta2) / ds->count);
     }
 }
 
 /* Delete a node from BSTDA with data.name matching with the given name
  * and stats fields using incremental/online algorithm.
  * @parame ds - pointer to the BSTDS.
  * @parama name - node data.name to be removed.
  */
 void remove_record(BSTDS *ds, char *name) {
     BSTNODE *node = bst_search(ds->root, name);
     if (node != NULL) {
         double delta = node->data.score - ds->mean;
         ds->count--;
         ds->mean -= delta / ds->count;
         double delta2 = node->data.score - ds->mean;
         ds->stddev = sqrt(((ds->count + 1) * pow(ds->stddev, 2) - delta * delta2) / ds->count);
         bst_delete(&ds->root, name);
     }
 }
 
 /* Clean the BSTDS and reset count, mean, stddev
  * @parame ds - pointer to the BSTDS.
  */
 void bstds_clean(BSTDS *ds) {
   bst_clean(&ds->root);
   ds->count = 0;
   ds->mean = 0;
   ds->stddev = 0;
 }