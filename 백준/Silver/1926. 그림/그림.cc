#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int board[502][502];
bool vis[502][502];

int n, m;
queue<pair<int, int>> Q;

int bfs()
{
  int count = 1;
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
      if (vis[nx][ny] || board[nx][ny] != 1)
        continue;
      vis[nx][ny] = 1;
      count++;
      Q.push({nx, ny});
    }
  }
  return count;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  int checkCount = 0;
  int answer = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] && !vis[i][j])
      {
        vis[i][j] = 1;
        Q.push({i, j});
        answer = max(answer, bfs());
        checkCount++;
      }
    }
  }
  cout << checkCount << "\n" << answer;
}