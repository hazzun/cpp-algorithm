#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[102][102];
bool vis[102][102];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 0)
        vis[i][j] = true;
    }
  }

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  vis[0][0] = 1;

  bool isEscape = false;

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (board[nx][ny] == 0 || vis[nx][ny])
        continue;

      vis[nx][ny] = 1;
      Q.push({nx, ny});

      if (nx == n - 1 && ny == m - 1)
        isEscape = true;
    }
  }
  if (isEscape)
    cout << 1;
  else
    cout << 0;
}