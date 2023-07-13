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
#define forir(a,b) for(auto i=a;i>=b;--i)
#define forj(a,b) for(auto j=a;j<b;++j)
#define forjr(a,b) for(auto j=a;j>=b;--j)

string s1, s2;
vector<vector<int>> dp(5001, vector<int>(5001, -1));

int memo(int i, int j){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = 0 + memo(i - 1, j - 1);
    } else{
        return dp[i][j] = 1 + min(memo(i - 1, j - 1), 
                    min(memo(i - 1, j), memo(i, j - 1)));
    }
}

int32_t main(){
	fastio
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    cout << memo(n - 1, m - 1);
    
}
