#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
    int num;                // Data of the node
    struct node *nextptr;   // Address of the next node
} *stnode;                  // Pointer to the starting node




// Main function
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);
    
    int array[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printreverse(createNode(n,array));
    return 0;
}
struct node* createNode(int n,int array[])
{
    struct node *a = (struct node*)malloc(sizeof(struct node));
    a->num = array[n-1];
    a->nextptr = NULL;
    struct node *x = a;
    int i;
    for (i=n-2;i>=0;i--)
    {
        struct node *b = (struct node*)malloc(sizeof(struct node));
        b->num = array[i];
        b->nextptr = x;
        x = b;
    }
    return x;
}
void printreverse(struct node* pointer)
{
    if (pointer->nextptr==NULL)
    {
        printf("%d ",pointer->num);
        return;
    }
    printreverse(pointer->nextptr);
    printf("%d ",pointer->num);
    return;
}