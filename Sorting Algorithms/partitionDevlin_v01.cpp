#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 100

void outputArray (int *A, int n){
  for (int i = 0; i < n; i++)
    printf ("%i ", A[i]);
    
}  

/*
  Use A[lo] as the pivot to partition A[lo..hi]
  Move A[lo] (the pivot) to a location in the array
  such that all elements to the left of this location
  are less than the pivot and all elements to the right
  are greater than or equal to the pivot.
  
  At McDs ... I wrote this code in 3 minutes ... very easy
  if you just think before you write.
*/

void partition (int *A, int lo, int hi){
  int pivot = A[lo];
  
  while (lo < hi){
    while (A[hi] >= pivot && lo < hi) hi--;
    if (lo < hi){
      A[lo] = A[hi];
      lo++;
    }
    
    while (A[lo] < pivot && lo < hi) lo++;
    if (lo < hi){
      A[hi] = A[lo];
      hi--;
    }    
  } 
  A[lo] = pivot;
}  

int main(){
  int A[MAX_NUMS] = {68, 21, 78, 25, 43, 87, 3,
                    37, 19, 57, 22, 25, 71};
  int nA = 13;
  
  printf ("Before partitioning ...\n");
  outputArray(A, nA);
  printf ("\n\n");
  partition (A, 0, nA-1);
  printf ("After partitioning ...\n");
  outputArray(A, nA);
  printf ("\n\n");

  system ("pause");
}  
