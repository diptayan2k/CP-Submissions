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
using namespace std;
ll mod=1000000007;

/*vector<ll> v[100001];
bool vis[100001];
ll n;
ll child[100001];
void dfs(ll u)
{
    vis[u]=true;
    //cout<<u<<" ";
    if(!v[u].empty())
    {
        f(i,0,v[u].size()-1)
        {
           if(!vis[v[u][i]])
           {
            dfs(v[u][i]);
            child[u]+=child[v[u][i]];
           }

        }
    }
}
*/
int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
string s;
vector<ll> v;
cin>>s;
ll a[100001];
a[0]=1;
a[1]=1;
f(i,2,100001) a[i]=(a[i-1]%mod+a[i-2]%mod)%mod;

ll cn=0;
ll len=s.size();
f(i,0,len-1)
{
    if(s[i]=='n')
    {

        while(s[i]=='n'&&i<len)
        {
          cn++;
          cn=cn%mod;
          i++;
        }
        i--;

        v.pb(cn%mod);
        cn=0;

    }
}

f(i,0,len-1)
{
    if(s[i]=='u')
    {

        while(s[i]=='u'&&i<len)
        {
          cn++;
          i++;
          cn=cn%mod;
        }
        i--;

        v.pb(cn%mod);
        cn=0;

    }
}
ll ans=1;
f(i,0,len-1)
{
    if(s[i]=='m'||s[i]=='w')
    {
        cout<<0;
        exit(0);
    }
}
if(!v.empty())
{
    f(i,0,v.size()-1)
    ans=(ans%mod*a[v[i]]%mod)%mod;
}
cout<<ans;
}
