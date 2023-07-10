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
string path = "";
int ax, ay;
int bx, by;
int dist[1010][1010];
char par[1010][1010];
char graph[1010][1010];

bool isValid (int x, int y) {
  if (x < 0) return false;
  if (y < 0) return false;
  if (x >= n) return false;
  if (y >= m) return false;
//   if(vis[x][y]) return false;
  if (graph[x][y] == '#') return false;
  return true;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int32_t main(){
	fastio
	cin >> n >> m;

    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> graph[i][j];
        dist[i][j] = 1e9;

        if(graph[i][j] == 'A'){
            ax = i;
            ay = j;
            dist[ax][ay] = 0;
        }
        if(graph[i][j] == 'B'){
            bx = i;
            by = j;
        }
      }
    }

    set<pair<int, pair<pair<int, int>, string>>> st;
    st.insert({0, {{ax, ay}, ""}});

    while(!st.empty()){
        auto node = *st.begin();
        int dis = node.first;
        int parx = node.second.first.first;
        int pary = node.second.first.second;
        string way = node.second.second;
        st.erase(node);

        for(int i = 0; i < 4; i++){
            int childx = parx + dx[i];
            int childy = pary + dy[i];

            if(isValid(childx, childy) && dis + 1 < dist[childx][childy]){

                dist[childx][childy] = dis + 1;
                if(i == 0)      par[childx][childy]= 'R';
                else if(i == 1) par[childx][childy]= 'L';
                else if(i == 2) par[childx][childy]= 'D';
                else if(i == 3) par[childx][childy]= 'U';

                if(childx == bx && childy == by){
                    ans = dis + 1;
                    path = way;
                    flag = true;
                    break; 
                }

                st.insert({dis + 1, {{childx, childy}, way}});
            }
        }
        if(flag) break;
    }
    if(flag){
        cout << "YES" << endl;
        cout << ans << endl;

        pair<int, int> p = {bx, by};
        string s = "";
        for(int i = dist[bx][by]; i > 0; i--){
            s.push_back(par[p.first][p.second]);
            if(par[p.first][p.second] == 'D')       p = {p.first-1, p.second};
            else if(par[p.first][p.second] == 'U')  p = {p.first+1, p.second};
            else if(par[p.first][p.second] == 'R')  p = {p.first, p.second-1};
            else if(par[p.first][p.second] == 'L')  p = {p.first, p.second+1};
        }

        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
