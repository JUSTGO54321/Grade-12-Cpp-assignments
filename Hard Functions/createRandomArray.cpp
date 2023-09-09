#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
	This function returns takes two parameters and
	returns a randomly generated integer between min and max.
*/
int rb (int min, int max){
	return rand() % (max - min + 1) + min;
}

/*
	This function randomly creates an array containing
	n integers between min and max inclusive
*/
void crArray (int *A, int n, int min, int max){
	
	int randomNum;
	
	for (int i = 0; i < n; i++){
		randomNum = rb(min, max);
		A[i] = randomNum;
	}
}

/*
	This function outputs an array of integers right 
	aligned in 10 spaces with numsPerLine integers per
	line. For example if A = {2, -3, 8, 11, 7, 4, 2, 9, -18}
	then n = 9 and numsPerLine = 4 then the output would be

        2        -3         8        11   
        7         4         2         9
      -18
*/
void outputArrayNumsPerLine (int *A, int n, int numsPerLine){
	
	for (int i = 1; i <= n; i++){
		
		printf ("%10i", A[i]);
		
		if (i % numsPerLine == 0){
			
			printf ("\n");
			
		}
	}
	printf ("\n");
}


int main(){
	int A[200];
	int nA;
	int min, max;
	int numsPerLine;	
	srand (time (NULL));	// necessary in main to seed the random number generator
	

	while (1){
		printf ("How many integers would you like in your random array? ");
		scanf ("%i", &nA);
		
		printf ("Enter the minimum integer in your array: ");
		scanf ("%i", &min);

		printf ("Enter the maximum integer in your array: ");
		scanf ("%i", &max);
		
		crArray(A, nA, min, max);
		
		printf ("\n\nNow lets output your array ...\n");
		printf ("How many integers would you like per line? ");
		scanf ("%i", &numsPerLine);
		outputArrayNumsPerLine (A, nA, numsPerLine);
		system ("pause");	
		system ("cls");
	}
		
	return 0;
}
