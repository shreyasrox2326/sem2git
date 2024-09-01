#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int * arr;
    int size;
}q;

int occupied(struct stack *s)
{
    int count=0;
    while (1)
    {
        if (s->arr[count]==0)
        break;
        if (count==s->size)
        break;
        count++;
    }
    return count;
}

int peek(struct stack *s,int depth)
{
    if (depth>=s->size) return 0;
    if (depth>=occupied(s)) return 0;
    return(s->arr[occupied(s)-1-depth]);
}
int overflow(struct stack *s)
{
    if (s->arr[s->size-1]==0) return 0;
    else return 1;
}
int underflow(struct stack *s)
{
    if (s->arr[0]==0) return 1;
    else return 0;
}
int pop(struct stack *s)
{
    int x = peek(s,0);
    s->arr[occupied(s)-1]=0;
    return x;
}

int push(struct stack *s, int value)
{
    if (overflow(s))  return 0;
    int count=0;
    while(1)
    {
        if (s->arr[count]==0)
        {
            s->arr[count]=value;
            return 1;
        }
        else
        count++;
    }
}
void printstack(struct stack* s)
{
    printf("Top -> ");
    for(int i=0;i<s->size;i++)
    {
        if (s->arr[(s->size)-1-i]==0)
        printf("_ ");
        else
        printf("%d ",s->arr[(s->size)-1-i]);
    }
    printf("\n");
}

void init(struct stack *s)
{
    for(int i=0;i<s->size;i++)
    {
        s->arr[i]=0;
    }
}
int main()
{
    struct stack a;
    a.size=20;
    init(&a);
    
   
}