
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



