#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 1000


/*
	This function takes an array A containing n integers
	and deletes all integer less than x. It returns the
	new number of elements in the array.
*/
int deleteLessThan (int *A, int n, int x){
	
	int j = 0;
	
	for (int i = 0; i < n; i++){
		if(A[i] >= x){
			A[j] = A[i];
			j++;
		}
	}
	return j;
}

int outputArray (int *A, int n){
	for (int i = 0; i < n; i++){
		printf ("A[%i] = %i\n", i,A[i]);
	}
}

int main (){
	int myArray[MAX_NUMS] = {-3, -9, -18, -4, -1, -32, -78};
	int numElements = 7;
	int delNum = -45;
	
	printf ("Here is your array before deletion ...\n");
	outputArray(myArray, numElements);
	
	numElements = deleteLessThan (myArray, numElements, delNum);
	
	printf ("\n\n");
	printf ("Here is the array after deleting all elements ");
	printf ("that are less than %i ...\n", delNum);
	outputArray(myArray, numElements);
}
