#include <stdlib.h>
#include <stdio.h>
#include "stuDefs.h"
#include "mhDefs.h"

/*
* Function: main
* Purpose:
*   Testing functionality
* Params: int argc, char* argv[]
* Return: int
*/
int main()
{
  HeapType  *heap;
  void      *ptr1, 
            *ptr2, 
            *ptr3, 
            *ptr4,
            *ptr5,
            *ptr6,
            *ptr7,
            *ptr8,
            *ptr9,
            *ptr10;

  heap = (HeapType *) malloc(sizeof(HeapType));
  mh_init(heap);

  ptr1 = mh_alloc(heap, 5*sizeof(int), "ints");
  ptr2 = mh_alloc(heap, 10*sizeof(double), "doubles");
  ptr3 = mh_alloc(heap, 8*sizeof(char), "chars");
  ptr4 = mh_alloc(heap, 12*sizeof(StudentType), "Students");

  printf("\nDUMP 1, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_dealloc(heap, ptr1);
  mh_dealloc(heap, ptr2);
  mh_dealloc(heap, ptr3);

  printf("\nDUMP 2, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_collect(heap);

  printf("\nDUMP 3, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  printf("\n\n");

  ptr5 = mh_alloc(heap, sizeof(long), "long");
  printf("\nDUMP 4, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_dealloc(heap, ptr5);
  mh_collect(heap);
  printf("\nDUMP 5, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  ptr6 = mh_alloc(heap, 10*sizeof(float), "float");
  printf("\nDUMP 6, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_dealloc(heap, ptr6);
  printf("\nDUMP 7, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  ptr7 = mh_alloc(heap, 10*sizeof(short), "short");
  printf("\nDUMP 8, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_dealloc(heap, ptr7);
  printf("\nDUMP 9, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  ptr8 = mh_alloc(heap, 2*sizeof(A), "A");
  printf("\nDUMP 10, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_dealloc(heap, ptr8);
  printf("\nDUMP 11, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  ptr9 = mh_alloc(heap, 3 * sizeof(B), "B");
  printf("\nDUMP 12, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  mh_dealloc(heap, ptr9);
  printf("\nDUMP 13, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  mh_collect(heap);  
  ptr10=mh_alloc(heap, 4 * sizeof(C), "C");
  printf("\nDUMP 14, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  mh_dealloc(heap, ptr10);
  printf("\nDUMP 15, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  mh_collect(heap);  

  mh_cleanup(heap);
  free(heap);

  return 0;
}
