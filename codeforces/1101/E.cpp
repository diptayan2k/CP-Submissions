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

ll t;
cin>>t;
pair<ll,ll> m,n;
m.F=0;
    m.S=0;
    n.F=0;
    n.S=0;
while(t--)
{
    char ch;
    ll a,b,h,w,x,y;


    ll ff=0;
    scanf(" %c %lld%lld",&ch,&a,&b);

    if(a>b) swap(b,a);
    if(ch=='+')
    {
        if(a>m.F) {m.F=a;}
        if(b>m.S) {m.S=b; }

    }

    //cout<<m.F<<" "<<m.S<<endl<<n.F<<" "<<n.S<<endl;
    if(ch=='?')
    {
        if(a>=m.F&&b>=m.S)
        {
            ff=1;

        }

    }
    if(ch=='?')
    {
        if(ff==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
	return 0;
}




