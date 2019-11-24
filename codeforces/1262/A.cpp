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
map<ll,ll> m;
vector<ll> v[200001],ans;
bool vis[200001];
ds s[200001];
void dfs(ll u)
{
    vis[u]=true;
    cout<<u<<" ";
    m[u]--;


 if(!v[u].empty())
 {
     f(i,0,v[u].size()-1)
     {
         if(!vis[v[u][i]]&&m[v[u][i]]==3)
            dfs(v[u][i]);
     }
 }

}

// A function to calculate the number of


int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    pair<ll,ll> p[n];
    f(i,0,n-1)
    cin>>p[i].F>>p[i].S;
    ll x=p[0].F;
    ll y=p[0].S;
    f(i,0,n-1)
    {
        x=max(x,p[i].F);
        y=min(y,p[i].S);
    }
    cout<<max(x-y,(ll)0)<<endl;


}
return 0;
}
    //c//out<<endl;








