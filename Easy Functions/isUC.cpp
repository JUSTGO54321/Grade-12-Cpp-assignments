#include <stdio.h>
#include <stdlib.h>

/*
	This function takes a character and returns 1 if it is
	an uppercase character otherwise it returns 0
*/
int isUC (char c){
	// currently this function will execute but it will return 
	// garbage to the calling function 
	int isUC;
	
	if (c >= 65 && c <= 90){
		isUC = 1;
	}
	else {
		isUC = 0;
	}
	return isUC;
}

int main (){
	char c;
	
	while(1){
		printf ("Enter an uppercase character: ");
		c = getchar ();
		
		if (isUC(c)){
			printf ("'%c' is an uppercase character.\n",c);
		}
		else{
			printf ("'%c' is not an uppercase character.\n",c);
		}
		
		fflush(stdin); // getchar is leaving the newline char in the stdin buffer
		// fflush flushes out this buffer so that getchar and gets will work next time
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
