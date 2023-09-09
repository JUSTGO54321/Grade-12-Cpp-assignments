#include <stdio.h>
#include <stdlib.h>

/*
	This function takes a hex digit and returns the corresponding
	decimal number. This function ASSUMES that the calling function
	will pass in a valid hex digit.
	
	The hex digit use upper or lowercase letters.
*/
int decDigitToHex (int dec){
	// currently this function will execute but it will return 
	// garbage to the calling function 
	char hex;
	
	if (dec >= 10 && dec <= 15){
		hex = dec + '7';
	}
	else if (dec >= 0 && dec <= 9){
		hex = dec + 48;
	}
	return hex;
}

int main (){
	int dec;
	
	while(1){
		printf ("Enter a dec digit: ");
		scanf ("%i", &dec);
		
		printf ("%i = %c\n\n", dec, decDigitToHex(dec));
		
		fflush(stdin); // getchar is leaving the newline char in the stdin buffer
		// fflush flushes out this buffer so that getchar and gets will work next time
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
