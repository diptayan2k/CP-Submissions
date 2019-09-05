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
ll t;
cin>>t;
while(t--)
{
ll a,b,c;
cin>>a>>b>>c;


if(a>b+c)    cout<<c+1<<endl;
else if(b>=a+c) cout<<0<<endl;
else cout<<c-(c-(a-b))/2<<endl;



}
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








