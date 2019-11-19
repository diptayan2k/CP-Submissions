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




int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

ll t;
cin>>t;
while(t--)
{
    ll a,b;
    cin>>a>>b;
    ll c=abs(a-b);
    ll ans=0;
    if(c>=5)
    {
        ll x=c/5;
        c-=5*x;
        ans+=x;
    }
    if(c>=2)
    {
        ll x=c/2;
        c-=2*x;
        ans+=x;
    }
    if(c>=1)
    {
        ans+=c;
    }
    cout<<ans<<endl;
}


}
    //c//out<<endl;








