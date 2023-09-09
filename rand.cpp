#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100        
/*
	This function returns takes two parameters and
	returns a randomly generated integer between min and max.
*/
int rb (int min, int max){
	return rand() % (max - min + 1) + min;
}
                                   
int main(){
	
	int numRand;
	
	printf ("How many random numbers do you want: ");
	scanf ("%i", &numRand);
	
	srand (time (NULL));	// necessary in main to seed the random number generator
	
	for (int i = 0; i < numRand; i++){
		printf ("%i\n", rb(MIN, MAX));
	}
	
}  
