n,m=input().split()
a=list(map(int, input().split()))
n=int(n)
m=int(m)
a.sort()
b=[]
b.append(0)
for i in range (n):
    b.append(a[i]+b[i])
p=n//m
if(n%m!=0): p += 1
q=n%m

c= [[0 for x in range (p+2)] for y in range (m+1) ]
for i in range(n-m+1,n+1):
    d=i//m
    if(i%m!=0): d+=1
    ans=0
    k=i
    ans=0
    for j in range (p,0,-1):
        t=max(k-m,0)
        ans=(b[k]-b[t])
        c[i%m][k//m]=ans
        k-=m
    for j in range(1,p+1):
        c[i%m][j]+=c[i%m][j-1]
    for j in range(1,p+1):
        c[i%m][j]+=c[i%m][j-1]
        
for i in range (1,n+1):
    print(c[(i)%m][(i)//m], end=' ')