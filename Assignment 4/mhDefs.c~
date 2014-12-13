#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mhDefs.h"
/*
* Function: mh_init
* Purpose: 
*   Initialize the head, and set number of blocks
*   to zero.
* Params: HeapType *
* Return: void
*/
void mh_init(HeapType *heap){
  heap->head      = NULL;
  heap->numBlocks = 0;
}

/*
* Function: mh_cleanup
* Purpose:
*   Iterates through the LinkedList, and removes the address 
*   associated with it, and frees the block as well.
* UPDATE:
*   According to a forum post by Christine, mh_cleanup should
*   also free the node as well as the associated data.
* Therefore the only difference being that in mh_collect,
* the head is also reset.
* Params: HeapType *
* Return: void
*/
void mh_cleanup(HeapType *heap){
  if(heap->head == NULL) return;
  NodeType *currNode = heap->head;
  NodeType *temp = NULL;
  while(currNode != NULL) {
    temp = currNode;
    free(currNode->data->addr);
    free(currNode->data);
    free(currNode);

    currNode = temp->next;
  }
  heap->head = NULL;
  heap->numBlocks = 0;
}

/*
* Function: mh_alloc
* Purpose:  
*   Creates a block, and a node, defines the blocks members,
*   assigns the address to a void pointer with size n, 
*   and iterates to the end of the linked list to append the block
* Params: HeapType *, int, char *
* Return: void *
*/
void *mh_alloc(HeapType *heap, int n, char *label) {
  BlockType *b    = (BlockType *) malloc(sizeof(BlockType)); //create block pointer
  NodeType  *node = (NodeType *)  malloc(sizeof(NodeType));

  b -> addr = (void *) malloc(n);
  b -> size = n;
  b -> rsv = C_TRUE;

  strncpy(b->tag, label, MAX_STR);
  b->tag[MAX_STR-1] = '\0';

  node->data = b;
  node->next = NULL;

  if(heap->head == NULL) {
    heap->head = node;
  }
  else{ 
    NodeType *currNode = heap->head;
    while(currNode != NULL) {
        if(currNode -> next == NULL) {
          currNode->next = node;
          break;
        }
      currNode = currNode->next;
    }
  }
  heap->numBlocks++;
  return b->addr;
}

/*
* Function: mh_dealloc
* Purpose:
*   Iterates through linked list, finds address to remove,
*   and frees all information corresponding with the node
*   and connects the previous node to the next of the one
*   removed
* Params: HeapType *, void *
* Return: void
*/
void mh_dealloc(HeapType *heap, void *addr){
  if(heap->head == NULL) { return; }

  NodeType *curNode  = heap->head;
  NodeType *prevNode = NULL;


  while(curNode != NULL) {
    
    if(curNode->data->addr == addr) {
      if(prevNode != NULL) prevNode->next = curNode->next;
      if(curNode == (heap->head)){
        if((heap->head)->next == NULL)
          heap->head = NULL;
        else
          heap->head = (heap->head)->next;
      }
      heap->numBlocks--;

      free(addr);
      free(curNode->data);
      free(curNode);

      break;
    }
      prevNode = curNode;
      curNode = curNode->next;
  }
}

/*
* Function: mh_count
* Purpose:
*   Gets the sum of all reserved block's sizes
* Params: HeapType *
* Return: int
*/
int mh_count(HeapType *heap){
  if(heap->head == NULL) {return 0;}
  int c = 0;
  NodeType *currNode = heap->head;
  while(currNode != NULL ){
    if(currNode->data->rsv == C_TRUE)
      c += currNode->data->size;
    currNode = currNode->next;
  }
  return c;
}

/*
* Function: mh_dump
* Purpose: 
*   Prints the information corresponding to each 
*   reserved block
* Params: HeapType *
* Return: void
*/
void mh_dump(HeapType *heap){
  if(heap->head == NULL) return;
  NodeType *currNode = heap->head;

  while(currNode != NULL){
      printf("%*s:%*d bytes stored at %p\n",10,
                currNode->data->tag,
                20,
                currNode->data->size,
                currNode->data->addr
          );
    currNode = currNode->next;
  }
}

/*
* Function: mh_collect
* Purpose:
*   A garbage collection function that deallocates
*   all memory tracked in each node in the linked list.
* Params: HeapType *
* Return: void
*/
void mh_collect(HeapType *heap){
  if(heap->head == NULL) return;

  NodeType *currNode = heap->head;
  NodeType *temp = NULL;

  while(currNode != NULL){

    temp = currNode;
    free(currNode->data->addr);
    free(currNode->data);
    free(currNode);
    currNode = temp->next;
  }
  heap->head      = NULL;
  heap->numBlocks = 0;
}
