#include <stdio.h>
#include <stdlib.h>

// Structure for a Node in a linked list
struct Node 
{
    int num;                // Data of the node
    struct Node *next;   // Address of the next node
};


struct Node* insert(struct Node * head,int position,int val)//insert Node into linked list, return head pointer
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node * head2=(struct Node *)malloc(sizeof(struct Node));
    head2=head;
    newnode->num = val;
    newnode->next= NULL;
    if (head==NULL||position==0)//when Node is inserted at starting (0th) position
    {
        newnode->next=head;
        return  newnode;
    }
    else if (position==-1)//when Node is inserted at last position in the list
    {
        while(1)
        {
            if(head->next == NULL )
            break;
            head = head->next;
        }
        head->next = newnode;
        return head2;
    }
    else//node is inserted in the middle
    {
        for(int i=0;i<position-1;i++)
        {
            
            if (head->next==NULL)
            {
                printf("Invalid index. Node could not be created.\n");
                return head2;
            }
            head=head->next;
        }
        newnode->next=head->next;
        head->next=newnode;
        return head2;
    }
}
int len(struct Node * head)//returns length of linked list
{
    if (head==NULL)
    {
        return 0;
    }
    else
    {
        int count=0;
        while(1)
        {
            if (head==NULL)
            {
                return count;
            }
            count++;
            head=head->next;
        }
    }
}

struct Node * element(struct Node * head, int index)//function to return pointer to element of a linked list at a particular position
{
    int LLen;
    LLen=len(head);
    if (index<LLen && index>=LLen*(-1))
    {
        if (index>=0)
        index=index;
        else
        index=LLen+index;
        {
            struct Node * temp;
            temp=head;
            for (int i=0;i<index;i++)
            {
                temp=temp->next;

            }
            return temp;
        }
    }
    else
    {
        printf("Invalid index. Len=%d\n",LLen);
        return 0;
    }
}