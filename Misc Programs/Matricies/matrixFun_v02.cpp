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
			printf ("%4i",A.mat[i][j]);
		}
		printf ("\n");
	}
}

void productMatAB (matrixType A, matrixType B, matrixType *product){
	
	int sum = 0;
	
	for (int i = 1; i <= A.rows; i++){
		
		for (int k = 1; k <= B.cols; k++){
			sum = 0;
			for (int j = 1; j <= A.cols; j++){
				sum = sum + A.mat[i][j] * B.mat[j][k];
			}
			product->mat[i][k] = sum;
		}
	
	}
	product->rows = A.rows;
	product->cols = B.cols;
}

void sumMatAB (matrixType A, matrixType B, matrixType *sum){
	
	for (int i = 1; i <= A.rows; i++){
		for (int j = 1; j <= A.cols; j++){
			sum->mat[i][j] = A.mat[i][j] B.mat[i][j];
		}
	}
	
}

int main(){
	matrixType A, B, prodAB, prodBA, sumAB;
	
	// randomly create matrices A and B using the given specs
	
	// lets hard-coded matrices A and B and compute products and sums if possible
	A.rows = 3;
	A.cols = 2;
	A.mat[1][1] = 3;
	A.mat[1][2] = -2;
	A.mat[2][1] = 5;
	A.mat[2][2] = 1;
	A.mat[3][1] = 0;
	A.mat[3][2] = 4;

	printf ("Here is matrix A ....\n");
	outputMatrix (A);

	B.rows = 2;
	B.cols = 5;
	B.mat[1][1] = 4;
	B.mat[1][2] = -3;
	B.mat[1][3] = 5;
	B.mat[1][4] = 2;
	B.mat[1][5] = 0;
	B.mat[2][1] = 0;
	B.mat[2][2] = 1;
	B.mat[2][3] = -4;
	B.mat[2][4] = 4;
	B.mat[2][5] = 5;
	
	printf ("\n\nHere is matrix B ...\n");
	outputMatrix (B);
	
	// compute the products A * B if possible
	productMatAB(A, B, &prodAB);
	// for these hard-coded matrices A*B is computable
	printf ("\n\nHere is the product matrix A*B ...\n");
	// call your function here
	outputMatrix (prodAB);
	// compute the product B * A if possible
	// for these hard-coded matrices B*A is not computatble
	
	// compute the sum 
	// matrices MUST have the same dimensions for the sum to exist
	//sumMatAB(A, B, &sumAB);
	
  	srand((unsigned)time(NULL));   // seed the random number generator
	
}
