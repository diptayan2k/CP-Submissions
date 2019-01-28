#include <iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
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

ll n,k;
cin>>n>>k;
vv <ll> a;
f(i,0,n-1) {
    ll x;
    cin>>x;
    a.pb(x);}
string s;
cin>>s;
s+="@";
f(i,0,n-1)
{  ll p=i;
    ll c=0;


        while(s[i]==s[i+1]&&i<=n-1) {c++; i++;}

    sort(a.begin()+p,a.begin()+i+1);
    reverse(a.begin()+p,a.begin()+i+1);


}
ll ss=0;


f(i,0,n-1)
{
  char b=s[i];
  ll c=0;
    ll q;
    f(j,i,n-1)
    { if(s[j]==b)
        {  if(c<=k-1)
            {ss+=a[j];
         c++;
         //cout<<ss<<" "<<j<<" "<<a[j]<<" "<<q<<s[i]<<" "<<c<<endl;
         }
         q=j;

         }

        else { //cout<<"B"<<endl;
        break;}

    }
    i=q;

//cout<<ss<<" ";*/



}
cout<<ss;
	return 0;
}
