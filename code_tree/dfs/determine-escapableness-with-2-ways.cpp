#include <iostream>
#include <stack>

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int board[102][102];
bool vis[102][102];
int n, m;
bool isEscape;
stack<pair<int, int>> S;

void dfs(int x, int y)
{
  while (!S.empty())
  {
    auto cur = S.top();
    S.pop();

    for (int dir = 0; dir < 2; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (vis[nx][ny] || board[nx][ny] == 0)
        continue;
      if (nx == n - 1 && ny == m - 1)
      {
        isEscape = true;
        return;
      }
      vis[nx][ny] = 1;
      S.push({nx, ny});
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  vis[0][0] = 1;
  S.push({0, 0});
  dfs(0, 0);
  if (isEscape)
    cout << 1;
  else
    cout << 0;
}