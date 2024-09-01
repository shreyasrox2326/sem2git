
def ncr(n,r):
    if r==0:
        return([[]])
    elif r==n:
        lista=[]
        for i in range(1,n+1):
            lista+=[i]
        return([lista])
    else:
        templist=[]
        for i in range(1,n-r+2):
            for j in (ncr(n-1,r-1)):
                flag=1
                for k in range(len(j)):
                    j[k]+=i
                    if j[k]>n:
                        flag=0
                if (flag): templist+=[[i]+j]
        return(templist)
houses=[3,9,4,2,8]
n=len(houses)
possible=[]
for i in range(1,n+1):
    g=ncr(n,i)
    for a in g:
        for q in range(len(a)):
            a[q]-=1

    for a in g:
        valid=1
        for j in range(len(a)-1):
            if a[j]+1==a[j+1]:
                valid=0
        if valid: possible+=[a]

maxloot=0
for i in possible:
    loot=0
    for j in i:
        loot+=houses[j]
    if loot>maxloot: maxloot=loot
print(maxloot)