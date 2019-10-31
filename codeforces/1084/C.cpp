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
string s;
cin>>s;
string s1;

if(s[0]=='a') s1+='a';
s+="b";
f(i,1,s.size()-1)
{
    if(s[i]=='a') s1+="a";
    else if(s[i]=='b'&&s[i]!=s[i-1]) s1+="b";
}
//s1+="b";
//cout<<s1<<endl;
s=s1;
ll a[s.size()+2]={0};
ll b[s.size()+2]={0};
f(i,0,s.size()-1)
{
    if(s[i]=='a') a[i+1]=(1+a[i])%mod;
    if(s[i]=='b') a[i+1]=0;
}

//f(i,1,s.size()) cout<<a[i]<<" "<<endl;
ll ans=1;
f(i,2,s.size()) {if(s[i-1]=='b') ans=((a[i-1]+1)%mod*ans%mod)%mod; }
cout<<(ans-1+mod)%mod;
}
