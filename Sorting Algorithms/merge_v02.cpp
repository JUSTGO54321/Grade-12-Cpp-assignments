#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 100

void outputArray (int *A, int n){
  for (int i = 0; i < n; i++)
    printf ("%i ", A[i]);
    
}  

/*
  Merge two sorted subarrays, A[lo..mid] and A[mid+1..hi] 
  to create one sorted subarray A[lo..hi]
  
  Can you understand why this algorithm is clearly O(n)
  time complexity?
  
*/
void merge (int *A, int lo, int mid, int hi){
  int B[MAX_NUMS];
  int i = lo;
  int j = mid + 1;
  int k = lo;
  
  while (i <= mid && j <= hi){
    if (A[i] < A[j]){
      B[k] = A[i];
      i++;
    }  
    else{
      B[k] = A[j];
      j++;
    }  
    k++;    // always increment k
  }  
  
  // one subarray has be completely copied to B
  // just need to copy the rest of the other subarray to B
  // only one of the loops below will run
  while (i <= mid){
    B[k] = A[i];
    i++;
    k++;
  }  
  
  while (j <= hi){
    B[k] = A[j];
    j++;
    k++;
  } 
  
  // yikes ... almost forgot to copy B[lo..hi] to A[lo..hi]
  for (i = lo; i <= hi; i++){
    A[i] = B[i];
  }   
  
}  

int main(){
  int A[MAX_NUMS] = {15, 18, 18, 21, 49, 59, 62,
                    3, 9, 11, 17, 19, 29};
  int nA = 13;
  
  printf ("Before merging ...\n");
  outputArray(A, nA);
  printf ("\n\n");
  merge (A, 0, 6, nA-1);
  printf ("After merging ...\n");
  outputArray(A, nA);
  printf ("\n\n");

  system ("pause");
}  
