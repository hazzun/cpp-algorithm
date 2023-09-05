#include <iostream>
#include <vector>

using namespace std;

int board[1002][1002];
bool vis[1002];
int n, m;
int cnt;

void dfs(int start)
{
  for (int i = 0; i < n; i++)
  {
    if (board[start][i] == 1 && !vis[i])
    {
      vis[i] = true;
      cnt++;
      dfs(i);
    }
  }
}

int main()
{
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    board[x - 1][y - 1] = 1;
    board[y - 1][x - 1] = 1;
  }
  dfs(0);
  if (cnt)
    cout << cnt - 1;
  else
    cout << 0;
}