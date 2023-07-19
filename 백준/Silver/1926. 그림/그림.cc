#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[500][500];
bool vis[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int, int>> Q;

  int countPicture = 0;
  int mx = 0;
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      board[i][j] = k;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      if (vis[i][j] != board[i][j]) {
        countPicture++;

        Q.push({i, j});
        vis[i][j] = 1;

        int size = 0;

        while (!Q.empty()) {
          size++;
          pair<int, int> cur = Q.front();
          Q.pop();
            
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
              continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
        mx = max(mx, size);
      }
    }
  }
  cout << countPicture << "\n" << mx;
}