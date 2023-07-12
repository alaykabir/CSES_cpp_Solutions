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
 
int n, m, ans = 0;
bool flag = false;
vector<vector<int>> graph(100001);
priority_queue<int, vector<int>, greater<int>> pq;
bool vis[100001];
// int graph[100001][101];
int dist[100001];
 
int32_t main(){
	fastio
	cin >> n >> m;
 
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i = 0; i <= n; i++) dist[i] = 1e9;

    pq.push(1);
    vis[1] = true;
    dist[1] = 1;
 
    while(!pq.empty()){
        int par = pq.top();
        // int dis = node.first;
        // int par = node.second;
        // cout << dis << " " << par << endl;
        pq.pop();
 
        for(auto it : graph[par]){
            int child = it;
            if(!vis[child]){
                dist[child] = dist[par] + 1;
                vis[child] = true;
                // if(it == n){
                //     ans = dist[child];
                //     flag = true;
                //     break;
                // }

                pq.push(child);
            }
        }
        // if(flag) break;
    }
    if(dist[n] != 1e9){
        cout << dist[n] << endl;
    }
    else{
        cout << "IMPOSSSIBLE" << endl;
    }
    return 0;
}
