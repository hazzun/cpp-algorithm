#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];
bool vis[102][102];

int n, k;
queue<pair<int, int>> Q;

void bfs(int x, int y)
{
  Q.push({x, y});
  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();
    vis[cur.first][cur.second] = 1;

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (board[nx][ny] == 1 || vis[nx][ny])
        continue;
      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      Q.push({nx, ny});
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  while (k--)
  {
    int x, y;
    cin >> x >> y;
    board[x - 1][y - 1] = 1;
    bfs(x - 1, y - 1);
  }

  int count = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (vis[i][j])
        count++;

  cout << count;
}