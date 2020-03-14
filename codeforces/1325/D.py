import math
x,s=map(int,input().split())



if x>s:
    print(-1)
    exit

else:
    a=(s-x)//2
    p=0
    q=0
    r=0
    
    for i in range (60):
        if (x & pow(2,i)!=0) and (a & pow(2,i)==0) :
            p+=pow(2,i)
        if (x & pow(2,i)==0) and (a & pow(2,i)!=0) :
            p+=pow(2,i)
            q+=pow(2,i)
        if (x & pow(2,i)!=0) and (a & pow(2,i)!=0) :
            p+=pow(2,i)
            q+=pow(2,i)
            r+=pow(2,i)
    
    v=[]
    
    if p>0: v.append(p)
    if q>0: v.append(q)
    if r>0: v.append(r)
        
    flag=0
    if (s-x)%2==1:
        z=s-(p+q+r)
        if z^p^q^r != x :
            
            flag = 1
        else:
            v.append(z)
    
    
    if(flag == 1):
        print(-1)
    else:    
        print(len(v))
        for i in v:
            print(i,end=' ')
    
    
    
            
            