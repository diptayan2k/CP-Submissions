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

bool check_vowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
    return false;
}

vector<ll>  v[100001];
vector<ll>  v1[100001];
bool vis[100001];
ll a[100001]={0};
string s;
void dfs(ll u)
{
    vis[u]=true;

    ll ma=0;
    if(!v[u].empty())
    {
        f(i,0,v[u].size()-1)
        {  if(!vis[v[u][i]])
            {dfs(v[u][i]);
        ma=max(ma,a[v[u][i]]);
        }
    }}
     a[u]+=ma;
}

void dfs1(ll u)
{
    vis[u]=true;
    if(!v[u].empty())
    {
        f(i,0,v[u].size()-1)
        {  if(!vis[v[u][i]])
            { v1[u].pb(a[v[u][i]]);

                dfs1(v[u][i]);
            }

    sort(v1[u].begin(),v1[u].end());
    reverse(v1[u].begin(),v1[u].end());
    }

    }


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
ll a[n];
ll b[n];
ll c[n];
map <ll,ll> m;
f(i,0,n-1) {cin>>a[i]; m[a[i]]=i;}
f(i,0,n-1) {cin>>b[i]; c[i]=m[b[i]];}
ll mi=n+1;
ll ans=0;
g(i,n-1,0)
{
    if(c[i]>mi) ans++;
    mi=min(mi,c[i]);

}
cout<<ans;
}






/*
13
abijdaaaaaaii
1 12
1 2
2 3
2 4
2 5
4 6
4 7
12 13
4 8
6 9
7 10
8 11
*/
