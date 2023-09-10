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
    int ans = 1;
    for(int i = 1; i < x; i++){
        ans += 2 * i;
    }
    return ans;
}

void solve(){
    int x, y;
    cin >> x >> y;

    // int ans = 1;
    if(x == y){
        cout << diag(x) << endl;
        return;
    }
    int nx, ny;
    if(x < y){
        nx = y;
        int ans = diag(y);
        while(nx > x){
            ans++;
            nx--;
        }
        cout << ans << endl;
        return;
    }
    if(x > y){
        ny = x;
        int ans = diag(x);
        while(ny > y){
            ans++;
            ny--;
        }
        cout << ans << endl;
        return;
    }
}

int32_t main(){
	fastio
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
