#include <stdio.h>
#include <stdlib.h>

/*
	This function takes a hex digit and returns the corresponding
	decimal number. This function ASSUMES that the calling function
	will pass in a valid hex digit.
	
	The hex digit can use upper or lowercase letters.
*/
int hexDigitToDec (char hex){
	// currently this function will execute but it will return 
	// garbage to the calling function 
	int dec = 0;
	
	if (hex >= 'A' && hex <= 'F'){
		
		dec = hex - 'A' + 10;
		
	}
	else if (hex >= 'a' && hex <= 'f'){
		
		dec = hex - 'a' + 10;
		
	}
	else if (hex >= '1' && hex <= '9'){
		
		dec = hex - '0';
		
	}
	return dec;
}

int main (){
	char hex;
	
	while(1){
		printf ("Enter a hex digit: ");
		hex = getchar ();
		
		printf ("%c = %i\n\n", hex, hexDigitToDec(hex));
		
		fflush(stdin); // getchar is leaving the newline char in the stdin buffer
		// fflush flushes out this buffer so that getchar and gets will work next time
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
