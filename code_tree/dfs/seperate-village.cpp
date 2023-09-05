#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[27][27];
bool vis[27][27];
int n;

stack<pair<int, int>> S;

int dfs(int x, int y, int check)
{
  while (!S.empty())
  {
    auto cur = S.top();
    S.pop();
    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        continue;
      if (vis[nx][ny] || board[nx][ny] == 0)
        continue;
      vis[nx][ny] = 1;
      // dfs(nx, ny, check+1);
      check++;
      S.push({nx, ny});
    }
  }
  return check;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  vector<int> cnt;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 1 && !vis[i][j])
      {
        vis[i][j] = 1;
        S.push({i, j});
        cnt.push_back(dfs(i, j, 1));
        count++;
      }
    }
  }
  cout << count << "\n";
  sort(cnt.begin(), cnt.end());
  for (auto i : cnt)
    cout << i << "\n";
}