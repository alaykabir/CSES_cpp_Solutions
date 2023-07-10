#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
bool flag = false;
string path = "";
int ax, ay;
int bx, by;
int dist[1010][1010];
char graph[1010][1010];

string direction(int i2, int j2, int i1, int j1){
    if(i2 - i1 == 1) return "D";
    if(i1 - i2 == 1) return "U";
    if(j2 - j1 == 1) return "R";
    if(j1 - i2 == 1) return "L";
}

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

int main() {
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

        for(int k = 0; k < 4; k++){
            int childx = parx + dx[k];
            int childy = pary + dy[k];

            if(isValid(childx, childy) && dis + 1 < dist[childx][childy]){
                dist[childx][childy] = dis + 1;

                if(childx == bx && childy == by){
                    ans = dis + 1;
                    path = way;
                    flag = true;
                    break; 
                }

                st.insert({dis + 1, {{childx, childy}, way += direction(childx, childy, parx, pary)}});
            }
        }
        if(flag) break;
    }
    if(flag){
        cout << "YES" << endl;
        cout << ans << endl;
        cout << path << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
