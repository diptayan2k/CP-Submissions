#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcount(x)
using namespace std;


void solve(ll t)
{
    ll n,m;
    cin>>n>>m;
    ll s=0;
    ll a[m];
    ll fr[63]={0};
    f(i,0,m-1)
    {
        cin>>a[i];
        s+=a[i];
        fr[(ll)log2(a[i])]++;
    }

    if(s<n)
    {
        cout<<-1<<endl;
        return;
    }

    ll ans=0;
    f(i,0,60)
    {
        ll p=(1ll<<i);

        if((n&p)!=0)
        {

            if(fr[i]!=0)
            {
                fr[i]--;
            }
            else
            {
                while(fr[i]==0 and i<=60)
                {
                    i++;
                    ans++;
                }
                fr[i]--;
                i--;
            }

        }
        fr[i+1]+=(fr[i]/2);
    }
    cout<<ans<<endl;




}


int main()
{
    ll t=1;
    scanf("%lld",&t);

    f(i,1,t)
    {
        solve(i);
    }

}

