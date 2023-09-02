#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int vis[102][102];

int solution(vector<vector<int>> maps)
{
  int row = maps.size();
  int col = maps[0].size();

  for (int i = 0; i < row; i++)
  { // 행
    for (int j = 0; j < col; j++)
    { // 열
      if (maps[i][j] == 0)
        vis[i][j] = -1;
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

      if (nx < 0 || ny < 0 || nx >= row || ny >= col)
        continue;
      if (maps[nx][ny] == 0 || vis[nx][ny] > 0)
        continue;

      vis[nx][ny] = vis[cur.first][cur.second] + 1;
      if (nx == row - 1 && ny == col - 1)
      {
        isEscape = true;
        // break;
      }
      Q.push({nx, ny});
    }
  }
  if (isEscape)
    return vis[row - 1][col - 1];
  else
    return -1;
}