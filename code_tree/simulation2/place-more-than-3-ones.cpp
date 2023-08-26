#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
int board[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int Check(int i, int j)
{
  int check = 0;
  for (int dir = 0; dir < 4; dir++)
  {
    int nx = i + dx[dir];
    int ny = j + dy[dir];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
      continue;
    if (!board[nx][ny])
      continue;
    if (board[nx][ny])
      check++;
  }
  return check;
}

int main()
{
  cin >> n;

  int answer = 0;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (Check(i, j) >= 3)
        count++;
    }
  }

  cout << count;
}