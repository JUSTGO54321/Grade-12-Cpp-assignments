#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 21
#define MAX_COLS 21

#define MIN_VALUE 0
#define MAX_VALUE 5
#define OPEN 'O'
#define CLOSED 'C'



enum colourType {red, green, blue, yellow, pink};


typedef struct{
  enum colourType colour; // see the possible colors
  int value;      // integer from 0 to 5
  char status;  // a grid cell is either open 'O' or closed  'C' 
} cellType;

// data structure for a matrix
typedef struct {
  cellType cells[MAX_ROWS+1][MAX_COLS+1]; // ignore row 0 and col 0 on board!
  int r,c;    // number of rows and columns of cells
} boardType;

char COLOURS[][10] = {"R", "G", "B", "Y", "P"};

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
  B->cells[1][9].colour = blue;
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
  B->cells[2][9].colour = green;
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
  B->cells[3][7].colour = green;
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
  B->cells[4][4].colour = yellow;
  B->cells[4][4].value = 1;
  B->cells[4][5].colour = red;
  B->cells[4][5].value = 1;
  B->cells[4][6].colour = blue;
  B->cells[4][6].value = 0;
  B->cells[4][7].colour = green;
  B->cells[4][7].value = 5;
  B->cells[4][8].colour = blue;
  B->cells[4][8].value = 4;
  B->cells[4][9].colour = green;
  B->cells[4][9].value = 2;
  B->cells[4][10].colour = yellow;
  B->cells[4][10].value = 3;
    
  B->cells[5][1].colour = blue;
  B->cells[5][1].value = 0;
  B->cells[5][2].colour = green;
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
  B->cells[5][10].colour = green;
  B->cells[5][10].value = 4;
    
  B->cells[6][1].colour = blue;
  B->cells[6][1].value = 5;
  B->cells[6][2].colour = yellow;
  B->cells[6][2].value = 2;
  B->cells[6][3].colour = green;
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
    
  B->cells[7][1].colour = green;
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
      printf ("%s%i%c  ",COLOURS[B->cells[rows][cols].colour],
      B->cells[rows][cols].value,B->cells[rows][cols].status); 
    printf ("\n");
  } 
}


void closeAllCells (boardType *B){
  for (int rows = 1; rows <= B->r; rows++){
    for (int cols = 1; cols <= B->c; cols++){
      B->cells[rows][cols].status = 'C';
  	}
  }
}

int evaluateCells(boardType *B, int r, int c) {
  // {"R", "G", "B", "Y", "P"};
  if (r < 1 || r > B->r) return 0;
  if (c < 1 || c > B->c) return 0;
  if (B->cells[r][c].status == 'O') return 0;
  B->cells[r][c].status = 'O';
  if (B->cells[r][c].colour != 2 && B->cells[r][c].colour != 1) return B->cells[r][c].value; 
  if (B->cells[r][c].colour == 1) return B->cells[r][c].value + evaluateCells(B, r + 1, c) + evaluateCells(B, r - 1, c) + evaluateCells(B,r,c + 1) + evaluateCells(B, r, c - 1) + evaluateCells(B, r + 1, c + 1) + evaluateCells(B, r - 1, c - 1) + evaluateCells(B, r - 1, c + 1) +evaluateCells(B, r + 1, c - 1);
  return B->cells[r][c].value * 2;
}

int main (){
  boardType board;
  int row, col; // the board starts at row 1 and col 1
  int score = 0;    // score obtained for a cell on the board
  
  hardCodeBoard (&board);  
  closeAllCells (&board);	// make sure all cells are closed to begin game

  while (1){
    outputBoard (&board);

    printf ("\n\nEnter the cell you wish to evaluate.\n");
    
    // ASSUME VALID INPUT
    printf ("Enter a row between 1 and %i inclusive: ", board.r);
    scanf ("%i", &row);
    printf ("Enter a column between 1 and %i inclusive: ", board.c);
    scanf ("%i", &col);

    // call a function to evaluate this cell in the grid
    
    // Firstly set the cell to OPEN (open the cell)
    // if the cell is pink, green red or yellow add the cells value to the score 
    // if the cell is blue add twice the value of the cell to the score
    // ***** if the cell is GREEN, then open ALL adjacent cells (that have not
    // been opened already) and treat each of these cells the same way you 
    // treat any cell that gets opened
    
    // Output the new board to be sure you opened the correct cells and
    // be sure to report the score of the cell

    printf ("The value of your cell is %i\n", evaluateCells(&board, row, col));

  }

}
