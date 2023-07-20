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
 
 
int memo(int n, vi&dp){
    if(n == 0) return 0;
    if(n < 0) return 1e9;
    if(dp[n] != -1) return dp[n];
    
    string s = to_string(n);
    int len = s.length();
    int mini = 1e9;
    int ans = 0;
    
    for(int ind = 0; ind < len; ind++){
        int digit = s[ind] - '0';
        if(digit == 0) continue;
        ans = 1 + memo(n - digit, dp);
        mini = min(mini, ans);
    }
    return dp[n] = mini;
}
 
void solve(){
 
    int n;
    cin >> n;
    
    string s = to_string(n);
    int len = s.length();
    
    vector<int> dp(n + 1, -1);
    
    cout << memo(n, dp);
}
 
 
int32_t main(){
	fastio
	int test_cases = 1;
    // cin >> test_cases;
    while(test_cases--)solve();
    return 0;
}
