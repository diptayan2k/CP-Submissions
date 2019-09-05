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
ll n,x;
cin>>n>>x;
ll d[n],h[n],b[n];
 vector < pair< ll,pair<ll,ll> > > p(n);
f(i,0,n-1) cin>>d[i]>>h[i];
f(i,0,n-1) { b[i]=d[i]-h[i]; }
//sort(p.begin(),p.end());
sort(b,b+n,greater<int>());
//sort(d,d+n,greater<int>());
ll c[n][n];
memset(c,0,sizeof(c));
ll q=x;
ll ans=100000000000000000;
f(i,0,n-1)
{
    f(j,0,n-1){
    x=q;
x-=d[i];

x=max(x,(ll)0);
if(x==0) {c[i][j]=1; goto w; }
c[i][j]++;
//cout<<x<<" "<<b[0]<<endl;
if(b[j]<=0) {c[i][j]=100000000000000000; goto w; }
c[i][j]+=(x/b[j]);
if(x%b[j]!=0) c[i][j]++;
   w:
    ans=min(ans,c[i][j]);

    }
}
//sort(c,c+n);

if(ans==100000000000000000) {cout<<-1<<endl; continue;}

cout<<ans<<endl;




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








