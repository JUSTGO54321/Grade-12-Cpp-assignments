#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COORDS 10
#define MAX_DIGITS_PER_COORD 9

typedef struct{
	int coords[MAX_COORDS];
	int n;
}nTupleType;

int parseNTuple (char *nts, nTupleType *nTuple){
	
	nTuple->n = 0;
	char temp[100];
	int numDigits;
	int i = 0;
	int j = 0;
	int k = 0;
	
	while (nts[i] == ' '){
		i++;
	}
	
	if (nts[i] != '('){
		return 0;
	} 
	i++;
	
	while (nTuple->n <= MAX_COORDS){	
		
		if (nts[i] != '-' && nts[i] < '0' || nts[i] > '9'){
			return 0;
		}
		
		if (nts[i] == '0'){
			if(nts[i + 1] != ',') return 0;
		}
		
		numDigits = 0;
		j = 0;
		
		while (nts[i] != ',' && nts[i] != ')'){
			
			if (numDigits == 0 && nts[i] == '-'){
				temp[j] = nts[i];
				j++;
				i++;
			}
			
			if(nts[i] < '0'|| nts[i] > '9'){
				return 0;
			}
			
			temp[j] = nts[i];
			j++;
			i++;
			numDigits++;
			if(numDigits > MAX_DIGITS_PER_COORD){
				return 0;
			}
		}
		
		temp[j] = 0;
		//printf ("%s\n", temp);
		nTuple->coords[k] = atoi(temp);
		k++;
		nTuple->n = nTuple->n + 1;
		
		if(nTuple->n > MAX_COORDS){
			return 0;
		}
		
		if(nts[i] == ')'){
			i++;
			
			while(nts[i]){
				
				if(nts[i] != ' '){
					return 0;
				}
				i++;
			}
			return 1;
		}
		i++;
	}
}

void outputNTuple (nTupleType nTuple){
	printf ("(");
	for (int i = 0; i < nTuple.n; i++){
		if (i == (nTuple.n) - 1){
			printf ("%i)", nTuple.coords[i]);
		}
		else{
			printf ("%i,", nTuple.coords[i]);
		}
	}
}

int main(){
	
	char nTupString[100];
	nTupleType nTuple;
	
	printf("Enter a tuple: \n");
	gets(nTupString);
	
	if (parseNTuple(nTupString, &nTuple)){
		printf ("Here is your nTuple ...\n");
		outputNTuple(nTuple);
	}
	else{
		printf ("\"%s\" is an invalid nTuple String.\n\n", nTupString);
	}
}
