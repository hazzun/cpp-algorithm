#include <iostream>
#include <utility>
#include <queue>

using namespace std;

char board[102][102]; // 일반인들을 위한 보드
int board2[102][102]; // 적록색약을 가진 사람들을 위한 보드
bool vis[102][102];
bool vis2[102][102];

int n;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(char color, int x, int y)
{
  queue<pair<int, int>> Q;

  vis[x][y] = true;
  Q.push({x, y});

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        continue;
      if (board[nx][ny] != color || vis[nx][ny])
        continue;

      vis[nx][ny] = true;
      Q.push({nx, ny});
    }
  }
}
void BFS2(char color, int x, int y)
{
  queue<pair<int, int>> Q;

  vis2[x][y] = true;
  Q.push({x, y});

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        continue;
      if (board2[nx][ny] != color || vis2[nx][ny])
        continue;

      vis2[nx][ny] = true;
      Q.push({nx, ny});
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int normalCount = 0;
  int specialCount = 0;

  // board 입력받기
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 'G')
        board2[i][j] = 'R';
      else
        board2[i][j] = board[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 'R' && !vis[i][j])
      {
        // cout << "BFS 들어가기 전, i = " << i << ", j = " << j << "\n";
        normalCount++;
        BFS('R', i, j);
      }
      else if (board[i][j] == 'G' && !vis[i][j])
      {
        // cout << "BFS 들어가기 전, i = " << i << ", j = " << j << "\n";
        normalCount++;
        BFS('G', i, j);
      }
      else if (board[i][j] == 'B' && !vis[i][j])
      {
        // cout << "BFS 들어가기 전, i = " << i << ", j = " << j << "\n";
        normalCount++;
        BFS('B', i, j);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board2[i][j] == 'R' && !vis2[i][j])
      {
        // cout << "BFS 들어가기 전, i = " << i << ", j = " << j << "\n";
        specialCount++;
        BFS2('R', i, j);
      }
      else if (board2[i][j] == 'B' && !vis2[i][j])
      {
        // cout << "BFS2 들어가기 전, i = " << i << ", j = " << j << "\n";
        specialCount++;
        BFS2('B', i, j);
      }
    }
  }

  cout << normalCount << " " << specialCount;
}