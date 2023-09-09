#include "deleteSubString.cpp"
#include <stdio.h>

int main(){
	char sentence[] = "hi my name is poop";
	char substring[] = " my name";
	deleteSubString(sentence, substring);
	printf ("%s", sentence);
}
