#include <stdio.h>
// autotype using https://www.askpython.com/python/examples/auto-type-text-using-python
int fact(int n)
{   int fact=1,i=1;
    do
    {
        fact*=i;
        i++;
    }
    while (i<=n);
    return(fact);
}
int  ** ncr(int n,int r)
{
    if(r==0)
    {
        int p=-1;
        int *q=&p;
        int **r=&q;
        return r;
    }
    else if(r==n)
    {
        int * lista;
        for (int i=1;i<n+1;i++)
        {
            int *p=&i;
            lista[i]=*p;
        }
        int **listb=&lista;
        return listb;
    }
    else
    {
        int ** templist;
        for(int i=1;i<n-r+2;i++)
        {
            int ** temp= ncr(n-1,r-1);
            int nchooser=fact(n-1)/(fact(r-1)*fact(n-r));
            for(int j=0;j<nchooser;j++)
            {
                int flag=1,count=0;
                for(int k=0;k<r-1;k++)
                {
                    (** (temp + (j*(r-1) + k)))++;
                    if ((** (temp + (j*(r-1) + k)))>n)
                    flag=0;
                }
                if (flag)
                {
                    for(int k=0;k<r-1;k++)
                    {
                        **(templist+count)=**(temp + (j*(r-1) + k));
                        count++;
                    }
                }
            }
        }
        return templist;
    }
}

int main()
{
    int n=4,r=2;
    printf("heklo");
}