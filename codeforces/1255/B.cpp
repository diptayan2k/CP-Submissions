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
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define ds set <ll, greater<ll> >
using namespace std;
/*
vector<ll> v[200001];
bool vis[200001];
ds s;
void dfs(ll u)
{
    vis[u]=true;
    //cout<<u<<" ";
    s.insert(u);

 if(!v[u].empty())
 {
     f(i,0,v[u].size()-1)
     {
         if(!vis[v[u][i]])
            dfs(v[u][i]);
     }
 }

}
*/


int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
while(t--){
ll n,m;
cin>>n>>m;
ll a[n];

f(i,0,n-1) cin>>a[i];
if(m<n||n==2)
{
    cout<<-1<<endl;
    continue;
}
ll ans=0;
f(i,0,n-1) ans+=a[i];
ans*=2;
pair<ll,ll> p[n];
f(i,0,n-1)
{p[i].F=a[i]; p[i].S=i+1;}
sort(p,p+n);

m-=n;
ans+=m*(p[0].F+p[1].F);
cout<<ans<<endl;
f(i,1,n-1)
{
    cout<<i<<" "<<i+1<<endl;
}
cout<<n<<" "<<1<<endl;
f(i,1,m)
{
    cout<<p[0].S<<" "<<p[1].S<<endl;
}
}




}
    //c//out<<endl;








