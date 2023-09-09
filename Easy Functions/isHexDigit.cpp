#include <stdio.h>
#include <stdlib.h>

/*
	This function takes a character and returns 1 if it is
	a HEX digit ... a-f and A-F are acceptable. Return 0 if
	the character is not a HEX digit
*/
int isHexDigit (char c){
	// currently this function will execute but it will return 
	// garbage to the calling function 
	
	if (c >= '0' && c <= '9' || c >= 'A' && c <= 'F' || c >= 'a' && c <= 'f'){
		return 1;
	}
	else {
		return 0;
	}
}

int main (){
	char c;
	
	while(1){
		printf ("Enter a HEX digit: ");
		c = getchar ();
		
		if (isHexDigit(c)){
			printf ("%c is a hex digit.\n",c);
		}
		else{
			printf ("%c is not a hex digit.\n",c);
		}
		
		fflush(stdin); // getchar is leaving the newline char in the stdin buffer
		// fflush flushes out this buffer so that getchar and gets will work next time
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
