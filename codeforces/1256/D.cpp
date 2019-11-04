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

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

ll q;
cin>>q;
while(q--)
{
ll n,k;
cin>>n>>k;
string s;
cin>>s;

vector<ll> v;
f(i,0,n-1) if(s[i]=='0') v.pb(i);
if(v.empty()) {cout<<s<<endl; continue;
}
ll a[v.size()+1];
ll p=v.size();

f(i,0,p-1)
a[i]=v[i]-i;

//f(i,0,p-1) cout<<a[i]<<" ";
//cout<<endl;
f(i,0,p-1)
{
    if(k>=a[i]) {k-=a[i]; v[i]=i;}
    else
    {
        v[i]=v[i]-k;
        k=0;
        break;
    }
}
//f(i,0,p-1) cout<<a[i]<<" ";
//cout<<endl;
char ch[n];
f(i,0,n-1) ch[i]='1';
f(i,0,p-1) ch[v[i]]='0';
f(i,0,n-1)
cout<<ch[i];
cout<<endl;
}
}
