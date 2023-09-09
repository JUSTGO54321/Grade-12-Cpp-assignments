#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 21
#define MAX_COLS 21

#define MIN_VALUE 0
#define MAX_VALUE 5
#define OPEN 'O'
#define CLOSED 'C'



typedef enum colourType {red, green, blue, yellow, pink};


typedef struct{
  colourType colour; // see the possible colors
  int value;      // integer from 0 to 5
  char status;  // a grid cell is either open or closed  
} cellType;

// data structure for a matrix
typedef struct {
  cellType cells[MAX_ROWS+1][MAX_COLS+1]; // ignore row 0 and col 0 on board!
  int r,c;    // number of rows and columns of cells
} boardType;

// use this to output the enumerated type data
char COLOURS[][10] = {"R", "G", "B", "Y", "P"};

// This function just sets up a gameboard that you can use later
void hardCodeBoard (boardType *B) {
  // set to a 10 by 7 board
  // remember ignore row 0 and col 0
  B->r = 7;
  B->c = 10;
  
  // set ALL cells to closed
  for (int rows = 1; rows <= B->r; rows++)
    for (int cols = 1; cols <= B->c; cols++)
      B->cells[rows][cols].status = CLOSED;

  // now set each cell
  B->cells[1][1].colour = red;
  B->cells[1][1].value = 5;
  B->cells[1][2].colour = green;
  B->cells[1][2].value = 2;
  B->cells[1][3].colour = blue;
  B->cells[1][3].value = 4;
  B->cells[1][4].colour = pink;
  B->cells[1][4].value = 3;
  B->cells[1][5].colour = green;
  B->cells[1][5].value = 4;
  B->cells[1][6].colour = yellow;
  B->cells[1][6].value = 1;
  B->cells[1][7].colour = red;
  B->cells[1][7].value = 3;
  B->cells[1][8].colour = green;
  B->cells[1][8].value = 0;
  B->cells[1][9].colour = green;
  B->cells[1][9].value = 4;
  B->cells[1][10].colour = pink;
  B->cells[1][10].value = 1;
  
  B->cells[2][1].colour = yellow;
  B->cells[2][1].value = 2;
  B->cells[2][2].colour = pink;
  B->cells[2][2].value = 1;
  B->cells[2][3].colour = green;
  B->cells[2][3].value = 3;
  B->cells[2][4].colour = red;
  B->cells[2][4].value = 5;
  B->cells[2][5].colour = blue;
  B->cells[2][5].value = 5;
  B->cells[2][6].colour = blue;
  B->cells[2][6].value = 0;
  B->cells[2][7].colour = yellow;
  B->cells[2][7].value = 2;
  B->cells[2][8].colour = red;
  B->cells[2][8].value = 1;
  B->cells[2][9].colour = blue;
  B->cells[2][9].value = 3;
  B->cells[2][10].colour = yellow;
  B->cells[2][10].value = 4;

  B->cells[3][1].colour = pink;
  B->cells[3][1].value = 4;
  B->cells[3][2].colour = green;
  B->cells[3][2].value = 3;
  B->cells[3][3].colour = blue;
  B->cells[3][3].value = 5;
  B->cells[3][4].colour = blue;
  B->cells[3][4].value = 1;
  B->cells[3][5].colour = green;
  B->cells[3][5].value = 1;
  B->cells[3][6].colour = red;
  B->cells[3][6].value = 0;
  B->cells[3][7].colour = pink;
  B->cells[3][7].value = 0;
  B->cells[3][8].colour = pink;
  B->cells[3][8].value = 1;
  B->cells[3][9].colour = yellow;
  B->cells[3][9].value = 2;
  B->cells[3][10].colour = blue;
  B->cells[3][10].value = 3;
    
  B->cells[4][1].colour = yellow;
  B->cells[4][1].value = 2;
  B->cells[4][2].colour = green;
  B->cells[4][2].value = 4;
  B->cells[4][3].colour = pink;
  B->cells[4][3].value = 0;
  B->cells[4][4].colour = green;
  B->cells[4][4].value = 1;
  B->cells[4][5].colour = red;
  B->cells[4][5].value = 1;
  B->cells[4][6].colour = blue;
  B->cells[4][6].value = 0;
  B->cells[4][7].colour = green;
  B->cells[4][7].value = 5;
  B->cells[4][8].colour = blue;
  B->cells[4][8].value = 4;
  B->cells[4][9].colour = yellow;
  B->cells[4][9].value = 2;
  B->cells[4][10].colour = green;
  B->cells[4][10].value = 3;
    
  B->cells[5][1].colour = blue;
  B->cells[5][1].value = 0;
  B->cells[5][2].colour = yellow;
  B->cells[5][2].value = 2;
  B->cells[5][3].colour = pink;
  B->cells[5][3].value = 0;
  B->cells[5][4].colour = blue;
  B->cells[5][4].value = 4;
  B->cells[5][5].colour = green;
  B->cells[5][5].value = 5;
  B->cells[5][6].colour = green;
  B->cells[5][6].value = 2;
  B->cells[5][7].colour = red;
  B->cells[5][7].value = 1;
  B->cells[5][8].colour = red;
  B->cells[5][8].value = 1;
  B->cells[5][9].colour = yellow;
  B->cells[5][9].value = 0;
  B->cells[5][10].colour = blue;
  B->cells[5][10].value = 4;
    
  B->cells[6][1].colour = blue;
  B->cells[6][1].value = 5;
  B->cells[6][2].colour = yellow;
  B->cells[6][2].value = 2;
  B->cells[6][3].colour = yellow;
  B->cells[6][3].value = 4;
  B->cells[6][4].colour = blue;
  B->cells[6][4].value = 3;
  B->cells[6][5].colour = red;
  B->cells[6][5].value = 4;
  B->cells[6][6].colour = pink;
  B->cells[6][6].value = 1;
  B->cells[6][7].colour = red;
  B->cells[6][7].value = 3;
  B->cells[6][8].colour = yellow;
  B->cells[6][8].value = 0;
  B->cells[6][9].colour = blue;
  B->cells[6][9].value = 4;
  B->cells[6][10].colour = green;
  B->cells[6][10].value = 1;
    
  B->cells[7][1].colour = blue;
  B->cells[7][1].value = 5;
  B->cells[7][2].colour = yellow;
  B->cells[7][2].value = 2;
  B->cells[7][3].colour = pink;
  B->cells[7][3].value = 4;
  B->cells[7][4].colour = pink;
  B->cells[7][4].value = 3;
  B->cells[7][5].colour = red;
  B->cells[7][5].value = 4;
  B->cells[7][6].colour = pink;
  B->cells[7][6].value = 1;
  B->cells[7][7].colour = green;
  B->cells[7][7].value = 3;
  B->cells[7][8].colour = green;
  B->cells[7][8].value = 0;
  B->cells[7][9].colour = red;
  B->cells[7][9].value = 4;
  B->cells[7][10].colour = yellow;
  B->cells[7][10].value = 1;
    
}

void outputBoard (boardType *B){
  for (int rows = 1; rows <= B->r; rows++){
    for (int cols = 1; cols <= B->c; cols++)
      printf ("%s%i%c ",
	  			COLOURS[B->cells[rows][cols].colour],
				B->cells[rows][cols].value,
				B->cells[rows][cols].status); 
    printf ("\n");
  }
}

int sumPoints (boardType board){
	
	int sum = 0;
	for (int i = 1; i <= board.r; i++){
		for (int j = 1; j <= board.c; j++){
			sum = sum + board.cells[i][j].value;
		}
	}
	return sum;
	
}

int sumPointsColour (boardType board){
	
	int sum = 0;
	for (int i = 1; i <= board.r; i++){
		for (int j = 1; j <= board.c; j++){
			if (board.cells[i][j].colour == 0){
				sum = sum + board.cells[i][j].value;
			}
		}
	}
	return sum;
	
}
void sort (int *A, int n){
	
	int i, j, temp;
	for (i = 0; i < n - 1; i++){
		for (j = 1; j < n - i - 1; j++){
			if (A[j] > A[j + 1]){
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

int mostFrequentColour (boardType board){
	
	int colour[5] = {0, 0, 0, 0, 0};
	
	for (int i = 1; i <= board.r; i++){
		for (int j = 1; j <= board.c; j++){
			switch (board.cells[i][j].colour){
				 case 0:
					colour[0]++;
					break;
					
				case 1:
					colour[1]++;
					break;
					
				case 2:
					colour[2]++;
					break;
				
				case 3:
					colour[3]++;
					break;
					
				case 4:
					colour[4]++;
					break;
			}
		}
	}

	if (colour[0] > colour[1] && colour[0] > colour[2] && colour[0] > colour[3] && colour[0] > colour[4]){ //running out of time so im doing it very inefficiently
		return 0;
	}
	else if (colour[1] > colour[2] && colour[1] > colour[3] && colour[1] > colour[4]){
		return 1;
	}
	else if (colour[2] > colour[3] && colour[2] > colour[4]){
		return 2;
	}
	else if (colour[3] > colour[4]){
		return 3;
	}
	else {
		return 4;
	}
}

void deleteRow (boardType *board, int row){
	for (int i = 1; i <= board->c; i++){
		board->cells[row][i] = board->cells[row + 1][i];
	}
	(board->r)--;
}
int main (){
	
	boardType board;
	
	hardCodeBoard (&board);
	outputBoard (&board);
	
	// call a function to determine the sum of the points (values) on the board
	printf ("\nThe sum of all points on the board is %i\n", sumPoints(board));
	// call a function that takes a colour and determines the sum of all the 
	// cells of that colour ... don't bother getting the colour from the user
	// just hard-code the colour in the function call
	printf ("The sum of all points who's colour is red is %i\n", sumPointsColour(board));
	
	// write a function that determines the colour that occurs most frequently
	 // on the board
	printf ("The colour that occurs most frequently on the board is ");
	
	switch (mostFrequentColour(board)){
		
		case 0:
			printf ("red");
			break;
		
		case 1:
			printf ("green");
			break;
			
		case 2:
			printf ("blue");
			break;
			
		case 3:
			printf ("yellow");
			break;
		
		case 4:
			printf ("pink");
			break;
	}
	printf ("\n\n");
	 // call a function that takes a row number and deletes that row
	deleteRow(&board, 6);
	 // ... don't bother getting the row number just hard code it in 
	 // the function call ... be sure to output the board to verify the deletion
	outputBoard (&board);
	printf ("Row 6 has been deleted...\n\n");
	
	system ("PAUSE");
}
