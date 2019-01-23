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

ll findlcm(ll arr[],ll n)
{

    ll ans = arr[0];


    for (ll i = 1; i < n; i++)
        ans = (((arr[i] * ans))/(__gcd(arr[i], ans)));

    return ans;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll n;
cin>>n;
string t;
cin>>t;
string s[6];
 s[0]="RGB",s[1]="RBG",s[2]="GBR",s[3]="GRB",s[4]="BGR",s[5]="BRG";
ll a=n/3;
string aa[6];
f(i,0,5)
{
    f(j,1,a) aa[i]+=s[i];
}
f(i,0,5)
{
    aa[i]+=s[i].substr(0,n%3);
}
//f(i,0,5) cout<<aa[i]<<endl;

ll bbb[6]={0};
f(i,0,5)
{
    f(j,0,n-1)
    if(t[j]!=aa[i][j]) bbb[i]++;
}
//f(i,0,5) cout<<bbb[i]<<" "<<aa[i]<<endl;
ll mi=n;
ll z=0;
f(i,0,5)
{
    if(bbb[i]<=mi)
        {mi=bbb[i]; z=i;}
}
cout<<bbb[z]<<endl<<aa[z];


	return 0;
}
