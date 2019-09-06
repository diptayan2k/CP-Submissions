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
ll n,k;
cin>>n>>k;
ll a[n];
f(i,0,n-1) cin>>a[i];
sort(a,a+n);
vector <ll> v[n];
map<ll,ll> m,d,p;
f(i,0,n-1)
{ ll x=a[i];
    v[i].pb(x);
    while(x!=0)
        {
            x/=2;
            v[i].pb(x);
        }
}

f(j,0,30)
{
    f(i,0,n-1) {
    if(v[i].size()>=j) { if(m[v[i][j]]<=k) m[v[i][j]]++; if(m[v[i][j]]<=k) d[v[i][j]]+=j;
    //if(m[v[i][j]]>=k) { cout<<d[v[i][j]]; exit(0);} }

}}
}
ll ans=200000000000000001;
f(i,0,n-1)
f(j,0,v[i].size()-1) if(m[v[i][j]]>=k) ans=min(ans,d[v[i][j]]);

cout<<ans;


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








