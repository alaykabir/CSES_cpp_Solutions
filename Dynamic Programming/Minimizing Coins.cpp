
#include <bits/stdc++.h>
 
#define int long long
#define endl "\n"
#define spc " "
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pip pair<int,pi>
#define pl pair<ll,ll>
#define plp pair<ll,pl>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define ins insert
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val
#define sz(q) (int)(q.size())
 
using namespace std;
 
#define fori(a,b) for(auto i=a;i<b;++i)
#define foir(a,b) for(auto i=a;i>=b;--i)
#define forj(a,b) for(auto j=a;j<b;++j)
#define forjr(a,b) for(auto j=a;j>=b;--j)
 
int n, x;
vector<int> coins(100);

int32_t main(){
	fastio
    
	cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coins[i];
 
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
 
    for(int tar = 0; tar <= x; tar++){
        if(tar % coins[0] == 0) dp[0][tar] = tar / coins[0];
        else dp[0][tar] = 1e9;
    }
 
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= x; tar++){
            int notake = dp[ind - 1][tar];
 
            int take = 1e9;
            if(coins[ind] <= tar){
                take = 1 + dp[ind][tar - coins[ind]];
            }
 
            dp[ind][tar] = min(take, notake);
        }
    }
 
    cout << dp[n - 1][x] << endl;
}
