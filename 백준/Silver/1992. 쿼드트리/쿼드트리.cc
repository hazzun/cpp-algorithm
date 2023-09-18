#include <iostream>
#include <string>

using namespace std;

int n;
string board[65];

bool isSame(int x, int y, int count)
{
  for (int i = x; i < x + count; i++)
  {
    for (int j = y; j < y + count; j++)
    {
      if (board[i][j] != board[x][y])
        return false;
    }
  }
  return true;
}

void rec(int x, int y, int size)
{
  // 종료조건
  if (isSame(x, y, size))
  {
    cout << board[x][y];
    return;
  }
  // 재귀호출
  else
  {
    int div = size / 2;
    cout << "(";
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        rec(x + i * div, y + j * div, div);
      }
    }
    cout << ")";
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> board[i];

  rec(0, 0, n);
}