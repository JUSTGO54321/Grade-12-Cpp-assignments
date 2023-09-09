#include <stdio.h>
#include <stdlib.h>

#define MAX_BYTES 4

/*
	Assume that bs contains binary number stored
	as a string. numBytes will be either 1, 2 or
	4. tc will contain the twos complement of bs at
	the conclusion of the function call.
*/
void  findTwosComplement (char *bs, char *tc, int numBytes){
	
	int size = numBytes * 8;
	int done = 0;

	
	for (int i = size - 1; i >= 0; i--){
		if (bs[i] == '0'){
			tc[i] = '1';
		}
		else {
			tc[i] = '0';
		}
	}
	
	for (int i = size - 1; i >= 0; i--){
		if (!done){
			if (tc[i] == '0'){
				done = 1;
				tc[i] = '1';
			}
			else {
				tc[i] = '0';
			}
		}
	}
	
	tc[size] = 0;
	
}


int main(){
	char binString[MAX_BYTES * 8 + 1];
	char twosComplement[MAX_BYTES * 8 + 1];
	// the extra byte is for the Null char
	int numBytes;

	while (1){		// here is an infinite loop in C ... 1 is always TRUE
		printf ("How many bytes will your binary string contain? ");
		scanf("%i", &numBytes);
		fflush (stdin);
		printf ("Enter your binary string: ");
		gets (binString);
		
		findTwosComplement (binString, twosComplement, numBytes);
		
		printf ("The 2's complement of %s is %s\n\n", binString, twosComplement);
		
		system ("pause");	
		system ("cls");
	}
		
	return 0;
}
