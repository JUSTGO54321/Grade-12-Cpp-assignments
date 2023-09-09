#include <stdio.h>
#include <stdlib.h>

#define MAX_BYTES 4


/*
	Assume that op1 and op2 contains binary numbers stored
	as a string and that numBytes will be either 1, 2 or
	4. Your function computes the sum of op1 plus op2.
	Like a computer your function will ignore the overflow 
	bit (don't store it in the sum).
	
	Your function will return 1 if overflow occurred or 
	0 if no overflow took place.
*/
int addBinNumbers (char *op1, char *op2, char *sum, int numBytes){
	
	int size;
	int op1Size;
	int op2Size;
	int sumReversedSize;
	char carry = '0';
	char op1Reversed[numBytes * 8 + 1];
	char op2Reversed[numBytes * 8 + 1];
	char sumReversed[numBytes * 8 + 1];
	
	size = numBytes * 8;
	op2Size = size;
	op1Size = size;
	sumReversedSize = size;
	
	//printf ("Size of binary string = %i\nop1 = %s\nop2 = %s\n", size, op1, op2);
	
	for (int i = 0; i < size; i++){
		op1Reversed[i] = op1[op1Size - 1];
		op2Reversed[i] = op2[op2Size - 1];
		op1Size--;
		op2Size--;
	}
	
	op1Reversed[size] = 0;
	op2Reversed[size] = 0;
	
	//printf ("op1Reversed = %s\nop2Reversed = %s\n", op1Reversed, op2Reversed);
	
	for (int i = 0; i < size; i++){
		if (carry + op1Reversed[i] + op2Reversed[i] == 144){
			carry = '0';
			sumReversed[i] = '0';
		}
		else if (carry + op1Reversed[i] + op2Reversed[i] == 145){
			carry = '0';
			sumReversed[i] = '1';
		}
		else if (carry + op1Reversed[i] + op2Reversed[i] == 146){
			carry = '1';
			sumReversed[i] = '0';
		}
		else if (carry + op1Reversed[i] + op2Reversed[i] == 147){
			carry = '1';
			sumReversed[i] = '1';
		}
	}
	
	sumReversed[size] = 0;
	
	//printf ("sumReversed = %s\noverflow = %c\n", sumReversed, carry);
	
	for (int i = 0; i < size; i++){
		sum[i] = sumReversed[sumReversedSize - 1];
		sumReversedSize--;
	}
	
	sum[size] = 0;
	
	return carry - 48;
}

int main(){
	char op1[MAX_BYTES * 8 + 1];	// op stands for operand
	char op2[MAX_BYTES * 8 + 1];
	char sum[MAX_BYTES * 8 + 1];
	int numBytes;
	int overflow;	// 1 if overflow occurred else 0

	while (1){		// here is an infinite loop in C ... 1 is always TRUE
		printf ("How many bytes will your binary operands contain? ");
		scanf("%i", &numBytes);
		fflush(stdin);
		printf ("Enter your the first binary operand: ");
		gets (op1);
		printf ("Enter your the second binary operand: ");
		gets (op2);

		
		overflow = addBinNumbers (op1, op2, sum, numBytes);
		
		printf ("\n\n");
		printf ("Here is your sum.\n");
		printf ("%40s\n", op1);
		printf ("%40s\n", op2);
		printf ("%40s\n\n", sum);
		
		if (overflow) printf ("Overflow occurred during addition.\n");
		else printf ("No overflow occurred during additon.\n");
		
		system ("pause");	
		system ("cls");
	}
		
	return 0;
}
