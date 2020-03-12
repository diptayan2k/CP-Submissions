#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
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
ll mod=1000000007;
ll k,n;
string s;

map<pair<ll,ll>,ll> m;
ll len;
ll dp[150][150][30];

ll foo(ll idx, ll ch,ll prev)
{
    if(ch>k)
    {
        return -1000000007;
    }
    if(idx==len)
    {

        return 0;
    }

    if(dp[idx][ch][prev]!=-1) return dp[idx][ch][prev];

    ll res=-1000000007;

    f(i,0,25)
    {

        if(s[idx]-'a'==i)
        {
            res=max(res,foo(idx+1,ch,i)+m[{prev,i}]);
        }
        else
        {
            res=max(res,foo(idx+1,ch+1,i)+m[{prev,i}]);
        }
    }

    return dp[idx][ch][prev]=res;
}

void solve(ll t)
{
    cin>>s>>k;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        char x,y;
        ll c;
        cin>>x>>y>>c;
        m[{x-'a',y-'a'}]=c;
    }
    //cout<<m[{'s'-'a','e'-'a'}]<<endl;
    len=s.length();
    f(i,0,100) f(j,0,100) f(k,0,26) dp[i][j][k]=-1;
    cout<<foo(0,0,26);


}








int main()
{
    ios::sync_with_stdio(0);
    ll t=1;
    f(i,1,t)
    {
        solve(i);
    }

}


