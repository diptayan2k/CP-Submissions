for _ in range(int(input())):
    n=int(input())
    a=0
    b=0
    cn=0;
    for i in range (1,n):
        if i<n//2:
            a+=(1<<i)
        else : b+=(1<<i)
    a+=(1<<n)

    print(int(abs(a-b)))