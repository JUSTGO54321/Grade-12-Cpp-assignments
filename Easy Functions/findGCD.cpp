#include <stdio.h>
#include <stdlib.h>

/*
	Write a function that finds the greatest common divisor of two
	positive integers. The calling function must pass two positive 
	integers. The gcd of 8 and 12 is 4.
	
	You are NOT allowed to use Euclid's algorithm! Don't worry about
	it if you do not know this algorithm.
*/
int findGCD (int a, int b){
	// currently this function will execute but it will return 
	// garbage to the calling function 
	
	int mod = 2;
	
	if (a == 1 || b == 1){
		return 1;
	}
	
	while (1){
		if (a % mod == 0 && b % mod == 0){
			if (a > b && mod == b){
				return b;
			}
			else if (b > a && mod == a){
				return a;
			}
			else{
				return mod;
			}
		}
		else{
			mod++;
		}	
	}
}

int main (){
	int n1, n2;
	int gcd;
	
	while(1){
		printf ("Enter a positive integer: ");
		scanf("%i", &n1);
		printf ("Enter a second positive integer: ");
		scanf("%i", &n2);
		
		gcd = findGCD(n1, n2);
		printf ("gcd(%i,%i) = %i\n\n",n1, n2,gcd);
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
