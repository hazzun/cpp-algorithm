#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[102][102];
bool vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, maxHigh = 0, maxCount = 0;
queue<pair<int, int>> Q;

void BFS()
{
  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (vis[nx][ny] == 1)
        continue;
      if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        continue;

      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int SectionCheck(int index)
{
  // vis에 영역구분 해주기
  for (int j = 0; j < n; j++)
  {
    for (int k = 0; k < n; k++)
    {
      if (board[j][k] <= index)
        vis[j][k] = 1;
    }
  }

  int count = 0;

  // 영역 구분이 된 이후, 물애 침수되지 않은 부분 큐에 넣고 BFS 돌리기
  for (int j = 0; j < n; j++)
  {
    for (int k = 0; k < n; k++)
    {
      if (vis[j][k] == 0)
      {
        count++;
        Q.push({j, k});
        BFS();
      }
    }
  }

  // vis 초기화
  for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++)
      vis[j][k] = 0;
  return count;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] > maxHigh)
        maxHigh = board[i][j];
    }
  }

  for (int i = 0; i <= maxHigh; i++)
  {
    if (maxCount < SectionCheck(i))
      maxCount = SectionCheck(i);
  }

  cout << maxCount;
}