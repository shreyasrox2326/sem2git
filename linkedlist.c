#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node 
{
    int num;                // Data of the node
    struct node *nextptr;   // Address of the next node
};


struct node* insert(struct node * head,int position,int val)//insert node into linked list, return head pointer
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node * head2=(struct node *)malloc(sizeof(struct node));
    head2=head;
    newnode->num = val;
    newnode->nextptr= NULL;
    if (head==NULL||position==0)//when node is inserted at starting (0th) position
    {
        newnode->nextptr=head;
        return  newnode;
    }
    else if (position==-1)//when node is inserted at last position in the list
    {
        while(1)
        {
            if(head->nextptr == NULL )
            break;
            head = head->nextptr;
        }
        head->nextptr = newnode;
        return head2;
    }
    else//node is inserted in the middle
    {
        for(int i=0;i<position-1;i++)
        {
            
            if (head->nextptr==NULL)
            {
                printf("Invalid index. Node could not be created.\n");
                return head2;
            }
            head=head->nextptr;
        }
        newnode->nextptr=head->nextptr;
        head->nextptr=newnode;
        return head2;
    }
}
int len(struct node * head)//returns length of linked list
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
            head=head->nextptr;
        }
    }
}

int element(struct node * head, int index)//function to return element of a linked list at a particular position
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
            struct node * temp;
            temp=head;
            for (int i=0;i<index;i++)
            {
                temp=temp->nextptr;

            }
            return(temp->num);
        }
    }
    else
    {
        printf("Invalid index. Len=%d\n",LLen);
        return 0;
    }
}

int main()
{
    struct node * head=NULL;
    head=insert(head,-1,314);
    head=insert(head,-1,324);
    head=insert(head,-1,343);
    head=insert(head,-1,344);
    printf("%d=len/\n",len(head));
    printf("%d ",element(head,-4));
    printf("%d ",element(head,-3));
    printf("%d ",element(head,-2));
    printf("%d ",element(head,-1));
    printf("%d ",element(head,-5));

}