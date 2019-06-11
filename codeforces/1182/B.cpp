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
ll mi;
ll m;

ll s=0;

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

    // Return mid + 1 because of 0-based indexing
    // of array
    return mid-d + 1;
}

int main(){
ll h,w;
cin>>h>>w;
string s[h];
f(i,0,h-1)
{cin>>s[i];
}
/*cout<<endl;
f(i,0,h-1)
{cout<<s[i];
cout<<endl;}*/
ll p=-1, q=-1;
f(i,1,h-2)
f(j,1,w-2)
{
    if(s[i][j]=='*'&&s[i+1][j]=='*'&&s[i][j+1]=='*'&&s[i-1][j]=='*'&&s[i][j-1]=='*')
        {p=i; q=j;}
}
if(p==-1||q==-1) {cout<<"NO"; exit(0);}
f(j,q,w-1)
{ if(s[p][j]=='*'&&s[p][j-1]=='.')
   {cout<<"NO"; exit(0);}
}
f(j,0,q)
{ if(s[p][j]=='*'&&s[p][j+1]=='.')
   {cout<<"NO"; exit(0);}
}

f(i,p,h-1)
{ if(s[i][q]=='*'&&s[i-1][q]=='.')
   {cout<<"NO"; exit(0);}
}
f(i,0,p)
{ if(s[i][q]=='*'&&s[i+1][q]=='.')
   {cout<<"NO"; exit(0);}
}
f(i,0,h-1)
f(j,0,w-1)
{
    if(i!=p&&j!=q)
        if(s[i][j]=='*')
    {
        cout<<"NO"; exit(0);
    }
}
cout<<"YES";
return 0;
}