#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=100005;
#define M 1000000007
#define double long double
#define BINF 1000000000000001
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 5000004
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;


int n, m, k;
int a[105];
int dp[101][105][101], p[105][105];

int foo(int ind, int gr, int prev){
    if(ind == n + 1){  
        if(gr == k + 1)
            return 0;
        return BINF;
    }
    if(dp[ind][gr][prev] != -1)
        return dp[ind][gr][prev];

    int res = BINF;
    if(a[ind] != 0){
        res = min(res, foo(ind + 1, gr + (prev != a[ind]), a[ind]));
    }else{
        for(int i = 1; i <= m; i++){
            res = min(res, p[ind][i] + foo(ind + 1, gr + (prev != i), i));
        }
    }
    return dp[ind][gr][prev] = res;
}


#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout); 
#endif

    init(dp, -1);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> p[i][j];

    int ans = foo(1, 1, 102);
    if(ans == BINF)
        ans = -1;
    cout << ans << endl;
   
return 0;  
}