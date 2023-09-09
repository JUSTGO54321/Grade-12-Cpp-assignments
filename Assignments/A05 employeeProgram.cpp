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
	int day;
	int month;
	int year;
} dateType;

typedef struct {
	char lName[MAX_NAME_CHARS + 1];
	char mName[MAX_NAME_CHARS + 1];
	char fName[MAX_NAME_CHARS + 1];
	char gender;
	dateType dob;
	int salary;
} empType;


// return 1 if the parsing was a success
// return 0 if the parsing was unsuccessful ... see emp string requirements
// I'm not allowed strtok :(

int parseEmp(char *s, empType *emp){
	// your code starts here
	empType temp;
	int i = 0;
	int numChars = 0;
	char tempIntString[100];
	
	//fName
	while (s[i] == ' '){
		i++;
	}
	
	numChars = 0;
	while (s[i] != ',' && s[i] != ' '){
		if (s[i] < MIN_NAME_CHAR || s[i] > MAX_NAME_CHAR){
			return 0;
		}
		
		temp.lName[numChars] = s[i];
		numChars++;
		i++;
		
		if (numChars > MAX_NAME_CHARS){
			return 0;
		}
	}
	if (numChars < MIN_NAME_CHARS){
		return 0;
	}
	while (s[i] != ','){
		if (s[i] == ' '){
			i++;
		}
		else{
			return 0;
		}
	}
	temp.lName[numChars] = 0;
	i++;
	//lName
	while (s[i] == ' '){
		i++;
	}
	
	numChars = 0;
	while (s[i] != ',' && s[i] != ' '){
		if (s[i] < MIN_NAME_CHAR || s[i] > MAX_NAME_CHAR){
			return 0;
		}
		
		temp.mName[numChars] = s[i];
		numChars++;
		i++;
		
		if (numChars > MAX_NAME_CHARS){
		return 0;
		}
	}	
	if (numChars < MIN_NAME_CHARS){
		return 0;
	}
	
	while (s[i] != ','){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}
	temp.mName[numChars] = 0;
	i++;
	//lName
	while (s[i] == ' '){
		i++;
	}
	
	numChars = 0;
	while (s[i] != ',' && s[i] != ' '){
		if (s[i] < MIN_NAME_CHAR || s[i] > MAX_NAME_CHAR){
			return 0;
		}
		
		temp.fName[numChars] = s[i];
		numChars++;
		i++;
		
		if (numChars > MAX_NAME_CHARS){
		return 0;
		}
	}	
	if (numChars < MIN_NAME_CHARS){
		return 0;
	}
	
	while (s[i] != ','){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}
	temp.fName[numChars] = 0;
	i++;
	//gender
	while (s[i] == ' '){
		i++;
	}
	if (s[i] != 'F' && s[i] != 'M' && s[i] != 'N'){
		return 0;
	}
	else{
		temp.gender = s[i];
		i++;
	}
	while (s[i] != ','){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}
	i++;
	//day
	while (s[i] == ' '){
		i++;
	}
	
	numChars = 0;
	if (s[i] < '1' || s[i] > '9'){
		return 0;
	}

	while (s[i] != ',' && s[i] != ' '){
		if (s[i] < '0' || s[i] > '9'){
			return 0;
		}
		tempIntString[numChars] = s[i];
		i++;
		numChars++;
	}
	tempIntString[numChars] = 0;
	if (atoi(tempIntString) < MIN_DAY || atoi(tempIntString) > MAX_DAY){
		return 0;
	}
	else{
		temp.dob.day = atoi(tempIntString);
	}
	
	while (s[i] != ','){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}
	i++;
	//month
	while (s[i] == ' '){
		i++;
	}
	
	numChars = 0;
	if (s[i] < '1' || s[i] > '9'){
		return 0;
	}
	
	while (s[i] != ',' && s[i] != ' '){
		if (s[i] < '0' || s[i] > '9'){
			return 0;
		}
		tempIntString[numChars] = s[i];
		i++;
		numChars++;
	}
	tempIntString[numChars] = 0;
	if (atoi(tempIntString) < MIN_MONTH || atoi(tempIntString) > MAX_MONTH){
		return 0;
	}
	else{
		temp.dob.month = atoi(tempIntString);
	}
	
	while (s[i] != ','){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}
	i++;
	//year
	while (s[i] == ' '){
		i++;
	}
	numChars = 0;
	if (s[i] < '1' || s[i] > '9'){
		return 0;
	}
	
	while (s[i] != ',' && s[i] != ' '){
		if (s[i] < '0' || s[i] > '9'){
			return 0;
		}
		tempIntString[numChars] = s[i];
		i++;
		numChars++;
	}
	tempIntString[numChars] = 0;
	if (atoi(tempIntString) < MIN_YEAR || atoi(tempIntString) > MAX_YEAR){
		return 0;
	}
	else{
		temp.dob.year = atoi(tempIntString);
	}
	while (s[i] != ','){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}
	i++;
	//salary
	while (s[i] == ' '){
		i++;
	}
	
	numChars = 0;
	if (s[i] < '1' || s[i] > '9'){
		return 0;
	}
	
	while (s[i] != 0 && s[i] != ' '){
		if (s[i] < '0' || s[i] > '9'){
			return 0;
		}
		tempIntString[numChars] = s[i];
		i++;
		numChars++;
	}
	tempIntString[numChars] = 0;
	if (atoi(tempIntString) < MIN_SALARY || atoi(tempIntString) > MAX_SALARY){
		return 0;
	}
	else{
		temp.salary = atoi(tempIntString);
	}
	while (s[i]){
		if (s[i] != ' '){
			return 0;
		}
		else{
			i++;
		}
	}	
	if (s[i]){
		return 0;
	}
	
	*emp = temp;
	return 1;
}

void getEmps(empType *emps, int n){
	char empString[256];
	int i = 0;

	while (i < n){

		printf ("Enter your employee string below...\n");
		gets(empString);
	
		if(parseEmp(empString, &emps[i])) i++;	// we got a valid employee!
		else printf ("INVALID INPUT...\n");
	}
	
}

void swap (empType *emp1, empType *emp2){
	empType temp;
	temp = *emp1;
	*emp1 = *emp2;
	*emp2 = temp;
}

void sortEmpsByDOB (empType *emps, int n){
	
	empType temp;
	
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (emps[j].dob.year > emps[j + 1].dob.year){
				swap (&emps[j], &emps[j + 1]);
			}
			else if (emps[j].dob.year == emps[j + 1].dob.year){
				if (emps[j].dob.month > emps[j + 1].dob.month){
					swap (&emps[j], &emps[j + 1]);
				}
				else if (emps[j].dob.month == emps[j + 1].dob.month){
					if (emps[j].dob.day > emps[j + 1].dob.day){
						swap (&emps[j], &emps[j + 1]);						
					}
				}
			}
		}
	}
}

void outputEmps(empType *emps, int n){
	
	printf ("\n");
	for (int i = 0; i < n; i++){
		printf ("%s,%s,%s,%c,%i,%i,%i,%i\n", emps[i].lName, emps[i].mName, emps[i].fName, emps[i].gender, emps[i].dob.day, emps[i].dob.month, emps[i].dob.year, emps[i].salary);
	}

}

int main(){
	empType emps[100];
	int numEmps = 3;
	
	getEmps(emps, numEmps);
	printf ("\nBefore sort");
	outputEmps (emps, numEmps);
	sortEmpsByDOB (emps, numEmps);
	printf ("\nAfter sort");
	outputEmps(emps, numEmps);
	return 0;
}
