#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
struct node *loopremove(struct node *head, int length)
{
    struct node *pointerlist[length];
    for (int i = 0; i < length; i++)
        pointerlist[i] = NULL;
    int n = length;
    struct node *temp;
    int count = 0;
    temp = head;
    int flag = 0;
    int loopstart = 0;
    int loopend = 0;
    int flag2 = 0;
    while (1)
    {
        if (temp == NULL)
        {
            flag2 = 1;
            printf("h\n");
            break;
        }
        for (int j = 0; j < count; j++)
        {
            if (pointerlist[j] == temp)
            {
                flag = 1;
                loopend = j;
                break;
            }
        }
        if (flag)
        {
            printf("Loopback detected: %d -> %d\n", count - 1, loopend);
            loopstart = count;
            break;
        }
        pointerlist[count] = temp;
        temp = temp->nextptr;
        if (temp == NULL)
            break;
        count++;
    }
    if (flag2)
    {
        printf("No loopbacks detected.\n");
    }
    else
    {
        temp = head;
        for (int q = 0; q < n - 1; q++)
            temp = temp->nextptr;
        temp->nextptr = NULL;
    }
    temp = head;
    return temp;
}

int main()
{
    struct node *head;
    head = NULL;
    printf("No. of elements: ");
    int n, x, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Element #%d: ", i);
        scanf("%d", &x);
        head = insert(head, -1, x);
    }
    int a;
    printf("Last node points to: ");
    scanf("%d", &a);
    element(head, n - 1)->nextptr = element(head, a);
    loopremove(head, n);
    struct node *temp;
    temp = head;
    while (1)
    {
        if (temp == NULL)
            break;
        printf("%d ", temp->num);
        temp = temp->nextptr;
    }
}