#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int loot(int houses[],int start,int end)//house array, start@(inclusive),end@(non inclusive)
{
    int money,maxmoney,i,num=end-start;

    if (num<=0)
    {
        return 0;
    }
    else if (num==1)
    {
        money=houses[start];
        maxmoney=money;
        return maxmoney;
    }
    else if (num==2)
    {
        money=max(houses[start],houses[start+1]);
        maxmoney=money;
        return maxmoney;
    }
    else
    {   maxmoney=0;
        for(i=start;i<end-1;i++)//for houses[i+1 to exist],max value of i is end-2
        {
            money=max(houses[i]+loot(houses,i+2,end),houses[i+1]+loot(houses,i+3,end));
            if (money>maxmoney)
            maxmoney=money;
        }
        return maxmoney;
    }
    
}

int main()
{
    int n[]={3,9,4,2,8};
    int end=sizeof(n)/sizeof(n[0]);
    printf("%d",loot(n,0,end));
}