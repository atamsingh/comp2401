#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100
#define MAX_COMPS 100
/*
* Assignment 2
* Seena Rowhani
* =============
* You will write a program in C, in the Ubuntu Linux environment, to help the user compute their final grade in a course, 
* based on multiple weighting schemes. Your program will prompt the user to enter the major course components. 
* These are the items that are given weights in the course outline, for example Assignments, Tutorials, Tests, Final 
* exam, etc. Then your program will prompt the user to enter some weighting schemes, with one value for each course 
* component. For example, one weighting scheme could have 50% for Assignments, 10% for Tutorials and 40% for the 
* Final exam. Another weighting scheme could weigh the Assignments at 40% and the Final exam at 60%. Finally, your 
* program will prompt the user to enter the grade they received for each component, and print out the final grade the 
* user would get based on each weighting scheme
*
*/

/*
* struct Course
* Members:
* 	components        - two dimensional array of characters repr course names.
* 	schemes           - two dimensional array of floats for grade scheme
* 	numComponents     - int repr number of componenets
* 	numMarkingSchemes - int number of marking schemes
*/

typedef struct{
	char components[MAX_COMPS][MAX_STR];
	float  schemes[MAX_COMPS][MAX_COMPS];
	int  numComponents; 
	int  numMarkingSchemes;
} Course;

//Declare my functions
void initCourse(Course **);
void setNumberComponents(Course *);
void setComponents(Course *, int);
void setNumberMarkingSchemes(Course *);
void setMarkingSchemes(Course *,int);
void computeMarks(const Course *);

/*
* int main:
* Returns 0 if program properly runs
* Creates pointer to Course struct, initializes it, and computes the marks.
* @param argc    - number of command line arguments
* @param *argv[] - command line args
*/
int main(int argc, char* argv[]){
	Course *course;
	initCourse(&course);
	computeMarks(course);
	free(course);
	return 0;
}
/*
* void initCourse:
* Initializes the Course structure.
* Allocates size
* Sets properties
*/
void initCourse(Course **course){
	*course = (Course *) malloc(sizeof(Course));
	setNumberComponents(*course);
	setComponents(*course, (*course)->numComponents);
	setNumberMarkingSchemes(*course);
	setMarkingSchemes(*course, (*course)->numMarkingSchemes);
}
/*
* void setNumberComponents
* Sets the number of components for the course
*/
void setNumberComponents(Course *c){
	char str[8]; //bucket string
	do{
		printf("\nHow many marking components in the course? ");

		fgets(str, sizeof(str), stdin); //read 8 characters from stdin buffer
		sscanf(str, "%d", &(c->numComponents)); //scans string for integer
		if( (c->numComponents) == 0 ) //error checking
			printf("\t[Invalid Input] Try again!\n");

	}while( (c->numComponents) == 0 ); //continue if error
}
/*
* void setComponents
* Prompts user to enter component names
* @param *c - Pointer to a Course struct
* @param n  - Integer repre number of components
*/
void setComponents(Course *c, int n){
	int i;
	char str[MAX_STR];
	for(i = 0 ; i < n ; i++){
		printf("\tenter next component name: ");
		fgets(str, sizeof(str), stdin); //read buffer of max string
		sscanf(str, "%s", c->components[i]); //scans string for string
	}
}
/*
* void setNumberMarkingSchemes
* @param *c - Pointer to course struct
*/
void setNumberMarkingSchemes(Course *c){
	char str[8];

	do{
		printf("\nHow many marking schemes? ");
		fgets(str, sizeof(str), stdin); //gets string
		sscanf(str, "%d", &(c->numMarkingSchemes)); //scans string for int
		if( (c->numMarkingSchemes) == 0 ) //condition for error check
			printf("\t[Invalid Input] Try again!\n"); //prints error
	}while( (c->numMarkingSchemes) == 0 ); //continue if error
}
/*
* void setMarkingSchemes
* Sets the marking scheme
* BONUS:=====
* Included the sum printed per iteration to assist user when inputting
* weight values. :)
* @param *c  - Pointer to a course struct
*/
void setMarkingSchemes(Course *c, int n){
	int i;
	int j;
	float sum = 0;
	char  str[8];
		for(j = 0 ; j < n ; j++){
			do{
				sum = 0;
				printf("\nMarking scheme #%d:\n",(j+1));
				for(i = 0 ; i < c->numComponents ; i++){
					do{
						printf("(%.2f/100.00)\tEnter %s's weight: ", sum, c->components[i]);	
						fgets(str, sizeof(str), stdin);
						sscanf(str, "%f", &(c->schemes[j][i]));
						if((c->schemes[j][i]) < 0)
							printf("[Not a valid number] Try again.\n");
					}while( (c->schemes[j][i]) < 0); //error checking number is valid
					sum += (c -> schemes[j][i]);
				}
				if(sum != 100)
					printf("values do not add up to 100!\tTry again...\n"); //error check if number doesnt add to 100
			}while(sum != 100); //continue
		}
}
/*
* void computeMarks
* Prints the marks in accordance to each grading scheme.
* Had it so that it allowed for bonus marks, but was recommended
* not to by TA.
* @param *c - Constant pointer to a struct. No modifications are made
*/
void computeMarks(const Course *c){
	int i;
	char str[8];
	float grades[c->numComponents];

	for(i = 0 ; i < (c->numComponents) ; i++){
		do{
			printf("Enter your %s's mark: ", (c->components[i]));
			fgets(str, sizeof(str), stdin);
			sscanf(str, "%f", &grades[i]);
			if(grades[i] < 0 || grades[i] > 100)
				printf("\n[Grade is not in valid range (0-100)] Try again.\n");
		}while(grades[i] < 0 || grades[i] > 100);
		
	}
	printf("\n");
	i = 0;
	for(i = 0 ; i < (c->numMarkingSchemes) ; i++){
		float grade = 0;
		int j;
		for(j = 0 ; j < c->numComponents ; j++)
			grade += ( ( grades[j] / 100.0) * (c->schemes[i][j]) );
		printf("Grade using marking scheme #%d:\t%.2f\n", (i+1), grade);
	}
	printf("\n");
}
