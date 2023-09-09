#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRACTIONS 100	// without structures this will be NO FUN 
#define MAX_EQUATIONS 100
#define MIN_NUMERATOR -99
#define MAX_NUMERATOR 99
#define MIN_DENOMINATOR -99
#define MAX_DENOMINATOR 99

int gcd (int top, int bot){
	
	if (top < 0){
		top = -top;
	}
	if (bot < 0){
		bot = -bot;
	}
	
	while (top != bot){
		if (top > bot){
			top = top - bot;
		}
		else{
			bot = bot - top;
		}
	}
	return top;
}

void simplifyFraction (int *num, int *den){
	
	int gcdFraction;
	
	if(*num != 0){
		gcdFraction = gcd(*num, *den);
		
		*num = *num / gcdFraction;
		*den = *den / gcdFraction;
			
		if (*den < 0){
			*num = -*num;
			*den = -*den;
		}
	}
}

void eqnInput (int *num1, int *den1, int *num2, int *den2, int isDiv){
	
	do{
		printf ("Enter the numerator for fraction #1: ");
		scanf ("%i", num1);
		
		if (*num1 > MAX_NUMERATOR || *num1 < MIN_NUMERATOR){
			printf ("INVALID INPUT\n");
		}
	}
	while (*num1 > MAX_NUMERATOR || *num1 < MIN_NUMERATOR);
	

	do{
		printf ("Enter the denominator for fraction #1: ");
		scanf ("%i", den1);
		
		if (*den1 > MAX_DENOMINATOR || *den1 < MIN_DENOMINATOR || *den1 == 0){
			printf ("INVALID INPUT\n");
		}
	}
	while (*den1 > MAX_DENOMINATOR || *den1 < MIN_DENOMINATOR || *den1 == 0);
	
	if (isDiv){
		do{
			printf ("Enter the numerator for fraction #2: ");
			scanf ("%i", num2);
		
			if (*num2 > MAX_NUMERATOR || *num2 < MIN_NUMERATOR || *num2 == 0){
				printf ("INVALID INPUT\n");
			}
		}
		while (*num2 > MAX_NUMERATOR || *num2 < MIN_NUMERATOR || *num2 == 0);	
	}
	else{
		do{
			printf ("Enter the numerator for fraction #2: ");
			scanf ("%i", num2);
		
			if (*num2 > MAX_NUMERATOR || *num2 < MIN_NUMERATOR){
				printf ("INVALID INPUT\n");
			}
		}
		while (*num2 > MAX_NUMERATOR || *num2 < MIN_NUMERATOR);	
	}

	do{
		printf ("Enter the denominator for fraction #2: ");
		scanf ("%i", den2);
		
		if (*den2 > MAX_DENOMINATOR || *den2 < MIN_DENOMINATOR || *den2 == 0){
			printf ("INVALID INPUT\n");
		}
	}
	while (*den2 > MAX_DENOMINATOR || *den2 < MIN_DENOMINATOR || *den2 == 0);
}

void printAns (int numAns, int denAns){
	
	if (numAns == denAns){
		printf ("1");
	}
	else if (numAns == -denAns){
		printf ("-1");
	}
	else if (denAns == 1 || numAns == 0){
		printf ("%i", numAns);
	}
	else{
		printf ("%i/%i", numAns, denAns);
	}
	printf ("\n");
}

void randFractions (int *num, int *den){
	
	*num = rand() % (MAX_NUMERATOR - MIN_NUMERATOR + 1) + MIN_NUMERATOR;
	do{
		*den = rand() % (MAX_DENOMINATOR - MIN_DENOMINATOR + 1) + MIN_DENOMINATOR;
	}
	while (*den == 0);

	
	printf ("\nHERE IS YOUR RANDOM FRACTION...\n%i/%i\n\n", *num, *den);
}

void getFractions(int *num, int *den){
	
	printf("\nGETTING USER INPUTED FRACTION...\n");
	
	do{
		printf("Please enter the numerator for the fraction: ");
		scanf("%i", num);
		
		if(*num > MAX_NUMERATOR || *num < MIN_NUMERATOR){
			printf("Invalid input...\n");
		}
	}
	while(*num > MAX_NUMERATOR || *num < MIN_NUMERATOR);
		
	do{
		printf("Please enter the denominator for the fraction: ");
    	scanf("%i", den);
    	
    	if(*den > MAX_DENOMINATOR || *den < MIN_DENOMINATOR || *den == 0){
      		printf("Invalid input...\n");
   		}
  	}
	while(*den > MAX_DENOMINATOR || *den < MIN_DENOMINATOR || *den == 0);
	printf ("USER FRACTION HAS BEEN STORED...\n\n");
}

void printFractions(int *num, int *den, int counter){
	
 	int reNum[MAX_FRACTIONS];
  	int reDen[MAX_FRACTIONS];
  	
	if (counter == 0){
		printf ("\nNO STORED FRACTIONS...\n\n");
	}
	else{
	
		printf("\nDISPLAYING USER ENTERED FRACTION...\n");
	
	  	for(int j = 0; j < counter; j++){
	    	reNum[j] = num[j];
	    	reDen[j] = den[j];
	    	if (reNum[j] != 0){
	    		simplifyFraction(&reNum[j], &reDen[j]);
	    	}
	  	}
		
		for(int i = 0; i < counter; i++){
	
			printf ("Fraction #%i: ", i + 1);
			printf ("%i/%i = ", num[i], den[i]);
			
			printAns(reNum[i], reDen[i]);
		}
		printf ("\n");
	}
}

void addFractions (int *num1, int *den1, int *num2, int *den2, int *numAns, int *denAns, char *op){
	
	printf ("\nYou have chosen to Add Fractions\n\n");
	
	eqnInput(num1, den1, num2, den2, 0);
	
	*numAns = *num1 * *den2 + *num2 * *den1;
	*denAns = *den1 * *den2;
	
	simplifyFraction (numAns, denAns);
	
	printf ("Here are the results:\n%i/%i + %i/%i = ", *num1, *den1, *num2, *den2);
	printAns(*numAns, *denAns);
	printf ("\n");
}

void subFractions (int *num1, int *den1, int *num2, int *den2, int *numAns, int *denAns, char *op){
	
	printf ("\nYou have chosen to Subtract Fractions\n\n");
	
	eqnInput(num1, den1, num2, den2, 0);
	
	*numAns = *num1 * *den2 - *num2 * *den1;
	*denAns = *den1 * *den2;
	
	simplifyFraction (numAns, denAns);
	
	printf ("Here are the results:\n%i/%i - %i/%i = ", *num1, *den1, *num2, *den2);
	printAns(*numAns, *denAns);
	printf ("\n");
}

void divFractions (int *num1, int *den1, int *num2, int *den2, int *numAns, int *denAns, char *op){
	
	printf ("\nYou have chosen to Divide Fractions\n\n");
	
	eqnInput(num1, den1, num2, den2, 1);
	
	*numAns = *num1 * *den2;
	*denAns = *den1 * *num2;
	
	simplifyFraction (numAns, denAns);
	
	printf ("Here are the results:\n%i/%i / %i/%i = ", *num1, *den1, *num2, *den2);
	printAns(*numAns, *denAns);
	printf ("\n");
}

void multFractions (int *num1, int *den1, int *num2, int *den2, int *numAns, int *denAns, char *op){
	
	printf ("\nYou have chosen to Multiply Fractions\n\n");
	
	eqnInput(num1, den1, num2, den2, 0);
	
	*numAns = *num1 * *num2;
	*denAns = *den1 * *den2;
	
	simplifyFraction (numAns, denAns);
	
	printf ("Here are the results:\n%i/%i * %i/%i = ", *num1, *den1, *num2, *den2);	
	printAns(*numAns, *denAns);
	printf ("\n");
}

void printAllEquations (int *num1, int *den1, int *num2, int *den2, char *op, int *numAns, int *denAns, int counter){
	
	if (counter == 0){
		printf ("\nNO STORED EQUATIONS...\n\n");
	}
	else{
		printf ("\nDISPLAYING ALL EQUATIONS...\n");
		for (int i = 0; i < counter; i++){			
			printf ("Equation #%i: %i/%i %c %i/%i = ", i + 1, num1[i], den1[i], op[i], num2[i], den2[i]);
			
			printAns(numAns[i], denAns[i]);
		}
		printf ("\n");
	}
}

int main (){
	
	int menu = 1;
	int storeFracCounter = 0;
	int storeFracNum[MAX_FRACTIONS];
	int storeFracDen[MAX_FRACTIONS];
	int eqnCounter = 0;
	int eqnNum1[MAX_FRACTIONS];
	int eqnDen1[MAX_FRACTIONS];
	char eqnOp[MAX_FRACTIONS];
	int eqnNum2[MAX_FRACTIONS];
	int eqnDen2[MAX_FRACTIONS];
	int eqnNumAns[MAX_FRACTIONS];
	int eqnDenAns[MAX_FRACTIONS];	
	
	srand(time(NULL));
	
	while (1){
		
		if (eqnCounter == 100 && storeFracCounter == 100){
			printf ("--------------------------\nYou have reached the max amount of fractions stored and equations stored\n");
			printf ("\nMENU\n3. Display Fractions\n8. Display Equations\n9. Quit\n");
			
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
						
			switch (menu){
				
				case 3:
					printFractions(storeFracNum, storeFracDen, storeFracCounter);
					break;
					
				case 8:
					printAllEquations(eqnNum1, eqnDen1, eqnNum2, eqnDen2, eqnOp, eqnNumAns, eqnDenAns, eqnCounter);
					break;
					
				case 9:
					exit(0);
					break;
				
				default:
					printf ("INVALID INPUT\n\n");
			}
		}
		else if (eqnCounter == 100){
			printf ("--------------------------\nYou have reached the max amount of equations stored\n");
			printf ("\nMENU\n1. Create Random Fractions\n2. Store Fractions\n3. Display Fractions\n8. Display Equations\n9. Quit\n");
			
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
			switch (menu){
				
				case 1:
					randFractions(&storeFracNum[storeFracCounter], &storeFracDen[storeFracCounter]);
					storeFracCounter++;
					break;
					
				case 2:
					getFractions(&storeFracNum[storeFracCounter], &storeFracDen[storeFracCounter]);
					storeFracCounter++;
					break;
					
				case 3: 
					printFractions(storeFracNum, storeFracDen, storeFracCounter);
					break;
					
				case 8: 
					printAllEquations(eqnNum1, eqnDen1, eqnNum2, eqnDen2, eqnOp, eqnNumAns, eqnDenAns, eqnCounter);
					break;
					
				case 9:
					exit(0);
					break;
				
				default:
					printf ("INVALID INPUT\n\n");
			}
		}
		else if (storeFracCounter == 100){
			printf ("--------------------------\nYou have reached the max amount of fractions stored\n");
			printf ("\nMENU\n3. Display Fractions\n4. Add Fractions\n5. Subtract Fractions\n6. Divide Fractions\n7. Multiply Fractions\n8. Display Equations\n9. Quit\n");
			
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
			switch (menu){
				case 3: 
					printFractions(storeFracNum, storeFracDen, storeFracCounter);
					break;
					
				case 4:
					eqnOp[eqnCounter] = '+';
					addFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);
					eqnCounter++;
					break;
					
				case 5:
					eqnOp[eqnCounter] = '-';					
					subFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);
					eqnCounter++;
					break;
					
				case 6:
					eqnOp[eqnCounter] = '/';
					divFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);					
					eqnCounter++;
					break;
					
				case 7:
					eqnOp[eqnCounter] = '*';
					multFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);
					eqnCounter++;
					break;
					
				case 8: 
					printAllEquations(eqnNum1, eqnDen1, eqnNum2, eqnDen2, eqnOp, eqnNumAns, eqnDenAns, eqnCounter);
					break;
					
				case 9:
					exit(0);
					break;
					
				default:
					printf ("INVALID INPUT\n\n");
			}
		}
		else{
			
			printf ("--------------------------\nMENU\n1. Create Random Fractions\n2. Store Fractions\n3. Display Fractions\n4. Add Fractions\n");
			printf ("5. Subtract Fractions\n6. Divide Fractions\n7. Multiply Fractions\n8. Display Equations\n9. Quit\n");
		
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
			switch (menu){
				
				case 1:
					randFractions(&storeFracNum[storeFracCounter], &storeFracDen[storeFracCounter]);
					storeFracCounter++;
					break;
					
				case 2:
					getFractions(&storeFracNum[storeFracCounter], &storeFracDen[storeFracCounter]);
					storeFracCounter++;
					break;
					
				case 3: 
					printFractions(storeFracNum, storeFracDen, storeFracCounter);
					break;
					
				case 4:
					eqnOp[eqnCounter] = '+';
					addFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);
					eqnCounter++;
					break;
					
				case 5:
					eqnOp[eqnCounter] = '-';					
					subFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);
					eqnCounter++;
					break;
					
				case 6:
					eqnOp[eqnCounter] = '/';
					divFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);					
					eqnCounter++;
					break;
					
				case 7:
					eqnOp[eqnCounter] = '*';
					multFractions(&eqnNum1[eqnCounter], &eqnDen1[eqnCounter], &eqnNum2[eqnCounter], &eqnDen2[eqnCounter], &eqnNumAns[eqnCounter], &eqnDenAns[eqnCounter], &eqnOp[eqnCounter]);
					eqnCounter++;
					break;
					
				case 8: 
					printAllEquations(eqnNum1, eqnDen1, eqnNum2, eqnDen2, eqnOp, eqnNumAns, eqnDenAns, eqnCounter);
					break;
					
				case 9:
					exit(0);
					break;
					
				default:
					printf ("INVALID INPUT\n\n");
			}
		}
	}
}
