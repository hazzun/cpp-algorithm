#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int board[102][102];
bool vis[102][102];

int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, 1, 0, -1};

int m, n, k;
int sx, sy, ex, ey;
vector<int> ans;

int BFS(int i, int j)
{
  int count = 0;
  queue<pair<int, int>> Q;

  Q.push({i, j});
  vis[i][j] = 1;

  while (!Q.empty())
  {
    count++;
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int dx = cur.first + nx[dir];
      int dy = cur.second + ny[dir];

      if (dx < 0 || dy < 0 || dx >= m || dy >= n)
        continue;
      if (vis[dx][dy] || board[dx][dy] == 1)
        continue;

      Q.push({dx, dy});
      vis[dx][dy] = 1;
    }
  }
  return count;
}

int main(void)
{
  int cnt = 0;
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;

  while (k--)
  {
    cin >> sy >> sx >> ey >> ex;
    for (int i = sx; i < ex; i++)
    {
      for (int j = sy; j < ey; j++)
      {
        board[i][j] = 1;
        vis[i][j] = true;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 0 && !vis[i][j])
      {
        ans.push_back(BFS(i, j));
        cnt++;
      }
    }
  }

  sort(ans.begin(), ans.end());

  cout << cnt << '\n';
  for (int i : ans)
    cout << i << ' ';
}