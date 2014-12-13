#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t05defs.h"

#define ARR_SIZE 2

typedef struct {
  StudentType **arr;
  int count;
  int capacity;
} StudentArray;

void initStuArray(StudentArray *);
void printArray(const StudentArray *);

/* Implement the following functions */
void growArray(StudentArray *);
void addStudent(StudentArray *, StudentType *);

int main(void) {
  int i;
  StudentType *matilda, *joe, *timmy;
  
  matilda = (StudentType *) calloc(1, sizeof(StudentType));
  joe = (StudentType *) calloc(1, sizeof(StudentType));
  timmy = (StudentType *) calloc(1, sizeof(StudentType));

  initStudent("Matilda", "Mallister", 22, "123444555",
              9.0, matilda);
  initStudent("Joe", "The Plumber", 24, "567888999",
              8.7, joe);
  initStudent("Timmy", "Tortoise", 99, "345667788",
              11.5, timmy); 
 
  StudentArray * comp2401 = (StudentArray *) calloc(1, sizeof(StudentArray));

  initStuArray(comp2401);

/*  Uncomment the following lines once addStudent is implemented  */

//  addStudent(comp2401, matilda);
//  addStudent(comp2401, joe);
//  addStudent(comp2401, timmy);

  printArray(comp2401);

  free(comp2401->arr);
  free(comp2401);

  return 0;
}

void initStuArray(StudentArray *stuArray) {
  stuArray->count = 0;
  stuArray->capacity = ARR_SIZE;
  stuArray->arr = (StudentType **) calloc(stuArray->capacity, sizeof(StudentType *));
}

/*   Function:  growArray                                   */
/*         in:  Location of StudentArray to be modified     */
/*        out:  Modified StudentArray                       */
/*    Purpose:  double the size of stuArray->arr            */
void growArray(StudentArray * stuArray) {
}

/*   Function:  addStudent                                  */
/*         in:  Location of StudentArray to be modified     */
/*         in:  Location of StudentType to be added         */
/*        out:  StudentArray with added StudentType         */
/*    Purpose:  adds stu to stuArray->arr; if stuArray->arr */
/*              is full, grow it then add stu.              */
void addStudent(StudentArray * stuArray, StudentType * stu) {
}

void printArray(const StudentArray * stuArray) {
  int i;

  printf("StudentArray\n");
  printf("Capacity: %d\n", stuArray->capacity);
  printf("Count:    %d\n", stuArray->count);
  printf("Students:\n");
  
  for (i = 0; i < stuArray->count; i++) {
    printStudent( stuArray->arr[i] );
  }
}
