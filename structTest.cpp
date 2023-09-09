#include <stdio.h>
#include <stdlib.h>

#define MIN_NAME_CHARS 3
#define MAX_NAME_CHARS 10
#define MIN_NAME_CHAR 'a'
#define MAX_NAME_CHAR 'z'
#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_YEAR 1980
#define MAX_YEAR 2000
#define MIN_SALARY 20000
#define MAX_SALARY 500000

typedef struct {
	int day, month,year;
} dateType;

typedef struct {
	char lName[MAX_NAME_CHARS + 1];
	char mName[MAX_NAME_CHARS + 1];
	char fName[MAX_NAME_CHARS + 1];
	char gender;
	dateType dob;
	int salaryType;
} empType;

void getEmpsFromUser (empType *emps, int n){
	
	empType temp;
	int invalid = 0;
	char empString[400];
	int i = 0;
	int numChars = 0;
	char tempIntString[10];
	
	do {
		invalid = 0;
		printf ("Enter the emplyoyee record: ");
		gets(empString);
		//fName
		while (empString[i] == ' '){
			i++;
		}
		
		numChars = 0;
		while (empString[i] != ',' && empString[i] != ' '){
			if (empString[i] < MIN_NAME_CHAR || empString[i] > MAX_NAME_CHAR){
				invalid = 1;
				goto invalid;
			}
			
			temp.fName[numChars] = empString[i];
			numChars++;
			i++;
			
			if (numChars > MAX_NAME_CHARS){
				invalid = 1;
				goto invalid;
			}
		}
		if (numChars < MIN_NAME_CHARS){
			invalid = 1;
			goto invalid;
		}
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		temp.fName[numChars] = 0;
		i++;
		//lName
		while (empString[i] == ' '){
			i++;
		}
		
		numChars = 0;
		while (empString[i] != ',' && empString[i] != ' '){
			if (empString[i] < MIN_NAME_CHAR || empString[i] > MAX_NAME_CHAR){
				invalid = 1;
				goto invalid;
			}
			
			temp.mName[numChars] = empString[i];
			numChars++;
			i++;
			
			if (numChars > MAX_NAME_CHARS){
			invalid = 1;
			goto invalid;
			}
		}	
		if (numChars < MIN_NAME_CHARS){
			invalid = 1;
			goto invalid;
		}
		
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		temp.mName[numChars] = 0;
		i++;
		//lName
		while (empString[i] == ' '){
			i++;
		}
		
		numChars = 0;
		while (empString[i] != ',' && empString[i] != ' '){
			if (empString[i] < MIN_NAME_CHAR || empString[i] > MAX_NAME_CHAR){
				invalid = 1;
				goto invalid;
			}
			
			temp.lName[numChars] = empString[i];
			numChars++;
			i++;
			
			if (numChars > MAX_NAME_CHARS){
			invalid = 1;
			goto invalid;
			}
		}	
		if (numChars < MIN_NAME_CHARS){
			invalid = 1;
			goto invalid;
		}
		
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		temp.lName[numChars] = 0;
		i++;
		//gender
		while (empString[i] == ' '){
			i++;
		}
		if (empString[i] != 'F' && empString[i] != 'M' && empString[i] != 'N'){
			invalid = 1;
			goto invalid;
		}
		else{
			temp.gender = empString[i];
			i++;
		}
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		i++;
		//day
		while (empString[i] == ' '){
			i++;
		}
		
		numChars = 0;
		if (empString[i] < '1' || empString[i] > '9'){
			invalid = 1;
			goto invalid;
		}
		
		while (empString[i] != ',' && empString[i] != ' '){
			if (empString[i] < '0' || empString[i] > '9'){
				invalid = 1;
				goto invalid;
			}
			tempIntString[numChars] = empString[i];
			i++;
			numChars++;
		}
		tempIntString[i] = 0;
		if (atoi(tempIntString) < MIN_DAY || atoi(tempIntString) > MAX_DAY){
			invalid = 1;
			goto invalid;
		}
		else{
			temp.dob.day = atoi(tempIntString);
		}
		
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		i++;
		//month
		while (empString[i] == ' '){
			i++;
		}
		
		numChars = 0;
		if (empString[i] < '1' || empString[i] > '9'){
			invalid = 1;
			goto invalid;
		}
		
		while (empString[i] != ',' && empString[i] != ' '){
			if (empString[i] < '0' || empString[i] > '9'){
				invalid = 1;
				goto invalid;
			}
			tempIntString[numChars] = empString[i];
			i++;
			numChars++;
		}
		tempIntString[i] = 0;
		if (atoi(tempIntString) < MIN_MONTH || atoi(tempIntString) > MAX_MONTH){
			invalid = 1;
			goto invalid;
		}
		else{
			temp.dob.month = atoi(tempIntString);
		}
		
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		i++;
		//year
		while (empString[i] == ' '){
			i++;
		}
		numChars = 0;
		if (empString[i] < '1' || empString[i] > '9'){
			invalid = 1;
			goto invalid;
		}
		
		while (empString[i] != ',' && empString[i] != ' '){
			if (empString[i] < '0' || empString[i] > '9'){
				invalid = 1;
				goto invalid;
			}
			tempIntString[numChars] = empString[i];
			i++;
			numChars++;
		}
		tempIntString[i] = 0;
		if (atoi(tempIntString) < MIN_YEAR || atoi(tempIntString) > MAX_YEAR){
			invalid = 1;
			goto invalid;
		}
		else{
			temp.dob.year = atoi(tempIntString);
		}
		while (empString[i] != ','){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		i++;
		//salary
		while (empString[i] == ' '){
			i++;
		}
		
		numChars = 0;
		if (empString[i] < '1' || empString[i] > '9'){
			invalid = 1;
			goto invalid;
		}
		
		while (empString[i] != '.' && empString[i] != ' '){
			if (empString[i] < '0' || empString[i] > '9'){
				invalid = 1;
				goto invalid;
			}
			tempIntString[numChars] = empString[i];
			i++;
			numChars++;
		}
		tempIntString[i] = 0;
		if (atoi(tempIntString) < MIN_SALARY || atoi(tempIntString) > MAX_SALARY){
			invalid = 1;
			goto invalid;
		}
		else{
			temp.salaryType = atoi(tempIntString);
		}
		while (empString[i] != '.'){
			if (empString[i] != ' '){
				invalid = 1;
				goto invalid;
			}
			else{
				i++;
			}
		}
		i++;	
		if (empString[i] != 0){
			invalid = 1;
			goto invalid;
		}
		
		emps[n] = temp;
		
		invalid:
			// ("INVALID INPUT...\n");
			invalid = 0;

	} while (invalid);
}

void sortEmpsByDOB (empType *emps, int n){
	
	int temp;
	
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (emps[j].dob.year > emps[j + 1].dob.year){
				temp = emps[j].dob.year;
				emps[j].dob.year = emps[j + 1].dob.year;
				emps[j + 1].dob.year = temp;
			}
			else if (emps[j].dob.year == emps[j + 1].dob.year){
				if (emps[j].dob.month > emps[j + 1].dob.month){
					temp = emps[j].dob.month;
					emps[j].dob.month = emps[j + 1].dob.month;
					emps[j + 1].dob.month = temp;
				}
				else if (emps[j].dob.month == emps[j + 1].dob.month){
						temp = emps[j].dob.day;
						emps[j].dob.day = emps[j + 1].dob.day;
						emps[j + 1].dob.day = temp;
				}
			}
		}
	}
}

void outputEmps (empType *emps, int n){
	
	for (int i = 0; i < n; i++){
		printf ("%s,%s,%s,%c,%i,%i,%i,%i.\n", emps[i].fName, emps[i].mName, emps[i].lName, emps[i].gender, emps[i].dob.day, emps[i].dob.month, emps[i].dob.year, emps[i].salaryType);
		printf ("HI");
	}

}
int main (){
	empType emps[1000];
	int numEmps = 5;		// not getting this from user … i gave it to you
	char empString [400];		// won’t overflow this … I hope

	// now get this many employees from the user

	// getEmpsFromUser will be tough
	// sortEmpsByDOB will be easier
	// outputEmps will be easy … just output one emp per line comma delimited with no spaces
	for (int i = 0; i < numEmps; i++){
		getEmpsFromUser(emps, i);	// you write this
	}
	sortEmpsByDOB(emps, numEmps);		// you write this .. young to old
	outputEmps (emps, numEmps);		// you write this
}

