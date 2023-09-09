#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROWS 1
#define MAX_ROWS 4
#define MIN_COLS 1
#define MAX_COLS 4
#define MIN_ENTRY 0
#define MAX_ENTRY 9

typedef struct {
	int mat [MAX_ROWS + 1] [MAX_COLS + 1];
	// ignoring row 0 and col 0 in 2D matrix
	int rows;
	int cols;
} matrixType;


int randBetween (int minNum, int maxNum){
  	return rand () % (maxNum - minNum + 1) + minNum;
}    

void outputMatrix (matrixType A){
	for (int i = 1; i <= A.rows; i++){
		for (int j = 1; j <= A.cols; j++){
			printf ("%4i", A.mat[i][j]);
		}
		printf ("\n");
	}
}

int main(){
	matrixType A, B, prodAB, prodBA, sumAB;
	
	// randomly create matrices A and B using the given specs
	A.rows = 3;
	A.cols = 2;
	A.mat[1][1] = 3;
	A.mat[1][2] = -2;
	A.mat[2][1] = 5;
	A.mat[2][2] = 1;
	A.mat[3][1] = 0;
	A.mat[3][2] = 4;
	
	// lets output this hard-coded matrix
	outputMatrix (A);
	
	// compute the products A * B if possible
	
	// compute the product B * A if possible
	
	// computer the sum 
  	srand((unsigned)time(NULL));   // seed the random number generator
	
}
