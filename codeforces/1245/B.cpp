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
ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    ll a,b,c;
    cin>>a>>b>>c;
    string s;
    cin>>s;
    map<char,ll> m;
    f(i,0,n-1)
    {
        m[s[i]]++;
    }
    ll p=n/2;
    if(n%2==1) p++;
    char ch[n];
    f(i,0,n-1) ch[i]='.';
    f(i,0,n-1)
    {
        if(s[i]=='S')
        {
            if(a>0)
            {
                a--;
                ch[i]='R';
            }

        }
        if(s[i]=='R')
        {
            if(b>0)
            {
                b--;
                ch[i]='P';
            }

        }
        if(s[i]=='P')
        {
            if(c>0)
            {
                c--;
                ch[i]='S';
            }

        }
    }

    f(i,0,n-1)
    {
        if(ch[i]=='.')
        {
            if(a>0)
            {   a--;
                ch[i]='R';
            }
            else if(b>0)
            {   b--;
                ch[i]='P';
            }
            else if(c>0)
            {   c--;
                ch[i]='S';
            }
        }
    }
    ll cc=0;
    f(i,0,n-1)
    {
        if(s[i]=='R'&&ch[i]=='P') cc++;
        else if(s[i]=='P'&& ch[i]=='S') cc++;
        else if(s[i]=='S'&&ch[i]=='R') cc++;
    }
    if(cc<p)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;

    f(i,0,n-1) cout<<ch[i];
    cout<<endl;


}
}
