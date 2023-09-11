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

int diag(int x){
    return ((x*x) - x + 1);
}

void solve(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 0 << endl; 
        return;
    }
    if(n == 2){
        cout << 0 << endl;
        cout << 6 << endl;
        return;
    }
    cout << 0 << endl;
    cout << 6 << endl;
    int k = 1;
    for(int i = 3; i <= n; i++){
        int grid = i * i;
        int total = (grid * (grid - 1)) / 2;

        int factor = (k * (k + 1)) / 2;
        k++;

        int ans = total - (8 * (factor));

        cout << ans << endl;
    }
}

int32_t main(){
	fastio
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
}
