#include <stdio.h>
#include <stdlib.h>

/*
	Write a function that takes a base and an exponent and
	computes base^exponent. Assume that base and exp are
	greater than or equal to one. Don't worry if overflow
	occurs ... not your problem
*/
int myPower (int base, int exp){
	
	int power = base;
	
	for (int i = 1; i < exp; i++){
		
		power = power * base;
		
	}
	
	return power;
}

int main (){
	int base, exp;
	int power;
	
	while(1){
		printf ("Enter your base: ");
		scanf("%i", &base);
		printf ("Enter a second positive integer: ");
		scanf("%i", &exp);
		
		power = myPower(base, exp);
		printf ("power(%i,%i) = %i\n\n",base, exp,power);
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
