#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int boardSize, trial, x, y;
int board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int maxNum;

pair<int, int> priority(int num)
{
  if (num == board[x - 1][y - 1])
    return pair<int, int>({x - 1, y - 1});
  for (int i = 0; i < boardSize; i++)
  {
    for (int j = 0; j < boardSize; j++)
    {
      if (board[i][j] == num)
      {
        // cout << i << " " << j << ", ";
        return pair<int, int>({i, j});
      }
    }
  }
}

int bfs(pair<int, int> dot)
{
  if (boardSize == 1)
    maxNum = board[dot.first][dot.second];
  else
    maxNum = 0;
  queue<pair<int, int>> Q;
  // cout << dot.first << dot.second;
  Q.push({dot.first, dot.second});
  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize)
        continue;
      if (vis[nx][ny] || board[nx][ny] >= board[dot.first][dot.second])
        continue;

      cout << "nx : " << nx << ", ny : " << ny << "\n";

      vis[nx][ny] = 1;
      maxNum = max(maxNum, board[nx][ny]);
      Q.push({nx, ny});
    }
  }
  for (int i = 0; i < boardSize; i++)
  {
    for (int j = 0; j < boardSize; j++)
    {
      vis[i][j] = 0;
    }
  }
  if (maxNum == 0)
    return board[dot.first][dot.second];
  else
    return maxNum;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> boardSize >> trial;
  for (int i = 0; i < boardSize; i++)
  {
    for (int j = 0; j < boardSize; j++)
    {
      cin >> board[i][j];
    }
  }
  cin >> x >> y;
  vis[x - 1][y - 1] = 1;

  pair<int, int> arg = {x - 1, y - 1};
  int answer = 0;
  while (trial--)
  {
    answer = bfs(arg);
    cout << "answer = " << answer << "\n";
    arg = priority(answer);
    cout << "arg.first = " << arg.first << ", arg.second = " << arg.second << "\n";
  }
  cout << "\n";
  cout << arg.first + 1 << " " << arg.second + 1;
}

/**
 * 초기 좌표값 입력받기
 * 해당 좌표에 해당하는 값보다 작은 것을 바탕으로 bfs돌림
 * bfs 돌리면서 최대값 받아내기
 * 최대값을 인자로 넣어서 우선순위가 높은 좌표값을 받아오는 함수 실행
 */