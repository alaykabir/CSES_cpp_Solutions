
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
 
int n;
vector<vector<char>> grid(1000, vector<char>(1000));
vector<vector<int>> dp(1000, vector<int>(1000, -1));

int memo(int i, int j){
    if(i < 0 || j < 0) return 0;
    if(i == 0 && j == 0) return 1;
    if(grid[i][j] == '*') return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int up = memo(i - 1, j);
    int left = memo(i, j - 1);

    return dp[i][j] = (up + left) % mod;
}

int32_t main(){
	fastio
	cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    if(grid[n-1][n-1] != '*' && grid[0][0] != '*') cout << memo(n-1, n-1);
    else cout << 0 << endl;
    
}
