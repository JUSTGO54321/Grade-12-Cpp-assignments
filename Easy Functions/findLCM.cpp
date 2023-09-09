#include <stdio.h>
#include <stdlib.h>

/*
	Write a function that finds the lowest common multiple of two
	positive integers. The calling function must pass two positive 
	integers. The lowest common multiple of 8 and 12 is 24.
*/
int findLCM (int a, int b){
	// currently this function will execute but it will return 
	// garbage to the calling function
	int max;
	int lcm = 2;
	
	max = a * b;
	
	while (1) {
		if (a == 1 || b == 1){
			if (a > b){
				return a;
			}
			else {
				return b;
			}
		}
        else {
        	if (lcm % a == 0 && lcm % b == 0) {
        	    return lcm;
        	}
        lcm++;
    	}
	}

}

int main (){
	int n1, n2;
	int lcm;
	
	while(1){
		printf ("Enter a positive integer: ");
		scanf("%i", &n1);
		printf ("Enter a second positive integer: ");
		scanf("%i", &n2);
		
		lcm = findLCM(n1, n2);
		printf ("lcm(%i,%i) = %i\n\n",n1, n2,lcm);
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
