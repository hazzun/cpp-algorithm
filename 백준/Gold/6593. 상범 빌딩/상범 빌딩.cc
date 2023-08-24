#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};

int L, R, C;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0)
      return 0;

    char board[32][32][32];
    int vis[32][32][32] = {};

    queue<pair<int, pair<int, int>>> Q;

    for (int i = 0; i < L; i++)
    {
      for (int j = 0; j < R; j++)
      {
        for (int k = 0; k < C; k++)
        {
          cin >> board[i][j][k];
          if (board[i][j][k] == 'S')
            Q.push({i, {j, k}});
        }
      }
    }

    bool isOver = false;

    while (!Q.empty())
    {
      if (isOver)
        break;
      auto cur = Q.front();
      Q.pop();

      for (int dir = 0; dir < 6; dir++)
      {
        int nz = cur.first + dz[dir];
        int nx = cur.second.first + dx[dir];
        int ny = cur.second.second + dy[dir];

        if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] > 0)
          continue;
        if (nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= R || ny >= C)
          continue;

        if (board[nz][nx][ny] == 'E')
        {
          isOver = true;
          cout << "Escaped in " << vis[cur.first][cur.second.first][cur.second.second] + 1 << " minute(s).\n";
          break;
        }

        vis[nz][nx][ny] = vis[cur.first][cur.second.first][cur.second.second] + 1;
        Q.push({nz, {nx, ny}});
      }
    }
    while (!Q.empty())
      Q.pop();
    if (!isOver)
      cout << "Trapped!\n";
  }
}