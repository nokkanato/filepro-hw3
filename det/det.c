#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dealloc(int ***a, int n);
double compute_det(int **a, int n) {
  double result = 0;

  if (n==1){

    return a[0][0];

  }
   if (n==2){
    return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

  }
   if (n==3){
    // printf("in\n" );
    // printf("%d\n", a[0][0] *a[1][1] );
    return (
            (a[0][0] * a[1][1] * a[2][2]) +
            (a[0][1] * a[1][2] * a[2][0]) +
            (a[0][2] * a[1][0] * a[2][1])
            )      -
            (
            (a[0][2] * a[1][1] * a[2][0])-
            (a[0][1] * a[1][0] * a[2][2])-
            (a[0][0] * a[1][2] * a[2][1])
            )  ;

  }
  else{
    printf("--------\n" );

    int **temp;
    double result = 0;

    for (int x = 0; x < n; x++) {
        temp = malloc(sizeof(double *) * (n - 1));
        for (int i = 0; i < n - 1; i++)
            temp[i] = malloc(sizeof(double) * (n - 1));

        for (int i = 1; i < n; i++) {
            for (int j = 0, l = 0; j < n; j++) {

                if (j != x){
                    temp[i - 1][l++] = a[i][j];
                }
            }
        }

        if (x%2 == 0){
          result += (a[0][x] * compute_det(temp, n-1));
        }else {
          result -= (a[0][x] * compute_det(temp, n-1));

        }
        dealloc(&temp, n-1);

        // free(*a);
        return result;
        // dealloc(&temp, n - 1);
    }

  }

}

void dealloc(int ***a, int n ){
  for (int i=0; i<n; i++){
    free((*a)[i]);
  }
  free(*a);
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  int size = 0;
  scanf("%d", &size);

  int **array = (int**)malloc(sizeof(int**)*size);

  for (int i= 0; i < size; i++) {
    array[i] = (int*)malloc(sizeof(int)*size);
    for (int j=0; j< size; j++){
      int temp ;
      scanf("%d", &temp );
      array[i][j] = temp;
    }

  }

  printf("%f\n", compute_det(array, size));


  for (int i = 0; i<size; i++){
    for (int j =0; j< size; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n" );
  }


}
