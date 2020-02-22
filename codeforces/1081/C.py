import math
n,m,k=map(int,input().split())
mod=998244353
print((math.factorial(n-1)%mod*m*pow(m-1,k,mod)*pow(math.factorial(n-1-k)%mod*math.factorial(k)%mod,mod-2,mod))%mod)