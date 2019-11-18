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

ll n,m;
cin>>n>>m;
f(i,0,m-1)
{
    ll x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
}
ll ans=0;
f(i,1,n)
{
    if(!vis[i])
    {
        if(!s.empty())
        {   ds:: iterator it1,it2;
            /*
            for(it=s.begin();it!=s.end();it++)
            {
                cout<<*it<<"-";
            }
            cout<<endl;
            */
            it1=s.begin();
            it2=s.end();
            it2--;
            ll x=*it2;
            ll y=*it1;
            if(i>x&&i<y) ans++;



        }
        dfs(i);
        //cout<<endl;

    }
}
cout<<ans;



}
    //c//out<<endl;








