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
    ll a[n+1];
    ll c[n+1]={0};
    f(i,1,n) cin>>a[i];
    ll b[n+1]={0};
    f(i,1,n)
    {
        if(b[a[i]]==0)
        {
            c[i]=a[i];
            b[a[i]]=1;
        }
    }

    ll cn=0;
    vector<ll> v,d;
    f(i,1,n) if(c[i]==0) v.pb(i);
    f(i,1,n) if(b[i]==0) d.pb(i);
    if(!v.empty())
    f(i,0,v.size()-1)
    {
        c[v[i]]=d[i];

    }
    ll ff=0;
    f(i,1,n)
    {
        if(c[i]>a[i]) ff=1;
    }
    ll ma=1;
    f(i,1,n)
    {
        ma= max(ma,a[i]);
        if(a[i]<ma) ff=1;
    }
    ll e[n+1];
    ma=0;
    f(i,1,n)
    {
        ma=max(ma,c[i]);
        e[i]=ma;
        if(e[i]!=a[i]) ff=1;
    }
    if(ff==1)
    {
        cout<<-1;
    }
    else
    f(i,1,n) cout<<c[i]<<" ";
    cout<<endl;


}
return 0;
}
    //c//out<<endl;








