/* Name: Kanokpatai Kanato
 * ID: 5680412
 */


#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"
#include <string.h>


void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {


  for (int k = 0, i = 0, j = 0; k < (nL + nR) ;k++) {
    if (j >= nR || ( i < nL && (L[i].data < R[j].data))){
      output[k] = L[i++];
    }else{
      output[k] = R[j++];
    }
  }
}

void merge_sort(Entry *entries, int n) {

  if (n > 1){
    int leftN = n/2;
    int rightN = n - (leftN);
    Entry *left = entries;
    Entry *right = &(entries[leftN]);

    Entry *temp = (Entry*) calloc(n, sizeof(Entry));


    merge_sort(left, leftN);
    merge_sort(right, rightN);
    merge(temp, left, leftN, right, rightN);

    for ( int i =0; i< n ;++i){
      entries[i] = temp[i];
    }
    // entries = temp;
    free(temp);
//    temp = NULL;
  }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
  int count = 0;

  scanf("%d", &count);

  Entry *array = (Entry*) malloc(sizeof(Entry) * count);

  for (int i = 0; i < count; i++) {
    int d;
    array[i].name = (char *)malloc(sizeof(char)*MAX_NAME_LENGTH);
    scanf("%d %s", &d, array[i].name);
    array[i].data = d;
  }

  merge_sort(array, count);


  for (int i = 0; i< count; i++){

    // printf("  array[i].data = %d || array[i].name = %s\n",array[i].data, array[i].name );
    printf("%d %s\n", array[i].data, array[i].name);

  }
    // IMPLEMENT
}
