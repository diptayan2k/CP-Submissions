#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,b,a) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
using namespace std;

ll mod(string num, ll a)
{
    // Initialize result
    ll res = 0;

    // One by one process all digits of 'num'
    for (ll i = 0; i < num.length(); i++)
         res = (res*10 + (ll)num[i] - '0') %a;

    return res;
}
/*
ll s;dcklsvkn dsk kmlasknd

void dfs(vv<ll> v[],bool vis[],ll i,ll sum[],ll a[], ll c[])
{
      vis[i]=true;
     sum[i]=a[i];
     c[i]=0;

    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs(v,vis,v[i][j],sum,a,c);
    sum[i]+=sum[v[i][j]];
    c[i]++;
    }



}
ll p;
void dfs1(vv<ll> v[],bool vis[],ll i,ll sum[],ll c[], ll a[])
{
      vis[i]=true;


    if(!v[i].empty())
    f(j,0,v[i].size()-1)
    if(!vis[v[i][j]])
    {
    dfs1(v,vis,v[i][j],sum,c,a);
    s=max(s,s-sum[v[i][j]]-m);
    }
    p=p-sum[i]-m;
    s=max(s,p);




}

ll binarySearchCount(ll arr[], ll n, ll key, ll d)
{ ll left =d;
ll     right = n;

    ll mid;
    while (left < right)
    {
        mid = (right + left) >> 1;

        // Check if key is present in array
        if (arr[mid] == key)
        {
            // If duplicates are present it returns
            // the position of last element
            while (mid+1<n && arr[mid+1] == key)
                 mid++;
            break;
        }

        // If key is smaller, ignore right half
        else if (arr[mid] > key)
            right = mid;

        // If key is greater, ignore left half
        else
            left = mid + 1;
    }

    // If key is not found in array then it will be
    // before mid
    while (mid > -1 && arr[mid] > key)
        mid--;

    //Return mid + 1 because of 0-based indexing
    // of array
    return mid-d + 1;
}

*/

int main(){
ll t;
cin>>t;
while(t--)
{ ll m,n;
 cin>>n>>m;
 string s[n];
 f(i,0,n-1)
 cin>>s[i];
 ll p[n]={0},q[m]={0};
 ll d=0;
 f(i,0,n-1)
 { ll count =0;
   f(j,0,m-1)
    if(s[i][j]=='.') count++;
   p[i]=count;
}


f(i,0,m-1)
 { ll count =0;
   f(j,0,n-1)
    if(s[j][i]=='.') count++;
   q[i]=count;
}
ll ans=m*n;
f(i,0,n-1)
f(j,0,m-1)
{ ans=(s[i][j]=='.')?(min((p[i]+q[j]-1),ans)):(min((p[i]+q[j]),ans));

}
cout<<ans<<endl;
}
}
