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
using namespace std;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
string s;
cin>>s;
ll a=0;
ll b=0;
f(i,0,s.length()-1)
{
    if(s[i]=='0')
    {
        cout<<1<<" "<<((a++)%4)+1<<endl;
    }
    if(s[i]=='1')
    {
     if(b%2==0)
     cout<<3<<" "<<(b%2)+1<<endl;
     if(b%2==1)
     cout<<3<<" "<<(b%2)+2<<endl;
     b++;

    }
}
	return 0;
}
