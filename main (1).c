#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
/*
// Structure for a node in a linked list
struct node {
    int num;                // Data of the node
    struct node *nextptr;   // Address of the next node
} *stnode;                  // Pointer to the starting node
*/
void printreverse(struct node* pointer)
{
    if (pointer->nextptr==NULL)//true if pointer is at last node
    {
        printf("%d ",pointer->num);
        return;
    }
    printreverse(pointer->nextptr);//calls function for next node
    printf("%d ",pointer->num);
    return;
}

// Main function
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);
    
    int x;
    struct node * linkedlist=NULL;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        linkedlist=insert(linkedlist,-1,x);
    }
    printreverse(linkedlist);
    return 0;
}
