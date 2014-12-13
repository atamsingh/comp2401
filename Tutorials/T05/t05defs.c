#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t05defs.h"

void printStudent(const StudentType *stu)
{
  printf("Here's %s! %s %s is this smart: %.1f\n",
         stu->basicInfo.first, 
         stu->basicInfo.first, stu->basicInfo.last,
         stu->gpa);
}

void initStudent(char *f, char *l, int a,
                 char *n, float g, StudentType *stuPtr)
{
  strcpy(stuPtr->basicInfo.first, f);
  strcpy(stuPtr->basicInfo.last, l);
  stuPtr->basicInfo.age = a;
  strcpy(stuPtr->stuNumber, n);
  stuPtr->gpa = g;
}

