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
 
void solve(){
    string s;
    cin >> s;
    int n = s.size();

    unordered_map<char, int> mp;
    fori(0, n){
        mp[s[i]]++;
    }    

    int odd = 0;
    int even = 0;
    char char_odd;

    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second % 2){
            odd++;
            char_odd = it->first;
        } 

        if(odd > 1){
            cout << "NO SOLUTION";
            return;
        }
    }

    string ans;
    string temp;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second % 2) continue;
        

        int n = (it->second) / 2;
        char c = it->first;

        while(n--){
            temp += c;
            mp[c]--;
        }
    }
    ans += temp;
    ans += char_odd;

    reverse(temp.begin(), temp.end());
    ans += temp;

    cout << ans;
    
}
 
int32_t main(){
	fastio
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
}
