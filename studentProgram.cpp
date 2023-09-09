#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CHAR 'z'
#define MIN_CHAR 'a'
#define MAX_CHARS 15
#define MIN_CHARS 2

typedef struct{
	char fName[MAX_CHARS + 1];
	char lName[MAX_CHARS + 1];
	int mathMark;
	char sex;
} studentType;

int rb (int min, int max){
	return rand() % (max - min + 1) + min;
}

void getStudent (studentType *s){
	
	int numCharsF = rb(MIN_CHARS, MAX_CHARS);
	int numCharsL = rb(MIN_CHARS, MAX_CHARS);
	int i;
	
	for (i = 0; i < numCharsF; i++){
		s->fName[i] = rb(MIN_CHAR, MAX_CHAR);
	}
	s->fName[i] = 0;
	
	for (i = 0; i < numCharsL; i++){
		s->lName[i] = rb(MIN_CHAR, MAX_CHAR);
	}
	s->lName[i] = 0;
	
	if(rb (0, 1)){
		s->sex = 'F';
	}
	else{
		s->sex = 'M';
	}
	
	s->mathMark = rb(0, 100);
	
}

void getStudents (studentType *s, int *n){
	
	int i;
	*n = rb (1, 40);
	
	for (i = 0; i < *n; i++){
		getStudent (&s[i]);
	}
	
}

void swap (studentType *s, int j){
	
	studentType temp;
	
	temp = s[j];
	s[j] = s[j + 1];
	s[j + 1] = temp;
	
}

void sortStudents (studentType *s, int n){
	
	int i, j;
	
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (s[j].mathMark > s[j + 1].mathMark){
				swap (s, j);
			}
		}
	}
	
}

void outputStudent (studentType s, int n){
	
	char p[50];
	
	sprintf (p, "Student #%i", n + 1);
	printf ("%15s", p);
	printf ("%20s", s.fName);
	printf ("%20s", s.lName);
	printf ("%10i", s.mathMark);
	printf ("%5c\n", s.sex);
	
}

void outputStudents (studentType *s, int n){
	
	int i;
	for (i = 0; i < n; i++){
		outputStudent (s[i], i);
	}
	printf ("\n"); //looks nicer
	
}
int main(){
	
	studentType student[40];
	int numStudents;
	
	srand((unsigned)time(NULL));
	
	getStudents (student, &numStudents);
	outputStudents (student, numStudents);
	sortStudents (student, numStudents);
	printf ("Here are the students sorted by math mark\n\n");
	outputStudents (student, numStudents);
	system ("PAUSE");
}
