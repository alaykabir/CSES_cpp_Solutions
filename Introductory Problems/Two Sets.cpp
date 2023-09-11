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

    int sum = (n * (n + 1)) / 2;
    if(sum % 2 != 0){
        cout << "NO";
        return;
    }

    cout << "YES" << endl;

    int half_sum = sum / 2;
    

    int pairs = half_sum / (n + 1);
    int rem = half_sum % (n + 1);

    cout << n / 2  << endl;

    for(int i = 1; i <= pairs; i++){
        cout << i << " " << n - i + 1 << " ";
    }

    if(rem) cout << rem;
    cout << endl;

    if(n % 2 == 0) cout << n / 2 << endl;
    else cout << n / 2 + 1 << endl;

    int factor = 0;
    if(rem) factor = 1;
    for(int i = pairs + 1; i <= (n - pairs - factor); i++){
        cout << i << " ";
    }
    
}

int32_t main(){
	fastio
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
}
