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





int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
ll n,k;
cin>>n>>k;
ll a[n];
f(i,0,n-1) cin>>a[i];
queue<ll> q;
map<ll,ll> m;

f(i,0,n-1)
{ if(!m[a[i]])
 {
     if(q.size()<k) {q.push(a[i]); m[a[i]]=1;}
     else if(q.size()==k){ m[q.front()]=0; q.pop(); q.push(a[i]); m[a[i]]=1;}
 }


}
vector<ll> v;
while (!q.empty())
    {
        v.pb(q.front());
        q.pop();
    }
if(!v.empty()){
cout<<v.size()<<endl;
g(i,v.size()-1,0) cout<<v[i]<<" ";
}
else cout<<0;



}
