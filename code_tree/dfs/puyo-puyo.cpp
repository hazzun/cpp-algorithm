#include <iostream>

using namespace std;

int n, blockCount;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];
bool vis[102][102];

void initializeVis()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      vis[i][j] = false;
}

void dfs(int x, int y)
{
  for (int dir = 0; dir < 4; dir++)
  {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
      continue;
    if (board[x][y] != board[nx][ny] || vis[nx][ny])
      continue;

    vis[nx][ny] = 1;
    blockCount++;
    dfs(nx, ny);
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  int bomb = 0, maxCount = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!vis[i][j])
      {
        vis[i][j] = 1;
        dfs(i, j);
        maxCount = max(maxCount, blockCount + 1);
        if (blockCount + 1 >= 4)
        {
          bomb++;
        }
        // blockCount 초기화
        blockCount = 0;
      }
    }
  }
  cout << bomb << " " << maxCount;
}