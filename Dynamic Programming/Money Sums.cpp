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

int n, sum = 0;
vector<int> arr(100);
set<int> ans;

void memo(int ind){
    if(ind < 0){
        ans.insert(sum);
        return;
    };

    sum += arr[ind]; 
    memo(ind - 1);
    sum -= arr[ind];
    memo(ind - 1);
}

int32_t main(){
	fastio
    cin >> n;
    fori(0, n) cin >> arr[i];

    memo(n - 1);
    cout << ans.size() - 1 << endl;
    for(auto it : ans){
        if(it != 0) cout << it << " ";
    }
    
}
