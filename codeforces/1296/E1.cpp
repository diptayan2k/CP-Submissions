#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ll> v[100001];
ll a[100001];
bool vis[100001];
void bfs(ll u)
{
    a[u]=0;
    queue<ll> q;
    q.push(u);

    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        vis[x]=true;

        for(auto i: v[x])
        {


            if(!vis[i]){

            vis[i]=true;
            q.push(i);
            if(a[i]==-1) a[i]=a[x]^1;
            else if(a[i]==a[x])
            {
                cout<<"NO"<<endl;
                exit(0);
            }

            }
            else
            {
                if(a[x]==a[i])
                {
                    cout<<"NO"<<endl;
                    exit(0);

                }

            }

        }

    }




}

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;


    f(i,0,n-1)
    {
        f(j,i+1,n-1)
        {
            if(s[j]<s[i])
            {
                v[j+1].pb(i+1);
                v[i+1].pb(j+1);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }

    f(i,0,n)
    {
        a[i]=-1;
        vis[i]=false;
    }

    f(i,1,n)
    {
        if(!vis[i]) bfs(i);
    }

    cout<<"YES"<<endl;

    f(i,1,n) cout<<a[i];

}

int main()
{
   ll t=1;

   while(t--)
   {
       solve();
   }

}
