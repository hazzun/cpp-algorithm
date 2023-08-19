#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char board[1002][1002];
int humanBoard[1002][1002];
int fireBoard[1002][1002];

int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, 1, 0, -1};

int R, C;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;

  queue<pair<int, int>> humanQ;
  queue<pair<int, int>> fireQ;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == '#')
      {
        humanBoard[i][j] = -1;
        fireBoard[i][j] = -1;
      }
      else if (board[i][j] == 'J')
      {
        humanBoard[i][j] = 1;
        humanQ.push({i, j});
      }
      else if (board[i][j] == 'F')
      {
        fireBoard[i][j] = 1;
        fireQ.push({i, j});
      }
    }
  }

  // 불 먼저 BFS 돌리기
  while (!fireQ.empty())
  {
    auto cur = fireQ.front();
    fireQ.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int dx = cur.first + nx[dir];
      int dy = cur.second + ny[dir];

      if (dx < 0 || dy < 0 || dx >= R || dy >= C)
        continue;
      if (fireBoard[dx][dy] >= 1 || fireBoard[dx][dy] == -1)
        continue;

      fireBoard[dx][dy] = fireBoard[cur.first][cur.second] + 1;
      fireQ.push({dx, dy});
    }
  }

  // 사람 BFS 돌리기
  while (!humanQ.empty())
  {
    auto cur = humanQ.front();
    humanQ.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int dx = cur.first + nx[dir];
      int dy = cur.second + ny[dir];

      if (dx < 0 || dy < 0 || dx >= R || dy >= C)
      {
        cout << humanBoard[cur.first][cur.second];
        return 0;
      }
      if (humanBoard[dx][dy] == -1 || humanBoard[dx][dy] >= 1)
        continue;
      if (fireBoard[dx][dy] != 0 && fireBoard[dx][dy] <= humanBoard[cur.first][cur.second] + 1)
        continue;
      humanBoard[dx][dy] = humanBoard[cur.first][cur.second] + 1;
      humanQ.push({dx, dy});
    }
  }
  cout << "IMPOSSIBLE";
}