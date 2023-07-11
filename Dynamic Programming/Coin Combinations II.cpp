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
 
int n, x, ans = 0;
int coins[100];
bool flag = false;
// vector<int> prev(1000001, 0);
// vector<int> curr(1000001, 0);
 
int32_t main(){
	fastio
	cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> prev(1000001, 0);
    vector<int> curr(1000001, 0);

    for(int tar = 1; tar <= x; tar++){
        if(tar % coins[0] == 0){
            prev[tar] = 1;
        }
    }

    prev[0] = curr[0] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int tar = 1; tar <= x; tar++){
            int notake = prev[tar];

            int take = 0;
            if(coins[ind] <= tar){
                take = curr[tar - coins[ind]];
            }

            curr[tar] = (take + notake) % mod;
        }

        prev = curr;
    }

    cout << prev[x] <<endl;
}
