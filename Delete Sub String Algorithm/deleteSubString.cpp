#include <string.h>

void deleteSubString (char *sentence, char *subString){
	
	int sentenceLen = strlen(sentence);
	int subStringLen = strlen(subString);
	int i = 0;
	
	while (i < sentenceLen){
		if (strstr(&sentence[i], subString) == &sentence[i]){
			sentenceLen -= subStringLen;
			
			for (int j = i; j < sentenceLen; j++){
				sentence[j] = sentence[j + subStringLen];
			}
		}
		else i++;
	}
	sentence[i] = 0;
} 
