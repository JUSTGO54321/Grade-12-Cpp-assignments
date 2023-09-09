#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void outputRectangle (int lt, int rt, int bot, int top){
	printf ("botLeft = (%i, %i)\n",lt,bot);
	printf ("topRight = (%i, %i)\n", rt, top);
}

int findArea (int lt, int rt, int bot, int top){
	return lt * bot;
}

int findPerimeter (int lt, int rt, int bot, int top){
	return lt + rt + bot + top;
}

double findDiagonal(int lt, int rt, int bot, int top){
	int diagonal = lt * lt + bot * bot;
	diagonal = sqrt(diagonal);
}

int main (){
	// left is always smaller than right
	// bottom is always smaller than top
	// this defines a rectangle
	int left, right, bottom, top;
	int area, perimeter;
	double diagonalLength;
	
	
	
	while(1){
		printf ("Now defining your rectangle ... \n");
		printf ("Enter left: ");
		scanf("%i", &left);
		printf ("Enter right: ");
		scanf("%i", &right);
		printf ("Enter bottom: ");
		scanf("%i", &bottom);
		printf ("Enter top: ");
		scanf("%i", &top);
		
		
		area = findArea(left, right, bottom, top);
		perimeter = findPerimeter(left, right, bottom, top);
		diagonalLength = findDiagonal (left, right, bottom, top);
		
		printf ("\n");
		printf ("Here is your rectangle ... \n");
		outputRectangle (left, right, bottom, top);
		printf ("\n");
		printf ("Here are the statistics for your rectangle ...\n");
		printf ("Area = %i square units\n", area);
		printf ("Perimeter = %i units\n", perimeter);
		printf ("Diagonal Length = %0.2lf units\n\n", diagonalLength);
		
		
		system ("pause");
		system ("cls");
		// pause the program and clear the output screen
	}
	return 0;
	
}
