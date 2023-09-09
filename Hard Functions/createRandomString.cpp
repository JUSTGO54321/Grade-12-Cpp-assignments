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
	This function creates a random string having between
	minChars and maxChars characters all between minChar
	and maxChar inclusive.
*/
int  crs (char *s, int minChar, int maxChar, int minChars, int maxChars){
	// your code goes here
	int numChars = rb(minChars, maxChars);
	
	for (int i = 0; i < numChars; i++){
		
		char randomChar = rb(minChar, maxChar);
		
		s[i] = randomChar;
	}
}

int main(){
	char s[80];
	char min;
	char max;
	int minChars;
	int maxChars;
	
	srand (time (NULL));	// necessary in main to seed the random number generator
	

	while (1){		// here is an infinite loop in C ... 1 is always TRUE
		printf ("Enter the smallest character: ");
		scanf ("%c", &min);
		fflush(stdin);
		
		printf ("Enter the largest character: ");
		scanf ("%c", &max);
		fflush(stdin);
		
		printf ("Enter the minimum number of characters in your string: ");
		scanf ("%i", &minChars);
		fflush(stdin);
		
		printf ("Enter the maximum number of characters in a your string: ");
		scanf ("%i", &maxChars);
		fflush(stdin);

		crs (s,min,max,minChars,maxChars);
		printf ("Here is your random string: %s\n\n",s);
	
		system ("pause");	
		system ("cls");
	}
		
	return 0;
}
