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
/*
ll mod=1000000007;
ll si=0;
vector<ll> v[100000];
bool vis[100000];

void dfs(ll u)
{  cout<<u<<" ";
    vis[u]=true;
  si++;
 if(!v[u].empty())
 {
     f(i,0,v[u].size()-1)
     {
         if(!vis[v[u][i]])
            dfs(vis[v[u][i]]);
     }
 }

}
*/
ll b[1000001]={0};


int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);


    ll n;
    cin>>n;
    vector<ll> v;
    ll a[n];
    f(i,0,n-1) cin>>a[i];
    memset(b,0,sizeof(b));
    ll flag=0;
    ll num=0;
    ll d=0;

    f(i,0,n-1)
    {
        if(a[i]>0)
        {
          b[a[i]]++;
          num++;
          d++;
          if(b[a[i]]>1||b[a[i]]<0)
          {
              flag=1;
              break;
          }
        }
        if(a[i]<0)
        {
            b[-1*a[i]]--;
            num--;
            d++;
            ll p=-1*a[i];
            if(b[p]>1||b[p]<0)
            {
              flag=1;
              break;
            }
        }
        if(num==0)
        {
            v.pb(d);
            d=0;
        }

    }
    //cout<<flag<<endl;
    if(flag==1)
    {
        cout<<-1<<endl;
        exit(0);
    }
    if(v.empty())
    {
        cout<<-1<<endl;
        exit(0);
    }

    ll sum=0;
    f(i,0,v.size()-1)
    sum+=v[i];
    if(sum!=n)
    {
        cout<<-1<<endl;
        exit(0);
    }
    ll k=0;
    f(i,0,v.size()-1)
    {
        map<ll,ll> m;
        f(j,1,v[i])
        {
            if(m[a[k]]!=0) {flag=1; break;}
            m[a[k++]]++;

        }
    }
    if(flag==1)
    {
        cout<<-1<<endl;
        exit(0);
    }
    cout<<v.size()<<endl;
    f(i,0,v.size()-1)
    cout<<v[i]<<" ";
    cout<<endl;







}
