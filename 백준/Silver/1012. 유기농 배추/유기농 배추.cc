#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int coin;
  cin >> coin;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  while (coin--)
  {
    int m, n, k;
    cin >> m >> n >> k;

    int count = 0;

    int board[52][52] = {0};
    bool vis[52][52] = {false};

    queue<pair<int, int>> Q;

    for (int i = 0; i < k; i++)
    {
      int x, y;
      cin >> x >> y;
      board[y][x] = 1;
    }

    // cout << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //   for (int j = 0; j < m; j++)
    //     cout << board[i][j] << " ";
    //   cout << "\n";
    // }
    // cout << "\n";

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] == 1 && !vis[i][j])
        {
          vis[i][j] = true;
          Q.push({i, j});

          while (!Q.empty())
          {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];

              if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
              if (vis[nx][ny] || board[nx][ny] != 1)
                continue;

              vis[nx][ny] = true;
              // cout << "nx = " << nx << ", ny = " << ny << "\n";
              Q.push({nx, ny});
            }
          }
          count++;
          // cout << "i = " << i << ", j = " << j << "\n";
          // cout << count << "\n";
        }
      }
    }
    cout << count << "\n";
  }
}