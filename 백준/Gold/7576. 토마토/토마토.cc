#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> Q;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 1)
        Q.push({i, j});
      if (board[i][j] == 0)
        dist[i][j] = -1;
    }
  }

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        continue;
      if (board[nx][ny] > 0 || board[nx][ny] == -1)
        continue;
      board[nx][ny] = board[cur.first][cur.second] + 1;
      dist[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }

  int max = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (dist[i][j] == -1)
      {
        cout << -1;
        return 0;
      }
      else if (max < board[i][j])
        max = board[i][j];
    }
  }
  cout << max - 1;
}