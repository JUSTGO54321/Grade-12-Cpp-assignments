#include <stdio.h>
#include <stdlib.h>

/*
	Delete all occurences of delChar from s
	and return the number of deletions that took
	place. For example, if s = "Fishing Rod" and
	delChar = i then after the call s = "Fshng Rod" and
	the function returns 2 to the calling function.
*/
int  delAllChars (char *s, char delChar){
	// your code goes here
	
	int found = 0;
	int i = 0;
	int done;
	
	while (s[i]){
		
		if (s[i] == delChar){
			found++;
		}
		i++;
	}
	
	for (int j = 0; j < found; j++){
		
		done = 0;
		
		for (int k = 0; k < i; k++){
			
			if(!done){
       	
          		if(delChar == s[k]){
				done = 1;
				s[k] = s[k + 1];
				}
			}
			else{
				s[k] = s[k + 1];
			}
		}
	}
}

int main(){
	char s[80];
	char c;
	int numDeletions;

	while (1){		// here is an infinite loop in C ... 1 is always TRUE
		printf ("Enter your string: ");
		gets(s);
		printf ("Enter the character to be deleted: ");
		c = getchar();
		fflush(stdin);
		
		printf ("Your string was before deletion is %s\n\n",s);
		
		numDeletions = delAllChars (s, c);
		printf ("Your string after deletion is  %s\n", s);
		printf ("%i %c's were deleted.\n\n", numDeletions, c);
		system ("pause");	
		system ("cls");
	}
		
	return 0;
}
