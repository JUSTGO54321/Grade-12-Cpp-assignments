#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MPW_LT 0
#define MPW_RT 800
#define MPW_BOT 0
#define MPW_TOP 600

#define RECT_NAME_CHARS 5
#define RECT_MIN_NAME_CHAR 'a'
#define RECT_MAX_NAME_CHAR 'd'

#define MAX_RECTS 200
#define MAX_U_I 500

typedef struct {
	int lt, rt, bot, top;
	char name[RECT_NAME_CHARS + 1];
	int area, perimeter;
} rectType;

typedef struct {
	rectType r1, r2;
	rectType unionRect;
	rectType sectRect;
	int intersection;	// 0 means no intersection, 1 means intersection
} rectMathType;

int rb (int min, int max){
	return rand() % (max - min + 1) + min;
}

int isDuplicate (rectType *r, char *s, int n){

	for (int i = 0; i < n; i++){
		if (strcmp(r[i].name, s) == 0){
			return 1;
		}
	}
	return 0;
}

void insertRectangle (rectType *rect, rectType temp, int n){
	
	int insertPos = 0;
	
	for (int i = 0; i <= n; i++){
		if (strcmp(rect[i].name, temp.name) > 0 || strlen(rect[i].name) == 0){
			insertPos = i;
			break;
		}
	}                     
	for (int i = n + 1; i >= insertPos; i--){
		rect[i] = rect[i - 1];
	}
	rect[insertPos] = temp;
	
}

void aAndP (rectType *rect){
	rect->area = (rect->rt - rect->lt) * (rect->top - rect->bot);
	rect->perimeter = 2 * ((rect->rt - rect->lt) + (rect->top - rect->bot));
}

void getRect (rectType *rect, int n){
	
	int i = 0;
	int invalid = 0;
	rectType temp;
	
	do{
		fflush(stdin);
		printf ("Enter the name of the rectangle: ");
		gets(temp.name);
		
		invalid = 0;
		if (strlen(temp.name) < 1 || strlen(temp.name) > RECT_NAME_CHARS || isDuplicate(rect, temp.name, n)){
			printf ("INVALID INPUT\n");
			invalid = 1;
		}
		
		i = 0;
		while (temp.name[i] && invalid == 0){
			if (temp.name[i] < RECT_MIN_NAME_CHAR || temp.name[i] > RECT_MAX_NAME_CHAR){
				printf ("INVALID INPUT\n");
				invalid = 1;
			}
			i++;
		}
	
	} while (invalid);
	
	do{
		printf ("Enter the left side: ");
		fflush(stdin);
		scanf ("%i", &temp.lt);
		
		if (temp.lt < MPW_LT || temp.lt >= MPW_RT){
			printf ("INVALID INPUT\n");
		}
		
	} while (temp.lt < MPW_LT || temp.lt >= MPW_RT);
	
	do{
		printf ("Enter the right side: ");
		fflush(stdin);
		scanf ("%i", &temp.rt);
		
		if (temp.rt <= temp.lt || temp.rt > MPW_RT){
			printf ("INVALID INPUT\n");
		}
		
	} while (temp.rt <= temp.lt || temp.rt > MPW_RT);
	
	do{
		printf ("Enter the bottom side: ");
		fflush(stdin);
		scanf ("%i", &temp.bot);
		
		if (temp.bot < MPW_BOT || temp.bot >= MPW_TOP){
			printf ("INVALID INPUT\n");
		}
		
	} while (temp.bot < MPW_BOT || temp.bot >= MPW_TOP);
	
	do{
		printf ("Enter the top side: ");
		fflush(stdin);
		scanf ("%i", &temp.top);
		
		if (temp.top <= temp.bot || temp.top > MPW_TOP){
			printf ("INVALID INPUT\n");
		}
		
	} while (temp.top <= temp.bot || temp.top > MPW_TOP);
	
	aAndP(&temp);
	printf ("YOUR RECTANGLE HAS BEEN STORED...\n\n");
	
	insertRectangle(rect, temp, n);

}

void randRect (rectType *rect, int n){
	
	int numCharName;
	rectType temp;
	
	do{
		numCharName = rb(1, RECT_NAME_CHARS);
		for (int i = 0; i < numCharName; i++){
			temp.name[i] = rb(RECT_MIN_NAME_CHAR, RECT_MAX_NAME_CHAR);
		}
		temp.name[numCharName] = 0;
	} while (isDuplicate(rect, temp.name, n));
	
	temp.lt = rb(MPW_LT, MPW_RT - 1);
	temp.rt = rb(temp.lt + 1, MPW_RT);
	temp.bot = rb(MPW_BOT, MPW_TOP - 1);
	temp.top = rb(temp.bot + 1, MPW_TOP);
	aAndP(&temp);

	insertRectangle(rect, temp, n);

	printf ("YOUR RANDOM RECTANGLE HAS BEEN STORED...\n\n");
}

void findRect (rectType *rect, int n){
	
	char name[10];
	
	printf ("Enter the name of the rectangle you want to find: ");
	fflush(stdin);
    gets(name);

	
	for (int i = 0; i < n; i++){
		if (strcmp(name, rect[i].name) == 0){
			printf ("\nRECTANGLE HAS BEEN FOUND...\n\n");
			printf ("%10s%10s%10s%10s%10s%10s%10s\n", "NAME", "LEFT", "RIGHT", "BOTTOM", "TOP", "AREA", "PERIMETER");
			printf ("%10s%10i%10i%10i%10i%10i%10i\n\n", rect[i].name, rect[i].lt, rect[i].rt, rect[i].bot, rect[i].top, rect[i].area, rect[i].perimeter);
			break;
		}
		else if (i == n - 1){
			printf ("ERROR 404 RECTANGLE NOT FOUND...\n\n");
		}
	}
}

void deleteRect (rectType *rect, int n){
	
	char name[10];
	
	printf ("Enter the name of the rectangle you want to delete: ");
    fflush(stdin);
	gets(name);

	
	for (int i = 0; i < n; i++){
		if (strcmp(name, rect[i].name) == 0){
			for (int j = i; j < n; j++){
				rect[j] = rect[j + 1];
			}
			printf ("RECTANGLE '%s' HAS BEEN DELETED...\n\n", name);
			break;
		}
		else if (i == n - 1){
			printf ("ERROR 404 RECTANGLE NOT FOUND...\n\n");
		}
	}
}

void findUnionIntersection (rectType *rect, int nRect, rectMathType *rectMath, int nMath){
	
	rectMathType temp;
	int random1;
	int random2;
	int invalid1 = 0;
	int invalid2 = 0;
	//unionRect
	do{
		random1 = rb(0, nRect - 1);
		random2 = rb(0, nRect - 1);	
		
		if (random1 < random2){
			temp.r1 = rect[random1];
			temp.r2 = rect[random2];
		}
		else{
			temp.r1 = rect[random2];
			temp.r2 = rect[random1];
		}	
		
		invalid1 = 0;
		invalid2 = 0;
		int l = 0;
		
		for (int i = 0; i < nMath; i++){
			if (strcmp(rectMath[i].r1.name, temp.r1.name) == 0){
				invalid1 = 1;
				l = i;
				while (strcmp(rectMath[l].r1.name, temp.r1.name) == 0){
					if (strcmp(rectMath[l].r1.name, temp.r1.name) != 0){
						break;
					} 
					else{
						l++;	
					}
				}
				for (i; i < l; i++){
					if (strcmp(rectMath[i].r2.name, temp.r2.name) == 0){
						invalid2 = 1;
						break;
					}
				}
				break;
			}
		}
		
	} while(invalid1 && invalid2);
	
	if (temp.r1.lt < temp.r2.lt){
		temp.unionRect.lt = temp.r1.lt;
	}
	else{
		temp.unionRect.lt = temp.r2.lt;
	}
	
	if (temp.r1.rt > temp.r2.rt){
		temp.unionRect.rt = temp.r1.rt;
	}
	else{
		temp.unionRect.rt = temp.r2.rt;
	}
	
	if (temp.r1.bot < temp.r2.bot){
		temp.unionRect.bot = temp.r1.bot;
	}
	else{
		temp.unionRect.bot = temp.r2.bot;
	}
	
	if (temp.r1.top > temp.r2.top){
		temp.unionRect.top = temp.r1.top;
	}
	else{
		temp.unionRect.top = temp.r2.top;
	}
	
	aAndP(&temp.unionRect);	
	
	//intersectionRect
	if (temp.r1.lt < temp.r2.rt && temp.r1.rt > temp.r2.lt && temp.r1.top > temp.r2.bot && temp.r1.bot < temp.r2.top){
		temp.intersection = 1;
		if (temp.r1.top < temp.r2.top){
			temp.sectRect.top = temp.r1.top;
			temp.sectRect.bot = temp.r2.bot;
		}
		else {
			temp.sectRect.top = temp.r2.top;
			temp.sectRect.bot = temp.r1.bot;	
		}
		
		if (temp.r1.lt < temp.r2.lt){
			temp.sectRect.lt = temp.r1.lt;
			temp.sectRect.rt = temp.r2.rt;
		}
		else{
			temp.sectRect.lt = temp.r2.lt;
			temp.sectRect.rt = temp.r1.rt;
		}
	}
	else {
		temp.intersection = 0;
		temp.sectRect.top = 0;
		temp.sectRect.bot = 0;
		temp.sectRect.lt = 0;
		temp.sectRect.rt = 0;
	}
	
	aAndP(&temp.sectRect);
	
	int i = 0;
	for (i = 0; i < nMath; i++){
		if (strcmp(rectMath[i].r1.name, temp.r1.name) >= 0 || strlen(rectMath[i].r1.name) == 0){
			break;
		}
	}
			
	int j = i;
	if (strlen(rectMath[i].r1.name) == 0){
		rectMath[i] = temp;
	}
	else if (strcmp(rectMath[j].r1.name, temp.r1.name) > 0){
		for (int k = nMath; k >= i; k--){
			rectMath[k] = rectMath[k - 1];
		}
		rectMath[i] = temp;
	}
	else{
		while (strcmp(rectMath[j].r1.name, temp.r1.name) == 0){
			if (strcmp(rectMath[j].r1.name, temp.r1.name) != 0){
				break;
			} 
			else{
				j++;	
			}
		}
		for (i; i < j; i++){
			if (strcmp(rectMath[i].r2.name, temp.r2.name) > 0){
				break;
			}
		}
		for (int k = nMath; k >= i; k--){
			rectMath[k] = rectMath[k - 1];
		}
		rectMath[i] = temp;
	}
	
	printf ("YOUR UNION AND INTERSECTION RECTANGLES HAVE BEEN STORED...\n\n");
	
}

void outputRects (rectType *rect, int n){
	
	printf ("%10s%10s%10s%10s%10s%10s%10s\n", "NAME", "LEFT", "RIGHT", "BOTTOM", "TOP", "AREA", "PERIMETER");
	for (int i = 0; i < n; i++){
		printf ("%10s%10i%10i%10i%10i%10i%10i\n", rect[i].name, rect[i].lt, rect[i].rt, rect[i].bot, rect[i].top, rect[i].area, rect[i].perimeter);
	}
    printf ("\n");
}

void outputUnionIntersection (rectMathType *rect, int n){
	
	char unionRect[50];
	char sectRect[50];
	
	printf ("%30s%10s%10s%10s%10s%10s%10s\n", "NAME", "LEFT", "RIGHT", "BOTTOM", "TOP", "AREA", "PERIMETER");
	for (int i = 0; i < n; i++){
		printf ("%30s%10i%10i%10i%10i%10i%10i\n", rect[i].r1.name, rect[i].r1.lt, rect[i].r1.rt, rect[i].r1.bot, rect[i].r1.top, rect[i].r1.area, rect[i].r1.perimeter);
		printf ("%30s%10i%10i%10i%10i%10i%10i\n", rect[i].r2.name, rect[i].r2.lt, rect[i].r2.rt, rect[i].r2.bot, rect[i].r2.top, rect[i].r2.area, rect[i].r2.perimeter);
		sprintf (unionRect, "%s union %s", rect[i].r1.name, rect[i].r2.name);
		printf ("%30s%10i%10i%10i%10i%10i%10i\n", unionRect, rect[i].unionRect.lt, rect[i].unionRect.rt, rect[i].unionRect.bot, rect[i].unionRect.top, rect[i].unionRect.area, rect[i].unionRect.perimeter);
		sprintf (sectRect, "%s intersection %s", rect[i].r1.name, rect[i].r2.name);
		printf ("%30s%10i%10i%10i%10i%10i%10i\n\n", sectRect, rect[i].sectRect.lt, rect[i].sectRect.rt, rect[i].sectRect.bot, rect[i].sectRect.top, rect[i].sectRect.area, rect[i].sectRect.perimeter);
	}
}

int main (){
	
	rectType myRects[MAX_RECTS];
	rectMathType rectMath[MAX_U_I];
	int numRects = 0;	
	int numUnionIntersections = 0;	
	int menu = 0;
	
	srand(time(NULL));
	
	while (1){
		
		if (numRects == MAX_RECTS){
			
			printf ("==================================\nYou have reached the maximum stored rectangles\n\nRectangle Program Menu Options\n\n");
			printf ("3. Find Rectangle\n4. Delete Rectangle\n5. Find Union and Intersection of Two Rectangles\n6. Output Rectangles\n7. Output Union and Intersection Stats\n8. Quit\n");
			printf ("\nChoose an option: ");
			fflush(stdin);
			scanf ("%i", &menu);
			printf ("==================================\n\n");
			
			switch (menu){
		
				case 3:
					if (numRects == 0){
						printf ("NO STORED RECTANGLES...\n\n");
					}
					else{
						findRect(myRects, numRects);
					}
					break;
				
				case 4:
					if (numRects == 0){
						printf ("NO STORED RECTANGLES...\n\n");
					}
					else{
						deleteRect(myRects, numRects);
                        numRects--;
					}
					break;
				
				case 5:
					if (numRects < 2){
						printf ("NOT ENOUGH RECTANGLES STORED...\n\n");
					}
					else if (numUnionIntersections == (numRects * (numRects + 1)) / 2){
						printf ("MAX UNION AND INTERSECTION RECTANGLES STORED...\n\n");
					}
					else{
						findUnionIntersection(myRects, numRects, rectMath, numUnionIntersections);
                        numUnionIntersections++;
					}
					break;
				
				case 6:
					if (numRects == 0){
						printf ("NO STORED RECTANGLES...\n\n");
					}
					else{
						outputRects(myRects, numRects);
					}
					break;
				
                case 7:
                    if (numUnionIntersections == 0){
                        printf ("NO UNIONS OR INTERSECTIONS STORED...\n\n");
                    }
                    else{
                        outputUnionIntersection(rectMath, numUnionIntersections);
                    }
                    break;
				case 8:
					printf ("QUITTING PROGRAM...\n");
					exit(0);
					break;
				
				default:
					printf ("INVALID INPUT\n\n");
			}
		}
		else{
			
			printf ("==================================\nRectangle Program Menu Options\n\n");
			printf ("1. Insert User Rectangle\n2. Insert Random Rectangle\n3. Find Rectangle\n4. Delete Rectangle\n5. Find Union and Intersection of Two Rectangles\n6. Output Rectangles\n7. Output Union and Intersection Stats\n8. Quit\n");
			printf ("\nChoose an option: ");
			fflush(stdin);
			scanf ("%i", &menu);

			printf ("==================================\n\n");
			
			switch (menu){
			
				case 1:
					getRect(myRects, numRects);
					numRects++;
					break;
				
				case 2:
					randRect(myRects, numRects);
					numRects++;
					break;
				
				case 3:
					if (numRects == 0){
						printf ("NO STORED RECTANGLES...\n\n");
					}
					else{
						findRect(myRects, numRects);
					}
					break;
				
				case 4:
					if (numRects == 0){
						printf ("NO STORED RECTANGLES...\n\n");
					}
					else{
						deleteRect(myRects, numRects);
                        numRects--;
					}
					break;
				
				case 5:
					if (numRects < 2){
						printf ("NOT ENOUGH RECTANGLES STORED...\n\n");
					}
					else if (numUnionIntersections == (numRects * (numRects + 1)) / 2){
						printf ("MAX UNION AND INTERSECTION RECTANGLES STORED...\n\n");
					}
					else{
						findUnionIntersection(myRects, numRects, rectMath, numUnionIntersections);
                        numUnionIntersections++;
					}
					break;
				
				case 6:
					if (numRects == 0){
						printf ("NO STORED RECTANGLES...\n\n");
					}
					else{
						outputRects(myRects, numRects);
					}
					break;
				
                case 7:
                    if (numUnionIntersections == 0){
                        printf ("NO UNIONS OR INTERSECTIONS STORED...\n\n");
                    }
                    else{
                        outputUnionIntersection(rectMath, numUnionIntersections);
                    }
                    break;
				case 8:
					printf ("QUITTING PROGRAM...\n");
					exit(0);
					break;
				
				default:
					printf ("INVALID INPUT\n\n");
			}	
		}		
	}	
}
