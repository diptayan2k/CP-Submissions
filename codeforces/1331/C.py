n=int(input())
s=bin(n)
d=s[2:len(s)]
d=d[::-1]
for i in range(len(d),6):
    d+="0"
d=d[::-1]
p=str(d[0])+str(d[5])+str(d[3])+str(d[2])+str(d[4])+str(d[1])
print(int(p,2))