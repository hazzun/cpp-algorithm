#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int len;

int board[302][302];
bool vis[302][302];

int dx[8] = {1, -1, 2, -2, -1, -2, 1, 2};
int dy[8] = {2, -2, 1, -1, 2, 1, -2, -1};

int BFS(int i, int j)
{
  int count = 1;

  vis[i][j] = 1;

  queue<pair<int, int>> Q;
  Q.push({i, j});

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 8; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= len || ny >= len)
        continue;
      if (vis[nx][ny] || board[nx][ny] == 1)
        continue;

      vis[nx][ny] = 1;
      if (board[nx][ny] == -1)
      {
        return board[cur.first][cur.second];
      }
      board[nx][ny] = board[cur.first][cur.second] + 1;

      Q.push({nx, ny});
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, result;
  cin >> n;

  while (n--)
  {
    cin >> len;
    int sx, sy, ex, ey; // start 좌표값, end 좌표값
    cin >> sx >> sy >> ex >> ey;
    board[sx][sy] = 1;
    board[ex][ey] = -1;

    if (sx == ex && sy == ey)
    {
      cout << "0\n";
    }
    else
    {
      result = BFS(sx, sy);
      cout << result << "\n";
    }

    for (int i = 0; i < len; i++)
      fill(board[i], board[i] + len, 0);
    for (int i = 0; i < len; i++)
      fill(vis[i], vis[i] + len, 0);
  }
}