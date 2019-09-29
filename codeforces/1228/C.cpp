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

bool prime[100000+1];

set <ll, greater <ll> > pf;

ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p%m * p%m) % m;

    return (y%2 == 0)? p%m : (x%m * p%m) % m;
}

void primeFactors(ll n)
{

    while (n % 2 == 0)
    {
        pf.insert(2);
        n = n/2;
    }


    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {  pf.insert(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
       pf.insert(n);
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   //SieveOfEratosthenes(100001);

    ll x,n;
    cin>>x>>n;
    ll pd=1;
    primeFactors(x);
    set <ll, greater <ll> > :: iterator itr;
    for (itr = pf.begin(); itr != pf.end(); ++itr)
    {
       ll a=*itr;
       ll b=0;
       ll c=n;
       while(c!=0)
       {

           c/=a;
           b+=c;

       }
        pd=(pd%1000000007*power(a,b,1000000007)%1000000007)%1000000007;
    }



    cout<<pd%1000000007;





}


