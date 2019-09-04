#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;



void initialize( ll Arr[ ], ll N, ll size[])
{
    for(ll i = 0;i<N;i++)
    {
Arr[ i ] = i ;
size[ i ] = 1;
}
}

ll root (ll Arr[ ] ,ll i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
i = Arr[ i ];
    }
return i;
}

void weightedunion(ll Arr[ ],ll size[ ],ll A,ll B)
{
    ll root_A = root(Arr,A);
    ll root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size[root_B] += size[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
size[root_A] += size[root_B];
}

}

int main(){
ll n;
cin>>n;
string s;
cin>>s;
ll a[n];
f(i,0,n-1) {if(s[i]=='(') a[i]=1; else a[i]=-1;}
ll sum=0;
//f(i,0,n-1) cout<<a[i]<<" ";
f(i,0,n-1) sum+=a[i];
//cout<<sum;


if(sum!=0) {cout<<"No"; exit(0);}

f(i,0,n-1)
{
if((a[i]==-1 && sum>0)||a[i]==1) sum+=a[i];

}

if(sum<=1) {cout<<"Yes"; exit(0);}
cout<<"No";
}

/*
1
5 4
1 2
3 4
3 5
2 3
*/

/*
1
6
1 2 3
5 1
5 6
1 3
6 2
6 4
*/










