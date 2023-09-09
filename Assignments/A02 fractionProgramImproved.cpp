#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRACTIONS 100	// without structures this will be NO FUN 
#define MAX_EQUATIONS 100
#define MIN_NUMERATOR -99
#define MAX_NUMERATOR 99
#define MIN_DENOMINATOR -99
#define MAX_DENOMINATOR 99
#define MAX_INPUT_LENGTH 256

typedef struct{
	int n;
	int d;
} fractionType;

typedef struct{
	fractionType op1, op2;
	char operation;
	fractionType ans;
} equationType;

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

void simplifyFraction (int *n, int *d){
	
	int gcdFraction;
	
	if(*n != 0){
		gcdFraction = gcd(*n, *d);
		
		*n = *n / gcdFraction;
		*d = *d / gcdFraction;
			
		if (*d < 0){
			*n = -(*n);
			*d = -(*d);
		}
	}
}

void randFractions(fractionType *fraction){
	
	fraction->n = rand() % (MAX_NUMERATOR - MIN_NUMERATOR + 1) + MIN_NUMERATOR;
	do{
		fraction->d = rand() % (MAX_DENOMINATOR - MIN_DENOMINATOR + 1) + MIN_DENOMINATOR;
	}
	while (fraction->d == 0);

	printf ("\nYOUR RANDOM FRACTION HAS BEEN STORED...\n\n");
}

void getFractions (fractionType *fraction){
	
	int invalid = 0;
	int i = 0;
	int j = 0;
	int minusCounter = 0;
	int slashCounter = 0;
	int digitCounter = 0;
	int numDigits = 0;
	int len;
	char parse[MAX_INPUT_LENGTH];
	char temp[10];
	
	printf("\nGETTING USER INPUTED FRACTIONS...\n");
	
	do{
		
		fflush (stdin);
	    printf("Please enter a fraction: ");
	    fgets (parse, MAX_INPUT_LENGTH, stdin);
	    
	    len = strlen(parse);
	    if (len > 0 && parse[len - 1] == '\n'){
	    	parse[len - 1] = 0;
		}
		
		i = 0;
		minusCounter = 0;
		slashCounter = 0;
		digitCounter = 0;
		
		while (parse[i]){
	    	
	    	if (parse[i] == ' '){
	    		i++;
			}
	    	else if (parse[i] >= '0' && parse[i] <= '9'){
	    		digitCounter++;
	    		i++;	    		
			}
			else if (parse[i] == '-'){
				minusCounter++;
				i++;
			}
			else if (parse[i] == '/'){
				slashCounter++;
				i++;
			}
			else{
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
		}
		
		if (digitCounter > 4 || minusCounter > 2 || slashCounter != 1){
			printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
		}
		
		i = 0;
		j = 0;
		numDigits = 0;
		
		while (parse[i] == ' '){
			i++;
		}
		
		if (parse[i] != '-' && parse[i] < '1' || parse[i] != '-' && parse[i] > '9'){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto notGood;
		}
		
		while (parse[i] != '/'){
			
			if (numDigits == 0 && parse[i] == '-'){
				if(parse[i + 1] == '0'){
					printf ("INVALID INPUT\n");
					invalid = 1;
					goto notGood;
				}
				else{
					temp[j] = parse[i];
					i++;
					j++;
				}
			}
			
			if (parse[i] < '0' || parse[i] > '9'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
			
			if (parse[i] == '0' && parse[i + 1] != '/'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
			
			temp[j] = parse[i];
			i++;
			j++;
			numDigits++;
			
			if(numDigits > 2){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
		}
		
		temp[j] = 0;
		fraction->n = atoi(temp);
		numDigits = 0;
		
		i++;
		j = 0;
		
		if (parse[i] != '-' && parse[i] < '0' || parse[i] != '-' && parse[i] > '9'){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto notGood;
		}
		
		while (parse[i] != ' ' && parse[i] != 0){
			
			if (numDigits == 0 && parse[i] == '-'){
				temp[j] = parse [i];
				i++;
				j++;
			}
			
			if (parse[i] < '0' || parse[i] > '9'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
			
			if (parse[i] == '0' && parse[i + 1] != ' ' || parse[i] == '0' && parse[i + 1] != 0){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
			
			temp[j] = parse[i];
			i++;
			j++;
			numDigits++;
			
			if(numDigits > 2){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto notGood;
			}
		}
		
		temp[j] = 0;
		fraction->d = atoi(temp);
		
		invalid = 0;
		printf ("YOUR FRACTION HAS BEEN STORED...\n\n");
		notGood:;
		
	} while (invalid == 1);
}

void displayFractions(fractionType *fraction, int counter){
	
	int reNum[MAX_FRACTIONS];
	int reDen[MAX_FRACTIONS];
	
	if (counter == 0){
		printf ("\nNO STORED EQUATIONS...\n\n");
	}
	else{
		printf ("\nDISPLAYING ALL FRACTIONS...\n");
		
		for (int j = 0; j < counter; j++){
	    	reNum[j] = fraction[j].n;
	    	reDen[j] = fraction[j].d;
	    	
	    	if (reNum[j] != 0){
	    		simplifyFraction(&reNum[j], &reDen[j]);
	    	}
	  	}
	  	
		for (int i = 0; i < counter; i++){
	
			printf ("Fraction #%i: ", i + 1);
			printf ("%i/%i = ", fraction[i].n, fraction[i].d);
			
			if (reNum[i] == reDen[i]){
				printf ("1");
			}
			else if (reNum[i] == -reDen[i]){
				printf ("-1");
			}
			else if (reDen[i] == 1 || reNum[i] == 0){
				printf ("%i", reNum[i]);
			}
			else{
				printf ("%i/%i", reNum[i], reDen[i]);
			}
			printf ("\n");
		}
		printf ("\n");
	}
}

void getExpression(equationType *exp){

	int invalid = 0;
	int i = 0;
	int j = 0;
	int minusCounter = 0;
	int plusCounter = 0;
	int slashCounter = 0;
	int multCounter = 0;
	int digitCounter = 0;
	int numDigits = 0;
	int len;
	char parse[MAX_INPUT_LENGTH];
	char temp[10];
	
	printf("\nGETTING USER INPUTED EXPRESSION...\n");
	
	do{
		
		fflush (stdin);
	    printf("Please enter a expression: ");
	    fgets (parse, MAX_INPUT_LENGTH, stdin);
	    
	    len = strlen(parse);
	    if (len > 0 && parse[len - 1] == '\n'){
	    	parse[len - 1] = 0;
		}
		
		i = 0;
		minusCounter = 0;
		plusCounter = 0;
		slashCounter = 0;
		multCounter = 0;
		digitCounter = 0;
		
	    while (parse[i]){
	    	
	    	if (parse[i] == ' '){
	    		i++;
			}
	    	else if (parse[i] >= '0' && parse[i] <= '9'){
	    		digitCounter++;
	    		i++;	    		
			}
			else if (parse[i] == '-'){
				minusCounter++;
				i++;
			}
			else if (parse[i] == '+'){
				plusCounter++;
				i++;
			}
			else if (parse[i] == '/'){
				slashCounter++;
				i++;
			}
			else if (parse[i] == '*'){
				multCounter++;
				i++;
			}
			else{
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
		}
		//printf ("Digits = %i\n'-' = %i\n'+' = %i\n'/' = %i\n'*' = %i\n", digitCounter, minusCounter, plusCounter, slashCounter, multCounter);
		if (digitCounter > 8 || minusCounter > 5 || plusCounter > 1 || slashCounter > 3 || slashCounter < 2 || multCounter > 1 || minusCounter == 5 && plusCounter == 1 || minusCounter == 5 && slashCounter == 3 || minusCounter == 5 && multCounter == 1 || plusCounter == 1 && slashCounter == 3 || plusCounter == 1 && multCounter == 1 || slashCounter == 3 && multCounter == 1){
	    	printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		i = 0;
		j = 0;
		
		while (parse[i] == ' '){
			i++;
		}
		
		if (parse[i] != '-' && parse[i] < '0' || parse[i] != '-' && parse[i] > '9'){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		while (parse[i] != '/'){
			
			if (numDigits == 0 && parse[i] == '-'){
				if(parse[i + 1] == '0'){
					printf ("INVALID INPUT\n");
					invalid = 1;
					goto bad;
				}
				else{
					temp[j] = parse[i];
					i++;
					j++;
				}
			}
			
			if (parse[i] < '0' || parse[i] > '9'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			if (parse[i] == '0' && parse[i + 1] != '/'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			temp[j] = parse[i];
			i++;
			j++;
			numDigits++;
			
			if(numDigits > 2){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
		}
		
		temp[j] = 0;
		exp->op1.n = atoi(temp);
		numDigits = 0;
		
		i++;
		j = 0;
		
		if (parse[i] != '-' && parse[i] < '1' || parse[i] != '-' && parse[i] > '9'){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		while (parse[i] != ' '){
			
			if (numDigits == 0 && parse[i] == '-'){
				temp[j] = parse [i];
				i++;
				j++;
			}
			
			if (parse[i] < '0' || parse[i] > '9'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			if (parse[i] == '0' && parse[i + 1] != ' '){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			temp[j] = parse[i];
			i++;
			j++;
			numDigits++;
			
			if(numDigits > 2){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
		}
		
		temp[j] = 0;
		exp->op1.d = atoi(temp);
		numDigits = 0;
		
		i++;
		j = 0;
		
		while (parse[i] == ' '){
			i++;
		}
		
		if (parse[i] == '+'){
			exp->operation = '+';
		}
		else if (parse[i] == '-'){
			exp->operation = '-';
		}
		else if (parse[i] == '*'){
			exp->operation = '*';
		}
		else if (parse[i] == '/'){
			exp->operation = '/';
		}
		else{
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		i++;
		
		if (parse[i] != ' '){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		while (parse[i] == ' '){
			i++;
		}
		
		if (parse[i] != '-' && parse[i] < '0' || parse[i] != '-' && parse[i] > '9' || exp->operation == '/' && parse[i] == '0'){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		while (parse[i] != '/'){
			
			if (numDigits == 0 && parse[i] == '-'){
				if(parse[i + 1] == '0'){
					printf ("INVALID INPUT\n");
					invalid = 1;
					goto bad;
				}
				else{
					temp[j] = parse[i];
					i++;
					j++;
				}
			}
			
			if (parse[i] < '0' || parse[i] > '9'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			if (parse[i] == '0' && parse[i + 1] != '/'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			temp[j] = parse[i];
			i++;
			j++;
			numDigits++;
			
			if(numDigits > 2){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
		}
		
		temp[j] = 0;
		exp->op2.n = atoi(temp);
		numDigits = 0;
		
		i++;
		j = 0;
		
		if (parse[i] != '-' && parse[i] < '1' || parse[i] != '-' && parse[i] > '9'){
			printf ("INVALID INPUT\n");
			invalid = 1;
			goto bad;
		}
		
		while (parse[i] != ' ' && parse[i] != 0){
			
			if (numDigits == 0 && parse[i] == '-'){
				temp[j] = parse [i];
				i++;
				j++;
			}
			
			if (parse[i] < '0' || parse[i] > '9'){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			if (parse[i] == '0' && parse[i + 1] != ' ' || parse[i] == '0' && parse[i + 1] != 0){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
			
			temp[j] = parse[i];
			i++;
			j++;
			numDigits++;
			
			if(numDigits > 2){
				printf ("INVALID INPUT\n");
				invalid = 1;
				goto bad;
			}
		}
		
		temp[j] = 0;
		exp->op2.d = atoi(temp);
		invalid = 0;
		printf ("YOUR EXPRESSION HAS BEEN STORED...\n\n");
		
		bad:;
			
		//printf ("%i/%i %c %i/%i\n\n", exp->op1.n, exp->op1.d, exp->operation, exp->op2.n, exp->op2.d);
	} while (invalid == 1);
}

void evaluateExpression (equationType *exp, int counter){
	
	if (counter == 0){
		printf ("\nNO STORED EQUATIONS...\n\n");
	}
	else{
		printf ("\nEVALUATING ALL EXPRESSIONS...\n");
		for (int i = 0; i < counter; i++){
			if (exp[i].operation == '+'){
				exp[i].ans.n = exp[i].op1.n * exp[i].op2.d + exp[i].op2.n * exp[i].op1.d;
				exp[i].ans.d = exp[i].op1.d * exp[i].op2.d;
			}
			else if (exp[i].operation == '-'){
				exp[i].ans.n = exp[i].op1.n * exp[i].op2.d - exp[i].op2.n * exp[i].op1.d;
				exp[i].ans.d = exp[i].op1.d * exp[i].op2.d;
			}
			else if (exp[i].operation == '*'){
				exp[i].ans.n = exp[i].op1.n * exp[i].op2.n;
				exp[i].ans.d = exp[i].op1.d * exp[i].op2.d;
			}
			else {
				exp[i].ans.n = exp[i].op1.n * exp[i].op2.d;
				exp[i].ans.d = exp[i].op1.d * exp[i].op2.n;
			}
			
			simplifyFraction(&exp[i].ans.n, &exp[i].ans.d);
			
			printf ("Expression #%i: %i/%i %c %i/%i = ", i + 1, exp[i].op1.n, exp[i].op1.d, exp[i].operation, exp[i].op2.n, exp[i].op2.d);
			
			if (exp[i].ans.n == exp[i].ans.d){
				printf ("1");
			}
			else if (exp[i].ans.n == -(exp[i].ans.d)){
				printf ("-1");
			}
			else if (exp[i].ans.d == 1 || exp[i].ans.n == 0){
				printf ("%i", exp[i].ans.n);
			}
			else{
				printf ("%i/%i", exp[i].ans.n, exp[i].ans.d);
			}
			printf ("\n");
		}
		printf ("\n");
	}
}

int main(){
	
	fractionType fraction[MAX_FRACTIONS];
	equationType exp[MAX_FRACTIONS];
	int menu = 0;
	int expCounter = 0;
	int fracCounter = 0;

	while (1){
		
		if (expCounter == 100 && fracCounter == 100){
			fflush(stdin);
			printf ("--------------------------\nYou have reached the max amount of fractions stored and expressions stored\n");
			printf ("\nMENU\n3. Display Fractions\n5. Evaluate Expressions\n6. Quit\n");
			
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
						
			switch (menu){
				
				case 3:
				displayFractions(fraction, fracCounter);
					break;
					
				case 5:
				evaluateExpression(exp, expCounter);	
					break;
					
				case 6:
					exit(0);
					break;
				
				default:
					printf ("\nINVALID INPUT\n\n");
			}
		}
		else if (expCounter == 100){
			fflush(stdin);
			printf ("--------------------------\nYou have reached the max amount of expressions stored\n");
			printf ("\nMENU\n1. Create Random Fractions\n2. Store Fractions\n3. Display Fractions\n5. Evaluate Expressions\n6. Quit\n");
			
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
			switch (menu){
				
				case 1:
				randFractions(&fraction[fracCounter]);
				fracCounter++;	
					break;
					
				case 2:
				getFractions(&fraction[fracCounter]);
				fracCounter++;
					break;
					
				case 3: 
				displayFractions(fraction, fracCounter);
					break;
					
				case 5: 
				evaluateExpression(exp, expCounter);	
					break;
					
				case 6:
					exit(0);
					break;
				
				default:
					printf ("\nINVALID INPUT\n\n");
			}
		}
		else if (fracCounter == 100){
			fflush(stdin);
			printf ("--------------------------\nYou have reached the max amount of fractions stored\n");
			printf ("\nMENU\n3. Display Fractions\n4. Store Expression\n5. Evaluate Expressions\n6. Quit\n");
			
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
			switch (menu){
				
				case 3: 
				displayFractions(fraction, fracCounter);	
					break;
					
				case 4:
				getExpression(&exp[expCounter]);
				expCounter++;	
					break;
					
				case 5:
				evaluateExpression(exp, expCounter);	
					break;

				case 6:
					exit(0);
					break;
					
				default:
					printf ("\nINVALID INPUT\n\n");
			}
		}
		else{
			
			printf ("--------------------------\nMENU\n1. Create Random Fractions\n2. Store Fractions\n3. Display Fractions\n4. Store Expression\n5. Evaluate Expression\n6. Quit\n");
			fflush(stdin);
			printf ("\nChoose an option: ");
			scanf ("%i", &menu);
			printf ("--------------------------\n");
			switch (menu){
				
				case 1:
				randFractions(&fraction[fracCounter]);
				fracCounter++;
					break;
					
				case 2:
				getFractions(&fraction[fracCounter]);
				fracCounter++;
					break;
					
				case 3: 
				displayFractions(fraction, fracCounter);	
					break;
					
				case 4:
				getExpression(&exp[expCounter]);
				expCounter++;
					break;
					
				case 5:
				evaluateExpression(exp, expCounter);
					break;
					
				case 6:
					exit(0);
					break;
					
				default:
					printf ("\nINVALID INPUT\n\n");
			}
		}
	}
}
