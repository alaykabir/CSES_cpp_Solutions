#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int vis[1010][1010];
char graph[1010][1010];

bool isValid (int x, int y) {
  if (x < 0) return false;
  if (y < 0) return false;
  if (x >= n) return false;
  if (y >= m) return false;
  if(vis[x][y]) return false;
  if (graph[x][y] == '#') return false;
  return true;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    vis[x][y] = 1;

    for (int i = 0 ; i < 4 ; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)){
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> graph[i][j];
        vis[i][j] = 0;
      }
    }

    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (graph[i][j] == '.' && !vis[i][j]) {
          dfs(i, j);
          ans++;
        }
      }
    }

    cout << ans << endl;
    return 0;
}
